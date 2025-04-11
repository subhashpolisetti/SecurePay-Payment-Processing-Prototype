#include "mainwindow.h"
#include "addcustomerdialog.h"
#include <QMessageBox>
#include <QDoubleValidator>
#include <QRegularExpressionValidator>
#include <QHeaderView>
#include <QDateTime>
#include <functional>
#include <iostream>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    // Create the application controller
    m_appController = std::make_unique<AppController>();
    
    // Set up the UI
    setupUI();
    
    // Set up the transaction update callback
    m_appController->setTransactionUpdateCallback(
        std::bind(&MainWindow::onTransactionUpdated, this, std::placeholders::_1));
    
    // Initialize the customer combo box
    for (const auto& customer : m_appController->getCustomers()) {
        m_customerComboBox->addItem(QString::fromUtf8(customer.getName().c_str()));
    }
    
    // Update customer details if there are any customers
    if (m_customerComboBox->count() > 0) {
        onCustomerSelected(0);
    }
    
    // Set window properties
    setWindowTitle("SecurePay Payment Processing");
    setMinimumSize(800, 600);
}

MainWindow::~MainWindow() {
    // Clean up resources if needed
}

void MainWindow::setupUI() {
    // Create central widget and main layout
    QWidget* centralWidget = new QWidget(this);
    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
    
    // Customer section
    QGroupBox* customerGroup = new QGroupBox("Customer Information", centralWidget);
    QVBoxLayout* customerLayout = new QVBoxLayout(customerGroup);
    
    QHBoxLayout* customerSelectionLayout = new QHBoxLayout();
    m_customerComboBox = new QComboBox(customerGroup);
    m_addCustomerButton = new QPushButton("Add Customer", customerGroup);
    customerSelectionLayout->addWidget(new QLabel("Select Customer:"));
    customerSelectionLayout->addWidget(m_customerComboBox, 1);
    customerSelectionLayout->addWidget(m_addCustomerButton);
    
    m_customerDetailsLabel = new QLabel(customerGroup);
    m_customerDetailsLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    m_customerDetailsLabel->setMinimumHeight(60);
    
    customerLayout->addLayout(customerSelectionLayout);
    customerLayout->addWidget(m_customerDetailsLabel);
    
    // Payment section
    QGroupBox* paymentGroup = new QGroupBox("Payment Information", centralWidget);
    QVBoxLayout* paymentLayout = new QVBoxLayout(paymentGroup);
    
    // Amount and payment method
    QFormLayout* paymentFormLayout = new QFormLayout();
    m_amountEdit = new QLineEdit(paymentGroup);
    m_amountEdit->setValidator(new QDoubleValidator(0.01, 10000.00, 2, paymentGroup));
    m_amountEdit->setPlaceholderText("Enter amount (e.g., 100.00)");
    
    m_paymentMethodComboBox = new QComboBox(paymentGroup);
    m_paymentMethodComboBox->addItem("Credit Card");
    m_paymentMethodComboBox->addItem("Debit Card");
    m_paymentMethodComboBox->addItem("Digital Wallet");
    
    paymentFormLayout->addRow("Amount ($):", m_amountEdit);
    paymentFormLayout->addRow("Payment Method:", m_paymentMethodComboBox);
    
    // Credit/Debit Card fields
    m_cardFieldsGroup = new QGroupBox("Card Details", paymentGroup);
    QFormLayout* cardFormLayout = new QFormLayout(m_cardFieldsGroup);
    
    m_cardNumberEdit = new QLineEdit(m_cardFieldsGroup);
    m_cardNumberEdit->setPlaceholderText("Enter card number");
    m_cardNumberEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{13,19}"), m_cardFieldsGroup));
    
    m_cardholderNameEdit = new QLineEdit(m_cardFieldsGroup);
    m_cardholderNameEdit->setPlaceholderText("Enter cardholder name");
    
    m_expiryDateEdit = new QLineEdit(m_cardFieldsGroup);
    m_expiryDateEdit->setPlaceholderText("MM/YY");
    // Allow both MM/YY format and MMYY format
    m_expiryDateEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("([0-9]{2}/[0-9]{2})|([0-9]{4})"), m_cardFieldsGroup));
    
    m_cvvEdit = new QLineEdit(m_cardFieldsGroup);
    m_cvvEdit->setPlaceholderText("CVV");
    m_cvvEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{3,4}"), m_cardFieldsGroup));
    m_cvvEdit->setMaxLength(4);
    
    cardFormLayout->addRow("Card Number:", m_cardNumberEdit);
    cardFormLayout->addRow("Cardholder Name:", m_cardholderNameEdit);
    cardFormLayout->addRow("Expiry Date:", m_expiryDateEdit);
    cardFormLayout->addRow("CVV:", m_cvvEdit);
    
    // Digital Wallet fields
    m_walletFieldsGroup = new QGroupBox("Wallet Details", paymentGroup);
    QFormLayout* walletFormLayout = new QFormLayout(m_walletFieldsGroup);
    
    m_walletIdEdit = new QLineEdit(m_walletFieldsGroup);
    m_walletIdEdit->setPlaceholderText("Enter wallet ID");
    
    m_walletEmailEdit = new QLineEdit(m_walletFieldsGroup);
    m_walletEmailEdit->setPlaceholderText("Enter wallet email");
    
    walletFormLayout->addRow("Wallet ID:", m_walletIdEdit);
    walletFormLayout->addRow("Email:", m_walletEmailEdit);
    
    // Submit button
    m_submitButton = new QPushButton("Submit Payment", paymentGroup);
    m_submitButton->setMinimumHeight(40);
    
    // Add payment components to layout
    paymentLayout->addLayout(paymentFormLayout);
    paymentLayout->addWidget(m_cardFieldsGroup);
    paymentLayout->addWidget(m_walletFieldsGroup);
    paymentLayout->addWidget(m_submitButton);
    
    // Ensure card fields are visible by default
    m_cardFieldsGroup->show();
    m_walletFieldsGroup->hide();
    
    // Result section
    QGroupBox* resultGroup = new QGroupBox("Transaction Result", centralWidget);
    QVBoxLayout* resultLayout = new QVBoxLayout(resultGroup);
    
    m_resultLabel = new QLabel(resultGroup);
    m_resultLabel->setAlignment(Qt::AlignCenter);
    m_resultLabel->setMinimumHeight(60);
    m_resultLabel->setStyleSheet("font-size: 16pt;");
    
    resultLayout->addWidget(m_resultLabel);
    
    // Transaction history section
    QGroupBox* historyGroup = new QGroupBox("Transaction History", centralWidget);
    QVBoxLayout* historyLayout = new QVBoxLayout(historyGroup);
    
    m_transactionTable = new QTableWidget(0, 5, historyGroup);
    m_transactionTable->setHorizontalHeaderLabels({"ID", "Customer", "Amount", "Payment Method", "Status"});
    m_transactionTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    m_transactionTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_transactionTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    
    historyLayout->addWidget(m_transactionTable);
    
    // Add all sections to main layout
    mainLayout->addWidget(customerGroup);
    mainLayout->addWidget(paymentGroup);
    mainLayout->addWidget(resultGroup);
    mainLayout->addWidget(historyGroup);
    
    // Set central widget
    setCentralWidget(centralWidget);
    
    // Set up status bar
    statusBar()->showMessage("Ready");
    
    // Connect signals and slots
    connect(m_customerComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onCustomerSelected);
    connect(m_addCustomerButton, &QPushButton::clicked,
            this, &MainWindow::onAddCustomerClicked);
    connect(m_paymentMethodComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onPaymentMethodSelected);
    connect(m_submitButton, &QPushButton::clicked,
            this, &MainWindow::onSubmitClicked);
    
    // Initialize payment method fields
    m_cardFieldsGroup->setVisible(true);
    m_walletFieldsGroup->setVisible(false);
}

void MainWindow::updateCustomerDetails() {
    int index = m_customerComboBox->currentIndex();
    if (index >= 0 && index < static_cast<int>(m_appController->getCustomers().size())) {
        const Customer& customer = m_appController->getCustomers()[index];
        QString details = QString("<b>Name:</b> %1<br><b>Email:</b> %2<br><b>Address:</b> %3")
            .arg(QString::fromUtf8(customer.getName().c_str()))
            .arg(QString::fromUtf8(customer.getEmail().c_str()))
            .arg(QString::fromUtf8(customer.getBillingAddress().c_str()));
        m_customerDetailsLabel->setText(details);
    } else {
        m_customerDetailsLabel->setText("No customer selected");
    }
}

void MainWindow::updatePaymentMethodFields() {
    QString paymentMethod = m_paymentMethodComboBox->currentText();
    
    std::cout << "Selected payment method: " << paymentMethod.toUtf8().constData() << std::endl;
    
    if (paymentMethod == "Credit Card" || paymentMethod == "Debit Card") {
        std::cout << "Showing card fields, hiding wallet fields" << std::endl;
        m_cardFieldsGroup->show();
        m_walletFieldsGroup->hide();
    } else if (paymentMethod == "Digital Wallet") {
        std::cout << "Hiding card fields, showing wallet fields" << std::endl;
        m_cardFieldsGroup->hide();
        m_walletFieldsGroup->show();
    }
}

void MainWindow::updateTransactionHistory() {
    const auto& transactions = m_appController->getTransactionHistory();
    
    // Clear the table
    m_transactionTable->setRowCount(0);
    
    // Add transactions to the table
    for (const auto& transaction : transactions) {
        int row = m_transactionTable->rowCount();
        m_transactionTable->insertRow(row);
        
        m_transactionTable->setItem(row, 0, new QTableWidgetItem(QString::fromUtf8(transaction->getTransactionId().c_str())));
        m_transactionTable->setItem(row, 1, new QTableWidgetItem(QString::fromUtf8(transaction->getCustomer().getName().c_str())));
        m_transactionTable->setItem(row, 2, new QTableWidgetItem(QString("$%1").arg(transaction->getAmount(), 0, 'f', 2)));
        m_transactionTable->setItem(row, 3, new QTableWidgetItem(QString::fromUtf8(transaction->getPaymentMethod().getType().c_str())));
        m_transactionTable->setItem(row, 4, new QTableWidgetItem(QString::fromUtf8(Transaction::statusToString(transaction->getStatus()).c_str())));
    }
}

void MainWindow::onCustomerSelected(int index) {
    updateCustomerDetails();
}

void MainWindow::onAddCustomerClicked() {
    AddCustomerDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        Customer customer = dialog.getCustomer();
        m_appController->addCustomer(customer);
        
        // Add the new customer to the combo box
        m_customerComboBox->addItem(QString::fromUtf8(customer.getName().c_str()));
        
        // Select the new customer
        m_customerComboBox->setCurrentIndex(m_customerComboBox->count() - 1);
    }
}

void MainWindow::onPaymentMethodSelected(int index) {
    updatePaymentMethodFields();
}

void MainWindow::onSubmitClicked() {
    // Validate amount
    bool amountValid;
    double amount = m_amountEdit->text().toDouble(&amountValid);
    
    if (!amountValid || amount <= 0) {
        QMessageBox::warning(this, "Validation Error", "Please enter a valid amount.");
        m_amountEdit->setFocus();
        return;
    }
    
    // Get selected customer
    int customerIndex = m_customerComboBox->currentIndex();
    if (customerIndex < 0 || customerIndex >= static_cast<int>(m_appController->getCustomers().size())) {
        QMessageBox::warning(this, "Validation Error", "Please select a customer.");
        return;
    }
    
    const Customer& customer = m_appController->getCustomers()[customerIndex];
    
    // Get payment method details
    QString paymentMethodType = m_paymentMethodComboBox->currentText();
    std::string details1, details2, details3, details4;
    
    if (paymentMethodType == "Credit Card" || paymentMethodType == "Debit Card") {
        // Validate card details
        if (m_cardNumberEdit->text().isEmpty()) {
            QMessageBox::warning(this, "Validation Error", "Please enter a card number.");
            m_cardNumberEdit->setFocus();
            return;
        }
        
        if (m_cardholderNameEdit->text().isEmpty()) {
            QMessageBox::warning(this, "Validation Error", "Please enter the cardholder name.");
            m_cardholderNameEdit->setFocus();
            return;
        }
        
        if (m_expiryDateEdit->text().isEmpty()) {
            QMessageBox::warning(this, "Validation Error", "Please enter the expiry date.");
            m_expiryDateEdit->setFocus();
            return;
        }
        
        if (m_cvvEdit->text().isEmpty()) {
            QMessageBox::warning(this, "Validation Error", "Please enter the CVV.");
            m_cvvEdit->setFocus();
            return;
        }
        
        details1 = m_cardNumberEdit->text().toUtf8().constData();
        details2 = m_cardholderNameEdit->text().toUtf8().constData();
        details3 = m_expiryDateEdit->text().toUtf8().constData();
        details4 = m_cvvEdit->text().toUtf8().constData();
    } else if (paymentMethodType == "Digital Wallet") {
        // Validate wallet details
        if (m_walletIdEdit->text().isEmpty()) {
            QMessageBox::warning(this, "Validation Error", "Please enter a wallet ID.");
            m_walletIdEdit->setFocus();
            return;
        }
        
        if (m_walletEmailEdit->text().isEmpty()) {
            QMessageBox::warning(this, "Validation Error", "Please enter the wallet email.");
            m_walletEmailEdit->setFocus();
            return;
        }
        
        details1 = m_walletIdEdit->text().toUtf8().constData();
        details2 = m_walletEmailEdit->text().toUtf8().constData();
    }
    
        // Create and process the transaction
    auto transaction = m_appController->createTransaction(
        customer,
        paymentMethodType.toUtf8().constData(),
        details1,
        details2,
        details3,
        details4,
        amount
    );
    
    if (transaction) {
        // Get the transaction ID before moving it
        std::string transactionId = transaction->getTransactionId();
        
        // Process the transaction
        m_appController->processTransaction(std::move(transaction));
        
        // Clear form fields
        m_amountEdit->clear();
        m_cardNumberEdit->clear();
        m_cardholderNameEdit->clear();
        m_expiryDateEdit->clear();
        m_cvvEdit->clear();
        m_walletIdEdit->clear();
        m_walletEmailEdit->clear();
        
        // Update transaction history
        updateTransactionHistory();
        
        // Get the processed transaction from history to show the result
        const auto& transactions = m_appController->getTransactionHistory();
        TransactionStatus status = TransactionStatus::PENDING;
        
        // Find the transaction we just processed
        for (const auto& tx : transactions) {
            if (tx->getTransactionId() == transactionId) {
                status = tx->getStatus();
                break;
            }
        }
        QString resultText;
        QString resultStyle;
        
        switch (status) {
            case TransactionStatus::APPROVED:
                resultText = "Transaction Approved";
                resultStyle = "color: green; font-weight: bold;";
                break;
            case TransactionStatus::DECLINED:
                resultText = "Transaction Declined";
                resultStyle = "color: red; font-weight: bold;";
                break;
            case TransactionStatus::FLAGGED_FOR_REVIEW:
                resultText = "Transaction Flagged for Review";
                resultStyle = "color: orange; font-weight: bold;";
                break;
            default:
                resultText = "Transaction Status: " + QString::fromUtf8(Transaction::statusToString(status).c_str());
                resultStyle = "color: black;";
                break;
        }
        
        m_resultLabel->setText(resultText);
        m_resultLabel->setStyleSheet("font-size: 16pt; " + resultStyle);
        
        // Update status bar
        statusBar()->showMessage("Transaction processed: " + QString::fromUtf8(transactionId.c_str()));
    } else {
        QMessageBox::critical(this, "Error", "Failed to create transaction.");
    }
}

void MainWindow::onTransactionUpdated(const Transaction& transaction) {
    // Update transaction history
    updateTransactionHistory();
    
    // Update status bar
    statusBar()->showMessage("Transaction updated: " + QString::fromUtf8(transaction.getTransactionId().c_str()));
}

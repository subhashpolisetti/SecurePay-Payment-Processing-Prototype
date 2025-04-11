#include "addcustomerdialog.h"
#include <QMessageBox>
#include <QRegularExpression>

AddCustomerDialog::AddCustomerDialog(QWidget* parent) : QDialog(parent) {
    // Set dialog properties
    setWindowTitle("Add New Customer");
    setMinimumWidth(400);
    
    // Create form fields
    m_nameEdit = new QLineEdit(this);
    m_emailEdit = new QLineEdit(this);
    m_addressEdit = new QLineEdit(this);
    
    // Create buttons
    m_okButton = new QPushButton("OK", this);
    m_cancelButton = new QPushButton("Cancel", this);
    
    // Connect buttons
    connect(m_okButton, &QPushButton::clicked, this, &AddCustomerDialog::validateForm);
    connect(m_cancelButton, &QPushButton::clicked, this, &QDialog::reject);
    
    // Create form layout
    QFormLayout* formLayout = new QFormLayout;
    formLayout->addRow("Name:", m_nameEdit);
    formLayout->addRow("Email:", m_emailEdit);
    formLayout->addRow("Billing Address:", m_addressEdit);
    
    // Create button layout
    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch();
    buttonLayout->addWidget(m_okButton);
    buttonLayout->addWidget(m_cancelButton);
    
    // Create main layout
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(buttonLayout);
    
    // Set focus to name field
    m_nameEdit->setFocus();
}

Customer AddCustomerDialog::getCustomer() const {
    return Customer(
        m_nameEdit->text().toUtf8().constData(),
        m_emailEdit->text().toUtf8().constData(),
        m_addressEdit->text().toUtf8().constData()
    );
}

void AddCustomerDialog::validateForm() {
    // Check if name is empty
    if (m_nameEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Validation Error", "Please enter a name.");
        m_nameEdit->setFocus();
        return;
    }
    
    // Check if email is valid
    QRegularExpression emailRegex("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}\\b");
    if (!emailRegex.match(m_emailEdit->text()).hasMatch()) {
        QMessageBox::warning(this, "Validation Error", "Please enter a valid email address.");
        m_emailEdit->setFocus();
        return;
    }
    
    // Check if address is empty
    if (m_addressEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Validation Error", "Please enter a billing address.");
        m_addressEdit->setFocus();
        return;
    }
    
    // All validation passed, accept the dialog
    accept();
}

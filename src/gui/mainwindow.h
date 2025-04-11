#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QTableWidget>
#include <QStatusBar>
#include <memory>
#include "../core/appcontroller.h"
#include "../core/transaction.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
    
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    
private:
    // Application controller
    std::unique_ptr<AppController> m_appController;
    
    // UI components - Customer section
    QComboBox* m_customerComboBox;
    QPushButton* m_addCustomerButton;
    QLabel* m_customerDetailsLabel;
    
    // UI components - Payment section
    QLineEdit* m_amountEdit;
    QComboBox* m_paymentMethodComboBox;
    
    // Credit Card / Debit Card fields
    QLineEdit* m_cardNumberEdit;
    QLineEdit* m_cardholderNameEdit;
    QLineEdit* m_expiryDateEdit;
    QLineEdit* m_cvvEdit;
    
    // Digital Wallet fields
    QLineEdit* m_walletIdEdit;
    QLineEdit* m_walletEmailEdit;
    
    QGroupBox* m_cardFieldsGroup;
    QGroupBox* m_walletFieldsGroup;
    
    QPushButton* m_submitButton;
    
    // UI components - Transaction result
    QLabel* m_resultLabel;
    
    // UI components - Transaction history
    QTableWidget* m_transactionTable;
    
    // Set up the UI
    void setupUI();
    
    // Update customer details display
    void updateCustomerDetails();
    
    // Update payment method fields visibility
    void updatePaymentMethodFields();
    
    // Update transaction history table
    void updateTransactionHistory();
    
private slots:
    // Handle customer selection change
    void onCustomerSelected(int index);
    
    // Handle add customer button click
    void onAddCustomerClicked();
    
    // Handle payment method selection change
    void onPaymentMethodSelected(int index);
    
    // Handle submit button click
    void onSubmitClicked();
    
    // Handle transaction update
    void onTransactionUpdated(const Transaction& transaction);
};

#endif // MAINWINDOW_H

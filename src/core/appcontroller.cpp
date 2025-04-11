#include "appcontroller.h"
#include <iostream>

AppController::AppController() : m_paymentGateway(std::make_unique<PaymentGateway>()) {
    std::cout << "AppController initialized" << std::endl;
    
    // Add the controller as an observer to the payment gateway
    m_paymentGateway->addObserver(this);
    
    // Add some default customers
    addCustomer(Customer("Alice Smith", "alice@example.com", "123 Main St, San Francisco, CA"));
    addCustomer(Customer("Bob Johnson", "bob@example.com", "456 Oak Ave, New York, NY"));
}

AppController::~AppController() {
    // Remove the controller as an observer from the payment gateway
    if (m_paymentGateway) {
        m_paymentGateway->removeObserver(this);
    }
}

void AppController::addCustomer(const Customer& customer) {
    m_customers.push_back(customer);
    std::cout << "Added customer: " << customer.getName() << std::endl;
}

const std::vector<Customer>& AppController::getCustomers() const {
    return m_customers;
}

std::unique_ptr<Transaction> AppController::createTransaction(
    const Customer& customer,
    const std::string& paymentMethodType,
    const std::string& paymentDetails1,
    const std::string& paymentDetails2,
    const std::string& paymentDetails3,
    const std::string& paymentDetails4,
    double amount) {
    
    // Create payment method based on type and details
    auto paymentMethod = createPaymentMethod(
        paymentMethodType, 
        paymentDetails1, 
        paymentDetails2, 
        paymentDetails3, 
        paymentDetails4);
    
    if (!paymentMethod) {
        std::cerr << "Failed to create payment method" << std::endl;
        return nullptr;
    }
    
    // Create transaction
    return TransactionFactory::createTransaction(
        customer, std::move(paymentMethod), amount);
}

void AppController::processTransaction(std::unique_ptr<Transaction> transaction) {
    if (m_paymentGateway && transaction) {
        m_paymentGateway->processTransaction(transaction);
    }
}

const std::vector<std::unique_ptr<Transaction>>& AppController::getTransactionHistory() const {
    return m_paymentGateway->getTransactions();
}

void AppController::onTransactionUpdated(const Transaction& transaction) {
    std::cout << "Transaction updated: " << transaction.getTransactionId() 
              << " - Status: " << Transaction::statusToString(transaction.getStatus()) 
              << std::endl;
    
    // Call the callback if set
    if (m_transactionUpdateCallback) {
        m_transactionUpdateCallback(transaction);
    }
}

void AppController::setTransactionUpdateCallback(std::function<void(const Transaction&)> callback) {
    m_transactionUpdateCallback = callback;
}

std::unique_ptr<PaymentMethod> AppController::createPaymentMethod(
    const std::string& paymentMethodType,
    const std::string& details1,
    const std::string& details2,
    const std::string& details3,
    const std::string& details4) {
    
    if (paymentMethodType == "Credit Card") {
        return PaymentMethodFactory::createCreditCard(
            details1,  // Card number
            details2,  // Cardholder name
            details3,  // Expiry date
            details4   // CVV
        );
    } else if (paymentMethodType == "Debit Card") {
        return PaymentMethodFactory::createDebitCard(
            details1,  // Card number
            details2,  // Cardholder name
            details3,  // Expiry date
            details4   // CVV
        );
    } else if (paymentMethodType == "Digital Wallet") {
        return PaymentMethodFactory::createDigitalWallet(
            details1,  // Wallet ID
            details2   // Email
        );
    }
    
    // Unknown payment method type
    std::cerr << "Unknown payment method type: " << paymentMethodType << std::endl;
    return nullptr;
}

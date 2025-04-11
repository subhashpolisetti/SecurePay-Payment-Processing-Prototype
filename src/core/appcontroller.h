#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include <vector>
#include <memory>
#include <string>
#include "customer.h"
#include "transaction.h"
#include "paymentmethod.h"
#include "paymentgateway.h"

// Controller class for the application (MVC pattern)
class AppController : public TransactionObserver {
public:
    AppController();
    ~AppController();
    
    // Customer management
    void addCustomer(const Customer& customer);
    const std::vector<Customer>& getCustomers() const;
    
    // Transaction processing
    std::unique_ptr<Transaction> createTransaction(
        const Customer& customer,
        const std::string& paymentMethodType,
        const std::string& paymentDetails1,
        const std::string& paymentDetails2,
        const std::string& paymentDetails3,
        const std::string& paymentDetails4,
        double amount);
    
    void processTransaction(std::unique_ptr<Transaction> transaction);
    
    // Get transaction history
    const std::vector<std::unique_ptr<Transaction>>& getTransactionHistory() const;
    
    // Observer method for transaction updates
    void onTransactionUpdated(const Transaction& transaction) override;
    
    // Set callback for transaction updates
    void setTransactionUpdateCallback(std::function<void(const Transaction&)> callback);
    
private:
    // List of customers
    std::vector<Customer> m_customers;
    
    // Payment gateway
    std::unique_ptr<PaymentGateway> m_paymentGateway;
    
    // Callback for transaction updates
    std::function<void(const Transaction&)> m_transactionUpdateCallback;
    
    // Create a payment method based on type and details
    std::unique_ptr<PaymentMethod> createPaymentMethod(
        const std::string& paymentMethodType,
        const std::string& details1,
        const std::string& details2,
        const std::string& details3,
        const std::string& details4);
};

#endif // APPCONTROLLER_H

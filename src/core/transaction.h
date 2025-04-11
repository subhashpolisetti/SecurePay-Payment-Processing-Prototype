#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <memory>
#include <chrono>
#include "customer.h"
#include "paymentmethod.h"

// Enum for transaction status
enum class TransactionStatus {
    PENDING,
    APPROVED,
    DECLINED,
    FLAGGED_FOR_REVIEW
};

// Class to represent a payment transaction
class Transaction {
public:
    Transaction(const Customer& customer, std::unique_ptr<PaymentMethod> paymentMethod, 
                double amount);
    
    // Getters
    std::string getTransactionId() const;
    const Customer& getCustomer() const;
    const PaymentMethod& getPaymentMethod() const;
    double getAmount() const;
    TransactionStatus getStatus() const;
    std::string getTimestamp() const;
    
    // Setters
    void setStatus(TransactionStatus status);
    
    // Convert status to string
    static std::string statusToString(TransactionStatus status);
    
private:
    std::string m_transactionId;
    Customer m_customer;
    std::unique_ptr<PaymentMethod> m_paymentMethod;
    double m_amount;
    TransactionStatus m_status;
    std::chrono::system_clock::time_point m_timestamp;
    
    // Generate a unique transaction ID
    static std::string generateTransactionId();
};

// Factory for creating transactions
class TransactionFactory {
public:
    static std::unique_ptr<Transaction> createTransaction(
        const Customer& customer, std::unique_ptr<PaymentMethod> paymentMethod, 
        double amount);
};

#endif // TRANSACTION_H

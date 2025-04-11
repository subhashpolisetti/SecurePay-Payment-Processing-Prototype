#ifndef PAYMENTGATEWAY_H
#define PAYMENTGATEWAY_H

#include <vector>
#include <memory>
#include <functional>
#include "transaction.h"
#include "fraudsystem.h"
#include "bank.h"

// Observer interface for transaction updates (Observer pattern)
class TransactionObserver {
public:
    virtual ~TransactionObserver() = default;
    virtual void onTransactionUpdated(const Transaction& transaction) = 0;
};

// Class for processing payments
class PaymentGateway {
public:
    PaymentGateway();
    
    // Process a transaction
    void processTransaction(std::unique_ptr<Transaction>& transaction);
    
    // Get all processed transactions
    const std::vector<std::unique_ptr<Transaction>>& getTransactions() const;
    
    // Add an observer for transaction updates (Observer pattern)
    void addObserver(TransactionObserver* observer);
    
    // Remove an observer
    void removeObserver(TransactionObserver* observer);
    
private:
    // Store processed transactions
    std::vector<std::unique_ptr<Transaction>> m_transactions;
    
    // List of observers (Observer pattern)
    std::vector<TransactionObserver*> m_observers;
    
    // Notify observers of transaction update
    void notifyObservers(const Transaction& transaction);
    
    // Simulate data encryption (in a real system, this would use actual encryption)
    void encryptTransactionData(const Transaction& transaction);
};

#endif // PAYMENTGATEWAY_H

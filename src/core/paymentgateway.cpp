#include "paymentgateway.h"
#include <iostream>
#include <algorithm>

PaymentGateway::PaymentGateway() {
    std::cout << "PaymentGateway initialized" << std::endl;
}

void PaymentGateway::processTransaction(std::unique_ptr<Transaction>& transaction) {
    std::cout << "Processing transaction " << transaction->getTransactionId() << std::endl;
    
    // Simulate data encryption
    encryptTransactionData(*transaction);
    
    // Evaluate fraud risk
    FraudSystem& fraudSystem = FraudSystem::getInstance();
    FraudRiskLevel riskLevel = fraudSystem.evaluateTransaction(*transaction);
    
    std::cout << "Fraud risk level: " << FraudSystem::riskLevelToString(riskLevel) << std::endl;
    
    // Authorize transaction with bank
    Bank& bank = Bank::getInstance();
    AuthorizationResult authResult = bank.authorizeTransaction(*transaction, riskLevel);
    
    std::cout << "Authorization result: " << Bank::resultToString(authResult) << std::endl;
    
    // Update transaction status based on authorization result
    switch (authResult) {
        case AuthorizationResult::APPROVED:
            transaction->setStatus(TransactionStatus::APPROVED);
            break;
        case AuthorizationResult::DECLINED:
            transaction->setStatus(TransactionStatus::DECLINED);
            break;
        case AuthorizationResult::REVIEW_REQUIRED:
            transaction->setStatus(TransactionStatus::FLAGGED_FOR_REVIEW);
            break;
    }
    
    // Notify observers before moving the transaction
    notifyObservers(*transaction);
    
    // Store the transaction (move ownership)
    m_transactions.push_back(std::move(transaction));
}

const std::vector<std::unique_ptr<Transaction>>& PaymentGateway::getTransactions() const {
    return m_transactions;
}

void PaymentGateway::addObserver(TransactionObserver* observer) {
    if (observer) {
        m_observers.push_back(observer);
    }
}

void PaymentGateway::removeObserver(TransactionObserver* observer) {
    auto it = std::find(m_observers.begin(), m_observers.end(), observer);
    if (it != m_observers.end()) {
        m_observers.erase(it);
    }
}

void PaymentGateway::notifyObservers(const Transaction& transaction) {
    for (auto observer : m_observers) {
        observer->onTransactionUpdated(transaction);
    }
}

void PaymentGateway::encryptTransactionData(const Transaction& transaction) {
    // In a real system, this would use actual encryption
    // For the prototype, we'll just simulate it
    std::cout << "Encrypting transaction data for " << transaction.getTransactionId() << std::endl;
}

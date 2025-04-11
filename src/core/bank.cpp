#include "bank.h"
#include <iostream>

// Singleton implementation
Bank& Bank::getInstance() {
    static Bank instance;
    return instance;
}

// Private constructor
Bank::Bank() {
    std::cout << "Bank initialized" << std::endl;
}

// Authorize a transaction
AuthorizationResult Bank::authorizeTransaction(const Transaction& transaction, 
                                              FraudRiskLevel fraudRiskLevel) {
    std::cout << "Authorizing transaction " << transaction.getTransactionId() << std::endl;
    
    // Check if the card is valid
    if (!isCardValid(transaction.getPaymentMethod())) {
        std::cout << "Card validation failed" << std::endl;
        return AuthorizationResult::DECLINED;
    }
    
    // Check if there are sufficient funds
    if (!hasSufficientFunds(transaction)) {
        std::cout << "Insufficient funds" << std::endl;
        return AuthorizationResult::DECLINED;
    }
    
    // Check fraud risk level
    if (fraudRiskLevel == FraudRiskLevel::HIGH) {
        std::cout << "High fraud risk, review required" << std::endl;
        return AuthorizationResult::REVIEW_REQUIRED;
    } else if (fraudRiskLevel == FraudRiskLevel::MEDIUM) {
        // For medium risk, randomly approve or require review
        // For the prototype, we'll just approve medium risk transactions
        std::cout << "Medium fraud risk, but approved" << std::endl;
        return AuthorizationResult::APPROVED;
    }
    
    // Low risk, approve the transaction
    std::cout << "Transaction approved" << std::endl;
    return AuthorizationResult::APPROVED;
}

// Check if the card is valid
bool Bank::isCardValid(const PaymentMethod& paymentMethod) const {
    // For the prototype, we'll consider all payment methods valid
    // In a real system, this would check expiration date, card status, etc.
    return true;
}

// Check if there are sufficient funds
bool Bank::hasSufficientFunds(const Transaction& transaction) const {
    // For the prototype, we'll use a simple rule:
    // Approve if amount is less than $5000
    return transaction.getAmount() < 5000.0;
}

// Convert authorization result to string
std::string Bank::resultToString(AuthorizationResult result) {
    switch (result) {
        case AuthorizationResult::APPROVED:
            return "Approved";
        case AuthorizationResult::DECLINED:
            return "Declined";
        case AuthorizationResult::REVIEW_REQUIRED:
            return "Flagged for Review";
        default:
            return "Unknown";
    }
}

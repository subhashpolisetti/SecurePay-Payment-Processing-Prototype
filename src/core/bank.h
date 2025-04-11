#ifndef BANK_H
#define BANK_H

#include "transaction.h"
#include "fraudsystem.h"

// Enum for authorization result
enum class AuthorizationResult {
    APPROVED,
    DECLINED,
    REVIEW_REQUIRED
};

// Singleton class for bank authorization
class Bank {
public:
    // Get the singleton instance
    static Bank& getInstance();
    
    // Prevent copying and assignment
    Bank(const Bank&) = delete;
    Bank& operator=(const Bank&) = delete;
    
    // Authorize a transaction
    AuthorizationResult authorizeTransaction(const Transaction& transaction, 
                                            FraudRiskLevel fraudRiskLevel);
    
    // Convert authorization result to string
    static std::string resultToString(AuthorizationResult result);
    
private:
    // Private constructor for singleton
    Bank();
    
    // Check if the transaction should be authorized
    bool hasSufficientFunds(const Transaction& transaction) const;
    bool isCardValid(const PaymentMethod& paymentMethod) const;
};

#endif // BANK_H

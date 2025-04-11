#ifndef FRAUDSYSTEM_H
#define FRAUDSYSTEM_H

#include <memory>
#include "transaction.h"

// Enum for fraud risk level
enum class FraudRiskLevel {
    LOW,
    MEDIUM,
    HIGH
};

// Singleton class for fraud detection
class FraudSystem {
public:
    // Get the singleton instance
    static FraudSystem& getInstance();
    
    // Prevent copying and assignment
    FraudSystem(const FraudSystem&) = delete;
    FraudSystem& operator=(const FraudSystem&) = delete;
    
    // Evaluate a transaction for fraud risk
    FraudRiskLevel evaluateTransaction(const Transaction& transaction);
    
    // Convert risk level to string
    static std::string riskLevelToString(FraudRiskLevel riskLevel);
    
private:
    // Private constructor for singleton
    FraudSystem();
    
    // Check for suspicious patterns
    bool isAmountSuspicious(double amount) const;
    bool isLocationSuspicious(const std::string& billingAddress) const;
    bool isPaymentMethodSuspicious(const PaymentMethod& paymentMethod) const;
};

#endif // FRAUDSYSTEM_H

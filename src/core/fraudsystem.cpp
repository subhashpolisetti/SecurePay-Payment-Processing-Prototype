#include "fraudsystem.h"
#include <algorithm>
#include <iostream>

// Singleton implementation
FraudSystem& FraudSystem::getInstance() {
    static FraudSystem instance;
    return instance;
}

// Private constructor
FraudSystem::FraudSystem() {
    std::cout << "FraudSystem initialized" << std::endl;
}

// Evaluate transaction for fraud risk
FraudRiskLevel FraudSystem::evaluateTransaction(const Transaction& transaction) {
    std::cout << "Evaluating transaction " << transaction.getTransactionId() 
              << " for fraud risk" << std::endl;
    
    // Count suspicious factors
    int suspiciousFactors = 0;
    
    if (isAmountSuspicious(transaction.getAmount())) {
        suspiciousFactors++;
    }
    
    if (isLocationSuspicious(transaction.getCustomer().getBillingAddress())) {
        suspiciousFactors++;
    }
    
    if (isPaymentMethodSuspicious(transaction.getPaymentMethod())) {
        suspiciousFactors++;
    }
    
    // Determine risk level based on number of suspicious factors
    if (suspiciousFactors == 0) {
        return FraudRiskLevel::LOW;
    } else if (suspiciousFactors == 1) {
        return FraudRiskLevel::MEDIUM;
    } else {
        return FraudRiskLevel::HIGH;
    }
}

// Check if amount is suspicious (high value transactions)
bool FraudSystem::isAmountSuspicious(double amount) const {
    // For the prototype, consider amounts over $1000 suspicious
    return amount > 1000.0;
}

// Check if location is suspicious
bool FraudSystem::isLocationSuspicious(const std::string& billingAddress) const {
    // For the prototype, consider certain locations suspicious
    // Convert to lowercase for case-insensitive comparison
    std::string lowerAddress = billingAddress;
    std::transform(lowerAddress.begin(), lowerAddress.end(), lowerAddress.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    
    // Check for suspicious locations
    return lowerAddress.find("unknown") != std::string::npos ||
           lowerAddress.find("test") != std::string::npos;
}

// Check if payment method is suspicious
bool FraudSystem::isPaymentMethodSuspicious(const PaymentMethod& paymentMethod) const {
    // For the prototype, consider digital wallets slightly more suspicious
    return paymentMethod.getType() == "Digital Wallet";
}

// Convert risk level to string
std::string FraudSystem::riskLevelToString(FraudRiskLevel riskLevel) {
    switch (riskLevel) {
        case FraudRiskLevel::LOW:
            return "Low";
        case FraudRiskLevel::MEDIUM:
            return "Medium";
        case FraudRiskLevel::HIGH:
            return "High";
        default:
            return "Unknown";
    }
}

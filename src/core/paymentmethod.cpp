#include "paymentmethod.h"
#include <iostream>

// CreditCard implementation
CreditCard::CreditCard(const std::string& cardNumber, const std::string& cardholderName, 
                       const std::string& expiryDate, const std::string& cvv)
    : m_cardNumber(cardNumber), m_cardholderName(cardholderName), 
      m_expiryDate(expiryDate), m_cvv(cvv) {}

bool CreditCard::process(double amount) const {
    // In a real system, this would connect to a payment processor
    // For the prototype, we'll simulate processing
    std::cout << "Processing credit card payment of $" << amount << std::endl;
    
    // Simple validation: approve if amount is < 10000
    return amount < 10000.0;
}

std::string CreditCard::getType() const {
    return "Credit Card";
}

std::string CreditCard::getDetails() const {
    // Mask the card number for security
    std::string maskedNumber = "XXXX-XXXX-XXXX-" + m_cardNumber.substr(m_cardNumber.length() - 4);
    return maskedNumber + " (" + m_cardholderName + ")";
}

// DebitCard implementation
DebitCard::DebitCard(const std::string& cardNumber, const std::string& cardholderName, 
                     const std::string& expiryDate, const std::string& cvv)
    : m_cardNumber(cardNumber), m_cardholderName(cardholderName), 
      m_expiryDate(expiryDate), m_cvv(cvv) {}

bool DebitCard::process(double amount) const {
    // In a real system, this would connect to a payment processor
    // For the prototype, we'll simulate processing
    std::cout << "Processing debit card payment of $" << amount << std::endl;
    
    // Simple validation: approve if amount is < 5000
    return amount < 5000.0;
}

std::string DebitCard::getType() const {
    return "Debit Card";
}

std::string DebitCard::getDetails() const {
    // Mask the card number for security
    std::string maskedNumber = "XXXX-XXXX-XXXX-" + m_cardNumber.substr(m_cardNumber.length() - 4);
    return maskedNumber + " (" + m_cardholderName + ")";
}

// DigitalWallet implementation
DigitalWallet::DigitalWallet(const std::string& walletId, const std::string& email)
    : m_walletId(walletId), m_email(email) {}

bool DigitalWallet::process(double amount) const {
    // In a real system, this would connect to a wallet provider API
    // For the prototype, we'll simulate processing
    std::cout << "Processing digital wallet payment of $" << amount << std::endl;
    
    // Simple validation: approve if amount is < 2000
    return amount < 2000.0;
}

std::string DigitalWallet::getType() const {
    return "Digital Wallet";
}

std::string DigitalWallet::getDetails() const {
    return m_walletId + " (" + m_email + ")";
}

// PaymentMethodFactory implementation
std::unique_ptr<PaymentMethod> PaymentMethodFactory::createCreditCard(
    const std::string& cardNumber, const std::string& cardholderName,
    const std::string& expiryDate, const std::string& cvv) {
    return std::make_unique<CreditCard>(cardNumber, cardholderName, expiryDate, cvv);
}

std::unique_ptr<PaymentMethod> PaymentMethodFactory::createDebitCard(
    const std::string& cardNumber, const std::string& cardholderName,
    const std::string& expiryDate, const std::string& cvv) {
    return std::make_unique<DebitCard>(cardNumber, cardholderName, expiryDate, cvv);
}

std::unique_ptr<PaymentMethod> PaymentMethodFactory::createDigitalWallet(
    const std::string& walletId, const std::string& email) {
    return std::make_unique<DigitalWallet>(walletId, email);
}

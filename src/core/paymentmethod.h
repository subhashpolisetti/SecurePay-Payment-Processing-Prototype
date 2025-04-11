#ifndef PAYMENTMETHOD_H
#define PAYMENTMETHOD_H

#include <string>
#include <memory>

// Abstract base class for payment methods (Strategy pattern)
class PaymentMethod {
public:
    virtual ~PaymentMethod() = default;
    
    // Process the payment (implemented by concrete strategies)
    virtual bool process(double amount) const = 0;
    
    // Get payment method type as string
    virtual std::string getType() const = 0;
    
    // Get payment method details for display
    virtual std::string getDetails() const = 0;
};

// Credit Card payment method
class CreditCard : public PaymentMethod {
public:
    CreditCard(const std::string& cardNumber, const std::string& cardholderName, 
               const std::string& expiryDate, const std::string& cvv);
    
    bool process(double amount) const override;
    std::string getType() const override;
    std::string getDetails() const override;
    
private:
    std::string m_cardNumber;
    std::string m_cardholderName;
    std::string m_expiryDate;
    std::string m_cvv;
};

// Debit Card payment method
class DebitCard : public PaymentMethod {
public:
    DebitCard(const std::string& cardNumber, const std::string& cardholderName, 
              const std::string& expiryDate, const std::string& cvv);
    
    bool process(double amount) const override;
    std::string getType() const override;
    std::string getDetails() const override;
    
private:
    std::string m_cardNumber;
    std::string m_cardholderName;
    std::string m_expiryDate;
    std::string m_cvv;
};

// Digital Wallet payment method
class DigitalWallet : public PaymentMethod {
public:
    DigitalWallet(const std::string& walletId, const std::string& email);
    
    bool process(double amount) const override;
    std::string getType() const override;
    std::string getDetails() const override;
    
private:
    std::string m_walletId;
    std::string m_email;
};

// Factory for creating payment methods
class PaymentMethodFactory {
public:
    static std::unique_ptr<PaymentMethod> createCreditCard(
        const std::string& cardNumber, const std::string& cardholderName,
        const std::string& expiryDate, const std::string& cvv);
        
    static std::unique_ptr<PaymentMethod> createDebitCard(
        const std::string& cardNumber, const std::string& cardholderName,
        const std::string& expiryDate, const std::string& cvv);
        
    static std::unique_ptr<PaymentMethod> createDigitalWallet(
        const std::string& walletId, const std::string& email);
};

#endif // PAYMENTMETHOD_H

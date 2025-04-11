#include "transaction.h"
#include <random>
#include <sstream>
#include <iomanip>

// Transaction implementation
Transaction::Transaction(const Customer& customer, std::unique_ptr<PaymentMethod> paymentMethod, 
                         double amount)
    : m_customer(customer), 
      m_paymentMethod(std::move(paymentMethod)), 
      m_amount(amount),
      m_status(TransactionStatus::PENDING),
      m_timestamp(std::chrono::system_clock::now()) {
    m_transactionId = generateTransactionId();
}

std::string Transaction::getTransactionId() const {
    return m_transactionId;
}

const Customer& Transaction::getCustomer() const {
    return m_customer;
}

const PaymentMethod& Transaction::getPaymentMethod() const {
    return *m_paymentMethod;
}

double Transaction::getAmount() const {
    return m_amount;
}

TransactionStatus Transaction::getStatus() const {
    return m_status;
}

std::string Transaction::getTimestamp() const {
    auto time = std::chrono::system_clock::to_time_t(m_timestamp);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

void Transaction::setStatus(TransactionStatus status) {
    m_status = status;
}

std::string Transaction::statusToString(TransactionStatus status) {
    switch (status) {
        case TransactionStatus::PENDING:
            return "Pending";
        case TransactionStatus::APPROVED:
            return "Approved";
        case TransactionStatus::DECLINED:
            return "Declined";
        case TransactionStatus::FLAGGED_FOR_REVIEW:
            return "Flagged for Review";
        default:
            return "Unknown";
    }
}

std::string Transaction::generateTransactionId() {
    // Generate a random transaction ID
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 15);
    
    const char* hex_chars = "0123456789ABCDEF";
    
    std::stringstream ss;
    ss << "TX-";
    for (int i = 0; i < 8; ++i) {
        ss << hex_chars[dis(gen)];
    }
    ss << "-";
    for (int i = 0; i < 4; ++i) {
        ss << hex_chars[dis(gen)];
    }
    
    return ss.str();
}

// TransactionFactory implementation
std::unique_ptr<Transaction> TransactionFactory::createTransaction(
    const Customer& customer, std::unique_ptr<PaymentMethod> paymentMethod, 
    double amount) {
    return std::make_unique<Transaction>(customer, std::move(paymentMethod), amount);
}

# SecurePay Payment Processing Prototype

This is a C++ application with a Qt6 GUI that demonstrates a payment processing use case. The application follows clean code principles, modular design, and incorporates several design patterns.

## Features

- Customer management (select existing or add new)
- Multiple payment methods (Credit Card, Debit Card, Digital Wallet)
- Transaction processing with fraud detection and bank authorization
- Transaction history tracking

## Design Patterns Used

- **Strategy Pattern**: For payment method types (CreditCard, DebitCard, DigitalWallet)
- **Factory Pattern**: For creating payment methods and transactions
- **Singleton Pattern**: For FraudSystem and Bank services
- **Observer Pattern**: For UI updates when transactions are processed
- **MVC Pattern**: Separating the GUI, model, and controller logic

## Project Structure

The project is organized into core and GUI components:

- **Core**: Contains business logic classes (Customer, Transaction, PaymentMethod, etc.)
- **GUI**: Contains UI components (MainWindow, AddCustomerDialog)

## Building the Project

### Prerequisites

- C++ compiler with C++17 support
- Qt6 development libraries
- CMake 3.16 or higher

### Build Steps

1. Create a build directory:
   ```
   mkdir build
   cd build
   ```

2. Configure and build:
   ```
   cmake ..
   make
   ```

## Running the Application

After building, run the application:

```
./SecurePay
```

## Using the Application

1. **Select a Customer**: Choose from the dropdown or add a new customer
2. **Enter Payment Details**:
   - Enter the amount
   - Select a payment method (Credit Card, Debit Card, or Digital Wallet)
   - Fill in the required details for the selected payment method
3. **Submit Payment**: Click the "Submit Payment" button
4. **View Result**: The transaction result will be displayed (Approved, Declined, or Flagged for Review)
5. **Transaction History**: View all processed transactions in the history table

## Design Principles

- **Single Responsibility**: Each class does one thing (Transaction, Customer, PaymentGateway, Bank, etc.)
- **Open/Closed**: New payment methods or fraud rules can be added without changing existing logic
- **Dependency Inversion**: GUI uses AppController interface to invoke core logic

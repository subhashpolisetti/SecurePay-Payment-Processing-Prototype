cmake_minimum_required(VERSION 3.16)
project(SecurePay VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

set(SOURCES
    src/main.cpp
    src/core/customer.cpp
    src/core/transaction.cpp
    src/core/paymentmethod.cpp
    src/core/paymentgateway.cpp
    src/core/fraudsystem.cpp
    src/core/bank.cpp
    src/core/appcontroller.cpp
    src/gui/mainwindow.cpp
    src/gui/addcustomerdialog.cpp
)

set(HEADERS
    src/core/customer.h
    src/core/transaction.h
    src/core/paymentmethod.h
    src/core/paymentgateway.h
    src/core/fraudsystem.h
    src/core/bank.h
    src/core/appcontroller.h
    src/gui/mainwindow.h
    src/gui/addcustomerdialog.h
)

add_executable(SecurePay ${SOURCES} ${HEADERS})

target_link_libraries(SecurePay PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

# Create a README.txt file
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/README.txt
"SecurePay Payment Processing Prototype
=======================================

Instructions:
1. Build the project using CMake:
   mkdir build
   cd build
   cmake ..
   make

2. Run the application:
   ./SecurePay

3. Select or add a customer
4. Fill out payment info and submit
5. Observe the payment status displayed and verify that transaction is recorded

This prototype demonstrates a payment processing use case with good modular design
and pattern usage including Strategy, Factory, Singleton, Observer, and MVC patterns.
")

#include <QApplication>
#include "gui/mainwindow.h"
#include <iostream>
#include <exception>

int main(int argc, char *argv[]) {
    try {
        // Create the Qt application
        QApplication app(argc, argv);
        
        // Set application information
        QApplication::setApplicationName("SecurePay");
        QApplication::setApplicationVersion("1.0");
        QApplication::setOrganizationName("CMPE 202");
        
        std::cout << "Starting SecurePay Payment Processing Application" << std::endl;
        
        // Create and show the main window
        MainWindow mainWindow;
        mainWindow.show();
        
        // Execute the application event loop
        return app.exec();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
        return 1;
    }
}

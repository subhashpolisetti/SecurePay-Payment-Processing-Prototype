#ifndef ADDCUSTOMERDIALOG_H
#define ADDCUSTOMERDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include "../core/customer.h"

class AddCustomerDialog : public QDialog {
    Q_OBJECT
    
public:
    AddCustomerDialog(QWidget* parent = nullptr);
    
    // Get the customer information entered in the dialog
    Customer getCustomer() const;
    
private:
    // Form fields
    QLineEdit* m_nameEdit;
    QLineEdit* m_emailEdit;
    QLineEdit* m_addressEdit;
    
    // Buttons
    QPushButton* m_okButton;
    QPushButton* m_cancelButton;
    
private slots:
    // Validate the form before accepting
    void validateForm();
};

#endif // ADDCUSTOMERDIALOG_H

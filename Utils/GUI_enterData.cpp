#include "GUI_enterData.h"

namespace utils
{
    pair<string, string> enterUsernameAndPassword()
    {
        // Create a QDialog as the input dialog
        QDialog dialog;
        QVBoxLayout layout(&dialog);

        // Create a QLabel for the message
        QLabel label("Enter Username and Password:", &dialog);
        layout.addWidget(&label);

        // Create a QLabel and QLineEdit for the username
        QLabel usernameLabel("Username:", &dialog);
        QLineEdit usernameLineEdit(&dialog);
        layout.addWidget(&usernameLabel);
        layout.addWidget(&usernameLineEdit);

        // Create a QLabel and QLineEdit for the password
        QLabel passwordLabel("Password:", &dialog);
        QLineEdit passwordLineEdit(&dialog);
        passwordLineEdit.setEchoMode(QLineEdit::Password);
        layout.addWidget(&passwordLabel);
        layout.addWidget(&passwordLineEdit);

        // Create a QPushButton for submitting the inputs
        QPushButton submitButton("Submit", &dialog);
        layout.addWidget(&submitButton);

        // Connect the submitButton's clicked signal to accept the dialog
        QObject::connect(&submitButton, &QPushButton::clicked, &dialog, &QDialog::accept);

        // Show the dialog
        dialog.show();

        // Start the event loop of the parent application to allow the dialog to be displayed and interacted with
        QCoreApplication::processEvents();

        // Run the event loop until the dialog is closed
        while (dialog.isVisible())
        {
            QCoreApplication::processEvents();
        }

        // Retrieve the entered username and password
        std::string username = usernameLineEdit.text().toStdString();
        std::string password = passwordLineEdit.text().toStdString();

        return std::make_pair(username, password);
    }

} // utils
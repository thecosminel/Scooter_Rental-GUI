#include "GUI_printFunctions.h"

namespace utils
{

    void printMessageWithQt(const std::string& errorMessage)
    {
        // Convert the error message to QString
        QString errorMessageQString = QString::fromStdString(errorMessage);

        // Create the dialog
        QDialog dialog;
        QVBoxLayout layout(&dialog);

        // Create a QLabel to display the error message
        QLabel errorLabel(errorMessageQString, &dialog);
        layout.addWidget(&errorLabel);

        // Create a QPushButton for closing the dialog
        QPushButton closeButton("Close", &dialog);
        layout.addWidget(&closeButton);

        // Connect the clicked signal of the close button to the dialog's close slot
        QObject::connect(&closeButton, &QPushButton::clicked, &dialog, &QDialog::accept);


        // Start the event loop of the parent application to allow the dialog to be displayed and interacted with
        QCoreApplication::processEvents();
        // Run the event loop until the dialog is closed
        while (dialog.isVisible())
        {
            QCoreApplication::processEvents();
        }

        // Set the dialog's layout
        dialog.resize(400, 300);
        dialog.setLayout(&layout);


        // Show the dialog
        dialog.exec();
    }

} // utils
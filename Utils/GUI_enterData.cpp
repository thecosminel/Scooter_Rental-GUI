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

    string enterLocationGUI()
    {
        QDialog dialog;
        QVBoxLayout layout(&dialog);

        QLabel label("Enter Location:", &dialog);
        layout.addWidget(&label);

        QLineEdit locationLineEdit(&dialog);
        layout.addWidget(&locationLineEdit);

        QPushButton submitButton("Submit", &dialog);
        layout.addWidget(&submitButton);

        QObject::connect(&submitButton, &QPushButton::clicked, &dialog, &QDialog::accept);

        dialog.setLayout(&layout);
        dialog.exec();

        std::string location = locationLineEdit.text().toStdString();

        return location;
    }



    string enterModelGUI()
    {
        QDialog dialog;
        QVBoxLayout layout(&dialog);

        QLabel label("Enter Scooter Model:", &dialog);
        layout.addWidget(&label);

        QLineEdit modelLineEdit(&dialog);
        layout.addWidget(&modelLineEdit);

        QPushButton submitButton("Submit", &dialog);
        layout.addWidget(&submitButton);

        QObject::connect(&submitButton, &QPushButton::clicked, &dialog, &QDialog::accept);

        dialog.setLayout(&layout);
        dialog.exec();

        std::string model = modelLineEdit.text().toStdString();

        return model;
    }

    string enterManufacturingDateGUI()
    {
        while (true) {
            QDialog dialog;
            QVBoxLayout layout(&dialog);

            QLabel label("Enter manufacturing date:", &dialog);
            layout.addWidget(&label);

            QLabel dateLabel("Manufacturing date:", &dialog);
            QLineEdit dateLineEdit(&dialog);
            layout.addWidget(&dateLabel);
            layout.addWidget(&dateLineEdit);

            QPushButton submitButton("Submit", &dialog);
            layout.addWidget(&submitButton);

            QObject::connect(&submitButton, &QPushButton::clicked, &dialog, &QDialog::accept);

            dialog.setLayout(&layout);
            dialog.exec();

            std::string date = dateLineEdit.text().toStdString();

            if (checkDateFormat(date))
            {
                return date;
            } else
            {
                printMessageWithQt("Invalid date formats!!");
            }
        }
    }

    double enterKmGUI()
    {
        QDialog dialog;
        QVBoxLayout layout(&dialog);

        QLabel label("Enter kilometers:", &dialog);
        layout.addWidget(&label);

        QLabel kmLabel("Kilometers:", &dialog);
        QLineEdit kmLineEdit(&dialog);
        layout.addWidget(&kmLabel);
        layout.addWidget(&kmLineEdit);

        QPushButton submitButton("Submit", &dialog);
        layout.addWidget(&submitButton);

        QObject::connect(&submitButton, &QPushButton::clicked, &dialog, &QDialog::accept);

        dialog.setLayout(&layout);
        dialog.exec();

        double kilometers = kmLineEdit.text().toDouble();

        return kilometers;
    }

    scooter::ScooterStatus enterStatusGUI()
    {
        QDialog dialog;
        auto *layout = new QVBoxLayout(&dialog);

        layout->addWidget(new QLabel("Choose scooter status", &dialog));

        auto *button1 = new QPushButton("PARKED", &dialog);
        QObject::connect(button1, &QPushButton::clicked, &dialog, [&dialog]() { dialog.done('1'); });
        layout->addWidget(button1);

        auto *button2 = new QPushButton("RESERVED", &dialog);
        QObject::connect(button2, &QPushButton::clicked, &dialog, [&dialog]() { dialog.done('2'); });
        layout->addWidget(button2);

        auto *button3 = new QPushButton("IN_USE", &dialog);
        QObject::connect(button3, &QPushButton::clicked, &dialog, [&dialog]() { dialog.done('3'); });
        layout->addWidget(button3);

        auto *button4 = new QPushButton("MAINTENANCE", &dialog);
        QObject::connect(button4, &QPushButton::clicked, &dialog, [&dialog]() { dialog.done('4'); });
        layout->addWidget(button4);

        auto *button5 = new QPushButton("OUT_OF_SERVICE", &dialog);
        QObject::connect(button5, &QPushButton::clicked, &dialog, [&dialog]() { dialog.done('5'); });
        layout->addWidget(button5);

        auto *button6 = new QPushButton("UNKNOWN", &dialog);
        QObject::connect(button6, &QPushButton::clicked, &dialog, [&dialog]() { dialog.done('6'); });
        layout->addWidget(button6);


        dialog.setLayout(layout);

        dialog.exec();


        // return chosen status
        char choice = static_cast<QChar>(dialog.result()).toLatin1();
        switch (choice)
        {
            case '1':
                return scooter::PARKED;
            case '2':
                return scooter::RESERVED;
            case '3':
                return scooter::IN_USE;
            case '4':
                return scooter::MAINTENANCE;
            case '5':
                return scooter::OUT_OF_SERVICE;
            default:
                return scooter::UNKNOWN;
        }
    }

    pair<string, string> enterManufacturingDatesGUI()
    {
        while (true)
        {
            QDialog dialog;
            QVBoxLayout layout(&dialog);

            QLabel label("Enter minimum and maximum manufacturing mates: ", &dialog);
            layout.addWidget(&label);

            QLabel minDateLabel("Minimum manufacturing mate:", &dialog);
            QLineEdit minDateLineEdit(&dialog);
            layout.addWidget(&minDateLabel);
            layout.addWidget(&minDateLineEdit);

            QLabel maxDateLabel("Maximum manufacturing mate:", &dialog);
            QLineEdit maxDateLineEdit(&dialog);
            layout.addWidget(&maxDateLabel);
            layout.addWidget(&maxDateLineEdit);

            QPushButton submitButton("Submit", &dialog);
            layout.addWidget(&submitButton);

            QObject::connect(&submitButton, &QPushButton::clicked, &dialog, &QDialog::accept);

            dialog.setLayout(&layout);
            dialog.exec();

            std::string minDate = minDateLineEdit.text().toStdString();
            std::string maxDate = maxDateLineEdit.text().toStdString();

            if (checkDateFormat(minDate) && checkDateFormat(maxDate))
            {
                return std::make_pair(minDate, maxDate);
            }
            else
            {
                printMessageWithQt("Invalid date formats!!");
            }
        }
    }


    pair<double, double> enterKmMultipleGUI()
    {
        QDialog dialog;
        QVBoxLayout layout(&dialog);

        QLabel label("Enter minimum and maximum Kilometers:", &dialog);
        layout.addWidget(&label);

        QLabel minKmLabel("Minimum Kilometers:", &dialog);
        QLineEdit minKmLineEdit(&dialog);
        layout.addWidget(&minKmLabel);
        layout.addWidget(&minKmLineEdit);

        QLabel maxKmLabel("Maximum Kilometers:", &dialog);
        QLineEdit maxKmLineEdit(&dialog);
        layout.addWidget(&maxKmLabel);
        layout.addWidget(&maxKmLineEdit);

        QPushButton submitButton("Submit", &dialog);
        layout.addWidget(&submitButton);

        QObject::connect(&submitButton, &QPushButton::clicked, &dialog, &QDialog::accept);

        dialog.setLayout(&layout);
        dialog.exec();

        double minKm = minKmLineEdit.text().toDouble();
        double maxKm = maxKmLineEdit.text().toDouble();

        return std::make_pair(minKm, maxKm);
    }

    string enterIdentifierGUI()
    {
        QDialog dialog;
        QVBoxLayout layout(&dialog);

        QLabel label("Enter Scooter Identifier:", &dialog);
        layout.addWidget(&label);

        QLineEdit identifierLineEdit(&dialog);
        layout.addWidget(&identifierLineEdit);

        QPushButton submitButton("Submit", &dialog);
        layout.addWidget(&submitButton);

        QObject::connect(&submitButton, &QPushButton::clicked, &dialog, &QDialog::accept);

        dialog.setLayout(&layout);
        dialog.exec();

        std::string identifier = identifierLineEdit.text().toStdString();

        return identifier;
    }


    // Modify function
    char whatScooterAttributesToModifyGUI()
    {
        QDialog dialog;
        auto *layout = new QVBoxLayout(&dialog);

        layout->addWidget(new QLabel("Choose what to modify", &dialog));

        auto *button1 = new QPushButton("1. Model", &dialog);
        QObject::connect(button1, &QPushButton::clicked, &dialog, [&dialog]() { dialog.done('1'); });
        layout->addWidget(button1);

        auto *button2 = new QPushButton("2. Manufacturing date", &dialog);
        QObject::connect(button2, &QPushButton::clicked, &dialog, [&dialog]() { dialog.done('2'); });
        layout->addWidget(button2);

        auto *button3 = new QPushButton("3. Km", &dialog);
        QObject::connect(button3, &QPushButton::clicked, &dialog, [&dialog]() { dialog.done('3'); });
        layout->addWidget(button3);

        auto *button4 = new QPushButton("4. Location", &dialog);
        QObject::connect(button4, &QPushButton::clicked, &dialog, [&dialog]() { dialog.done('4'); });
        layout->addWidget(button4);

        auto *button5 = new QPushButton("5. Status", &dialog);
        QObject::connect(button5, &QPushButton::clicked, &dialog, [&dialog]() { dialog.done('5'); });
        layout->addWidget(button5);

        auto *buttonX = new QPushButton("x. That's all", &dialog);
        QObject::connect(buttonX, &QPushButton::clicked, &dialog, [&dialog]() { dialog.done('x'); });
        layout->addWidget(buttonX);


        dialog.setLayout(layout);

        dialog.exec();

        return static_cast<QChar>(dialog.result()).toLatin1();
    }

} // utils
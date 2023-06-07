#include "MainGUI.h"

namespace gui
{
    MainGUI::MainGUI(QWidget *parent)
    {
        tableWidget_ = new QTableWidget(this);
//        Scooter scooter1("abc", "Cube", "30.10.2010", 300, "Bosanci", scooter::PARKED);
//        Scooter scooter2("xyz", "MTB", "12.11.2022", 300, "Ipotesti", scooter::MAINTENANCE);
//        scooters.push_back(scooter1);
//        scooters.push_back(scooter2);
        setUpTable();
    }

    MainGUI::~MainGUI()
    {
        delete tableWidget_;
    }

    void MainGUI::runGui()
    {
        // Used to return to main GUI
        bool restartMainGui;
        do
        {
            selectUserType();
            if (me == Manager)
            {
                restartMainGui = runManager();
            }
            else
            {
                restartMainGui = runUser();
            }

            setGeometry(200, 200, 1000, 600);
            callVectorSort(Operations::SortedId);
            show();
        } while (restartMainGui);
    }

    bool MainGUI::runManager()
    {
        cout << "Manager" << endl;
        logInAsManager();
        return false;
    }

    bool MainGUI::runUser()
    {
        cout << "User" << endl;
        logInAsUser();
        return false;
    }

    void MainGUI::selectUserType()
    {
        QWidget window;
        QVBoxLayout layout(&window);

        // Create a QLabel for the message
        QLabel label("What are you?", &window);
        layout.addWidget(&label);

        // Create two radio buttons representing the options
        QRadioButton radioOption1("Manager", &window);
        QRadioButton radioOption2("User", &window);

        // Create a button group and add the radio buttons to it
        QButtonGroup buttonGroup(&window);
        buttonGroup.addButton(&radioOption1);
        buttonGroup.addButton(&radioOption2);

        // Add the radio buttons to the layout
        layout.addWidget(&radioOption1);
        layout.addWidget(&radioOption2);

        // Connect the button group's buttonClicked signal to a slot
        bool isFirstButtonPressed = false;
        QObject::connect(&buttonGroup, QOverload<QAbstractButton*>::of(&QButtonGroup::buttonClicked), [&](QAbstractButton* button) {
            isFirstButtonPressed = (button == &radioOption1);
            QCoreApplication::exit();
        });

        // Show the main window
        window.show();

        // Create an event loop to wait for user input
        QEventLoop eventLoop;

        // Connect the buttonClicked signal to the QEventLoop's quit slot
        QObject::connect(&buttonGroup, QOverload<QAbstractButton*>::of(&QButtonGroup::buttonClicked), &eventLoop, &QEventLoop::quit);

        // Enter the event loop
        eventLoop.exec();

        // Return the result
        if (isFirstButtonPressed)
            me = Manager;
        else
            me = User;
    }

    void MainGUI::logInAsManager()
    {
        pair<string, string> userAndPass;
        userAndPass = enterUsernameAndPassword();
        cout << "User: " << userAndPass.first << endl;
        cout << "Pass: " << userAndPass.second << endl;
    }

    void MainGUI::logInAsUser()
    {
        pair<string, string> userAndPass;
        userAndPass = enterUsernameAndPassword();
        cout << "User: " << userAndPass.first << endl;
        cout << "Pass: " << userAndPass.second << endl;
    }

    pair<string, string> MainGUI::enterUsernameAndPassword()
    {
        QWidget window;
        QVBoxLayout layout(&window);

        // Create a QLabel for the message
        QLabel label("Enter Username and Password:", &window);
        layout.addWidget(&label);

        // Create a QLabel and QLineEdit for the username
        QLabel usernameLabel("Username:", &window);
        QLineEdit usernameLineEdit(&window);
        layout.addWidget(&usernameLabel);
        layout.addWidget(&usernameLineEdit);

        // Create a QLabel and QLineEdit for the password
        QLabel passwordLabel("Password:", &window);
        QLineEdit passwordLineEdit(&window);
        passwordLineEdit.setEchoMode(QLineEdit::Password);
        layout.addWidget(&passwordLabel);
        layout.addWidget(&passwordLineEdit);

        // Create a QPushButton for submitting the inputs
        QPushButton submitButton("Submit", &window);
        layout.addWidget(&submitButton);

        // Create a QEventLoop to block the execution until the submit button is clicked
        QEventLoop eventLoop;

        // Connect the submitButton's clicked signal to the eventLoop's quit slot
        QObject::connect(&submitButton, &QPushButton::clicked, &eventLoop, &QEventLoop::quit);

        // Show the main window
        window.show();

        // Start the event loop
        eventLoop.exec();

        // Retrieve the entered username and password
        std::string username = usernameLineEdit.text().toStdString();
        std::string password = passwordLineEdit.text().toStdString();

        return std::make_pair(username, password);
    }


    // Qt stuff
    void MainGUI::setUpTable()
    {
        auto *layout = new QVBoxLayout(this);

        tableWidget_->setColumnCount(6);
        tableWidget_->setHorizontalHeaderLabels(
                {"Identifier", "Model", "Commissioned Date", "Km", "Location", "Status"});
        tableWidget_->horizontalHeader()->setStretchLastSection(true);
        tableWidget_->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
        tableWidget_->verticalHeader()->setVisible(false);
        tableWidget_->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget_->setStyleSheet("QTableView { border: none; background-color: #ffffff; }"
                                    "QTableView::item { padding: 10px; }"
                                    "QHeaderView::section { background-color: #f0f0f0; }");

        //Connect stuff
        connect(tableWidget_, &QTableWidget::cellClicked, this, &MainGUI::handleCellClicked);
        // End connect

        layout->addWidget(tableWidget_);
        setLayout(layout);
        setStyleSheet("QWidget { background-color: #f5f5f5; }");
    }

    void MainGUI::populateTable(const vector<Scooter>& scootersVec)
    {
//        delete tableWidget_;
//        tableWidget_ = new QTableWidget(this);
//        setUpTable();
        // Clear old table
        tableWidget_->clear();


        int rowSize = static_cast<int>(scootersVec.size());
        tableWidget_->setRowCount(rowSize);
        for (int i = 0; i < rowSize; ++i)
        {
            const Scooter& scooter = scootersVec[i];
            auto* id = new QTableWidgetItem(QString::fromStdString(scooter.getIdentifier()));
            auto* model = new QTableWidgetItem(QString::fromStdString(scooter.getModel()));
            auto* date = new QTableWidgetItem(QString::fromStdString(scooter.getDate()));
            auto* km = new QTableWidgetItem(QString::fromStdString(doubleToString(scooter.getKilometers())));
            auto* location = new QTableWidgetItem(QString::fromStdString(scooter.getLocation()));
            auto* status = new QTableWidgetItem(QString::fromStdString(getScooterStatusString(scooter.getStatus())));

            tableWidget_->setItem(i, 0, id);
            tableWidget_->setItem(i, 1,  model);
            tableWidget_->setItem(i, 2, date);
            tableWidget_->setItem(i, 3, km);
            tableWidget_->setItem(i, 4, location);
            tableWidget_->setItem(i, 5, status);
        }

        // Resize to fit
        tableWidget_->resizeColumnsToContents();
    }

    void MainGUI::handleCellClicked(int row, int column)
    {
        // Sort the table based on the clicked column
//        tableWidget_->sortByColumn(column, Qt::AscendingOrder);
        switch (column) 
        {
            case 0:
                ui::ConcreteUI::callVectorSort(Operations::SortedId);
                break;
            case 1:
                ui::ConcreteUI::callVectorSort(Operations::SortedModel);
                break;
            case 2:
                ui::ConcreteUI::callVectorSort(Operations::SortedDate);
                break;
            case 3:
                ui::ConcreteUI::callVectorSort(Operations::SortedKm);
                break;
            case 4:
                ui::ConcreteUI::callVectorSort(Operations::SortedLocation);
                break;
            case 5:
                ui::ConcreteUI::callVectorSort(Operations::SortedStatus);
                break;
            default:
                break;
        }
    }


    // Implement from abstract
    void MainGUI::printScooterContainer(vector<Scooter> scootersVec)
    {
        populateTable(scootersVec);
    }

    void MainGUI::printMessage(std::string message)
    {
        cout << "To be implemented";
    }



}
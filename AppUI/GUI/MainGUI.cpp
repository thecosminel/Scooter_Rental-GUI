#include <QMessageBox>
#include <QTextEdit>
#include <QTextBrowser>
#include "MainGUI.h"

namespace gui
{
    MainGUI::MainGUI(QWidget *parent)
    {
        tableWidget_ = new QTableWidget(this);
        me = User;
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

//            setGeometry(200, 200, 1000, 600);
//            callVectorSort(Operations::SortedId);
            show();
        } while (restartMainGui);
    }

    bool MainGUI::runManager()
    {
        cout << "Manager" << endl;
        logInAsManager();
        if (user.empty())
        {
            return true;
        }

        char choice;
        do
        {
            choice = managerMenu();
            switch (choice) {
                case 'A':
                case 'a':
                    cout << "Add new scooter: ";
                    addNewScooter();
                    break;
                case 'D':
                case 'd':
                    cout << "Delete existing scooter: ";
                    deleteExistingScooter();
                    break;
                case 'M':
                case 'm':
                    cout << "Modify existing scooter: ";
                    modifyExistingScooter();
                    break;
                    // All scooters sort methods
                case '1':
                    cout << "Display all scooters sorted ascending by ID: ";
                    displayAllScootersSortedByID();
                    break;
                case '2':
                    cout << "Display all scooters sorted ascending by model: ";
                    displayAllScootersSortedByModel();
                    break;
                case '3':
                    cout << "Display all scooters sorted ascending by age: ";
                    displayAllScootersSortedByAge();
                    break;
                case '4':
                    cout << "Display all scooters sorted ascending by km: ";
                    displayAllScootersSortedByKm();
                    break;
                case '5':
                    cout << "Display all scooters sorted ascending by location: ";
                    displayAllScootersSortedByLocation();
                    break;
                case '6':
                    cout << "Display all scooters sorted ascending by status: ";
                    displayAllScootersSortedByStatus();
                    break;
                    // Search methods
                case 's':
                case 'S':
                    cout << "Show detailed scooter:";
                    showDetailed();
                case 'L':
                case 'l':
                    cout << "Search scooter by location: ";
                    searchScooterByLocation();
                    break;
                case '7':
                    cout << "Display scooters with km between:  ";
                    displayScootersFilteredByKm();
                    break;
                case '8':
                    cout << "Display scooters with manufacturing date between:  ";
                    displayScootersFilteredByDates();
                    break;

                case '9':
                    cout << "Display all parked scooters: ";
                    displayAllParkedScooters();
                    break;
                case 'B':
                case 'b':
                    cout << "+++ Closing app +++ ";
                    return true;
                case 'X':
                case 'x':
                    cout << "+++ Closing app +++ ";
                    return false;
                default:
                    cout << "Not an option...";
                    break;
            }
        } while (true);

        return false;
    }

    char MainGUI::managerMenu() //NOLINT
    {
        QDialog dialog;
        auto *layout = new QVBoxLayout(&dialog);

        layout->addWidget(new QLabel("Choose option:", &dialog));
        layout->addWidget(new QLabel("CUD methods:", &dialog));

        auto *buttonA = new QPushButton("A. Add new scooter", &dialog);
        QObject::connect(buttonA, &QPushButton::clicked, &dialog, [&dialog]() { dialog.done('A'); });
        layout->addWidget(buttonA);

        auto *buttonD = new QPushButton("D. Delete existing scooter", &dialog);
        QObject::connect(buttonD, &QPushButton::clicked, &dialog, [&dialog]() { dialog.done('D'); });
        layout->addWidget(buttonD);

        auto *buttonM = new QPushButton("M. Modify existing scooter", &dialog);
        QObject::connect(buttonM, &QPushButton::clicked, &dialog, [&dialog]() { dialog.done('M'); });
        layout->addWidget(buttonM);

        // Add more buttons for other options...

        layout->addWidget(new QLabel("All scooters sort methods:", &dialog));

        auto *button1 = new QPushButton("1. Display all scooters sorted ascending by ID", &dialog);
        QObject::connect(button1, &QPushButton::clicked, &dialog, [&dialog]() { dialog.done('1'); });
        layout->addWidget(button1);

        auto *button2 = new QPushButton("2. Display all scooters sorted ascending by model", &dialog);
        QObject::connect(button2, &QPushButton::clicked, &dialog, [&dialog]() { dialog.done('2'); });
        layout->addWidget(button2);

        auto *button3 = new QPushButton("3. Display all scooters sorted ascending by manufacturing date", &dialog);
        QObject::connect(button3, &QPushButton::clicked, &dialog, [&dialog]() { dialog.done('3'); });
        layout->addWidget(button3);

        auto *button4 = new QPushButton("4. Display all scooters sorted ascending by Km", &dialog);
        QObject::connect(button4, &QPushButton::clicked, &dialog, [&dialog]() { dialog.done('4'); });
        layout->addWidget(button4);

        auto *button5 = new QPushButton("5. Display all scooters sorted ascending by location", &dialog);
        QObject::connect(button5, &QPushButton::clicked, &dialog, [&dialog]() { dialog.done('5'); });
        layout->addWidget(button5);

        auto *button6 = new QPushButton("6. Display all scooters sorted ascending by status", &dialog);
        QObject::connect(button6, &QPushButton::clicked, &dialog, [&dialog]() { dialog.done('6'); });
        layout->addWidget(button6);


        // Add more buttons for the remaining sort methods...

        layout->addWidget(new QLabel("Search methods:", &dialog));

        auto *buttonS = new QPushButton("S. Show detailed scooter", &dialog);
        QObject::connect(buttonS, &QPushButton::clicked, &dialog, [&dialog]() { dialog.done('S'); });
        layout->addWidget(buttonS);

        auto *buttonL = new QPushButton("L. Search scooter by location", &dialog);
        QObject::connect(buttonL, &QPushButton::clicked, &dialog, [&dialog]() { dialog.done('L'); });
        layout->addWidget(buttonL);

        auto *button7 = new QPushButton("7. Display scooters with km between two values", &dialog);
        QObject::connect(button7, &QPushButton::clicked, &dialog, [&dialog]() { dialog.done('7'); });
        layout->addWidget(button7);

        auto *button8 = new QPushButton("8. Display scooters manufactured between two dates", &dialog);
        QObject::connect(button8, &QPushButton::clicked, &dialog, [&dialog]() { dialog.done('8'); });
        layout->addWidget(button8);

        auto *button9 = new QPushButton("9. Display all parked scooters", &dialog);
        QObject::connect(button9, &QPushButton::clicked, &dialog, [&dialog]() { dialog.done('9'); });
        layout->addWidget(button9);

        auto *buttonB = new QPushButton("B. Return to main ui", &dialog);
        QObject::connect(buttonB, &QPushButton::clicked, &dialog, [&dialog]() { dialog.done('B'); });
        layout->addWidget(buttonB);

        auto *buttonX = new QPushButton("X. Close app", &dialog);
        QObject::connect(buttonX, &QPushButton::clicked, &dialog, [&dialog]() { dialog.done('X'); });
        layout->addWidget(buttonX);

        // Add more buttons for the remaining search methods...

        dialog.setLayout(layout);

        dialog.exec();
        return static_cast<QChar>(dialog.result()).toLatin1();
    }


    // User stuff

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

        // Connect the button group's buttonClicked signal to a lambda slot
        bool isFirstButtonPressed = false;
        QObject::connect(&buttonGroup, QOverload<QAbstractButton*>::of(&QButtonGroup::buttonClicked), [&](QAbstractButton* button) {
            isFirstButtonPressed = (button == &radioOption1);
            window.close();
        });

        // Show the main window
        window.show();

        // Run the event loop of the parent application to allow the window to be displayed and interacted with
        QCoreApplication::processEvents();

        // Run the event loop until the window is closed
        while (window.isVisible())
        {
            QCoreApplication::processEvents();
        }

        // Return the result
        if (isFirstButtonPressed)
            me = Manager;
        else
            me = User;
    }

    void MainGUI::logInAsManager()
    {
        pair<string, string> userAndPass;
        bool retry = true;
        while (retry)
        {
            user = "";
            password = "";
            cout << "You have to log in..." << endl;
            try {
                userAndPass = enterUsernameAndPassword();
                if(userAndPass.first.empty())
                {
                    return;
                }
                user = userAndPass.first;
                password = userAndPass.second;
                ConcreteUI::tryToLogAsManager(user, password);
                retry = false;
            }
            catch (const std::invalid_argument& e)
            {
                printMessageWithQt(e.what());
                retry = true;
            }
        }
    }

    void MainGUI::logInAsUser()
    {
        pair<string, string> userAndPass;
        userAndPass = enterUsernameAndPassword();
        user = userAndPass.first;
        password = userAndPass.second;
//        bool retry = true;
//        while (retry)
//        {
//            cout << "You have to log in..." << endl;
//            try {
//                ConcreteUI::tryToLogAsManager(user, password);
//                retry = false;
//            }
//            catch (const std::invalid_argument& e)
//            {
//                cout << "Exception: " << e.what() << endl;
//                retry = true;
//            }
//        }
//        cout << "User: " << userAndPass.first << endl;
//        cout << "Pass: " << userAndPass.second << endl;
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
        printMessageWithQt(message);
    }




}
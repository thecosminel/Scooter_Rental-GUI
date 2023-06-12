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

        } while (restartMainGui);
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


    // Manager Stuff
    bool MainGUI::runManager()
    {
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
                    addNewScooter();
                    break;
                case 'D':
                case 'd':
                    deleteExistingScooter();
                    break;
                case 'M':
                case 'm':
                    modifyExistingScooter();
                    break;
                    // All scooters sort methods
                case '1':
                    displayAllScootersSortedByID();
                    break;
                case '2':
                    displayAllScootersSortedByModel();
                    break;
                case '3':
                    displayAllScootersSortedByAge();
                    break;
                case '4':
                    displayAllScootersSortedByKm();
                    break;
                case '5':
                    displayAllScootersSortedByLocation();
                    break;
                case '6':
                    displayAllScootersSortedByStatus();
                    break;
                    // Search methods
                case 's':
                case 'S':
                    showDetailed();
                    break;
                case 'L':
                case 'l':
                    searchScooterByLocation();
                    break;
                case '7':
                    displayScootersFilteredByKm();
                    break;
                case '8':
                    displayScootersFilteredByDates();
                    break;
                case '9':
                    displayAllParkedScooters();
                    break;

                 // Exit methods
                case 'B':
                case 'b':
                    updateMessage("+++ Closing app +++ ");
                    return true;
                case 'X':
                case 'x':
                    updateMessage("+++ Closing app +++ ");
                    return false;
                default:
                    updateMessage("Close the app using button: ~X. Close app~ ");
                    break;
            }
        } while (true);
    }


    // User stuff

    bool MainGUI::runUser()
    {
        logInAsUser();
        if (user.empty())
        {
            return true;
        }

        char choice;
        do
        {
            choice = userMenu();
            switch (choice) {
                    // All scooters sort methods
                case '1':
                    displayAllScootersSortedByID();
                    break;
                case '2':
                    displayAllScootersSortedByModel();
                    break;
                case '3':
                    displayAllScootersSortedByAge();
                    break;
                case '4':
                    displayAllScootersSortedByKm();
                    break;
                case '5':
                    displayAllScootersSortedByLocation();
                    break;
                case '6':
                    displayAllScootersSortedByStatus();
                    break;
                    // Search methods
                case '7':
                    displayScootersFilteredByKm();
                    break;
                case '8':
                    displayScootersFilteredByDates();
                    break;
                case '9':
                    displayAllParkedScooters();
                    break;
                case 'L':
                case 'l':
                    searchScooterByLocation();
                    break;
                case 's':
                case 'S':
                    showDetailed();
                    break;

                    // Personal scooters - user methods
                case 'M':
                case 'm':
                    displayMyScooters();
                    break;
                case 'R':
                case 'r':
                    reserveScooter();
                    break;
                case 'U':
                case 'u':
                    useScooter();
                    break;
                case 'p':
                case 'P':
                    parkScooter();
                    break;

                    // Exit methods
                case 'B':
                case 'b':
                    updateMessage("+++ Closing app +++ ");
                    return true;
                case 'X':
                case 'x':
                    updateMessage("+++ Closing app +++ ");
                    return false;
                default:
                    updateMessage("Close the app using button: ~X. Close app~ ");
                    break;
            }
        } while (true);
    }



    void MainGUI::logInAsManager()
    {
        pair<string, string> userAndPass;
        bool retry = true;
        while (retry)
        {
            user = "";
            password = "";
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
        bool retry = true;
        while (retry)
        {
            user = "";
            password = "";
            try {
                userAndPass = enterUsernameAndPassword();
                if(userAndPass.first.empty())
                {
                    return;
                }
                user = userAndPass.first;
                password = userAndPass.second;
                ConcreteUI::tryToLogAsUser(user, password);
                return;
            }
            catch (const std::invalid_argument& e)
            {
                printMessageWithQt(e.what());
                // Chose if try again or create new account
                retry = tryLogAgain();

            }
        }
        // Chose to create new account
        // Log in should work 100%
        pair<string, string> userPass = enterUsernameAndPassword();
        this->user = userPass.first;
        this->password = userPass.second;
        ConcreteUI::createUserAccount(user, password);
        try {
            ConcreteUI::tryToLogAsUser(user, password);
        }
        catch (const std::invalid_argument& e)
        {
            updateMessage("Create new account didn't work :( --- really don't know why");
        }
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
        tableWidget_->setColumnCount(6);
        tableWidget_->setHorizontalHeaderLabels(
                {"Identifier", "Model", "Commissioned Date", "Km", "Location", "Status"});


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
    void MainGUI::updateScooterContainer(vector<Scooter> scootersVec)
    {

        populateTable(scootersVec);
        setGeometry(200, 200, 1000, 600);
        show();
    }

    void MainGUI::updateMessage(std::string message)
    {
        printMessageWithQt(message);
    }


    // ------------------------
    // Manager & User methods
    // Sort all
    void MainGUI::displayAllScootersSortedByID()
    {
        ConcreteUI::callVectorSort(controller::SortedId);
    }

    void MainGUI::displayAllScootersSortedByModel()
    {
        ConcreteUI::callVectorSort(controller::SortedModel);
    }

    void MainGUI::displayAllScootersSortedByAge()
    {
        ConcreteUI::callVectorSort(controller::SortedDate);
    }

    void MainGUI::displayAllScootersSortedByKm()
    {
        ConcreteUI::callVectorSort(controller::SortedKm);
    }

    void MainGUI::displayAllScootersSortedByLocation()
    {
        ConcreteUI::callVectorSort(controller::SortedLocation);
    }

    void MainGUI::displayAllScootersSortedByStatus()
    {
        ConcreteUI::callVectorSort(controller::SortedStatus);
    }

    void MainGUI::displayAllParkedScooters()
    {
        ConcreteUI::callVectorSort(controller::FilteredParked);
    }

    void MainGUI::searchScooterByLocation()
    {
        string location = enterLocationGUI();
        ConcreteUI::callFilterLocation(controller::FilteredLocation, location);
    }

    void MainGUI::displayScootersFilteredByDates()
    {
        pair<string, string> dates = enterManufacturingDatesGUI();
        ConcreteUI::callFilterDates(controller::FilteredDates, dates);
    }

    void MainGUI::displayScootersFilteredByKm()
    {
        pair<double, double> km = enterKmMultipleGUI();
        ConcreteUI::callFilterKm(controller::FilterKm, km);
    }




    // -------------------------
    // Manager UI only

    void MainGUI::addNewScooter()
    {
        updateMessage("You have selected to add a new scooter to repo: ");
        string identifier = "NIL";
        string model = enterModelGUI();
        string manufacturingDate = enterManufacturingDateGUI();
        double km = enterKmGUI();
        string location = enterLocationGUI();
        ScooterStatus status = enterStatusGUI();
        Scooter newScooter(identifier, model, manufacturingDate, km, location, status);
        ConcreteUI::callCUD(controller::ADD,newScooter);
    }

    void MainGUI::deleteExistingScooter()
    {
        updateMessage("You have selected to delete a scooter from repo: ");
        string identifier = enterIdentifierGUI();
        Scooter removedScooter(identifier, "", "10.10.2010", 1, "", scooter::UNKNOWN);
        ConcreteUI::callCUD(controller::REMOVE, removedScooter);
    }

    void MainGUI::modifyExistingScooter()
    {
        updateMessage("You have selected to modify a scooter from repo: ");
        string identifier = enterIdentifierGUI();
        try {
            ConcreteUI::getCurrentScooter(identifier);
        }
        catch (const std::logic_error& exception)
        {
            updateMessage("No scooter with given id found!");
            return;
        }

        // Chose what to edit and do it
        vector<Scooter> scooterInVector;
        Scooter updatedScooter = currentScooter;
        char choice;
        bool done = false;
        do
        {
            scooterInVector.clear();
            scooterInVector.push_back(updatedScooter);
            updateScooterContainer(scooterInVector);
            choice = whatScooterAttributesToModifyGUI();
            switch (choice)
            {
                case '1':
                {
                    string model = enterModelGUI();
                    updatedScooter.setModel(model);
                    break;
                }

                case '2':
                {
                    string date = enterManufacturingDateGUI();
                    updatedScooter.setDate(date);
                    break;
                }

                case '3':
                {
                    double km = enterKmGUI();
                    updatedScooter.setKilometers(km);
                    break;
                }

                case '4':
                {
                    string location = enterLocationGUI();
                    updatedScooter.setLocation(location);
                    break;
                }
                case '5':
                {
                    ScooterStatus status = enterStatusGUI();
                    updatedScooter.setStatus(status);
                    break;
                }
                case 'x':
                case 'X':
                    done = true;
                    break;
                default:
                    updateMessage("Not an option!");
            }
        } while (!done);
        ConcreteUI::callCUD(controller::UPDATE, updatedScooter);
    }

    void MainGUI::showDetailed()
    {
        string id = enterIdentifierGUI();
        try {
            ConcreteUI::requestScooter(id);
        }
        catch (const std::logic_error& exception)
        {
            updateMessage("Scooter with given id not found!");
            return;
        }
        vector<Scooter> detailedScooter;
        detailedScooter.push_back(currentScooter);
        updateScooterContainer(detailedScooter);
    }

    // -------------------------
    // User UI only

    void MainGUI::reserveScooter()
    {
        string identifier = enterIdentifierGUI();
        // Check if identifier exists
        try {
            ConcreteUI::getCurrentScooter(identifier);
        }
        catch (const std::logic_error& exception)
        {
            updateMessage(exception.what());
            return;
        }
        // Check if not reserved
        Scooter scooter = currentScooter;
        try {
            ConcreteUI::callRUP(controller::RESERVE, scooter, user);
        }
        catch (const std::logic_error& exception)
        {
            updateMessage(exception.what());
            return;
        }
    }

    void MainGUI::parkScooter()
    {
        string identifier = enterIdentifierGUI();
        try {
            ConcreteUI::getCurrentScooter(identifier);
        }
        catch (const std::logic_error& exception)
        {
            updateMessage(exception.what());
            return;
        }
        Scooter scooter = currentScooter;
        try {
            ConcreteUI::callRUP(controller::PARK, scooter, user);
        }
        catch (const std::logic_error& exception)
        {
            updateMessage(exception.what());
            return;
        }
    }

    void MainGUI::useScooter()
    {
        string identifier = enterIdentifierGUI();
        try {
            ConcreteUI::getCurrentScooter(identifier);
        }
        catch (const std::logic_error& exception)
        {
            updateMessage(exception.what());
            return;
        }
        Scooter scooter = currentScooter;
        try {
            ConcreteUI::callRUP(controller::USE, scooter, user);
        }
        catch (const std::logic_error& exception)
        {
            updateMessage(exception.what());
            return;
        }
    }

    void MainGUI::displayMyScooters()
    {
        ConcreteUI::callVectorAllScootersOfUser(this->user);
    }

}
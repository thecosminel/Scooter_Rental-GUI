#include "AppRepository/CsvFileRepository.h"
#include "AppController/ConcreteController.h"
#include "AppUI/UI/MainUI.h"
// Tests
//#include "AppController/ctrl_tests.h"
//#include "AppRepository/repo_tests.h"

// Qt
#include "AppUI/GUI/MainGUI.h"
#include <QApplication>
#include <QFileDialog>
#include <QCheckBox>
#include <QLabel>
#include <QRadioButton>
#include <QButtonGroup>

using controller::AbstractController, controller::ConcreteController;
using repository::CsvFileRepository, repository::InMemoryRepository;
using ui::MainUI;
using namespace gui;
using std::make_shared;

string chooseCsvFile()
{
//    vector <string> files = {
//            "../Database/data.csv",
//            "../Database/scooters1.csv",
//            "../Database/scooters2.csv"
//    };
    vector <string> files = {
            "Database/data.csv",
            "Database/scooters1.csv",
            "Database/scooters2.csv"
    };
    cout << "Available CSV files: " << endl;
    for (int i = 1; i <= files.size(); ++i)
    {
        cout << i << " -> " << files[i-1] << endl;
    }
    while (true)
    {
        int filesSize = static_cast<int>(files.size());
        cout << "File wanted: (choose number)" << endl;
        int index;
        cin >> index;
        if (index >= 1 && index <= filesSize)
        {
            return files[index-1];
        }
        cout << "Out of range index!!" << endl;
    }
}

bool choseRepository()
{
    cout << "Do you want to save the data persistent?" << endl;
    cout << "  1. Yes" << endl;
    cout << "  2. No" << endl;
    while(true)
    {
        char choice;
        cout << "My choice: " << endl;
        cin >> choice;
        if (choice == '1')
            return true;
        else if (choice == '2')
            return false;
        cout << "Not an option..." << endl;
    }
}

string selectCSV()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr, "Open CSV File", QString(), "CSV Files (*.csv)");
    // Convert QString to std::string
    string str = fileName.toStdString();
    if (fileName.isEmpty())
    {
        throw std::invalid_argument("No file selected");
    }
    return str;
}

bool selectIfSavePersistent()
{
    QWidget window;
    QVBoxLayout layout(&window);

    // Create a QLabel for the message
    QLabel label("Do you want to persistently save the data?", &window);
    layout.addWidget(&label);

    // Create two radio buttons representing the options
    QRadioButton radioOption1("Yes", &window);
    QRadioButton radioOption2("No", &window);

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
    return isFirstButtonPressed;
}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    // Select file
    string fileName;
    try {
        fileName = selectCSV();
    }
    catch (const std::invalid_argument &e)
    {
        cout << "Error: " << e.what();
        return 0;
    }

    // Select if data is to be saved persistent
    shared_ptr<InMemoryRepository> repo;
    if (selectIfSavePersistent())
    {
        repo = make_shared<CsvFileRepository>(fileName);
    }
    else
    {
        repo = make_shared<InMemoryRepository>(fileName);
    }

    // Create GUI
    auto gui = make_shared<MainGUI>();

    // Create Ctrl
    auto ctrl = make_shared<ConcreteController>(repo, gui);


    // ISubject & IObserver attach
    repo->attach(ctrl);
    gui->attach(ctrl);

    // Qt
    gui->runGui();
    QApplication::exec();


    // ISubject & IObserver detach
    gui->detach(ctrl);
    repo->detach(ctrl);
    return 0;


//     Test ctrl and repo
//    test_ctrl();
//    test_repo();

//    string chosenFile = chooseCsvFile();
//
//    // Create layers
//    shared_ptr<InMemoryRepository> repo;
//    if (choseRepository())
//    {
//        repo = make_shared<CsvFileRepository>(chosenFile);
//    }
//    else
//    {
//        repo = make_shared<InMemoryRepository>(chosenFile);
//    }
//    auto ui = make_shared<MainUI>();
//    auto ctrl = make_shared<ConcreteController>(repo, ui);
//
//    // ISubject & IObserver attach
//    repo->attach(ctrl);
//    ui->attach(ctrl);
//
//    // Run programm
//    ui->run();
//
//    // ISubject & IObserver detach
//    ui->detach(ctrl);
//    repo->detach(ctrl);

    return 0;
}
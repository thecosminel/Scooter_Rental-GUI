#include "AppRepository/CsvFileRepository.h"
#include "AppController/ConcreteController.h"
#include "AppUI/UI/MainUI.h"
// Tests
//#include "AppController/ctrl_tests.h"
//#include "AppRepository/repo_tests.h"

// Qt
#include "AppUI/GUI/MainGUI.h"
#include <QApplication>

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


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    shared_ptr<InMemoryRepository> repo = make_shared<InMemoryRepository>("Database/data.csv");
    auto gui = make_shared<MainGUI>();
    auto ctrl = make_shared<ConcreteController>(repo, gui);
    // ISubject & IObserver attach
    repo->attach(ctrl);
    gui->attach(ctrl);

    // Qt
    gui->setGeometry(200, 200, 1000, 600);
    gui->callVectorSort(Operations::SortedId);
    gui->show();
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
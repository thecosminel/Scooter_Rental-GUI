#include "AppRepository/CsvFileRepository.h"
#include "AppController/ConcreteController.h"
#include "AppUI/UI/MainUI.h"
// Tests
#include "Tests/ctrl_tests.h"
#include "Tests/repo_tests.h"

// Qt
#include "AppUI/GUI/MainGUI.h"
#include <QApplication>


using controller::AbstractController, controller::ConcreteController;
using repository::CsvFileRepository, repository::InMemoryRepository;
using ui::MainUI;
using namespace gui;
using std::make_shared;


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    // Select if data is to be saved persistent
    shared_ptr<InMemoryRepository> repo;
    if (selectIfSavePersistent())
    {
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
        // Create repo using selected csv
        repo = make_shared<CsvFileRepository>(fileName);
    }
    else
    {
        repo = make_shared<InMemoryRepository>();
    }


    // Create GUI
    auto gui = make_shared<MainGUI>();

    // Create Ctrl
    auto ctrl = make_shared<ConcreteController>(repo, gui);


    // ISubject & IObserver attach
    repo->attach(ctrl);
    gui->attach(ctrl);

    // Run
    gui->runGui();
    QApplication::exec();


    // ISubject & IObserver detach
    gui->detach(ctrl);
    repo->detach(ctrl);


    //     Test ctrl and repo
    test_ctrl();
    test_repo();

    return 0;
}
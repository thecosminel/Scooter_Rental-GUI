#include "AppRepository/CsvFileRepository.h"
#include "AppController/ConcreteController.h"
#include "AppUI/UI/MainUI.h"

using controller::AbstractController, controller::ConcreteController;
using repository::CsvFileRepository;
using ui::MainUI;
using std::make_shared;

void function()
{
    auto repo = make_shared<CsvFileRepository>();
    auto ui = make_shared<MainUI>();

    auto ctrl = make_shared<ConcreteController>(repo, ui);

    repo->attach(ctrl);
    ui->attach(ctrl);

    ui->run();
    repo->getAllScootersFromRepo();

    ui->detach(ctrl);
    repo->detach(ctrl);
}

int main()
{
    function();

    return 0;
}
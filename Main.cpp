#include "AppRepository/CsvFileRepository.h"
#include "AppController/ConcreteController.h"
#include "AppUI/UI/MainUI.h"

using controller::AbstractController, controller::ConcreteController;
using namespace ui;
using namespace repository;
using std::make_shared;

void function()
{
    auto r = make_shared<CsvFileRepository>();
    auto ui = make_shared<MainUI>();

    auto c = make_shared<ConcreteController>(r, ui);
    r->attach(c);

    ui->run();
    r->getAllScootersFromRepo();



    r->detach(c);
}

int main()
{
    function();

    return 0;
}
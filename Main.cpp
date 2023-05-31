#include "AppRepository/CsvFileRepository.h"
#include "AppController/ConcreteController.h"

using controller::AbstractController, controller::ConcreteController;
using namespace repository;
using std::make_shared;

void function()
{
    auto r = make_shared<CsvFileRepository>();
    auto c = make_shared<ConcreteController>(r);
    r->attach(c);
    r->getAllScootersFromRepo();
    r->detach(c);
}

int main()
{
    function();

    return 0;
}
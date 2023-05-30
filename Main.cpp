#include "AppRepository/CsvFileRepository.h"
#include "AppController/AbstractController.h"

using controller::AbstractController;
using namespace repository;
using std::make_shared;

void function()
{
    auto r = make_shared<CsvFileRepository>();
    auto c = make_shared<AbstractController>(r);
    r->attach(c);
    r->getAllScootersFromRepo();
    r->detach(c);
}

int main()
{
    function();

    return 0;
}
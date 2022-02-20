#include "Director.h"

Director::Director(string employeeName, string uniqueID) : Employee(employeeName, uniqueID)
{
}

void Director::handleCall() noexcept
{
    isBusy = true;
    cout << name << " is busy handling the call." << endl;       
}
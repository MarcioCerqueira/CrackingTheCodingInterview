#include "Respondent.h"

Respondent::Respondent(string name, string ID, const shared_ptr<Manager>& assignedManager) : Employee(name, ID), 
    manager(assignedManager)
{

}

void Respondent::handleCall() noexcept
{
    
    bool isCallHandled;
    cout << "Can " << name << " handle the call? (0 - No, Other number - Yes)" << endl;
    cin >> isCallHandled;

    if(isCallHandled)
    {
        isBusy = true;
        cout << name << " is busy handling the call." << endl;
    } 
    else
    {
        isBusy = false;
        cout << name << " cannot handle the call. Escalating the call to his/her manager." << endl;
        if(manager) manager->handleCall();
        else cout << "Manager is not available. Call will not handled." << endl;
    }

}

bool Respondent::busy() const noexcept
{
    return isBusy;
}
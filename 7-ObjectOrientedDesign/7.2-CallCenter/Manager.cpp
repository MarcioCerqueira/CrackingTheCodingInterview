#include "Manager.h"

Manager::Manager(string name, string ID, const shared_ptr<Director>& assignedDirector) : Employee(name, ID), 
    director(assignedDirector)
{

}

void Manager::handleCall() noexcept
{
    
    if(isBusy)
    {

        cout << name << " is busy. Escalating the call to his/her director." << endl;
        if(director) director->handleCall();
        else cout << "Director not available. Call will not be handled." << endl;

    }
    else
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
            cout << name << " cannot handle the call. Escalating the call to his/her director." << endl;
            if(director) director->handleCall();
            else cout << "Director not available. Call will not be handled." << endl;
        }

    }

    

}

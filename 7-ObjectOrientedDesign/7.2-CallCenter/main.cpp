#include "CallCenter.h"

//Yeah, I have simplified this question by assigning each respondent, a manager, and each manager, a director.
//But, in a real interview, I would ask more questions to better understand the problem at hand.
int main()
{

    try
    {
        unique_ptr<CallCenter> callCenter = make_unique<CallCenter>();
        
        int numberOfEmployees;
        cout << "Enter the desired number of employees of the call center: ";
        cin >> numberOfEmployees;
        for(int employee = 0; employee < numberOfEmployees; employee++) callCenter->addEmployee();

        int numberOfCalls;
        cout << "Enter the desired number of calls: ";
        cin >> numberOfCalls;
        for(int call = 0; call < numberOfCalls; call++) callCenter->dispatchCall();
    } 
    catch(const exception& e)
    {
        cerr << e.what() << endl;
    }
    
    return 0;

}
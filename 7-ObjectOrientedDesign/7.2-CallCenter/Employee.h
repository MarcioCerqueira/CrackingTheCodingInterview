#include <string>
#include <iostream>
#include <memory>

using namespace std;

class Employee
{

public:
    Employee(string employeeName, string uniqueID);
    virtual void handleCall() noexcept = 0;
    virtual ~Employee() {};

protected:
    string name;
    string ID;
    bool isBusy;
};
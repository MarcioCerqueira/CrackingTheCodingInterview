#include "Employee.h"

class Director : public Employee
{

public:
    Director(string employeeName, string uniqueID);
    virtual void handleCall() noexcept override;

};
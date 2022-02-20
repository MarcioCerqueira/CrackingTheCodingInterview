#include "Manager.h"

class Respondent : public Employee
{

public:
    Respondent(string name, string ID, const shared_ptr<Manager>& assignedManager);
    virtual void handleCall() noexcept override;
    bool busy() const noexcept;

private:
    shared_ptr<Manager> manager;
    
};
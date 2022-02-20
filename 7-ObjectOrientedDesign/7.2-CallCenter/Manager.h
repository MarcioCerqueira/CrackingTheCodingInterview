#include "Director.h"

class Manager : public Employee
{

public:
    Manager(string name, string ID, const shared_ptr<Director>& assignedDirector);
    virtual void handleCall() noexcept override;

protected:
    shared_ptr<Director> director;

};
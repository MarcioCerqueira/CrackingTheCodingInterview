#include <vector>
#include <unordered_map>
#include <iostream>
#include <random>
#include "Respondent.h"

class CallCenter
{

public:
    void addEmployee();
    void dispatchCall();

private:
    void loadEmployeeData(string &name, string& ID, int& level) const;
    template<typename EmployeeLevel, typename SuperiorLevel> shared_ptr<SuperiorLevel> searchSuperior();
    vector<shared_ptr<Respondent>> freeRespondents;
    vector<shared_ptr<Respondent>> busyRespondents;
    unordered_map<string, shared_ptr<Employee>> employees;

};

#include "CallCenter_impl.h"
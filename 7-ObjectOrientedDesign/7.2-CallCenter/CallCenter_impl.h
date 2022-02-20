
void CallCenter::addEmployee()
{

    string name, employeeID;
    int level;
    loadEmployeeData(name, employeeID, level);
    
    shared_ptr<Manager> manager;
    shared_ptr<Director> director;
    
    switch(level)
    {
        case 0:
            manager = searchSuperior<Respondent, Manager>();
            if(manager) 
            {
                employees[employeeID] = dynamic_pointer_cast<Employee>(make_shared<Respondent>(Respondent(name, employeeID, manager)));
                freeRespondents.push_back(dynamic_pointer_cast<Respondent>(employees[employeeID]));
                cout << "Respondent " << name << " has been successfully added in the call center." << endl;
            }
            break;  
        case 1:
            director = searchSuperior<Manager, Director>();
            if(director) 
            {
                employees[employeeID] = dynamic_pointer_cast<Employee>(make_shared<Manager>(Manager(name, employeeID, director)));
                cout << "Manager " << name << " has been successfully added in the call center." << endl;
            }
            break;  
        case 2:
            employees[employeeID] = dynamic_pointer_cast<Employee>(make_shared<Director>(Director(name, employeeID)));
            cout << "Director " << name << " has been successfully added in the call center." << endl;
            break;
    }
    
}

void CallCenter::dispatchCall()
{

    if(freeRespondents.empty()) 
    {
        if(busyRespondents.empty()) cout << "Cannot handle the call. No respondent is available at the call center." << endl;
        else cout << "Cannot handle the call. Every respondent is busy at the moment." << endl;
        return;
    }

    default_random_engine generator;
    uniform_int_distribution<int> distribution(0, freeRespondents.size() - 1);
    int chosenEmployeeID = distribution(generator);
    
    freeRespondents[chosenEmployeeID]->handleCall();
    if(freeRespondents[chosenEmployeeID]->busy()) 
    {
        shared_ptr<Respondent> respondent = freeRespondents[chosenEmployeeID];
        freeRespondents.erase(freeRespondents.begin() + chosenEmployeeID);
        busyRespondents.push_back(respondent);
    }

}

void CallCenter::loadEmployeeData(string &name, string& ID, int& level) const
{

    cout << "What is the name of the employee?" << endl;
    cin >> name;

    ID = to_string(employees.size() + 1);

    do
    {
        cout << "What is the level of the employee? (0 - Respondent, 1 - Manager, 2 - Director)" << endl;
        cin >> level;
    } while (level < 0 || level > 2);

}

template<typename EmployeeLevel, typename SuperiorLevel>
shared_ptr<SuperiorLevel> CallCenter::searchSuperior()
{

    string ID;
    cout << "What is the ID of your superior?" << endl;
    cin >> ID;
            
    if(employees[ID])
    {
        shared_ptr<SuperiorLevel> superior = dynamic_pointer_cast<SuperiorLevel>(employees[ID]);
        if(superior) 
        {
            return superior;
        }
        else 
        {
            cout << "That is not a superior-equivalent ID." << endl;
            return nullptr;
        }
    } 
    else
    {
        cout << "There is not an employee with that ID." << endl;
        return nullptr;
    }
    return nullptr;

}
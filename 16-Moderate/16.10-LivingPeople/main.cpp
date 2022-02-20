#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person
{
    int birthYear;
    int deathYear;
};

void loadPeopleData(vector<Person>& people)
{

    int peopleNumber;
    cout << "How many people will be considered in this application? ";
    cin >> peopleNumber;
    people.resize(peopleNumber);

    cout << "Enter the people data (birth and death years)" << endl;
    for(auto& person : people) cin >> person.birthYear >> person.deathYear;

}

void getSortedYears(const vector<Person>& people, bool copyBirthYear, vector<int>& years)
{

    for(const auto& person : people) years.push_back((copyBirthYear) ? person.birthYear : person.deathYear);
    sort(years.begin(), years.end());

}

int maxAliveYear(const vector<Person>& people, int min, int max)
{

    vector<int> births, deaths;
    getSortedYears(people, true, births);
    getSortedYears(people, false, deaths);

    int birthIndex = 0;
    int deathIndex = 0;
    int currentlyAlive = 0;
    int maxAlive = 0;
    int maxAliveYear = min;

    while(birthIndex < births.size())
    {
        if(births[birthIndex] <= deaths[deathIndex])
        {
            currentlyAlive++;
            if(currentlyAlive > maxAlive)
            {
                maxAlive = currentlyAlive;
                maxAliveYear = births[birthIndex];
            }
            birthIndex++;
        } 
        else if(births[birthIndex] > deaths[deathIndex])
        {
            currentlyAlive--;
            deathIndex++;
        }
    }

    return maxAliveYear;
}


int main()
{

    vector<Person> people;
    loadPeopleData(people);
    cout << "Year with the most number of people alive: " << maxAliveYear(people, 1900, 2022) << endl;
    return 0;

}
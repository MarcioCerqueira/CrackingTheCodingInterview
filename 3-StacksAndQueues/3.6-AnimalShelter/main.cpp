#include <iostream>
#include <queue>

using namespace std;

void loadQueues(queue<int>& dogs, queue<int>& cats, int N)
{

    int animal;
    for(int count = 0; count < N; count++)
    {
        cout << "Animal is a dog (0) or a cat (1)? ";
        cin >> animal;
        if(animal == 0) dogs.push(count);
        else cats.push(count);
    }

}

void adoptAnimal(queue<int>& queue, bool isDog)
{

    string animal = (isDog) ? "dog" : "cat";
    if(queue.empty()) 
    {
        cout << "No more " << animal << "s available for adoption" << endl;
        return;
    }
    cout << "A " << animal << " has been adopted: " << queue.front() << endl;
    queue.pop();

}

void adoptAnimals(queue<int>& dogs, queue<int>& cats)
{

    bool adoption, oldestAnimal, animalType;
    do
    {

        cout << "Do you want to adopt an animal? (0 - No, 1 - Yes) ";
        cin >> adoption;

        if(!adoption) continue;

        cout << "Do you want to adopt the oldest animal? (0 - No, 1 - Yes) ";
        cin >> oldestAnimal;
        if(oldestAnimal) 
        {
            if(dogs.front() < cats.front()) adoptAnimal(dogs, true);
            else adoptAnimal(cats, false);
        } 
        else
        {
            cout << "Do you want to adopt a dog (0) or a cat (1)? ";
            cin >> animalType;
            if(animalType) adoptAnimal(cats, true);
            else adoptAnimal(dogs, false);
        }
        
    } while(adoption);
    
}

//Time complexity: O(N)
int main()
{

    queue<int> dogs;
    queue<int> cats;

    cout << "Write the number of animals available in the shelter: ";
    int N;
    cin >> N;
    loadQueues(dogs, cats, N);
    
    adoptAnimals(dogs, cats);
    return 0;
}
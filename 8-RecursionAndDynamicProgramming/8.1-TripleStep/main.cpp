#include <iostream>
#include <vector>

using namespace std;
vector<int> possibleWays;

//Time complexity: O(N)
int recursiveStepCount(int currentStep, int maxSteps)
{

    if(currentStep > maxSteps) return 0;
    if(currentStep == maxSteps) return 1;
    if(possibleWays[currentStep] > 0) return possibleWays[currentStep];

    for(int step = 1; step < 4; step++) possibleWays[currentStep] += recursiveStepCount(currentStep + step, maxSteps); 
    return possibleWays[currentStep];

}

//Time complexity: O(N)
int iterativeStepCount(int maxSteps)
{

    int step1 = 0;
    int step2 = 0;
    int step3 = 0;

    for(int step = maxSteps - 1; step >= 0; step--)
    {
        if(step == maxSteps - 1) step1 = 1;
        int sum = step1 + step2 + step3;
        step3 = step2;
        step2 = step1;
        step1 = sum;
    }

    return step1;

}

int main()
{

    int N;
    cout << "Write the number of steps in the staircase: " << endl;
    cin >> N;

    possibleWays.resize(N + 1);
    cout << "A child can run up the stairs in " << recursiveStepCount(0, N) << " possible ways" << endl;
    cout << "A child can run up the stairs in " << iterativeStepCount(N) << " possible ways" << endl;
    return 0;

}
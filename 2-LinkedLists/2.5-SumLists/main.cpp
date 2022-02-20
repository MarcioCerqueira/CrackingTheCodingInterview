#include <iostream>
#include <cmath>
#include <forward_list>

using namespace std;

void loadNumber(forward_list<int>& number, int digits)
{

    cout << "Write each digit of the number: ";
    int value;
    for(int digit = 0; digit < digits; digit++)
    {
        cin >> value;
        number.emplace_front(value);
    }

}

//Time complexity: O(N)
int sumNumbers(const forward_list<int>& firstNumber, const forward_list<int>& secondNumber)
{

    auto firstNumberIterator = firstNumber.begin();
    auto secondNumberIterator = secondNumber.begin();
    int sum = 0;
    int digitOrder = 0;

    while(firstNumberIterator != firstNumber.end() || secondNumberIterator != secondNumber.end())
    {

        int n1 = 0, n2 = 0;
        if(firstNumberIterator != firstNumber.end()) n1 = *firstNumberIterator;
        if(secondNumberIterator != secondNumber.end()) n2 = *secondNumberIterator;
        
        sum += (n1 + n2) * powf(10, digitOrder);
        digitOrder++;   
        
        if(firstNumberIterator != firstNumber.end()) firstNumberIterator++;
        if(secondNumberIterator != secondNumber.end()) secondNumberIterator++; 

    }

    return sum;

}

void convertNumberToList(int number, forward_list<int>& list)
{

    if(number == 0) return;
    int digitOrder = log10(number);
    
    while(digitOrder >= 0) 
    {
        int magnitude = static_cast<int>(powf(10, digitOrder));
        int digit = number / magnitude;
        number %= magnitude;
        list.emplace_front(digit);
        digitOrder--;
    }

}

void printList(const forward_list<int>& linkedList)
{

    cout << "Final linked list: ";
    int count = 0;
    for(auto &item : linkedList) 
    {
        if(count == 0) cout << item;
        else cout << " -> " << item;
        count++;
    }
    cout << endl;

}

int main()
{
    
    forward_list<int> firstNumber;
    forward_list<int> secondNumber;
    forward_list<int> sum;
    int numberOfDigits;
    
    cout << "Write the number of digits of the first number: ";
    cin >> numberOfDigits;
    if(numberOfDigits <= 0) return 0;
    loadNumber(firstNumber, numberOfDigits);

    cout << "Write the number of digits of the second number: ";
    cin >> numberOfDigits;
    if(numberOfDigits <= 0) return 0;
    loadNumber(secondNumber, numberOfDigits);

    convertNumberToList(sumNumbers(firstNumber, secondNumber), sum);
    printList(sum);
    return 0;

}
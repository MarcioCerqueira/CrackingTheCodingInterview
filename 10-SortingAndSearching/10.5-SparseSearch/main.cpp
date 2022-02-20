#include <iostream>
#include <string>
#include <vector>

using namespace std;

void loadSortedArray(vector<string>& sortedArray)
{

    int size;
    cout << "Enter the size of the array: " << endl;
    cin >> size;
    sortedArray.resize(size);

    cout << "Enter the number of non-empty strings: " << endl;
    cin >> size;
    
    int index; 
    for(int word = 0; word < size; word++)
    {
        cout << "Enter the position (starting from 0) and the desired word" << endl;
        cin >> index;
        cin >> sortedArray[index];
    }

}

//Time complexity: Worst case O(n)
int searchString(const vector<string>& sortedArray)
{

    string searchWord;
    cout << "Enter the search string: " << endl;
    cin >> searchWord;

    int begin = 0; 
    int end = sortedArray.size() - 1;
    while(begin <= end)
    {
        int middle = (begin + end)/2;
        if(sortedArray[middle] == searchWord) 
        {
            return middle;
        }
        else if(!sortedArray[middle].empty()) 
        {
            if(sortedArray[middle] > searchWord) end = middle - 1;
            else begin = middle + 1;
        } 
        else
        {
            int rightMiddle = middle;
            int leftMiddle = middle;
            bool exaustiveSearch = true;
            while(leftMiddle >= begin || rightMiddle <= end)
            {
                leftMiddle--;
                if(leftMiddle >= begin && !sortedArray[leftMiddle].empty()) 
                {
                    if(sortedArray[leftMiddle] == searchWord) return leftMiddle;
                    else if(sortedArray[leftMiddle] > searchWord) end = leftMiddle - 1;
                    else begin = rightMiddle + 1;
                    exaustiveSearch = false;
                    break;
                }
                rightMiddle++;
                if(rightMiddle <= end && !sortedArray[rightMiddle].empty())
                {
                    if(sortedArray[rightMiddle] == searchWord) return rightMiddle;
                    else if(sortedArray[rightMiddle] > searchWord) end = leftMiddle - 1;
                    else begin = rightMiddle + 1;
                    exaustiveSearch = false;
                    break;
                }
            }
            if(exaustiveSearch) return -1;
        }
    }
    return -1;

}

int main()
{

    vector<string> sortedArray;
    loadSortedArray(sortedArray);
    int index = searchString(sortedArray);
    if(index == -1) cout << "Search string could not be found" << endl;
    else cout << "Search string located at " << index << endl;
    return 0;
    
}
#include <string>
#include <iostream>

using namespace std;

//Time complexity: O(N)
bool isStringRotation(const string& s1, const string& s2)
{

    if(s1.size() != s2.size()) return false;
    
    string s3 = s1 + s1;
    if(s3.find(s2) != string::npos) return true;
    else return false;
    
}

int main()
{

    string s1, s2;
    cout << "Write two words: ";
    cin >> s1 >> s2;

    if(isStringRotation(s1, s2)) cout << s2 << " is a rotation of " << s1 << endl;
    else cout << s2 << " is not a rotation of " << s1 << endl;
    return 0;

}
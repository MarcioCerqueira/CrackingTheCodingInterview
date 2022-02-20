#include <iostream>
#include <random>
using namespace std;

int rand5()
{

    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist5(0, 4);
    return dist5(rng);

}

int rand7()
{
    while(true)
    {
        int num = 5 * rand5() + rand5();
        if(num < 21) return num % 7; 
    }
}

int main()
{
    cout << rand7() << endl;
}
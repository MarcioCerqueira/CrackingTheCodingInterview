#include <iostream>
#include <vector>
using namespace std;

void drawLine(vector<char> screen, int width, int x1, int x2, int y)
{

    int startOffset = x1 % 8;
    int firstFullchar = x1 / 8;
    if(startOffset != 0) firstFullchar++;

    int endOffset = x2 % 8;
    int lastFullchar = x2 / 8;
    if(endOffset != 7) lastFullchar--;

    for(int b = firstFullchar; b <= lastFullchar; b++)
        screen[(width / 8) * y + b] = static_cast<char>(0xFF);

    char startMask = static_cast<char>(0xFF >> startOffset);
    char endMask = static_cast<char>(~(0xFF >> (endOffset + 1)));

    if((x1 / 8) == (x2 / 8)) 
    {
        char mask = static_cast<char>(startMask & endMask);
        screen[(width / 8) * y + (x1 / 8)] |= mask;
    } 
    else
    {
        if(startOffset != 0)
        {
            int charNumber = (width / 8) * y + firstFullchar - 1;
            screen[charNumber] |= startMask;
        }
        if(endOffset != 7)
        {
            int charNumber = (width / 8) * y + lastFullchar - 1;
            screen[charNumber] |= endMask;    
        }
    }

}

int main()
{

    vector<char> screen;
    drawLine(screen, 16, 1, 8, 1);
    for(auto elem : screen)
        cout << static_cast<char>(elem) << " ";
    return 0;
}
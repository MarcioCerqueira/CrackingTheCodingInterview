#include <iostream>
#include <vector>

using namespace std;

void loadImage(vector<vector<int>>& image, int rows, int cols)
{

    image.resize(cols);
    for(auto& element : image) element.resize(rows);
    
    cout << "Enter the value of the pixels: ";
    for(int x = 0; x < cols; x++)
        for(int y = 0; y < rows; y++)
            cin >> image[x][y];

}

//Time complexity: O(n)
void paintFill(vector<vector<int>>& image, int x, int y, int oldColor, int newColor)
{

    if(x < 0 || y < 0 || x >= image.size() || y >= image[0].size()) return;
    if(image[x][y] == newColor || image[x][y] != oldColor) return;
    
    image[x][y] = newColor;
    paintFill(image, x - 1, y, oldColor, newColor);
    paintFill(image, x + 1, y, oldColor, newColor);
    paintFill(image, x, y - 1, oldColor, newColor);
    paintFill(image, x, y + 1, oldColor, newColor);

}

void paintFill(vector<vector<int>>& image)
{

    int x, y, color;
    cout << "Enter x and y pixels: ";
    cin >> x >> y;
    cout << "Enter new color: ";
    cin >> color;

    if(x < 0 || y < 0 || x >= image.size() || y >= image[0].size()) return;
    paintFill(image, x, y, image[x][y], color);

}

void printImage(const vector<vector<int>>& image)
{

    for(int x = 0; x < image.size(); x++) 
    {
        for(int y = 0; y < image[x].size(); y++) 
        {
            cout << image[x][y] << " ";
        }
        cout << endl;
    }

}

int main()
{

    int rows, cols;
    cout << "Enter the number of rows: " << endl;
    cin >> rows;
    cout << "Enter the number of columns: " << endl;
    cin >> cols;

    vector<vector<int>> image;
    loadImage(image, rows, cols);
    paintFill(image);
    printImage(image);
    return 0;

}
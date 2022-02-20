#include <iostream>

using namespace std;

struct Point
{
    double x;
    double y;
};

struct Line
{
    double slope;
    double yintercept;
    Line(const Point& start, const Point& end)
    {
        slope = (end.y - start.y) / (end.x - start.x);
        yintercept = end.y - slope * end.x;
    }
};

void swap(Point& p1, Point& p2)
{
    double x = p1.x;
    double y = p1.y;
    p1.x = p2.x;
    p1.y = p2.y;
    p2.x = x;
    p2.y = y;
}

bool isBetween(const double start, const double middle, const double end)
{
    if(start > end) return end <= middle && middle <= start;
    else return start <= middle && middle <= end;
}

bool isBetween(const Point& start, const Point& middle, const Point& end)
{
    return isBetween(start.x, middle.x, end.x) && isBetween(start.y, middle.y, end.y);
}

bool computeIntersection(Point& p1, Point& p2, Point& p3, Point& p4, Point &intersectionPoint)
{

    if(p1.x > p2.x) swap(p1, p2);
    if(p3.x > p4.x) swap(p3, p4);
    if(p1.x > p3.x)
    {
        swap(p1, p3);
        swap(p2, p4);
    }
    Line l1(p1, p2);
    Line l2(p3, p4);

    if(l1.slope == l2.slope)
    {
        if(l1.yintercept == l2.yintercept && isBetween(p1, p3, p2))
        {
            intersectionPoint = p3;
            return true;
        }
        return false;
    }

    double x = (l2.yintercept - l1.yintercept) / (l1.slope - l2.slope);
    double y = x * l1.slope + l1.yintercept;
    intersectionPoint.x = x;
    intersectionPoint.y = y;

    if(isBetween(p1, intersectionPoint, p2) && isBetween(p3, intersectionPoint, p4)) return true;
    return false;

}

int main()
{

    Point p1, p2, p3, p4;
    cout << "Enter the 2D coordinates of the start and end points that define the first line" << endl;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    cout << "Enter the 2D coordinates of the start and end points that define the second line" << endl;
    cin >> p3.x >> p3.y >> p4.x >> p4.y;
    
    Point intersectionPoint;
    if(!computeIntersection(p1, p2, p3, p4, intersectionPoint)) cout << "There is not a intersection" << endl;
    else cout << "Intersection point: (" << intersectionPoint.x << "," << intersectionPoint.y << ")" << endl;
    
    return 0;
    
}
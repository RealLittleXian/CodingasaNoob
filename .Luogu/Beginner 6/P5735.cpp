#include <iostream>
#include <cmath>
using namespace std;

float dis(float x1, float x2, float y1, float y2);

int main()
{
    float distance;
    float x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    distance = dis(x1, x2, y1, y2) + dis(x1, x3, y1, y3) + dis(x2, x3, y2, y3);
    printf("%.2f", distance);
    return 0;
}

float dis(float x1, float x2, float y1, float y2)
{
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}
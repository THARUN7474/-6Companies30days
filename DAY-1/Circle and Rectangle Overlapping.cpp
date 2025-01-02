#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2)
    {
        int x_c = max(x1, min(xCenter, x2));
        int y_c = max(y1, min(yCenter, y2));
        int n = x_c - xCenter;
        int m = y_c - yCenter;
        return ((n * n) + (m * m)) <= radius * radius;
    }
};
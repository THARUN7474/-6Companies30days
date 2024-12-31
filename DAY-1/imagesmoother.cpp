#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int m = img.size();                          // rows
        int n = img[0].size();                       // cols
        vector<vector<int>> v(m, vector<int>(n, 0)); //[[0,0,0],[0,0,0],[0,0,0]]
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int ans = 0;
                int c = 0;
                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        int nx = i + x;
                        int ny = j + y;
                        if (nx >= 0 && nx < m && ny >= 0 && ny < n)
                        {
                            ans += img[nx][ny];
                            c++;
                        }
                    }
                }
                v[i][j] = ans / c;
            }
        }

        return v;
    }
};
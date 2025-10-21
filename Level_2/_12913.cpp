#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> v)
{
    for(int i = 1; i<v.size(); i++)
    {
        v[i][0] += max(v[i-1][1], max(v[i-1][2],v[i-1][3]));
        v[i][1] += max(v[i-1][0], max(v[i-1][2],v[i-1][3]));
        v[i][2] += max(v[i-1][0], max(v[i-1][1],v[i-1][3]));
        v[i][3] += max(v[i-1][0], max(v[i-1][1],v[i-1][2]));
    }

    return *max_element(v.back().begin(), v.back().end());
}

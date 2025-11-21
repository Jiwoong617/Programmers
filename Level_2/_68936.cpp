#include <string>
#include <vector>

using namespace std;

void quad(vector<vector<int>>& arr, int x, int y, int n, vector<int>& v)
{
    int zero = 0, one = 0;
    for(int i = x; i<x+n; i++)
    {
        for(int j = y; j<y+n; j++)
        {
            if(arr[i][j]) one++;
            else zero++;
        }
    }
    
    if(one == n*n)
        v[1]++;
    else if(zero == n*n)
        v[0]++;
    else
    {
        quad(arr, x, y, n/2, v);
        quad(arr, x+n/2, y, n/2, v);
        quad(arr, x, y+n/2, n/2, v);
        quad(arr, x+n/2, y+n/2, n/2, v);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> v(2, 0);
    quad(arr, 0, 0, arr.size(), v);
    return v;
}

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> v) {
    for(int i = 1; i<v.size(); i++)
    {
        v[i][0] += v[i-1][0];
        for(int j = 1; j<=i; j++)
        {
            if(j == i) v[i][j] += v[i-1][j-1];
            else v[i][j] += max(v[i-1][j], v[i-1][j-1]);
        }
    }
    
    return *max_element(v.back().begin(), v.back().end());
}

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> ans;
    vector<vector<int>> tri(n, vector<int>(n));
    int x = -1, y = 0, a = 1;
    for(int i = 0; i<n; i++)
    {
        for(int j = i; j<n; j++)
        {
            if(i%3 == 0) x++;
            else if(i%3 == 1) y++;
            else
            {
                x--;
                y--;
            }
            tri[x][y] = a++;
        }
    }
    
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            if(tri[i][j]) ans.push_back(tri[i][j]);
    return ans;
}

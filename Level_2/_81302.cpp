#include <string>
#include <vector>

using namespace std;

bool isIn(int x, int y) { return 0 <= x && x < 5 && 0 <= y && y < 5; }

int check(vector<string>& p)
{
    int d1[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    int d2[4][2] = {{-2,0},{2,0},{0,-2},{0,2}};
    int d3[4][2] = {{-1,-1},{-1,1},{1,-1},{1,1}};
    
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(p[i][j] != 'P') continue;

            for(int k = 0; k < 4; k++)
            {
                int dx = i + d1[k][0];
                int dy = j + d1[k][1];
                if(isIn(dx, dy) && p[dx][dy] == 'P')
                    return 0;
            }

            for(int k = 0; k < 4; k++)
            {
                int dx = i + d2[k][0];
                int dy = j + d2[k][1];
                if(!isIn(dx, dy) || p[dx][dy] != 'P')
                    continue;

                int tx = i + d2[k][0]/2;
                int ty = j + d2[k][1]/2;
                if(p[tx][ty] != 'X')
                    return 0;
            }

            for(int k = 0; k < 4; k++)
            {
                int dx = i + d3[k][0];
                int dy = j + d3[k][1];
                if(!isIn(dx, dy) || p[dx][dy] != 'P')
                    continue;

                if(!(p[i][dy] == 'X' && p[dx][j] == 'X'))
                    return 0;
            }
        }
    }
    return 1;
}


vector<int> solution(vector<vector<string>> p) {
    vector<int> v;
    for(auto& a : p)
        v.push_back(check(a));
    return v;
}

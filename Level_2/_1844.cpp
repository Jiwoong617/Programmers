#include<vector>
#include<queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    maps[0][0] = 2;
    while(!q.empty())
    {
        pair<int, int> t = q.front();
        q.pop();
        
        for(int i = 0; i<4; i++)
        {
            int tx = dx[i] + t.first;
            int ty = dy[i] + t.second;
            
            if(tx < 0 || ty < 0 || tx >= maps.size() || ty >= maps[0].size()) continue;
            if(maps[tx][ty] == 1)
            {
                q.push(make_pair(tx,ty));
                maps[tx][ty] = maps[t.first][t.second] + 1;
            }
        }
    }
    
    if(maps[maps.size()-1][maps[0].size()-1] == 1)
        answer = -1;
    else
        answer = maps[maps.size()-1][maps[0].size()-1] -1;
    
    return answer;
}

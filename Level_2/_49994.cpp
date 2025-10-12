#include <string>
using namespace std;

int solution(string dirs) {
    int ans = 0;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    bool v[11][11][4] = {false,};
    
    int x = 5, y = 5;
    for(char c : dirs)
    {
        int t = 0;
        if(c == 'U') t = 0;
        if(c == 'D') t = 2;
        if(c == 'R') t = 1;
        if(c == 'L') t = 3;
        
        int tx = x+dx[t];
        int ty = y+dy[t];
        if(tx < 0 || tx > 10 || ty < 0 || ty > 10) continue;
        if(!v[tx][ty][t]) ans++;
        
        v[tx][ty][t] = true;
        v[x][y][(t+2)%4] = true;
        x = tx;
        y = ty;
    }
    
    return ans;
}

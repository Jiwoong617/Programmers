#include <string>
#include <vector>

using namespace std;

void dfs(vector<int>& v, int& cnt, int& n, int row)
{
    if(row == n)
    {
        cnt++;
        return;
    }
    
    for(int i = 0; i<n; i++)
    {
        v[row] = i;
        bool isPut = true;
        for(int j = 0; j<row; j++)
        {
            //같은 열, 대각선 체크
            if(v[row] == v[j] || abs(v[j]-v[row]) == abs(j-row))
            {
                isPut = false;
                break;
            }
        }
        
        if(isPut)
            dfs(v,cnt,n,row+1);
    }
}

int solution(int n) {
    vector<int> chess(n, 0);
    int cnt = 0;
    dfs(chess, cnt, n, 0);
    return cnt;
}

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int ans = 0;
    vector<vector<int>> sum(board.size()+2, vector<int>(board[0].size()+2, 0));
    
    for(auto& a : skill)
    {
        int val = (a[0] == 1 ? -a[5] : a[5]);
        sum[a[1]+1][a[2]+1] += val;
        sum[a[1]+1][a[4]+2] -= val;
        sum[a[3]+2][a[2]+1] -= val;
        sum[a[3]+2][a[4]+2] += val;
    }
    
    for(int i = 1; i<=board.size(); i++)
    {
        for(int j = 1; j<=board[0].size(); j++)
        {
            sum[i][j] += (sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1]);
            if(sum[i][j]+board[i-1][j-1] > 0)
                ans++;
        }
    }
    
    return ans;
}

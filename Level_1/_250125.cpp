#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1, 1, 0, 0};
    for(int i = 0; i<4; i++)
    {
        int x = h + dx[i];
        int y = w + dy[i];
        
        if(x >= board.size() || x < 0 || y < 0 || y >=board[i].size()) continue;
        
        if(board[h][w] == board[x][y])
            answer++;
    }
    
    return answer;
}

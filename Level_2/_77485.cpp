#include <string>
#include <vector>

using namespace std;

int rotate(int x, int y, int xx, int yy, vector<vector<int>>& mat)
{
    int ret = 10000;
    int lt = mat[x][y], rt = mat[x][yy];
    int lb = mat[xx][y], rb = mat[xx][yy];
    ret = min(ret, min(lt, min(rt, min(lb, rb))));
    for(int i = xx, j = x; i>x && j<xx; i--, j++) //우좌
    {
        mat[i][yy] = mat[i-1][yy];
        mat[j][y] = mat[j+1][y];
        ret = min(ret, min(mat[i][yy], mat[j][y]));
    }
    for(int i = yy, j = y; i>y && j<yy; i--, j++) //상하
    {
        mat[x][i] = mat[x][i-1];
        mat[xx][j] = mat[xx][j+1];
        ret = min(ret, min(mat[x][i], mat[xx][j]));
    }
    mat[x][y+1] = lt; mat[x+1][yy] = rt;
    mat[xx-1][y] = lb; mat[xx][yy-1] = rb;
    
    return ret;
}

vector<int> solution(int rows, int columns, vector<vector<int>> q) {
    vector<int> ans;
    vector<vector<int>> mat(rows, vector<int>(columns));
    int n = 1;
    for(int i = 0; i<rows; i++)
        for(int j = 0; j<columns; j++)
            mat[i][j] = n++;
    
    for(auto& a : q)
        ans.push_back(rotate(a[0]-1, a[1]-1, a[2]-1, a[3]-1, mat));
    
    return ans;
}

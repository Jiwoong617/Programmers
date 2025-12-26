#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> data, int col, int b, int e) {
    int ans = 0;
    sort(data.begin(), data.end(), [col](vector<int>& a, vector<int>& b){
        if(a[col-1] == b[col-1])
            return a[0] > b[0];
        return a[col-1] < b[col-1];
    });
    
    for(int i = b-1; i<e; i++)
    {
        int cnt = 0;
        for(int j = 0; j<data[i].size(); j++)
            cnt += data[i][j] % (i+1);
        ans ^= cnt;
    }
    
    return ans;
}

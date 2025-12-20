#include <string>
#include <vector>

using namespace std;

void hanoi(vector<vector<int>>& v, int n, int s, int m, int e)
{
    if(!n)
        return;
    
    hanoi(v, n-1, s,e,m);
    v.push_back({s, e});
    hanoi(v, n-1, m, s, e);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> v;
    hanoi(v, n, 1, 2, 3);
    return v;
}

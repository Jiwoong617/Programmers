#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> v(n);

    for(int i = 0; i<n; i++)
    {
        if(v[i]) continue;
        
        queue<int> q;
        q.push(i);
        v[i] = true;
        answer++;
        while(!q.empty())
        {
            int t = q.front();
            q.pop();
            for(int j = 0; j<n; j++)
            {
                if(i == j || v[j] || computers[t][j] == 0) continue;
                q.push(j);
                v[j] = true;
            }
        }
        
    }
    
    return answer;
}

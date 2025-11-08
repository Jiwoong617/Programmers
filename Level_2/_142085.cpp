#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int ans = 0;
    priority_queue<int> q;
    for(int i : enemy)
    {
        q.push(i);
        n-= i;
        
        if(n < 0)
        {
            if(k)
            {
                n += q.top();
                q.pop();
                k--;
            }
            else
                break;
        }
        ans++;
    }
    
    return ans;
}

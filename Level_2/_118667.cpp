#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int ans = 0;
    long long a = 0, b = 0;
    queue<int> q1, q2;
    for(int i = 0; i<queue1.size(); i++)
    {
        q1.push(queue1[i]);
        q2.push(queue2[i]);
        a += queue1[i];
        b += queue2[i];
    }
    
    for(int i = 0; i<4*queue1.size(); i++)
    {
        if(a == b) return ans;
        
        if(a > b)
        {
            a -= q1.front();
            b += q1.front();
            q2.push(q1.front());
            q1.pop();
        }
        else if(b > a)
        {
            a += q2.front();
            b -= q2.front();
            q1.push(q2.front());
            q2.pop();
        }
        ans++;
    }
    
    return -1;
}

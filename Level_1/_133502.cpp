#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> v) {
    int ans = 0;
    stack<int> s; s.push(0);
    for(int i : v)
    {
        int n = s.top(); s.pop();
        if(n == 1 && i == 2) s.push(4);
        else if (n == 4 && i == 3) s.push(5);
        else if (n == 5 && i == 1) ans++;
        else {s.push(n); s.push(i);}
    }
    
    return ans;
}

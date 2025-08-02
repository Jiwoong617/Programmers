#include <string>
#include <vector>

using namespace std;

int dfs(vector<int>& n, int& t, int now, int sum)
{
    if(now == n.size())
    {
        if(sum == t) return 1;
        else return 0;
    }
    
    return dfs(n, t, now+1, sum+n[now]) + dfs(n, t, now+1, sum-n[now]);
}

int solution(vector<int> numbers, int target) {
    return dfs(numbers, target, 1, numbers[0]) + dfs(numbers, target, 1, -numbers[0]);
}

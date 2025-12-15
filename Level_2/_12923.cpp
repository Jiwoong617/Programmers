#include <string>
#include <vector>

using namespace std;

long long yaksoo(long long n)
{
    long long a = 1;
    for(long long i = 2; i*i<=n; i++)
    {
        if(n%i == 0)
        {
            a = i;
            if(n/i<=10000000)
                return n/i;
        }
    }
    
    return a;
}

vector<int> solution(long long begin, long long end) {
    vector<int> ans;
    for(int i = begin; i<=end; i++)
    {
        if(i == 1)
            ans.push_back(0);
        else
            ans.push_back(yaksoo(i));
    }
    
    return ans;
}

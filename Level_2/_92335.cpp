#include <string>
#include <vector>

using namespace std;

void isPrime(int& ans, int n)
{
    if(n == 1 || !n) return;
    
    for(int i = 2; i*i<= n; i++)
        if(n%i == 0)
            return;
    
    ans++;
}

int solution(int n, int k) {
    int ans = 0;
    vector<int> v(1, 0);
    while(n)
    {
        v.push_back(n%k);
        n/=k;
    }
    
    int t = 0;
    for(int i = v.size()-1; i>= 0; i--)
    {
        if(v[i] == 0)
        {
            isPrime(ans, t);
            t = 0;
        }
        else
        {
            t*=10;
            t+=v[i];
        }
    }
    
    return ans;
}

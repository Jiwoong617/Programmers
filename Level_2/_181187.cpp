#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long ans = 0, a = r1, b = r2;
    for(long long i = 1; i<=b; i++)
    {
        long long n = a*a-i*i, m = b*b-i*i;
        
        m = floor(sqrt(m));
        if(n <= 0)
            ans += m+1;
        else
            ans += m-ceil(sqrt(n))+1;   
    }
    
    return ans*4;
}

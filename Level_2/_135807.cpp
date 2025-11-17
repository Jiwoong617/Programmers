#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {return (b == 0 ? a : gcd(b, a%b));}

int solution(vector<int> a, vector<int> b) {
    int ans = 0, n = a[0], m = b[0];
    for(int i : a) n = (n > i ? gcd(n, i):gcd(i,n));
    for(int i : b) m = (m > i ? gcd(m, i):gcd(i,m));
    
    bool fa = true, fb = true;
    for(int i : a)
    {
        if(m < 2 || i%m == 0)
        {
            fa = false;
            break;
        }
    }
    
    for(int i : b)
    {
        if(n < 2 || i%n == 0)
        {
            fb = false;
            break;
        }
    }
    
    if(fa) ans = max(ans, m);
    if(fb) ans = max(ans, n);
    
    return ans;
}

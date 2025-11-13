#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int ans = 0;
    while(n)
    {
        int t = n%10;
        n/=10;
        
        if(t == 5)
        {
            if(n%10 > 4)
                n++;
            ans +=5;
        }
        else if(t>5)
        {
            ans+= 10-t;
            n++;
        }
        else
            ans+=t;
    }
    return ans;
}

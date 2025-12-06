#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long ans = 0;
    for(long long i = 0; i<=d; i+=k)
    {
        long long n = sqrt((long long)d*d - i*i);
        ans += n/k+1;
    }
    return ans;
}

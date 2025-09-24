#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int a[100001];
    a[0] = 0; a[1] = 1; a[2] = 1;
    for(int i = 3; i<=n; i++)
        a[i] = (a[i-2] + a[i-1])%1234567;
    
    return a[n];
}

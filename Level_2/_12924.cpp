#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int ans = 1;
    for(int i = 2; i*(i-1)/2<n; i++)
        if ((n-i*(i-1)/2)%i == 0)
            ans++;
    return ans;
}

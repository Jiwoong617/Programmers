#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int l, int r) {
    int ans = 0;
    for (int i = l; i <= r; i++)
    {
        int t = sqrt(i);
        ans += (t * t == i ? -i : i);
    }
    return ans;
}

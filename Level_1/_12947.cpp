#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int n = x, m = 0;
    while(n)
    {
        m += n%10;
        n/=10;
    }
    
    return !(x%m);
}

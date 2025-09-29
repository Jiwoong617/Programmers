#include <string>
#include <vector>

using namespace std;

long long solution(int a) {
    int n[2001];
    n[1] = 1;n[2] = 2;
    for(int i = 3; i<=a; i++)
        n[i] = (n[i-1] + n[i-2]) % 1234567;
    return n[a];
}

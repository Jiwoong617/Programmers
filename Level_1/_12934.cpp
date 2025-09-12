#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    return sqrt(n) == (int)sqrt(n) ? pow(sqrt(n)+1,2):-1;
}

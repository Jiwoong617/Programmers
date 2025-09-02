#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

long long solution(long long n) {
    string s = to_string(n);
    sort(s.begin(), s.end(), greater<int>());
    
    return stoll(s);
}

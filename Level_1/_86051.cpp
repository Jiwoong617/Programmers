#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> v) {
    return 45 - accumulate(v.begin(), v.end(), 0);
}

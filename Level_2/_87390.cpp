#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long l, long long r) {
    vector<int> v;
    for(long long i = l; i<= r; i++)
        v.push_back(max(i/n+1, i%n+1));
    return v;
}

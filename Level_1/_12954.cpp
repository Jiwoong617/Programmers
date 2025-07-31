#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    long long a = x;
    answer.push_back(a);
    for(int i = 1; i<n; i++)
    {
        a+=x;
        answer.push_back(a);
    }
    return answer;
}

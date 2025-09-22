#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> makeBinary(int n)
{
    vector<int> v;
    while(n)
    {
        v.push_back(n%2);
        n/=2;
    }
    return v;
}

int solution(int n) {
    vector<int> v = makeBinary(n);
    int cnt = count(v.begin(), v.end(), 1);
    int num = n;
    while(1)
    {
        num++;
        vector<int> t = makeBinary(num);
        int cnt2 = count(t.begin(), t.end(), 1);
        if(cnt == cnt2)
            return num;
    }
    return 0;
}

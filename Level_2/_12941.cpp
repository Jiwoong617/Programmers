#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> a, vector<int> b)
{
    int s1= 0, s2 =0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i = 0; i<a.size(); i++)
    {
        s1 += a[i] * b[b.size() - 1 - i];
        s2 += b[i] * a[a.size() - 1 - i];
    }

    return s1>s2 ? s2 : s1;
}

#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> s)
{
    if(s.size() == 1) return s[0];
    
    vector<int> hol(s.size(), s[0]), jjak(s.size(), s[1]);
    jjak[0] = 0;
    for(int i = 2; i<s.size(); i++)
    {
        hol[i] = max(hol[i-1], hol[i-2] + s[i]);
        jjak[i] = max(jjak[i-1], jjak[i-2] + s[i]);
    }

    return max(hol[s.size()-2], jjak.back());
}

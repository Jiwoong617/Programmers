#include <iostream>
#include <string>
using namespace std;

int lr(string& s, int l, int r)
{
    while (l >= 0 && r < s.length() && s[l] == s[r])
    {
        l--;
        r++;
    }
    
    return r - l - 1;
}

int solution(string s)
{
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        //홀,짝
        ans = max(ans, lr(s, i, i));
        ans = max(ans, lr(s, i, i + 1));
    }
    
    return ans;
}

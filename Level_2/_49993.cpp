#include <string>
#include <vector>

using namespace std;

bool isSkill(string& s, string& st)
{
    int loc = 0;
    for(int i = 0; i<s.length(); i++)
    {
        int idx = 27;
        for(int j = 0; j<st.length(); j++)
            if(st[j] == s[i])
            {
                idx = j;
                break;
            }
        
        if(idx < loc) return false;
        loc = idx;
    }
    
    return true;
}

int solution(string s, vector<string> st) {
    int ans=0;
    for(string& a : st)
        if(isSkill(s, a)) ans++;
    return ans;
}

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int ans = s.length();
    for(int i = 1; i<s.length()/2+1; i++)
    {
        int cnt = 1;
        string cut = s.substr(0, i);
        string ss = "";
        for(int j = i; j<s.length(); j+=i)
        {
            if(cut == s.substr(j, i))
                cnt++;
            else
            {
                if(cnt > 1)
                    ss += to_string(cnt);
                ss += cut;
                cut = s.substr(j, i);
                cnt = 1;
            }
        }
        
        if(cnt > 1)
            ss += to_string(cnt);
        ss += cut;
        ans = min(ans, (int)ss.length());
    }
    return ans;
}

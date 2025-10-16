#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> ans;
    unordered_map<string, int> m;
    int cnt = 1;
    for(char c = 'A'; c<='Z'; c++)
    {
        string s(1, c);
        m[s] = cnt;
        cnt++;
    }
    
    string s = "", t = "";
    for(int i = 0; i<msg.length();)
    {
        t = s+msg[i];
        if(m.find(t) == m.end())
        {
            m[t] = cnt;
            cnt++;
            ans.push_back(m[s]);
            s = "";
        }
        else
        {
            s = t;
            i++;
        }
    }
    ans.push_back(m[s]);
    
    return ans;
}

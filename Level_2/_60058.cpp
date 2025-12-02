#include <string>
#include <vector>

using namespace std;

bool checkBracket(string& s)
{
    vector<char> v;
    for(char& c : s)
    {
        if(c == '(') v.push_back(c);
        else
        {
            if(v.size()) v.pop_back();
            else return false;
        }
    }
    
    if(v.size()) return false;
    else return true;
}

string dfs(string s)
{
    if(!s.length()) return "";
    
    int a = 0, b = 0;
    string u, v;
    for(int i = 0; i<s.length(); i++)
    {
        if(s[i] == '(') a++;
        else b++;
        
        if(a==b)
        {
            u = s.substr(0, i+1);
            v = s.substr(i+1);
            break;
        }
    }
    
    if(checkBracket(u)) return u + dfs(v);
    else
    {
        u = u.substr(1, u.length()-2);
        for(char& c : u)
            c ^= ('('^')');
        
        return '(' + dfs(v) + ')' + u;
    }
}

string solution(string p) {
    return dfs(p);
}

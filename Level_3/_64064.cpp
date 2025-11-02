#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> ban;

bool check(string& a, string& b)
{
    for(int i = 0; i<a.length(); i++)
    {
        if(b[i] == '*') continue;
        
        if(a[i] != b[i]) return false;
    }
    
    return true;
}

void dfs(vector<string>& uid, vector<string>& bid, int n, int bans)
{
    if(n == bid.size())
    {
        ban.insert(bans);
        return;
    }
    
    for(int i = 0; i<uid.size(); i++)
    {
        if(uid[i].length() != bid[n].length())
            continue;
        
        if(!(bans & (1 << i)) && check(uid[i], bid[n]))
            dfs(uid, bid, n+1, bans|(1<<i));
    }
}

int solution(vector<string> uid, vector<string> bid) {
    dfs(uid, bid, 0, 0);

    return ban.size();
}

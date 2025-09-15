#include <string>
#include <vector>

using namespace std;

int ans;
bool isfind;
char c[5] = {'A', 'E', 'I', 'O', 'U'};

void dfs(string s, string& word)
{
    if (s == word) 
    {
        isfind = true;
        return;
    }

    if (s.length() == 5 || isfind) return;
    
    for (int i = 0; i < 5; i++)
    {
        ans++;
        dfs(s + c[i], word);
        
        if (isfind) return;
    }
}

int solution(string word) {
    dfs("", word);
    
    return ans;
}

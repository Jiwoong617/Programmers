#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int answer = 51;
unordered_map<string, bool> visited;

int cmpStr(string& s1, string& s2)
{
    int n = 0;
    for(int i = 0; i<s1.length(); i++)
    {
        if(s1[i] != s2[i])
            n++;
    }
    
    return n;
}

void dfs(vector<string>& words, string& now, string& target, int cnt)
{
    if(now == target)
    {
        answer = min(answer, cnt);
        return;
    }
    
    for(int i = 0; i<words.size(); i++)
    {
        if(visited[words[i]] || cmpStr(now, words[i]) != 1) continue;
        visited[words[i]] = true;
        dfs(words, words[i], target, cnt+1);
        visited[words[i]]= false;
    }
}

int solution(string begin, string target, vector<string> words) {
    if(find(words.begin(), words.end(), target) == words.end())
        return 0;
    for(string s : words)
        visited[s] = false;

    dfs(words, begin, target, 0);
    
    return answer;
}

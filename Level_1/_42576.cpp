#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> m;
    for(string s : participant)
        m[s]++;
    
    for(string s : completion)
    {
        m[s]--;
        if(m[s] == 0)
            m.erase(s);
    }
    
    
    return m.begin()->first;
}

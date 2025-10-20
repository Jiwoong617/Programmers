#include <string>
#include <vector>
#include <set>

using namespace std;
vector<int> solution(vector<string> operations) {
    multiset<int> m;
    for(string& s : operations)
    {
        if (s[0] == 'I')
            m.insert(stoi(s.substr(2)));
        else
        {
            if(m.empty()) continue;
            
            if (s[2] == '1') m.erase(prev(m.end()));
            else m.erase(m.begin());
        }
    }

    if (m.empty())
        return {0, 0};
    return {*prev(m.end()), *m.begin()};
}

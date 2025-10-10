#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    s = s.substr(2);
    s.erase(remove(s.begin(), s.end(), '}'), s.end());
    
    vector<string> v;
    istringstream iss(s);
    string buf;
    while(getline(iss, buf, '{'))
        v.push_back(buf);
    
    vector<vector<int>> v2;
    for(int i = 0; i<v.size(); i++)
    {
        vector<int> temp;
        istringstream iss2(v[i]);
        while(getline(iss2, buf, ','))
            temp.push_back(stoi(buf));
        
        v2.push_back(temp);
    }
    sort(v2.begin(), v2.end(), [](auto& a, auto& b){
        return a.size() < b.size();
    });
    
    vector<int> ans;
    for(auto& vv : v2)
    {
        for(int i : vv)
        {
            if(find(ans.begin(), ans.end(), i) == ans.end())
                ans.push_back(i);
        }
    }
        
    return ans;
}

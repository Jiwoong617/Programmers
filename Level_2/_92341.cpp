#include <string>
#include <vector>
#include <map>

using namespace std;

int calc(const string& s)
{
    return stoi(s.substr(0,2)) * 60 + stoi(s.substr(3));
}

int fee(vector<int>& f, int n)
{
    if(n <= f[0]) return f[1];
    
    if((n-f[0])%f[2]) return f[1] + ((n-f[0])/f[2] + 1) * f[3];
    
    return f[1] + (n-f[0])/f[2] * f[3];
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> ans;
    map<int, vector<int>> m;
    for(string& s : records)
    {
        int car = stoi(s.substr(6, 4));
        m[car].push_back(calc(s.substr(0,5)));
    }
    
    for(auto& a: m)
    {
        if(a.second.size() & 1) a.second.push_back(1439);
        
        int sum = 0;
        for(int i = 0; i<a.second.size(); i+=2)
            sum += a.second[i+1] - a.second[i];
        
        ans.push_back(fee(fees, sum));
    }
    
    return ans;
}

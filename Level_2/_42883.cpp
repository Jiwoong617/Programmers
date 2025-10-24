#include <string>
#include <vector>

using namespace std;

string solution(string s, int k) {
    vector<char> v;
    for(char c : s)
    {
        while(v.size() && k>0 && v.back() < c)
        {
            v.pop_back();
            k--;
        }
        v.push_back(c);
    }
    
    return string(v.begin(), v.end()-k);
}

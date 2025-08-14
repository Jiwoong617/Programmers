#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, bool> m;
    sort(phone_book.begin(), phone_book.end());
    
    for(string s : phone_book)
    {
        for(int i = 1; i<=s.length(); i++)
        {
            string t = s.substr(0, i);
            if(m.count(t))
                return false;
        }
        
        m.insert(make_pair(s, true));
    }
    
    return answer;
}

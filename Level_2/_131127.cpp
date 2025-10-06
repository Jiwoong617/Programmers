#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int ans = 0;
    unordered_map<string, int> m;
    for(int i = 0; i<10; i++)
        m[discount[i]]++;
    
    for (int i = 0; i<=discount.size()-10; i++)
    {
        bool sign = true;
        for (int j = 0; j < want.size(); j++)
        {
            if (m.find(want[j]) == m.end() || m[want[j]] != number[j])
            {
                sign = false;
                break;
            }
        }

        if (sign)
            ans++;

        if (i + 10 < discount.size()) 
        {
            m[discount[i]]--;
            m[discount[i + 10]]++;
        }
    }
    
    return ans;
}

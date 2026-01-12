#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> combCount;
int maxCount;

void makeComb(string& order, int idx, int cnt, int target, string& current)
{
    if (cnt == target) 
    {
        combCount[current]++;
        maxCount = max(maxCount, combCount[current]);
        return;
    }

    for (int i = idx; i < order.size(); i++)
    {
        current.push_back(order[i]);
        makeComb(order, i + 1, cnt + 1, target, current);
        current.pop_back();
    }
}


vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> ans;
    for (auto& s : orders)
        sort(s.begin(), s.end());
    
    for (int c : course)
    {
        combCount.clear();
        maxCount = 0;

        for (auto& s : orders)
        {
            if (s.size() < c) 
                continue;
            string t = "";
            makeComb(s, 0, 0, c, t);
        }

        if (maxCount>1) 
        {
            for (auto& [menu, cnt] : combCount)
                if (cnt == maxCount)
                    ans.push_back(menu);
        }
    }
    
    sort(ans.begin(), ans.end());
    return ans;
}

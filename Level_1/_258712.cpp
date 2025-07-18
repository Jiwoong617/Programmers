#include <string>
#include <vector>
#include <map>

using namespace std;

//주면 + 받으면 -
int solution(vector<string> friends, vector<string> gifts) {
    int ans = 0;
    map<string, map<string, int>> m;
    map<string, int> gs_m; //선물 지수
    map<string, int> giftStatus; // 받아야할 선물 개수

    for (string s : friends)
    {
        giftStatus[s] = 0;
        for (string ss : friends)
        {
            if (s == ss) continue;
            m[s][ss] = 0;
        }
    }

    for (string s : gifts)
    {
        int pos = s.find(" ");
        string s1 = s.substr(0, pos);
        string s2 = s.substr(pos + 1);
        m[s1][s2]++;
        m[s2][s1]--;
    }

    for (auto a : m)
    {
        int giftScore = 0;
        for (auto g : m[a.first])
            giftScore += g.second;

        gs_m[a.first] = giftScore;
    }

    for (auto a : friends)
    {
        for (auto b : friends)
        {
            if (a == b) continue;

            if (!m[a][b])
            {
                if (gs_m[a] > gs_m[b])
                    giftStatus[a]++;
            }
            else if (m[a][b] > 0)
                giftStatus[a]++;
        }
    }

    for (auto a : giftStatus)
    {
        if (a.second > ans)
            ans = a.second;
    }

    return ans;
}

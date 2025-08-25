#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int len, int w, vector<int> tw) {
    reverse(tw.begin(), tw.end());
    deque<pair<int, int>> q; // w, t
    int time = 0, sum = 0;

    while (!q.empty() || tw.size() > 0)
    {
        for (int i = 0; i < q.size(); i++)
            q[i].second++;

        if (q.size() > 0 && q.front().second == len)
            q.pop_front();

        sum = 0;
        for (auto h : q) sum += h.first;
        if (tw.size() > 0)
        {
            if (sum + tw.back() <= w && q.size() < len)
            {
                q.push_back(make_pair(tw.back(), 0));
                tw.pop_back();
            }
        }

        time++;
    }

    return time;
}

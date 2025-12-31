#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end());
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    int time = 0, total = 0;
    int n = jobs.size(), i = 0;
    while(i<n || !pq.empty())
    {
        while (i<n && jobs[i][0] <= time)
        {
            pq.push({jobs[i][1], jobs[i][0]});
            i++;
        }
        
        if (pq.empty())
        {
            time = jobs[i][0];
            continue;
        }

        pair<int,int> t = pq.top(); pq.pop();
        time += t.first;
        total += time - t.second;
    }
    
    return total/n;
}

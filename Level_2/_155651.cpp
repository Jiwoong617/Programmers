#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int toTime(string& s)
{
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    return h * 60 + m;
}

int solution(vector<vector<string>> bt) {
    vector<pair<int, int>> book;
    
    for (auto& b : bt)
    {
        int start = toTime(b[0]);
        int end = toTime(b[1]);
        book.push_back({start, end + 10});
    }
    
    sort(book.begin(), book.end());
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto& b : book)
    {
        int start = b.first;
        int end = b.second;

        if (!pq.empty() && pq.top() <= start)
            pq.pop();

        pq.push(end);
    }

    return pq.size();
}

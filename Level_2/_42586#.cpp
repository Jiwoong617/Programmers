#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> v;

    for (int i = 0; i<speeds.size(); i++)
    {
        int t = 100 - progresses[i];
        if(t%speeds[i] > 0)
            t = t/speeds[i] + 1;
        else
            t = t/speeds[i];
        
        v.push_back(t);
    }

    int cnt = 1, t = v[0], sum = 0;
    for(int i = 1; i<v.size(); i++)
    {
        if (v[i] <= t)
            cnt++;
        else
        {
            answer.push_back(cnt);
            sum += cnt;
            cnt = 1;
            t = v[i];
        }
    }
    if(sum != v.size())
        answer.push_back(cnt);

    return answer;
}

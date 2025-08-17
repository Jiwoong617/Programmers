#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> totalPlays;
    map<string, vector<pair<int, int>>> songs; //횟수, 인덱스

    for (int i = 0; i < plays.size(); i++) {
        totalPlays[genres[i]] += plays[i];
        songs[genres[i]].push_back(make_pair(plays[i], i));
    }

    vector<pair<string, int>> order(totalPlays.begin(), totalPlays.end());
    sort(order.begin(), order.end(), [](auto& a, auto& b) {
        return a.second > b.second;
        });

    for (auto g : order) {
        vector<pair<int, int>>& vec = songs[g.first];
        sort(vec.begin(), vec.end(), [](auto& a, auto& b) 
            {
                if (a.first == b.first)
                    return a.second < b.second;

                return a.first > b.first;
            });

        for (int i = 0; i < vec.size() && i < 2; i++)
            answer.push_back(vec[i].second);
    }

    return answer;
}

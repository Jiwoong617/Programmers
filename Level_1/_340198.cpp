#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    int max_side = 0;
    for (int i = 0; i < park.size(); i++)
    {
        for (int j = 0; j < park[i].size(); j++)
        {
            if (park[i][j] != "-1") continue;

            int bound = 1;
            bool isPeople = false;
            while (1)
            {
                if (i + bound >= park.size() || j + bound >= park[i].size()) break;
                for (int k = 0; k <= bound; k++)
                {
                    if (park[i + bound][j + k] != "-1") isPeople = true;
                    if (park[i + k][j + bound] != "-1") isPeople = true;
                }

                if (isPeople) break;
                bound++;
            }

            max_side = max(max_side, bound);
        }
    }

    sort(mats.begin(), mats.end());
    for (int i : mats)
    {
        if (i > max_side) break;

        answer = i;
    }

    return answer;
}

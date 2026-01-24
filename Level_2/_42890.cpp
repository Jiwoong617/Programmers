#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<vector<string>> relation) {
    int row = relation.size();
    int col = relation[0].size();
    vector<int> v;

    for (int mask = 1; mask < (1 << col); mask++)
    {
        bool isMin = true;
        for (int key : v)
        {
            if ((key & mask) == key)
            {
                isMin = false;
                break;
            }
        }
        if (!isMin)
            continue;

        set<string> s;
        for (int i = 0; i < row; i++)
        {
            string comb = "";
            for (int j = 0; j < col; j++)
                if (mask & (1 << j)) 
                    comb += relation[i][j] + ",";
            
            s.insert(comb);
        }

        if (s.size() == row) 
            v.push_back(mask);
    }

    return v.size();
}

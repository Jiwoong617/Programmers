#include <string>
#include <vector>

using namespace std;

int dcRate[4] = {10,20,30,40};

void dfs(vector<vector<int>>& u, vector<int>& e, vector<int>& dc, int idx, int& plus, int& money)
{
    if(idx == e.size())
    {
        int curPlus = 0;
        int curMoney = 0;
        
        for(auto& user : u)
        {
            int sum = 0;
            for(int i = 0; i<e.size(); i++)
            {
                if(dc[i] >= user[0])
                    sum+= e[i] * (100-dc[i])/100;
            }
            
            if(sum >= user[1]) curPlus++;
            else curMoney+=sum;
        }

        if(curPlus > plus || (curPlus == plus && curMoney > money))
        {
            plus = curPlus;
            money = curMoney;
        }

        return;
    }
    
    for(int i = 0; i<4; i++)
    {
        dc[idx] = dcRate[i];
        dfs(u, e, dc, idx+1, plus, money);
    }
}

vector<int> solution(vector<vector<int>> u, vector<int> e) {
    int plus = 0, money = 0;
    vector<int> dc(e.size());
    dfs(u, e, dc, 0, plus, money);
    return {plus, money};
}

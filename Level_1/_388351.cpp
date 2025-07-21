#include <string>
#include <vector>

using namespace std;

int timeCalc(int t)
{
    int time_num = 0;
    time_num += (t % 100);
    time_num += ((t/100)*60);
    
    return time_num;
}


int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    vector<int> s;
    for(int i = 0; i<schedules.size(); i++)
        s.push_back(timeCalc(schedules[i] + 10));
    
    for(int i = 0; i<schedules.size(); i++)
    {
        bool isLate = false;
        for(int j = 0; j<7; j++) //날짜
        {
            int day = (startday+j)%7;
            if(day == 0  || day == 6)
                continue;
            
            int t = timeCalc(timelogs[i][j]);
            if(t > s[i])
                isLate = true;
        }
        
        if(!isLate)
            answer++;
    }

    return answer;
}

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int now = 0;
    int* server = new int[24]();
    
    for(int i = 0; i<24; i++)
    {
        if(i - k >= 0)
            now -= server[i-k];
        
        int need = players[i]/m;
        if(now < need)
        {
            server[i] = need-now;
            answer += need-now;
            now += need-now;
        }
    }
    
    return answer;
}

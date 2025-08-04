#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int a[] = { 1, 2, 3, 4, 5};
    int b[] = {2, 1, 2, 3, 2, 4, 2, 5};
    int c[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int cnt[3] = {0,0, 0};
    
    for(int i = 0; i<answers.size(); ++i)
    {
        if(a[i%5] == answers[i])
            cnt[0]++;
        if(b[i%8] == answers[i])
            cnt[1]++;
        if(c[i%10] == answers[i])
            cnt[2]++;
    }
    
    int ans = *max_element(cnt, cnt+3);
    for(int i = 0; i<3; i++)
        if(cnt[i] == ans)
            answer.push_back(i+1);
    
    return answer;
}

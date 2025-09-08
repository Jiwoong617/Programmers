#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int grid = brown+yellow;
    for(int i = brown/4; i<brown; i++)
    {
        if(grid % i == 0 && i >= grid/i && yellow % (i-2) == 0)
        {
            answer.push_back(i);
            answer.push_back(grid/i);
            break;
        }
    }
    
    return answer;
}

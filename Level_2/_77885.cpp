#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> num) {
    vector<long long> ans;
    for(int i = 0; i<num.size(); i++)
    {
        if(num[i] % 2)
        {
            long long n = 2;
            while(true)
            {
                if(n&num[i])
                    n*=2;
                else
                    break;
            }
            ans.push_back(num[i]+n/2);
        }
        else
            ans.push_back(num[i]+1);
    }
    
    return ans;
}

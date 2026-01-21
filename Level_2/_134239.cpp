#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> ans, woobak;
    woobak.push_back(k);
    while(k!=1)
    {
        if(k%2) k = k*3+1;
        else k/=2;
        woobak.push_back(k);
    }
    
    int n = woobak.size();
    vector<double> sum(n, 0);
    for(int i = 1; i<n; i++)
    {
        double size = (woobak[i-1] + woobak[i])/2.0;
        sum[i] = sum[i-1]+size;
    }
    
    for(auto& a: ranges)
    {
        int s = a[0];
        int e = n-1 + a[1];
        
        if(s>e) ans.push_back(-1);
        else ans.push_back(sum[e]-sum[s]);
    }
    
    return ans;
}

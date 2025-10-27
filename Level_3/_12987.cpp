#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int ans = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    for(int i = 0; i<a.size(); i++)
        if(a[ans] < b[i])
            ans++;
        
    return ans;
}

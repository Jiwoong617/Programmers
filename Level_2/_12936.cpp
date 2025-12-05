//시간 초과 - next_permutation 사용

#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    
    k--;
    while(k--)
        next_permutation(v.begin(), v.end());
    return v;
}

//정답

#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> v(n), ans;
    iota(v.begin(), v.end(), 1);
    
    vector<long long> fact(n+1, 1);
    for(int i = 1;i<=n; i++)
        fact[i] = fact[i-1]*i;
    
    k--;
    for (int i = n-1; i >= 0; i--)
    {
        long long idx = k / fact[i];
        k %= fact[i];

        ans.push_back(v[idx]);
        v.erase(v.begin() + idx);
    }
    
    return ans;
}

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int d) {
    vector<int> v;
    for(int i : arr)
        if(!(i%d)) v.push_back(i);
    
    sort(v.begin(), v.end());
    if(!v.size()) v.push_back(-1);
    return v;
}

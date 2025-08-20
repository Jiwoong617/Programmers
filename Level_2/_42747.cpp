#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<int> c) {
    int answer = 0;
    int size = c.size();
    sort(c.begin(), c.end(), greater<int>());
    
    for(int i= 0; i<size; ++i)
    {
        if(i >= c[i])
            return i;
    }
    
    return size;
}

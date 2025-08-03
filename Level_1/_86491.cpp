#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int a = 0, b = 0;
    
    for(int i = 0; i<sizes.size(); i++)
    {
        a = max(a, max(sizes[i][0], sizes[i][1]));
        b = max(b, min(sizes[i][0], sizes[i][1]));
    }
    
    return a*b;
}

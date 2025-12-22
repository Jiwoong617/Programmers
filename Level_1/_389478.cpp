#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int ans = 1;
    int r = (n+w-1)/w;
    int x = (num-1)/w;
    int y = (x%2 ? w-1-(num-1)%w :(num-1)%w);
    
    for(int i = x+1; i<r; i++)
    {
        int rowCount = ((i+1)*w > n ? n - i*w : w);
        int curY = ((i%2 ? w-1-y : y));
        
        if(rowCount > curY) ans++;
    }
    
    return ans;
}

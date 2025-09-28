#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    return (a%b ? gcd(b, a%b) : b);
}

int solution(vector<int> arr) {
    if(arr.size() == 1) return arr[0];
    
    int ans = arr[0]*arr[1]/gcd(arr[0], arr[1]);
    for(int i = 2; i<arr.size(); i++)
        ans = ans*arr[i]/gcd(ans, arr[i]);
    
    return ans;
}

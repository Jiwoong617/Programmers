#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    vector<char> v;
    while(n)
    {
        if(n%3)
            v.push_back(n%3+'0');
        else
        {
            v.push_back('4');
            n--;
        }
        n/=3;
    }
    
    return string(v.rbegin(), v.rend());
}

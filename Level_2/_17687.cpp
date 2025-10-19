#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, int p) {
    string ans = "";
    string temp = "0";
    for(int i = 0; temp.length()<=t*m; i++)
    {
        string s = "";
        int num = i;
        while(num)
        {
            int div = num%n;
            if(div > 9) s += ('A' + div - 10);
            else s += to_string(div);
            num/=n;
        }
        reverse(s.begin(), s.end());
        temp += s;
    }
    
    for(int i = p-1; i<t*m; i+=m)    
        ans += temp[i];
    
    return ans;
}

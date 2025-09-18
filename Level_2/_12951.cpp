#include <string>
#include <vector>

using namespace std;

string solution(string s) {

    if(s[0] > 96 && s[0] < 123)
        s[0] -= 32;
    
    for(int i = 1; i<s.length(); i++)
    {
        if(s[i-1] == ' ')
        {
            if(i && s[i] > 96 && s[i] < 123)
                s[i] -= 32;
        }
        else
        {
            if(s[i] > 64 && s[i] < 91)
                s[i] += 32;
        }
    }
    return s;
}

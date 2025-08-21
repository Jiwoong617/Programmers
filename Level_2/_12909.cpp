#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int n = 0;
    for(char c : s)
    {
        if(c == '(')
            n++;
        else
        {
            if(n <= 0)
                return false;
            else
                n--;
        }
    }
    
    
    return (n != 0 ? false : true);
}

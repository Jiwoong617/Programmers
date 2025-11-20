#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    int l = 9, r = 11;
    string s = "";
    for(int i : numbers)
    {
        if(i == 0) i = 11;
        
        if(i%3 == 1)
        {
            l = i-1;
            s += 'L';
        }
        else if(i%3 == 0)
        {
            r = i-1;
            s += 'R';
        }
        else
        {
            int ld = abs(l/3 - (i-1)/3) + abs(l%3 - (i-1)%3);
            int rd = abs(r/3 - (i-1)/3) + abs(r%3 - (i-1)%3);
            if(ld == rd) 
            {
                if(hand[0] == 'l')
                {
                    l = i-1;
                    s += 'L';
                }
                else
                {
                    r = i-1;
                    s += 'R';
                }
            }
            else if(ld > rd) {s += 'R'; r = i-1;}
            else {s += 'L'; l = i-1;}
        }
    }
    
    return s;
}

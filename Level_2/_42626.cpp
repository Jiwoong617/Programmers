#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> c, int K) {
    multiset<int> s;
    for(int a : c)
        s.insert(a);
    
    for(int i = 0; i<c.size() - 1; i++)
    {
        int a = *s.begin(); s.erase(s.begin());
        int b = *s.begin(); s.erase(s.begin());
        if(a >= K) return i;
        
        s.insert(a + 2*b);
    }
    
    return (*s.begin() >= K ? c.size()-1 : -1);
}

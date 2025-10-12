#include <string>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

int solution(string s1, string s2) {
    transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
    transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
    
    multiset<string> v1, v2;
    for(int i = 0; i<s1.length()-1; i++)
    {
        if(s1[i] < 'A' || s1[i] > 'Z') continue;
        if(s1[i+1] < 'A' || s1[i+1] > 'Z') continue;
        
        v1.insert(s1.substr(i, 2));
    }
    for(int i = 0; i<s2.length()-1; i++)
    {
        if(s2[i] < 'A' || s2[i] > 'Z') continue;
        if(s2[i+1] < 'A' || s2[i+1] > 'Z') continue;
        
        v2.insert(s2.substr(i, 2));
    }
    
    multiset<string> a;
    multiset<string> b;
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), inserter(a, a.begin()));
    set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), inserter(b, b.begin()));
    
    if(b.empty()) return 65536;
    return floor((float)a.size()/(float)b.size()*65536.0f);
}

#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> v(2, 0);
    set<string> s; s.insert(words[0]);
    for(int i = 1; i<words.size(); i++)
    {
        if(words[i-1].back() != words[i].front()
          || !s.insert(words[i]).second)
        {
            v[0] = i%n+1;
            v[1] = i/n+1;
            break;
        }
        
        s.insert(words[i]);
    }
    

    return v;
}

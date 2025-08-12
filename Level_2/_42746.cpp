#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> n;
    for(int i : numbers)
        n.push_back(to_string(i));
    
    sort(n.begin(), n.end(), [](const string& a, const string& b)
         {
             return (b+a) > (a+b);
         });
    
    for(string s : n)
        answer = s + answer;
    
    if(answer[0] == '0')
        answer = "0";
    return answer;
}

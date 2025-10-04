#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int ans = 0;
    int len = s.length();
    
    for(int i = 0; i<len; i++)
    {
        stack<char> st;
        for(int j = i; j<i+len; j++)
        {
            int t = j%len;
            if(s[t] == '[' || s[t] == '(' || s[t] == '{')
                st.push(s[t]);
            else
            {
                if(s[t] == ']' && !st.empty() && st.top() == '[') st.pop();
                else if(s[t] == ')' && !st.empty() && st.top() == '(') st.pop();
                else if(s[t] == '}' && !st.empty() && st.top() == '{') st.pop();
                else 
                {
                    st.push('a');
                    break;
                }
            }
        }
        
        if(st.empty())
            ans++;
    }
    
    return ans;
}

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> v) {
    vector<int> ans(v.size(), -1);
    stack<int> st;
    st.push(0);
    
    for(int i = 1; i<v.size(); i++)
    {
        while(!st.empty() && v[st.top()] < v[i])
        {
            ans[st.top()] = v[i];
            st.pop();
        }
        
        st.push(i);
    }
    
    return ans;
}

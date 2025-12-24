#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

void split(string& s, vector<string>& v)
{
    stringstream ss(s);
    string buffer;
    while(getline(ss, buffer, ' '))
        v.push_back(buffer);    
}

vector<string> solution(vector<string> record) {
    vector<string> command, uid;
    map<string, string> m;  //uid, name
    
    for(string& s : record)
    {
        vector<string> v;
        split(s, v);
        
        switch(v[0][0])
        {
            case 'E':
                m[v[1]] = v[2];
                uid.push_back(v[1]);
                command.push_back("님이 들어왔습니다.");
                break;
            case 'L':
                uid.push_back(v[1]);
                command.push_back("님이 나갔습니다.");
                break;
            case 'C':
                m[v[1]] = v[2];
                break;
        }
    }
    
    for(int i = 0; i<command.size(); i++)
        command[i] = m[uid[i]] + command[i];
    
    return command;
}

#include <string>
#include <set>
#include <sstream>

using namespace std;

string solution(string s) {
    set<int> v;
    istringstream istr(s);
    string str;
    while(getline(istr, str, ' '))
        v.insert(stoi(str));
    
    return to_string(*v.begin()) + " " + to_string(*v.rbegin());
}

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    return string(s.length()-4, '*') + s.substr(s.length()-4);
}

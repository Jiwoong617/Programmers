#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string numToString(long long n)
{
    string s = "";
    while (n)
    {
        n--;
        long long t = n % 26;
        n /= 26;

        char c = 'a' + t;
        s = c + s;
    }

    return s;
}

long long strToNum(string s)
{
    long long n = 0;
    long long cnt = 1;
    for (int i = s.length() -1; i >= 0; --i)
    {
        char c = s[i];
        n += (cnt * (c - 'a' + 1));
        cnt *= 26;
    }

    return n;
}

string solution(long long n, vector<string> bans) {
    vector<long long> v;

    for (string s : bans)
        v.push_back(strToNum(s));

    sort(v.begin(), v.end());
    for (long long num : v)
    {
        if (num <= n) n++;
        else break;
    }

    return numToString(n);
}

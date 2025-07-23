#include <string>
#include <vector>

using namespace std;

int toTime(string s)
{
    int n = 0;
    n += stoi(s.substr(0, 2)) * 60;
    n += stoi(s.substr(3));

    return n;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string ans = "";
    int v_len = toTime(video_len);
    int now = toTime(pos);
    int op = toTime(op_start);
    int ed = toTime(op_end);

    for (auto a : commands)
    {
        if (a == "next")
        {
            if (now <= ed && now >= op)
                now = ed + 10;
            else
            {
                now += 10;
                if (now <= ed && now >= op)
                    now = ed;
            }

            if (now > v_len)
                now = v_len;
        }
        else
        {
            now -= 10;
            if (now <= ed && now >= op)
                now = ed;

            if (now < 0)
                now = 0;
        }
    }

    if(now/60 < 10)
        ans = "0";
    ans += to_string(now / 60) + ":";
    if (now % 60 < 10)
        ans += "0";
    ans += to_string(now % 60);
    return ans;
}

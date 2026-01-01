#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct File
{
    string original;
    string head;
    int number;
};

vector<string> solution(vector<string> files) {
    vector<string> ans;
    vector<File> v;

    for (const string& f : files) {
        int i = 0;
        int n = f.size();

        while (i < n && !isdigit(f[i]))
            i++;
        string head = f.substr(0, i);

        int start = i;
        while (i < n && isdigit(f[i]) && i - start < 5)
            i++;
        int number = stoi(f.substr(start, i - start));

        v.push_back({f, head, number});
    }

    stable_sort(v.begin(), v.end(), [](const File& a, const File& b)
        {
            string ha = a.head, hb = b.head;
            transform(ha.begin(), ha.end(), ha.begin(), ::tolower);
            transform(hb.begin(), hb.end(), hb.begin(), ::tolower);

            if (ha != hb)
                return ha < hb;
            return a.number < b.number;
        });

    for (const auto& f : v)
        ans.push_back(f.original);

    return ans;
}

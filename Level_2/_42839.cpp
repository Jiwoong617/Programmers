#include <string>
#include <vector>
#include <set>

using namespace std;

int maxDeep;
bool visited[8];
set<int> s;

bool checkPrime(int num)
{
    if (num == 2 || num == 3) return true;
    if (num == 0 || num == 1) return false;

    bool isPrime = true;
    for (int i = 2; i * i <= num; i++)
    {
        if (num%i == 0)
        {
            isPrime = false;
            break;
        }
    }

    return isPrime;
}

void dfs(int deep, int num, string& n)
{
    if (checkPrime(num))
        s.insert(num);

    if (deep == maxDeep)
        return;

    for (int i = 0; i < maxDeep; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            dfs(deep + 1, num * 10 + (n[i] - '0'), n);
            visited[i] = false;
        }
    }

}

int solution(string numbers) {
    maxDeep = numbers.length();

    for (int i = 0; i < maxDeep; i++)
    {
        if (numbers[i] - '0' != 0)
        {
            visited[i] = true;
            dfs(1, numbers[i] - '0', numbers);
            visited[i] = false;
        }
    }

    return s.size();
}

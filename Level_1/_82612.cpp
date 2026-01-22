using namespace std;
#include <algorithm>

long long solution(int price, int money, int count)
{
    long long answer = 0;
    for(long long i = 1; i<=count; i++)
        answer += price*i;

    return max(0LL, answer - money);
}

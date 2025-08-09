#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> a;
    a.push_back(arr[0]);
    for(int i = 1; i<arr.size(); i++)
        if(a.back() != arr[i])
            a.push_back(arr[i]);

    return a;
}

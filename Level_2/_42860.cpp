#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int n = name.length();
    int ud = 0;
    int lr = n-1;

    for(int i = 0; i<n; i++)
    {
        char c = name[i];
        ud += min(c-'A', 'Z'-c+1);
        
        int j = i+1;
        while(name[j] == 'A')
            j++;
        
        lr = min(lr, min(n-j+i*2, (n-j)*2+i));
    }
    
    return ud+lr;
}_

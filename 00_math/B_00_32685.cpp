#include<iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c;
    cin >> a >> b>> c;
    // 16은 1<<4와 같다.
    a%=16;
    b%=16;
    c%=16;
    int result = a*16*16+b*16+c;
    
    if(result > 1000)
        cout << result << "\n";
    else if(result > 100)
        cout << 0 << result << "\n";    
    else if(result > 10)
        cout << 0 << 0 << result << "\n";
    else
        cout << 0 << 0 << 0 << result << "\n";
        
}
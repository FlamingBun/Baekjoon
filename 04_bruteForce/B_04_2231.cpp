#include<iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    int ans = 0;
    for(int i=1; i<n; i++)
    {
        int value = i;
        int sum = value;
        while(value != 0)
        {
            sum += value%10;
            value /= 10;
        }
        if(sum == n)
        {
            ans = i;
            break;
        }
    }
    
    cout << ans << "\n";
}
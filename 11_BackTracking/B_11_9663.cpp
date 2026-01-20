#include<iostream>
using namespace std;

int n;

int isused1[40];
int isused2[40];
int isused3[40];

int cnt = 0;

void func(int x)
{
    if(x == n)
    {
        cnt++;
        return;
    }
    
    for(int y=0; y<n; y++)
    {
        if(isused1[y]||isused2[x+y]||isused3[x-y+n-1]) continue;
        
        isused1[y] = 1;
        isused2[x+y] = 1;
        isused3[x-y+n-1] = 1;
        
        func(x+1);
        
        isused1[y] = 0;
        isused2[x+y] = 0;
        isused3[x-y+n-1] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    func(0);

    cout << cnt << '\n';
}
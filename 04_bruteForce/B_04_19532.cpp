#include<iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a,b,c,d,e,f;
    
    cin >> a >> b >> c>> d>> e>>f;

    int y = (c*d - f*a) / ((b*d) - (e*a));
        
    int x = (c*e - f*b) / ((a*e)-(d*b));
    
    cout << x << " " << y << "\n";
}
#include<iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string a, b, c;

    cin >> a >> b >> c;
    
    int an = stoi(a);
    int bn = stoi(b);
    int cn = stoi(c);
    
    cout << an + bn - cn << "\n";
    
    int abn = stoi(a+b);
    
    cout << abn - cn << "\n";
    
}
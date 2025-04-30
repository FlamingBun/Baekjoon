#include<iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    string s;
    int r;
    cin >> t;
    
    for(int i=0; i<t; i++)
    {
        cin >> r >> s;
        int cnt = s.length();
    
        for(int j=0; j<cnt; j++)
        {
            for(int k=0; k<r; k++)
            {
                cout << s[j];   
            }
        }
        cout << "\n";
    }   
}
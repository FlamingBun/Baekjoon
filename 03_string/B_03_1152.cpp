#include<iostream>
#include<string>
using namespace std;

string trim(string str)
{
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') +1);
    return str;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    getline(cin, s);
    s = trim(s);
    
    int len = s.length();
    int cnt = 1;
    
    if(len == 1 && s[0] == ' ')
    {
        cout << 0 << "\n";
        return 0;
    }
    
    for(int i=0; i< len; i++)
    {
            if(s[i] == ' ') cnt++;
    }
    cout << cnt << "\n";
}
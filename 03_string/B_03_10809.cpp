#include<iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    cin >> s;
    
    int alpha[26];
    // fill_n(배열 포인터, 초기화 길이, 초기화 값)
    // 배열을 같은 값으로 초기화할 때 사용하는 함수다.
    // 초기화 길이 이후에는 쓰레기 값이 들어간다.
    fill_n(alpha, 26, -1);
    
    for(int i=0; i < s.length(); i++)
    {
        int idx = s[i] - 'a';
        if(alpha[idx] == -1)
        {
            alpha[idx] = i;
        }
    }
    
    for(int i=0; i < 26; i++)
    {
        cout << alpha[i] << " ";
    }
}
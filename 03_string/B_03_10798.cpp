#include<iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    char arr[5][15];

    // 문자열 초기화할 때 이중 배열이면 다음과 같이 &arr[0][0]로 주소값에 접근
    // fill(배열 포인터, 원하는 범위의 끝 주소, 초기화 값)
    fill(&arr[0][0],&arr[0][0]+(5*15),'-');

    string s;
    int maxLen = 0;
    
    for(int i=0; i<5; i++)
    {
        cin >> s;
        int len = s.length();
        if(len > maxLen) maxLen = len;
        for(int j=0; j< len; j++)
        {
            arr[i][j] = s[j];
        }
    }
    
    string ans = "";
    for(int i=0; i<maxLen; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(arr[j][i] != '-')ans += arr[j][i];
        }
    }
    
    cout << ans << "\n";
}
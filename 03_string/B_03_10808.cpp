#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    // 배열 초기화
    int arr[26];
    
    fill(arr, arr+26, 0);
    
    string s;
    
    cin >> s;
    
    for(char e : s)
    {
        int index = e - 'a';
        arr[index]++;
    }
    
    for(int e : arr)
    {
        cout << e << ' ';
    }
}
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    int n;
    cin >> n;
    int a[1001];
    
    for(int i=0; i<n; i++)
    {
         cin >> a[i];   
    }
    // sort함수로 배열을 정렬할 때 a, a+n 처럼 배열의 주소값을 매개변수로 넘겨줘야한다.
    sort(a, a+n);
    
    for(int i=0; i<n; i++)
    {
        cout << a[i] << "\n";
    }
}
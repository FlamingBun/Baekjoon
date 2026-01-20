#include<iostream>
using namespace std;

// 한 변의 점의 개수는 "나누기 전의 점의 개수 * 2 - 1"이고
// 전체 점의 개수는 "한 변의 점의 개수의 제곱"이다.

int main()
{
    int n;
    cin >> n;

    int c=2;
    for(int i=0; i<n; i++)
    {
        c=c*2-1; // 한 변의 점의 개수 변화
    }

    cout << c*c << "\n";
}
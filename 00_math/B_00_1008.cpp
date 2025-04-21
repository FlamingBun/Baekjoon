#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a,b;
    cin >> a >> b;
    double c=  (double)a/(double)b;
    //  precision(n): 정수자리를 포함한 실수 전체 자리수를 n자리로 표현 
    //  소수점 아래로만 고정하고 싶은 경우 fixed를 사용
    cout.precision(10);
    cout << fixed;
    cout << c << "\n";
}
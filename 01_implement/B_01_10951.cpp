#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    // 1. 테스트 케이스 개수를 모를 때 "while(cin >> a >> b)"
    // cin이 조건식에 있으면 bool값이 반환

    // 2. while(!(cin >> a >> b).eof()) 
    // cin으로 읽기 시도를 한 후 eof()검사를 하는 방법이 있다.
    while(cin >> a >> b)
    {
        cout << a + b << "\n";
    }
}
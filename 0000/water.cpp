#include <iostream>
#include <vector>

using namespace std;

// tx, ty : 토템 좌표
// t : 시간 (분)
vector<pair<int,int>> water_range(int x, int y, int t) {
    vector<pair<int,int>> range;
    for (int i = -t; i <= t; i++) {
        for (int j = -t; j <= t; j++) {
            if (abs(i) + abs(j) <= t) {
                range.push_back({x + i, y + j});
            }
        }
    }
    return range;
}

int main() {
    int tx = 0, ty = 0; // 기준 좌표
    int t = 2;

    auto res = water_range(tx, ty, t);

    cout << "물 토템 " << t << "분 뒤 영역:\n";
    for (auto &p : res) {
        cout << "[" << p.first << "," << p.second << "] ";
    }
    cout << "\n";

    return 0;
}
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int x, y;
vector<vector<char>> v;

void init() {
    cout << "Enter number of rows:" << endl;
    cin >> x;
    cout << "Enter number of cols:" << endl;
    cin >> y;
    v.resize(x);
    for (int i = 0; i < x; i++)
        v[i].resize(y);

    cout << "Enter the board: " << endl;
    cout << "(B for block, T for target, space for empty, and * for wall" << endl;
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            cin >> v[i][j];
}

int main(void) {
    init();
}
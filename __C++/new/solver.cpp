#include <bits/stdc++.h>

using namespace std;

// variables
int n, m;
vector<vector<char>> vec; // only asterisks and dashes

void init() {
    // get dimensions
    cout << "Enter dimensions:" << endl;
    cin >> n >> m;

    // resize vector
    vec.resize(n);
    for (int i = 0; i < n; i++)
        vec[i].resize(m);

    // initialize
    cout << "Enter map ('-' for nothing, '0' for block, 'X' for target, and '#' for wall):" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> vec[i][j];
}

void solve() {
}

int main(void) {
    init();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}
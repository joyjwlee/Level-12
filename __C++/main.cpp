#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int x, y;
vector<vector<char> > v;

void init() {
    cout << "Enter number of rows:" << endl;
    cin >> x;
    cout << "Enter number of cols:" << endl;
    cin >> y;
    v.resize(x);
    for (int i = 0; i < x; i++)
        v[i].resize(y);

    cout << "Enter the board: " << endl;
    cout << "(B for block, T for target, . for empty, and * for wall" << endl;
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            cin >> v[i][j];
}

string vToS(vector<vector<char> > vec) {
    string str = "";
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            str += vec[i][j];
    return str;
}

vector<vector<char> > sToV(string str) {
    //
}

int main(void) {
    init();
    cout << "\nBoard:\n";
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
    cout << "\n"
         << vToS(v);
}

/*
*...*
.....
B.T.B
.....
*...*
*/
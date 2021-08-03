#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <map>

using namespace std;

int x, y; // dimensions
vector<vector<char> > v; // initial state
set<string> s; // stores visited states
map<string, string> m; // stores parents

// initialize x, y, and v
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

// convert vector to string
string vToS(vector<vector<char> > vec) {
    string str = "";
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            str += vec[i][j];
    return str;
}

// convert string to vector
vector<vector<char> > sToV(string str) {
    vector<vector<char> > vec(x, vector<char>(y));
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            vec[i][j] = str[i * x + j];
    return vec;
}

int main(void) {
    init();

    /*
    cout << "\nBoard:\n";
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
    cout << vToS(v) << endl;

    v = sToV(vToS(v));
    cout << "\nBoard:\n";
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
    */
}

/*
*...*
.....
B.T.B
.....
*.B.*
*/
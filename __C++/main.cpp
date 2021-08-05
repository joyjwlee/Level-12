#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

int x, y;                      // dimensions
vector<vector<char> > v;        // initial state
vector<int> targets;           // stores indices of T's
set<string> s;                 // stores visited states
map<string, string> m;         // stores parents
string starting, ending, curr; // starting, ending, and current states
queue<string> q;               // queue for bfs

// initialize x, y, v, and targets
void init() {
    // x and y
    cout << "Enter number of rows:" << endl;
    cin >> x;
    v.resize(x);
    cout << "Enter number of cols:" << endl;
    cin >> y;
    for (int i = 0; i < x; i++)
        v[i].resize(y);

    // v and targets
    cout << "Enter the board: " << endl;
    cout << "(B for block, T for target, . for empty, and * for wall" << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> v[i][j];
            // store indices for T
            if (v[i][j] == 'T')
                targets.push_back(i * x + j);
        }
    }
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

// return true is current state is answer (no T's left)
bool isAns(string str) {
    // keep track of indices of blocks
    set<int> indices;
    for (int i = 0; i < str.size(); i++)
        if (str[i] == 'B')
            indices.insert(i);

    // loop through all values in targets
    for (int i : targets)
        // if target is not covered
        if (indices.find(i) == indices.end())
            return false;

    // otherwise solution
    return true;
}

// bfs to find answer
void bfs() {
    // save starting state
    starting = vToS(v);

    // mark root as visited and enqueue
    s.insert(starting);
    q.push(starting);

    // bfs
    while (!q.empty()) {
        // get current
        curr = q.front();
        q.pop();

        // if we found answer
        if (isAns(curr)) {
            ending = curr;
            break;
        }

        // otherwise loop through next states
        // TODO 2
    }
}

int main(void) {
    init();
    bfs();

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
// level 12 -- where it all started
*...*
.....
B.T.B
.....
*.B.*
*/
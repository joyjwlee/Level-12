#include <bits/stdc++.h>

using namespace std;

vector< pair<int,int> > state; ///Has three pairs, each indicating a block
pair<int,int> one, two, three; ///Each one is a block
queue< vector< pair<int,int> > > q;
map<int, int> visited; ///State, Visited or not
map<int, int>::iterator itr;

void traverseMap () {
    cout << "\n===map===\n";
    for (itr = visited.begin(); itr != visited.end(); itr++) {
        cout << itr->first << " " << itr->second << endl;
    }
}

int getIndex (int r, int c) { ///From coordinates
    if (r == 0) return c-1;
    if (1 <= r && r <= 3) return 5*r+c-2;
    return 17+c;
}

pair<int,int> getCoordinate (int index) { ///From index
    pair<int,int> pos;
    if (0 <= index && index <= 2) {
        pos.first = 0;
        pos.second = index+1;
    } else if (3 <= index && index <= 17) {
        pos.first = (index+2)/5;
        pos.second = index+2-5*pos.first;
    } else {
        pos.first = 4;
        pos.second = index-17;
    }
    return pos;
}

int getVisitedIndex (int r1, int c1, int r2, int c2, int r3, int c3) {
    int pow1 = pow (2, getIndex(r1,c1) );
    int pow2 = pow (2, getIndex(r2,c2) );
    int pow3 = pow (2, getIndex(r3,c3) );
    return pow1+pow2+pow3;
}

int main(void) {
    ///Initialize the vector
    int r1 = 2, c1 = 0, r2 = 2, c2 = 4, r3 = 4, c3 = 2;
    one = make_pair(r1,c1); two = make_pair(r2,c2); three = make_pair(r3,c3);
    state.push_back(one); state.push_back(two); state.push_back(three);

    ///Run the BFS
    q.push(state);
    visited[ getVisitedIndex(r1,c1,r2,c2,r3,c3) ]++;
    while (!q.empty()) {
        //
    }
    /*
    cout << "coordinates to index: " << endl;
    cout << getIndex(r1,c1) << endl;
    cout << getIndex(r2,c2) << endl;
    cout << getIndex(r3,c3) << endl;
    cout << "index to coordinates: " << endl;
    for (int i = 0; i <= 20; i++) {
        pair<int,int> coords = getCoordinate(i);
        cout << "i:\t" << i << "\t" << coords.first << "\t" << coords.second << endl;
    }
    cout << getVisitedIndex(r1,c1,r2,c2,r3,c3);
    traverseMap();
    */
}


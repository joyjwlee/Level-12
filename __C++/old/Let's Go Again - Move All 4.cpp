#include <bits/stdc++.h>

using namespace std;

int maxReach, currStateIndex, backTrack;
vector<int> backTrackInd;
map<int,int> visited; ///Keep track if visited or not
map<int,int> parent; ///index, parent index (set first to -1)
map<int, int>::iterator itr;

struct state {
    pair<int,int> one, two, three;
};
queue<state> q;

void traverseBackTrack () {
    cout << "\n===BackTrack Index===\n";
    while (parent[backTrack] != -1) {
        backTrackInd.push_back(backTrack);
        backTrack = parent[backTrack];
    }
    backTrackInd.push_back(528640);
    for (int i = 0; i < backTrackInd.size(); i++)
        cout << backTrackInd[i] << endl;
}

void traverseVisitedMap () {
    cout << "\n===Visited Map===\n";
    for (itr = visited.begin(); itr != visited.end(); itr++) {
        cout << itr->first << " " << itr->second << endl;
    }
}

void traverseParentMap () {
    cout << "\n===Parent Map===\n";
    for (itr = parent.begin(); itr != parent.end(); itr++) {
        cout << "this one: " << itr->first << " and parent: " << itr->second << endl;
    }
}

///When reading index, convert to binary, count starting from 0 from the right side; # is location in grid
int gridIndex (int r, int c) { ///From single block's coordinates
    if (r == 0) return c-1;
    if (1 <= r && r <= 3) return 5*r+c-2;
    return 17+c;
}

int stateIndex (int r1, int c1, int r2, int c2, int r3, int c3) { ///From all 3 blocks
    int pow1 = pow (2, gridIndex(r1,c1) );
    int pow2 = pow (2, gridIndex(r2,c2) );
    int pow3 = pow (2, gridIndex(r3,c3) );
    return pow1+pow2+pow3;
}

pair<int,int> getCoordinate (int index) { ///From index, basically undoes gridIndex
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


int main(void) {
    ///Starting coordinates
    int r1 = 2, c1 = 0, r2 = 2, c2 = 4, r3 = 4, c3 = 2;

    ///Run the BFS
    q.push( state{ make_pair(r1,c1), make_pair(r2,c2), make_pair(r3,c3) } );
    visited[ stateIndex(r1,c1,r2,c2,r3,c3) ]++;
    parent[ stateIndex(r1,c1,r2,c2,r3,c3) ] = -1;
    while (!q.empty()) {
        ///Get front data, extract, and pop
        state Curr = q.front(); q.pop();
        pair<int,int> a = Curr.one;
        r1 = a.first; c1 = a.second;
        pair<int,int> b = Curr.two;
        r2 = b.first; c2 = b.second;
        pair<int,int> c = Curr.three;
        r3 = c.first; c3 = c.second;
        currStateIndex = stateIndex(r1,c1,r2,c2,r3,c3);

        ///If any of them in the middle, break and output
        if ( (a.first == 2) && (a.second == 2) ) {
            backTrack = currStateIndex;
            cout << "ANSWER INDEX: " << currStateIndex;
            break;
        }
        if ( (b.first == 2) && (b.second == 2) ) {
            backTrack = currStateIndex;
            cout << "ANSWER INDEX: " << currStateIndex;
            break;
        }
        if ( (c.first == 2) && (c.second == 2) ) {
            backTrack = currStateIndex;
            cout << "ANSWER INDEX: " << currStateIndex;
            break;
        }

        ///Move each in the four directions
        ///Move 1
            ///Up
            maxReach = 0;
            //If in first or last column, maxReach becomes 1
            if (a.second == 0 || a.second == 4) maxReach = 1;
            //If 2 is in the way; both same column
            if (a.second == b.second) {
                if (a.first > b.first) maxReach = max(maxReach,b.first+1);
            }
            //If 3 is in the way; both same column
            if (a.second == c.second) {
                if (a.first > c.first) maxReach = max(maxReach,c.first+1);
            }
            //Push if not visited, mark as visited and label parent
            if (!visited[ stateIndex(maxReach,c1,r2,c2,r3,c3) ]) {
                visited[ stateIndex(maxReach,c1,r2,c2,r3,c3) ]++;
                q.push( state{ make_pair(maxReach,c1), make_pair(r2,c2), make_pair(r3,c3) } );
                parent[ stateIndex(maxReach,c1,r2,c2,r3,c3) ] = currStateIndex;
            }
            ///Down
            maxReach = 4;
            //If in first or last column, maxReach becomes 3
            if (a.second == 0 || a.second == 4) maxReach = 3;
            //If 2 is in the way; both same column
            if (a.second == b.second) {
                if (a.first < b.first) maxReach = min(maxReach,b.first-1);
            }
            //If 3 is in the way; both same column
            if (a.second == c.second) {
                if (a.first < c.first) maxReach = min(maxReach,c.first-1);
            }
            //Push if not visited, mark as visited and label parent
            if (!visited[ stateIndex(maxReach,c1,r2,c2,r3,c3) ]) {
                visited[ stateIndex(maxReach,c1,r2,c2,r3,c3) ]++;
                q.push( state{ make_pair(maxReach,c1), make_pair(r2,c2), make_pair(r3,c3) } );
                parent[ stateIndex(maxReach,c1,r2,c2,r3,c3) ] = currStateIndex;
            }
            ///Left
            maxReach = 0;
            //If in first or last row, maxReach becomes 1
            if (a.first == 0 || a.first == 4) maxReach = 1;
            //If 2 is in the way; both same row
            if (a.first == b.first) {
                if (a.second > b.second) maxReach = max(maxReach,b.second+1);
            }
            //If 3 is in the way; both same row
            if (a.first == c.first) {
                if (a.second > c.second) maxReach = max(maxReach,c.second+1);
            }
            //Push if not visited, mark as visited and label parent
            if (!visited[ stateIndex(r1,maxReach,r2,c2,r3,c3) ]) {
                visited[ stateIndex(r1,maxReach,r2,c2,r3,c3) ]++;
                q.push( state{ make_pair(r1,maxReach), make_pair(r2,c2), make_pair(r3,c3) } );
                parent[ stateIndex(r1,maxReach,r2,c2,r3,c3) ] = currStateIndex;
            }
            ///Right
            maxReach = 4;
            //If in first or last row, maxReach becomes 3
            if (a.first == 0 || a.first == 4) maxReach = 3;
            //If 2 is in the way; both same row
            if (a.first == b.first) {
                if (a.second < b.second) maxReach = min(maxReach,b.second-1);
            }
            //If 3 is in the way; both same row
            if (a.first == c.first) {
                if (a.second < c.second) maxReach = min(maxReach,c.second-1);
            }
            //Push if not visited, mark as visited and label parent
            if (!visited[ stateIndex(r1,maxReach,r2,c2,r3,c3) ]) {
                visited[ stateIndex(r1,maxReach,r2,c2,r3,c3) ]++;
                q.push( state{ make_pair(r1,maxReach), make_pair(r2,c2), make_pair(r3,c3) } );
                parent[ stateIndex(r1,maxReach,r2,c2,r3,c3) ] = currStateIndex;
            }
        ///Move 2
            ///Up
            maxReach = 0;
            //If in first or last column, maxReach becomes 1
            if (b.second == 0 || b.second == 4) maxReach = 1;
            //If 2 is in the way; both same column
            if (b.second == a.second) {
                if (b.first > a.first) maxReach = max(maxReach,a.first+1);
            }
            //If 3 is in the way; both same column
            if (b.second == c.second) {
                if (b.first > c.first) maxReach = max(maxReach,c.first+1);
            }
            //Push if not visited, mark as visited and label parent
            if (!visited[ stateIndex(r1,c1,maxReach,c2,r3,c3) ]) {
                visited[ stateIndex(r1,c1,maxReach,c2,r3,c3) ]++;
                q.push( state{ make_pair(r1,c1), make_pair(maxReach,c2), make_pair(r3,c3) } );
                parent[ stateIndex(r1,c1,maxReach,c2,r3,c3) ] = currStateIndex;
            }
            ///Down
            maxReach = 4;
            //If in first or last column, maxReach becomes 3
            if (b.second == 0 || b.second == 4) maxReach = 3;
            //If 2 is in the way; both same column
            if (b.second == a.second) {
                if (b.first < a.first) maxReach = min(maxReach,a.first-1);
            }
            //If 3 is in the way; both same column
            if (b.second == c.second) {
                if (b.first < c.first) maxReach = min(maxReach,c.first-1);
            }
            //Push if not visited, mark as visited and label parent
            if (!visited[ stateIndex(r1,c1,maxReach,c2,r3,c3) ]) {
                visited[ stateIndex(r1,c1,maxReach,c2,r3,c3) ]++;
                q.push( state{ make_pair(r1,c1), make_pair(maxReach,c2), make_pair(r3,c3) } );
                parent[ stateIndex(r1,c1,maxReach,c2,r3,c3) ] = currStateIndex;
            }
            ///Left
            maxReach = 0;
            //If in first or last row, maxReach becomes 1
            if (b.first == 0 || b.first == 4) maxReach = 1;
            //If 2 is in the way; both same row
            if (b.first == a.first) {
                if (b.second > a.second) maxReach = max(maxReach,a.second+1);
            }
            //If 3 is in the way; both same row
            if (b.first == c.first) {
                if (b.second > c.second) maxReach = max(maxReach,c.second+1);
            }
            //Push if not visited, mark as visited and label parent
            if (!visited[ stateIndex(r1,c1,r2,maxReach,r3,c3) ]) {
                visited[ stateIndex(r1,c1,r2,maxReach,r3,c3) ]++;
                q.push( state{ make_pair(r1,c1), make_pair(r2,maxReach), make_pair(r3,c3) } );
                parent[ stateIndex(r1,c1,r2,maxReach,r3,c3) ] = currStateIndex;
            }
            ///Right
            maxReach = 4;
            //If in first or last row, maxReach becomes 3
            if (b.first == 0 || b.first == 4) maxReach = 3;
            //If 2 is in the way; both same row
            if (b.first == a.first) {
                if (b.second < a.second) maxReach = min(maxReach,a.second-1);
            }
            //If 3 is in the way; both same row
            if (b.first == c.first) {
                if (b.second < c.second) maxReach = min(maxReach,c.second-1);
            }
            //Push if not visited, mark as visited and label parent
            if (!visited[ stateIndex(r1,c1,r2,maxReach,r3,c3) ]) {
                visited[ stateIndex(r1,c1,r2,maxReach,r3,c3) ]++;
                q.push( state{ make_pair(r1,c1), make_pair(r2,maxReach), make_pair(r3,c3) } );
                parent[ stateIndex(r1,c1,r2,maxReach,r3,c3) ] = currStateIndex;
            }

        ///Move 3
            ///Up
            maxReach = 0;
            //If in first or last column, maxReach becomes 1
            if (c.second == 0 || c.second == 4) maxReach = 1;
            //If 2 is in the way; both same column
            if (c.second == b.second) {
                if (c.first > b.first) maxReach = max(maxReach,b.first+1);
            }
            //If 3 is in the way; both same column
            if (c.second == a.second) {
                if (c.first > a.first) maxReach = max(maxReach,a.first+1);
            }
            //Push if not visited, mark as visited and label parent
            if (!visited[ stateIndex(r1,c1,r2,c2,maxReach,c3) ]) {
                visited[ stateIndex(r1,c1,r2,c2,maxReach,c3) ]++;
                q.push( state{ make_pair(r1,c1), make_pair(r2,c2), make_pair(maxReach,c3) } );
                parent[ stateIndex(r1,c1,r2,c2,maxReach,c3) ] = currStateIndex;
            }
            ///Down
            maxReach = 4;
            //If in first or last column, maxReach becomes 3
            if (c.second == 0 || c.second == 4) maxReach = 3;
            //If 2 is in the way; both same column
            if (c.second == b.second) {
                if (c.first < b.first) maxReach = min(maxReach,b.first-1);
            }
            //If 3 is in the way; both same column
            if (c.second == a.second) {
                if (c.first < a.first) maxReach = min(maxReach,a.first-1);
            }
            //Push if not visited, mark as visited and label parent
            if (!visited[ stateIndex(r1,c1,r2,c2,maxReach,c3) ]) {
                visited[ stateIndex(r1,c1,r2,c2,maxReach,c3) ]++;
                q.push( state{ make_pair(r1,c1), make_pair(r2,c2), make_pair(maxReach,c3) } );
                parent[ stateIndex(r1,c1,r2,c2,maxReach,c3) ] = currStateIndex;
            }
            ///Left
            maxReach = 0;
            //If in first or last row, maxReach becomes 1
            if (c.first == 0 || c.first == 4) maxReach = 1;
            //If 2 is in the way; both same row
            if (c.first == b.first) {
                if (c.second > b.second) maxReach = max(maxReach,b.second+1);
            }
            //If 3 is in the way; both same row
            if (c.first == a.first) {
                if (c.second > a.second) maxReach = max(maxReach,a.second+1);
            }
            //Push if not visited, mark as visited and label parent
            if (!visited[ stateIndex(r1,c1,r2,c2,r3,maxReach) ]) {
                visited[ stateIndex(r1,c1,r2,c2,r3,maxReach) ]++;
                q.push( state{ make_pair(r1,c1), make_pair(r2,c2), make_pair(r3,maxReach) } );
                parent[ stateIndex(r1,c1,r2,c2,r3,maxReach) ] = currStateIndex;
            }
            ///Right
            maxReach = 4;
            //If in first or last row, maxReach becomes 3
            if (c.first == 0 || c.first == 4) maxReach = 3;
            //If 2 is in the way; both same row
            if (c.first == b.first) {
                if (c.second < b.second) maxReach = min(maxReach,b.second-1);
            }
            //If 3 is in the way; both same row
            if (c.first == a.first) {
                if (c.second < a.second) maxReach = min(maxReach,a.second-1);
            }
            //Push if not visited, mark as visited and label parent
            if (!visited[ stateIndex(r1,c1,r2,c2,r3,maxReach) ]) {
                visited[ stateIndex(r1,c1,r2,c2,r3,maxReach) ]++;
                q.push( state{ make_pair(r1,c1), make_pair(r2,c2), make_pair(r3,maxReach) } );
                parent[ stateIndex(r1,c1,r2,c2,r3,maxReach) ] = currStateIndex;
            }
    }

    ///Backtrack...
    traverseBackTrack();

    //traverseVisitedMap();
    //traverseParentMap();
}

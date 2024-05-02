#include <iostream>
#include <vector>

using namespace std;

bool isEulerian(int V, vector<vector<int> >& adj) {
    int oddDegreeVertices = 0;
    for (int i = 0; i < V; i++) {
        if (adj[i].size() % 2 != 0) {
            oddDegreeVertices++;
        }
    }

    if (oddDegreeVertices == 0 || oddDegreeVertices == 2) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int> > adj(V);

    for (int i = 0; i < E; i++) {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    if (isEulerian(V, adj)) {
        cout << "The graph is Eulerian." << endl;
    } else {
        cout << "The graph is not Eulerian." << endl;
    }

    return 0;
}

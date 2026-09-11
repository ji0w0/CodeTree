#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> graph;

bool visited[1000];
int result = 0;

void DFS(int vertex) {
    for(int i = 0; i < graph[vertex].size(); i++) {
        int curr_v = graph[vertex][i];
        if(!visited[curr_v])
        {
            result++;
            visited[curr_v] = true;
            DFS(curr_v);
        }
    }
}

int main() {
    cin >> n >> m;
    graph.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    visited[1] = true;
    DFS(1);

    cout << result;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

template<typename T>
class Graph {


    map<T , list<T> > mp;
public:
    void addEdge(T x, T y) {
        mp[x].push_back(y);
    }

    int bfs(T src, T dest) {

        queue<T> q;
        map<T, int> dist;

        for(auto node_pair : mp) {
            dist[node_pair.first] = INT_MAX;
        }
        q.push(src);
        dist[src] = 0;

        while(!q.empty()) {
            
            T node = q.front();
            for(auto x : mp[node]) {
                if(dist[x] == INT_MAX) {
                    q.push(x);
                    dist[x] = dist[node] + 1;
                }
            }
            q.pop();
        }

            //un comment code below to get more clarity.
        // for(auto node_pair : mp) {
           
        //    int node = node_pair.first;
        //    cout << node << "-->";
        //    for(auto y : mp[node]) {
        //        cout << y << " ";
        //    }
        //    cout << endl;
        // }

        return dist[dest];
    }

};
int main() {

    int board[50] = {0};


    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;

    Graph<int> g;

    for(int i=0;i<=36;i++) {
        for(int dice=1;dice<=6;dice++) {
            int j = i + dice;
            j+=board[j];

            if(j<=36)
                g.addEdge(i,j);
        }
    }
    g.addEdge(36,36);

    cout << g.bfs(0,36);   

    return 0;
}

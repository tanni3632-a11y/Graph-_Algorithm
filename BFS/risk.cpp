#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;  
    while (true) {
        vector<vector<int>> g(21); 
        int x;

       
        if (!(cin >> x)) return 0;  

     
        for (int i = 1; i <= 19; i++) {
            if (i != 1) cin >> x;  
            for (int j = 0; j < x; j++) {
                int v;
                cin >> v;
                g[i].push_back(v);
                g[v].push_back(i);
            }
        }

        int N;
        cin >> N;

        cout << "Test Set #" << T++ << "\n";

        while (N--) {
            int A, B;
            cin >> A >> B;

         
            queue<int> q;
            vector<int> dist(21, -1);
            dist[A] = 0;
            q.push(A);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : g[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }

            cout << setw(2) << A << " to "
                 << setw(2) << B << ": "
                 << dist[B] << "\n";
        }

        cout << "\n";  
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Lab Solution: Bicoloring Problem
Author: Your Name
*/

int main() {
    int n1 = 3;
    vector<pair<int,int>> edges1 = {{0,1},{1,2},{2,0}};
    int n2 = 3;
    vector<pair<int,int>> edges2 = {{0,1},{1,2}};
    int n3 = 9;
    vector<pair<int,int>> edges3 = {{0,1},{0,2},{0,3},{0,4},{0,5},{0,6},{0,7},{0,8}};

    vector<int> ns = {n1,n2,n3};
    vector<vector<pair<int,int>>> allEdges = {edges1, edges2, edges3};

    for(int t=0;t<3;t++){
        int n = ns[t];
        auto edges = allEdges[t];
        vector<vector<int>> g(n);
        for(auto e: edges){
            g[e.first].push_back(e.second);
            g[e.second].push_back(e.first);
        }

        vector<int> color(n,-1);
        queue<int> q;
        bool ok = true;

        for(int s=0;s<n && ok;s++){
            if(color[s]==-1){
                color[s]=0;
                q.push(s);
                while(!q.empty() && ok){
                    int u = q.front(); q.pop();
                    for(int v:g[u]){
                        if(color[v]==-1){
                            color[v]=1-color[u];
                            q.push(v);
                        } else if(color[v]==color[u]){
                            ok=false;
                            break;
                        }
                    }
                }
            }
        }

        if(ok) cout<<"BICOLORABLE."<<endl;
        else cout<<"NOT BICOLORABLE."<<endl;
    }

    return 0;
}

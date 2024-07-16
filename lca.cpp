#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;

// depth[u] = la profundidad de u en el arbol (la raiz tiene profundidad 0)
vector<int> depth;

// anc[u][i] = el ancestro 2^i de u (por ejemplo, anc[u][3] = el ancestro 8 de u)
vector<vector<int>> anc;

void dfs(int u, int p){
    depth[u] = depth[p] + 1;        // La profundidad de u es la profundidad de su padre + 1

    anc[u][0] = p;                  // El ancestro 2^0 de u es su padre
    for(int i = 1; i < 30; i++){    // Calculo todos los ancestros de u
        anc[u][i] = anc[anc[u][i-1]][i-1];
    }

    for(int v : graph[u]){          // Visito todos los hijos de u (los vecinos excepto su padre)
        if(v != p){
            dfs(v, u);
        }
    }
}

// Sube dist niveles desde u en el arbol
int lift(int u, int dist){
    for(int i = 0; i < 30; i++){    
        if(dist & (1 << i)){
            u = anc[u][i];
        }
    }
    return u;
}

// Ancestro comun mas bajo de a y b
// O(log n)
int lca(int a, int b){
    if(depth[a] < depth[b]) swap(a, b); // Los ordeno de tal manera que a sea el mas profundo
    a = lift(a, depth[a] - depth[b]);   // Subo a a la misma profundidad que b
    if(a == b) return a;                // Si a y b son iguales, entonces a es el lca
    
    for(int i = 29; i >= 0; i--){       // Subo a y b lo mas que pueda sin pasarme del lca
        if(anc[a][i] != anc[b][i]){
            a = anc[a][i];
            b = anc[b][i];
        }
    }
    return anc[a][0];                   // El lca es el padre de a
}

// Distancia entre a y b
// O(log n)
int dist(int a, int b){
    return depth[a] + depth[b] - 2 * depth[lca(a, b)];
}

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    graph.resize(n);
    depth.resize(n);
    anc.resize(n, vector<int>(30));

    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        for(int j = 0; j < m; j++){
            int a;
            cin >> a;
            a--;
            graph[i].push_back(a);
            graph[a].push_back(i);
        }
    }
    dfs(0, 0);
    // Obtener el lca de a y b
    cout << lca(a, b) << "\n";
    // Obtener la distancia entre a y b
    cout << dist(a, b) << "\n";
    return 0;
}
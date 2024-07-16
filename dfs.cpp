

vector<int> depth;  // guarda la distancia desde un nodo a la raiz
vector<int> parent; // guarda el padre de un nodo
vector<int> subtree_size; // guarda el tamaño del subarbol de un nodo (incluyendolo a el mismo)

void dfs(int u, int p, int d)
{
    depth[u] = d;
    parent[u] = p;
    int size = 1;
    for(int v : graph[u])
    {
        if(v != p){
            dfs(v, u, d+1);
            size += subtree_size[v];
        }
    }
    subtree_size[u] = size;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    rep(i, n-1)
    {
        int u, v; cin >> u >> v;
        u--, v--;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    depth.resize(n);
    parent.resize(n);
    subtree_size.resize(n);
    int root = 0;
    dfs(root, -1, 0);

    return 0;
}

vector <int> parent;
vector <int> size_set;
int cantidad_componentes = 0;

void make_set(int v){
    parent.push_back(v);
    size_set.push_back(1);
    cantidad_componentes++;
}

int find_set(int v){
    if (v == parent[v]){
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if (a != b){
        if (size_set[a] < size_set[b]){
            swap(a, b);
        }
        cantidad_componentes--;
        parent[b] = a;
        size_set[a] += size_set[b];
    }
}

int main()
{
    // crea n nodos
    int n = 10;
    rep(i, n){
        make_set(i);
    }

    // une los nodos
    union_sets(0, 1);
    union_sets(1, 2);
    union_sets(3, 4);

    // encuentra el representante de un nodo
    cout << find_set(0) << endl;

    // revisa si dos nodos estan unidos
    cout << (find_set(0) == find_set(3)) << endl;

    // cantidad de componentes distintas
    cout << cantidad_componentes << endl;
}
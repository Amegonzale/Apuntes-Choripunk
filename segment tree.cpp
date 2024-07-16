// Segment Tree Normal
// Queries en rango O(log n)
// Updates puntuales O(log n)
struct SegmentTree {

    // Neutro de la operacion
    // suma -> 0
    // multiplicacion -> 1
    // maximo -> -inf -> -1e9
    // minimo -> inf -> 1e9
    ll neut() { return 0; }               // **** MODIFICAR ****

    // Operacion
    ll merge(ll x, ll y) { return x + y; }// **** MODIFICAR ****

    int n; vector<ll> a;
    SegmentTree(int n = 0) : n(n), a(2 * n, neut()) {}

    // Consulta en rango [l, r), incluye l pero no incluye r
    ll query(int l, int r) {
        ll x = neut(), y = neut();
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) x = merge(x, a[l++]);
            if (r & 1) y = merge(a[--r], y);
        }
        return merge(x, y);
    }

    // Actualiza el valor en la posicion i, a[i] = x
    void update(int i, ll x) {
        for (a[i += n] = x; i /= 2;)
            a[i] = merge(a[2 * i], a[2 * i + 1]);
    }
};

int main()
{
    int n = 100;
    // Comienza el arreglo de largo n con todos los valores neutros
    SegmentTree st(n);

    // Actualiza el valor en la posicion i
    // a[5] = 10
    st.update(5, 10);

    // Setear todos los valores del arreglo
    rep(i, n){
        int x;
        cin >> x;
        st.update(i, x);
    }

    // Consulta en rango [l, r)
    int l, r;
    cin >> l >> r;
    // inclusivo - exclusivo
    cout << st.query(l, r) << endl;
    // inclusivo - inclusivo
    cout << st.query(l, r+1) << endl;
}
// Segment Tree with Lazy Propagation
// Queries en rango O(log n)
// Updates en rango O(log n)

struct SegmentTreeLazy {
    int n;
    vector<ll> a, b; // a -> valores actuales, b -> valores pendientes

    // Neutro de la operacion
    //  suma -> 0
    //  multiplicacion -> 1
    //  maximo -> -inf -> -1e9
    //  minimo -> inf -> 1e9
    ll qneut() { return -2e9; }                 // **** MODIFICAR ****
    // Operacion
    ll merge(ll x, ll y) { return max(x, y); }  // **** MODIFICAR ****

    // Neutro del update
    //  suma -> 0
    //  multiplicacion -> 1
    ll uneut() { return 0; }                    // **** MODIFICAR ****
    // Operacion del update
    void upd(int v, ll x, int l, int r){        // **** MODIFICAR ****
        // queries maximo - minimo
        a[v] += x;
        b[v] += x;
        // queries suma
        // a[v] += (r - l) * x;
        // b[v] += x;
        // queries multiplicacion
        // a[v] *= pow(x, r - l);
        // b[v] *= x;

        // setear un valor - queries de maximo - minimo
        // a[v] = x;
        // b[v] = x;
        // setear un valor - queries de suma
        // a[v] = (r - l) * x;
        // b[v] = x;
    }

    SegmentTreeLazy(int n = 0) : n(n), a(4 * n, qneut()),
        b(4 * n, uneut()) {}

    void push(int v, int vl, int vm, int vr) {
        upd(2 * v, b[v], vl, vm);
        upd(2 * v + 1, b[v], vm, vr);
        b[v] = uneut();
    }

    ll query(int l, int r, int v=1, int vl=0, int vr=1e9) {
        vr = min(vr, n);
        if (l <= vl && r >= vr) return a[v];
        if (l >= vr || r <= vl) return qneut();
        int vm = (vl + vr) / 2;
        push(v, vl, vm, vr);
        return merge(query(l, r, 2 * v, vl, vm),
            query(l, r, 2 * v + 1, vm, vr));
    }

    void update(int l, int r, ll x, int v = 1, int vl = 0,
            int vr = 1e9) {
        vr = min(vr, n);
        if (l >= vr || r <= vl || r <= l) return;
        if (l <= vl && r >= vr) upd(v, x, vl, vr);
        else {
            int vm = (vl + vr) / 2;
            push(v, vl, vm, vr);
            update(l, r, x, 2 * v, vl, vm);
            update(l, r, x, 2 * v + 1, vm, vr);
            a[v] = merge(a[2 * v], a[2 * v + 1]);
        }
    }
};



int main()
{
    int n = 100;
    // Comienza el arreglo de largo n con todos los valores neutros
    SegmentTreeLazy st(n);

    // Actualiza el rango [l, r) con el valor x
    // inclusivo - exclusivo
    st.update(5, 10, 5);

    // Setear todos los valores del arreglo
    rep(i, n){
        int x;
        cin >> x;
        st.update(i, i+1,  x);
    }

    // Consulta en rango [l, r)
    int l, r;
    cin >> l >> r;
    // inclusivo - exclusivo
    cout << st.query(l, r) << endl;
    // inclusivo - inclusivo
    cout << st.query(l, r+1) << endl;
}
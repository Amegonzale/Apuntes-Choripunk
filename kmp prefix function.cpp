vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> pi(n);
    repx(i, 1, n) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
// retorna un vector pi donde pi[i] es el largo del prefijo mas largo de s que es sufijo de s[0..i]

// pi = prefix_function("abcdabc")
// abcdabc
// pi[n-1] = 3

// ejemplo
// s  = abc#fiigjewnaabfsfdabcfsdffdsabcfsdfaba
// pi = 000000000000112000012300000001230000121

// el patron "abc" aparece en las posiciones donde pi[i] == patron.size()
// en este caso en las posiciones 12, 24, 37

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string texto = "fiigjewnaabfsfdabcfsdffdsabcfsdfaba";
    string patron = "abc";

    string s = patron + "#" + texto;
    vector<int> pi = prefix_function(s);
    
    cout << s << endl;
    rep(i, pi.size())
        cout << pi[i] << " ";
    cout << endl;
    return 0;
}








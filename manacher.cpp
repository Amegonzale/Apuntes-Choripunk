// odd[i]: length of longest palindrome centered at i
// even[i]: ...longest palindrome centered between i and i+1
// O(n)
void manacher(string &s,vector<int> &odd,vector<int> &even){
    string t = "$#";
    for(char c: s) t += c + string("#");
    t += "^";
    int n = t.size();
    vector<int> p(n);
    int l = 1, r = 1;
    repx(i, 1, n-1) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(t[i - p[i]] == t[i + p[i]]) p[i]++;
        if(i + p[i] > r) l = i - p[i], r = i + p[i];
    }
    repx(i, 2, n-2) {
        if(i%2) even.push_back(p[i]-1);
        else odd.push_back(p[i]-1);
    }
}

// ejemplo:
// s    = a a a c a b a
// odd  = 1 3 1 3 1 3 1 
// even =  2 2 0 0 0 0 

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    string s = "aaacaba";
    vector<int> odd, even;
    manacher(s, odd, even);

    cout << "a a a c a b a" << endl;
    for(int x: odd) cout << x << " ";
    cout << endl;
    cout << " ";
    for(int x: even) cout << x << " ";
    cout << endl;
    return 0;
}
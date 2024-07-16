ll extended_euclidean(ll a, ll b, ll &x, ll &y)
{
    if (a == 0){
        x = 0, y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = extended_euclidean(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

#define MOD 1000000007

// O(log a)
ll modular_inverse(ll a)
{
    ll x, y;
    ll g = extended_euclidean(a, MOD, x, y);
    if (g != 1)
        throw; //No solution!
    else
        return (x % MOD + MOD) % MOD;
}

// O(n)
void modular_inverse(vector<ll> &inv)
{
    inv[1] = 1;
    for(ll i = 2; i < inv.size(); i++)
        inv[i] = MOD - (MOD/i) * inv[MOD%i] % MOD;
}
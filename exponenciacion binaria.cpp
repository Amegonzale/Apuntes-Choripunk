#define MOD 1000000007

// O(log b)
// calcula a^b % MOD
// el modulo se puede sacar
ll bin_exp(int a, int b) 
{
    ll res = 1;
    while(b)
    {
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

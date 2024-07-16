
int n = 10000;
vector<bool> prime(n + 1, true);
prime[0] = prime[1] = false;
for(int i = 2; i < n; i++)
    if(prime[i])
        for(int j = 2*i; j < n; j += i)
            prime[j] = false;

// Crea un vector prime donde prime[i] es true si i es primo
// O(N log(log N))

// n/2 + n/3 + n/4 + n/5 .....
// n (1/2 + 1/3 + 1/4 + 1/5 ....)
// n log n


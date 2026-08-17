// Finds all primes <= n
vector<int> sieve(int n)
{
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;

    if (n >= 0) isPrime[0] = false;
    if (n >= 1) isPrime[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (!isPrime[i])
            continue;

        for (int j = i * i; j <= n; j += i)
            isPrime[j] = false;
    }

    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
            primes.push_back(i);
    }

    return primes;
}


const int MAXN = 1e7;

vector<int> spf(MAXN + 1);

// spf[x] = smallest prime factor of x
void buildSPF()
{
    for (int i = 0; i <= MAXN; i++)
        spf[i] = i;

    for (int i = 2; 1LL * i * i <= MAXN; i++)
    {
        if (spf[i] != i)
            continue;

        for (int j = i * i; j <= MAXN; j += i)
        {
            if (spf[j] == j)
                spf[j] = i;
        }
    }
}

// Prime factorization using SPF
map<ll,ll> factorize(ll x)
{
    map<ll,ll> factors;

    while (x > 1)
    {
        factors[spf[x]]++;
        x /= spf[x];
    }

    return factors;
}

// Prime factorization by trial division
map<ll,ll> factorize(ll x)
{
    map<ll,ll> factors;

    for (ll p = 2; p * p <= x; p++)
    {
        while (x % p == 0)
        {
            factors[p]++;
            x /= p;
        }
    }

    if (x > 1)
        factors[x]++;

    return factors;
}

// Returns all divisors of n
vector<ll> divisors(ll n)
{
    vector<ll> d;

    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i != 0)
            continue;

        d.push_back(i);

        if (i * i != n)
            d.push_back(n / i);
    }

    return d;
}

// Returns the number of positive divisors of n
ll divisorCount(ll n)
{
    ll ans = 1;

    for (ll p = 2; p * p <= n; p++)
    {
        if (n % p != 0)
            continue;

        ll cnt = 0;

        while (n % p == 0)
        {
            n /= p;
            cnt++;
        }

        ans *= cnt + 1;
    }

    if (n > 1)
        ans *= 2;

    return ans;
}

// Greatest Common Divisor
ll gcd(ll a, ll b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }

    return a;
}

// Least Common Multiple
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}


// Number of integers from 1 to n that are coprime with n
ll phi(ll n)
{
    ll ans = n;

    for (ll p = 2; p * p <= n; p++)
    {
        if (n % p == 0)
        {
            // Remove all occurrences of p
            while (n % p == 0)
                n /= p;

            // ans *= (1 - 1/p)
            ans -= ans / p;
        }
    }

    if (n > 1)
        ans -= ans / n;

    return ans;
}
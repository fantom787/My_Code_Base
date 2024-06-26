struct Hashing
{
    string s;
    int n;
    int primes;
    vector<ll> hashPrimes = {1000000009, 100000007};
    const ll base = 31;
    vector<vector<ll>> hashValues;
    vector<vector<ll>> powersOfBase;
    Hashing(string a)
    {
        s = a;
        n = sz(s);
        primes = sz(hashPrimes);
        hashValues = vector<vector<ll>>(primes, vector<ll>(n));
        powersOfBase = vector<vector<ll>>(primes, vector<ll>(n + 1));
        for (int i = 0; i < primes; i++)
        {
            powersOfBase[i][0] = 1;
            for (int j = 1; j <= n; j++)
            {
                powersOfBase[i][j] = (base * powersOfBase[i][j - 1]) % hashPrimes[i];
            }
        }
        for (int i = 0; i < sz(hashPrimes); i++)
        {
            for (int j = 0; j < n; j++)
            {
                hashValues[i][j] = ((s[j] - 'a' + 1LL) * powersOfBase[i][j]) % hashPrimes[i];
                hashValues[i][j] = (hashValues[i][j] + (j > 0 ? hashValues[i][j - 1] : 0LL)) % hashPrimes[i];
            }
        }
    }
    void addCharacter(char ch)
    {
        s += ch;
        n = sz(s);
        for (int i = 0; i < primes; i++)
        {
            while (sz(powersOfBase[i]) < sz(s))
            {
                powersOfBase[i].pb((powersOfBase[i].back() * base) % hashPrimes[i]);
            }
        }
        for (int i = 0; i < primes; i++)
        {
            while (sz(hashValues[i]) < sz(s))
            {
                if (sz(hashValues[i]) == 0)
                {
                    hashValues[i].pb((s[0] - 'a' + 1LL) % hashPrimes[i]);
                }
                else
                {
                    ll extraHash = hashValues[i].back() + ((s.back() - 'a' + 1LL) * powersOfBase[i][sz(s) - 1]) % hashPrimes[i];
                    hashValues[i].pb((extraHash + hashPrimes[i]) % hashPrimes[i]);
                }
            }
        }
    }
    vector<ll> substringHash(int l, int r)
    { // extra O(log) factor
        vector<ll> hash(primes);
        for (int i = 0; i < primes; i++)
        {
            ll val1 = hashValues[i][r];
            ll val2 = l > 0 ? hashValues[i][l - 1] : 0LL;
            ll val3 = ((val1 - val2) % hashPrimes[i] + hashPrimes[i]) % hashPrimes[i];
            ll val4 = modinv(powersOfBase[i][l], hashPrimes[i]);
            hash[i] = ((val3 * val4) % hashPrimes[i] + hashPrimes[i]) % hashPrimes[i];
        }
        return hash;
    }
    bool compareSubstrings(int l1, int r1, int l2, int r2)
    { // use this for comparing strings faster
        if (l1 > l2)
        {
            swap(l1, l2);
            swap(r1, r2);
        }
        for (int i = 0; i < primes; i++)
        {
            ll m = hashPrimes[i];
            ll val1 = ((hashValues[i][r1] - (l1 > 0 ? hashValues[i][l1 - 1] : 0LL)) % m + m) % m;
            ll val2 = ((hashValues[i][r2] - (l2 > 0 ? hashValues[i][l2 - 1] : 0LL)) % m + m) % m;
            if (((val1 * powersOfBase[i][l2 - l1]) % m + m) % m != val2)
            {
                return false;
            }
        }
        return true;
    }
};
/**
 * sieve: General snippet for sieve of Eratosthenes
 * 
 * Stores in an std::vector<int> whether the number in the corresponding index is prime
 * By default it goes up to 100'000, but that can be easily modified,
 * and the logic could also be easily modified to find number of prime/total factors
 * 
 * Time complexity: O(n * log(logn))
 */
std::vector<int> isPrime(100'000 + 1, 1);
for (int i = 2; i * i < isPrime.size(); ++i)
    if (isPrime[i])
        for (int j = i * i; j < isPrime.size(); j += i)
            isPrime[j] = 0;

/**
 * factorials: General snippet for factorials without modulo
 * 
 * Stores in an std::vector<ll> the factorial of a number (without modulo)
 * By default it calculates up to 20.
 */
std::vector<long long> fact(20 + 1, 1);
fact[0] = 1;
for (int i = 1; i < fact.size(); ++i) fact[i] = i * fact[i - 1];

/** 
 * nInputs: CP snippet for inputs to n-dimensional vector<int> a
 * 
 * Declares the vector<int> of size(n) and takes n inputs in it,
 * for use in tcCompi or ntCompi or mCompi snippets.
 */
vi a(n);
fi(n) { cin >> a[i]; }
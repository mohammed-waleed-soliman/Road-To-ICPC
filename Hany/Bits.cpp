// Convert number to binary string
string bin(ll n, int width = 0)
{
    string s;

    while (n)
    {
        s.push_back((n & 1) + '0');
        n >>= 1;
    }

    reverse(s.begin(), s.end());

    if (s.empty())
        s = "0";

    if (width > 0 && (int)s.size() < width)
        s = string(width - s.size(), '0') + s;

    return s;
}


// Check if bit b is ON
bool getBit(ll x, int b)
{
    return x & (1LL << b);
}

// Turn bit b ON
ll setBit(ll x, int b)
{
    return x | (1LL << b);
}

// Turn bit b OFF
ll clearBit(ll x, int b)
{
    return x & ~(1LL << b);
}

// Toggle bit b
ll toggleBit(ll x, int b)
{
    return x ^ (1LL << b);
}


// Is x a power of 2?
bool isPowerOfTwo(ll x)
{
    return x > 0 && (x & (x - 1)) == 0;
}

// Number of set bits
int countBits(ll x)
{
    return __builtin_popcountll(x);
}

// Position of lowest set bit
int lowestBit(ll x)
{
    return __builtin_ctzll(x);
}

// Remove the lowest set bit
ll removeLowestBit(ll x)
{
    return x & (x - 1);
}

// Get only the lowest set bit
ll lowestSetBit(ll x)
{
    return x & -x;
}

// Are all bits of b contained in a?
bool contains(ll a, ll b)
{
    return (a & b) == b;
}

// Does a and b have at least one common bit?
bool intersects(ll a, ll b)
{
    return (a & b) != 0;
}

// Are a and b disjoint?
bool disjoint(ll a, ll b)
{
    return (a & b) == 0;
}

// Bits in a that are NOT in b
ll difference(ll a, ll b)
{
    return a & ~b;
}

// Union of bits
ll combine(ll a, ll b)
{
    return a | b;
}

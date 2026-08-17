// Matrix multiplication: A(n x p) * B(p x m) -> C(n x m)
vector<vector<ll>> multiply(const vector<vector<ll>> &A,
                             const vector<vector<ll>> &B)
{
    int n = A.size();
    int p = A[0].size();
    int m = B[0].size();

    vector<vector<ll>> C(n, vector<ll>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < p; k++)
        {
            if (A[i][k] == 0)
                continue;

            for (int j = 0; j < m; j++)
            {
                C[i][j] =
                    (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }

    return C;
}	

// Adds two matrices of the same dimensions
vector<vector<ll>> addMatrix(const vector<vector<ll>> &A,
                              const vector<vector<ll>> &B)
{
    int n = A.size();
    int m = A[0].size();

    vector<vector<ll>> C(n, vector<ll>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            C[i][j] = (A[i][j] + B[i][j]) % MOD;
        }
    }

    return C;
}

// Creates an n x n identity matrix
vector<vector<ll>> identityMatrix(int n)
{
    vector<vector<ll>> I(n, vector<ll>(n, 0));

    for (int i = 0; i < n; i++)
        I[i][i] = 1;

    return I;
}


// Returns A^k using binary exponentiation
// A must be a square matrix
vector<vector<ll>> matrixPower(vector<vector<ll>> A, ll k)
{
    int n = A.size();

    // Identity matrix
    vector<vector<ll>> res(n, vector<ll>(n, 0));

    for (int i = 0; i < n; i++)
        res[i][i] = 1;

    while (k)
    {
        if (k & 1)
            res = multiply(res, A);

        A = multiply(A, A);
        k >>= 1;
    }

    return res;
}

// Returns the n-th Fibonacci number in O(log n)
ll fibonacci(ll n)
{
    if (n == 0)
        return 0;

    vector<vector<ll>> F = {
        {1, 1},
        {1, 0}
    };

    return matrixPower(F, n - 1)[0][0];
}
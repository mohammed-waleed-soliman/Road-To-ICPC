// Sparse Table
// Answers GCD queries on [l, r]
struct SparseTable
{
    int n, LOG;
    vector<vector<ll>> st;
    vector<int> lg;

    SparseTable(const vector<ll> &a)
    {
        n = a.size();
        LOG = 32 - __builtin_clz(n);

        st.assign(n, vector<ll>(LOG));
        lg.assign(n + 1, 0);

        for (int i = 2; i <= n; i++)
            lg[i] = lg[i / 2] + 1;

        for (int i = 0; i < n; i++)
            st[i][0] = a[i];

        for (int j = 1; j < LOG; j++)
        {
            for (int i = 0; i + (1 << j) <= n; i++)
            {
                st[i][j] = gcd(
                    st[i][j - 1],
                    st[i + (1 << (j - 1))][j - 1]
                );
            }
        }
    }


    // Returns sum of [l, r]
    ll query(int l, int r)
    {
        ll ans = 0;
        int len = r - l + 1;

        for (int j = LOG - 1; j >= 0; j--)
        {
            if ((1 << j) <= len)
            {
                ans += st[l][j];
                l += 1 << j;
                len -= 1 << j;
            }
        }

        return ans;
    }


    // Returns GCD of [l, r]
    ll query(int l, int r)
    {
        int j = lg[r - l + 1];

        return gcd(
            st[l][j],
            st[r - (1 << j) + 1][j]
        );
    }
};
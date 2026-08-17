struct SegTree
{
    int n;
    vector<ll> tree;

    SegTree(int sz)
    {
        n = sz;
        tree.assign(4 * n, 0);
    }

    // Builds the tree from the array
    void build(const vector<ll> &a, int node, int l, int r)
    {
        if (l == r)
        {
            tree[node] = a[l];
            return;
        }

        int mid = (l + r) / 2;

        build(a, node << 1, l, mid);
        build(a, node << 1 | 1, mid + 1, r);

        tree[node] = tree[node << 1] + tree[node << 1 | 1];
    }

    void build(const vector<ll> &a)
    {
        build(a, 1, 0, n - 1);
    }

    // Sets a[pos] = value
    void update(int node, int l, int r, int pos, ll value)
    {
        if (l == r)
        {
            tree[node] = value;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(node << 1, l, mid, pos, value);
        else
            update(node << 1 | 1, mid + 1, r, pos, value);

        tree[node] = tree[node << 1] + tree[node << 1 | 1];
    }

    void update(int pos, ll value)
    {
        update(1, 0, n - 1, pos, value);
    }

    // Returns the sum of [ql, qr]
    ll query(int node, int l, int r, int ql, int qr)
    {
        if (qr < l || r < ql)
            return 0;

        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) / 2;

        return query(node << 1, l, mid, ql, qr)
             + query(node << 1 | 1, mid + 1, r, ql, qr);
    }

    ll query(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
    }
};

// Iterative Segment Tree
struct SegTree
{
    int n;
    vector<ll> tree;

    SegTree(int sz)
    {
        n = 1;

        while (n < sz)
            n <<= 1;

        tree.assign(2 * n, 0);
    }

    // Builds the tree from an array
    void build(const vector<ll> &a)
    {
        for (int i = 0; i < a.size(); i++)
            tree[n + i] = a[i];

        for (int i = n - 1; i > 0; i--)
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    // Sets a[i] = v
    void update(int i, ll v)
    {
        i += n;
        tree[i] = v;

        // Recalculate all ancestors
        for (i >>= 1; i; i >>= 1)
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    // Returns sum of [l, r)
    ll query(int l, int r)
    {
        ll res = 0;

        l += n;
        r += n;

        while (l < r)
        {
            // l is a right child
            if (l & 1)
                res += tree[l++];

            // r is a right child
            if (r & 1)
                res += tree[--r];

            l >>= 1;
            r >>= 1;
        }

        return res;
    }
};


// Lazy Segment Tree
struct LazySegTree
{
    int n;
    vector<ll> tree, lazy;

    LazySegTree(int sz)
    {
        n = 1;

        while (n < sz)
            n <<= 1;

        tree.assign(2 * n, 0);
        lazy.assign(2 * n, 0);
    }

    // Builds the tree from the array
    void build(const vector<ll> &a)
    {
        for (int i = 0; i < a.size(); i++)
            tree[n + i] = a[i];

        for (int i = n - 1; i > 0; i--)
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    // Applies an addition to a whole node
    void apply(int node, ll value, int len)
    {
        tree[node] += value * len;
        lazy[node] += value;
    }

    // Pushes a pending update to the children
    void push(int node, int len)
    {
        if (lazy[node] == 0)
            return;

        int half = len / 2;

        apply(node << 1, lazy[node], half);
        apply(node << 1 | 1, lazy[node], half);

        lazy[node] = 0;
    }

    void update(int node, int nl, int nr,
                int l, int r, ll value)
    {
        if (r <= nl || nr <= l)
            return;

        if (l <= nl && nr <= r)
        {
            apply(node, value, nr - nl);
            return;
        }

        push(node, nr - nl);

        int mid = (nl + nr) / 2;

        update(node << 1, nl, mid, l, r, value);
        update(node << 1 | 1, mid, nr, l, r, value);

        tree[node] = tree[node << 1] + tree[node << 1 | 1];
    }

    // Adds value to every element in [l, r)
    void update(int l, int r, ll value)
    {
        update(1, 0, n, l, r, value);
    }

    ll query(int node, int nl, int nr,
             int l, int r)
    {
        if (r <= nl || nr <= l)
            return 0;

        if (l <= nl && nr <= r)
            return tree[node];

        push(node, nr - nl);

        int mid = (nl + nr) / 2;

        return query(node << 1, nl, mid, l, r)
             + query(node << 1 | 1, mid, nr, l, r);
    }

    // Returns sum of [l, r)
    ll query(int l, int r)
    {
        return query(1, 0, n, l, r);
    }
};


// Each node stores the frequency of every value in its segment
struct SegTree
{
    int n;
    vector<map<ll,ll>> tree;

    SegTree(int sz)
    {
        n = sz;
        tree.resize(4 * n);
    }

    // Merges the frequencies of two nodes
    void merge(map<ll,ll> &a, const map<ll,ll> &b)
    {
        for (auto [x, cnt] : b)
            a[x] += cnt;
    }

    void build(const vector<ll> &a, int node, int l, int r)
    {
        if (l == r)
        {
            tree[node][a[l]]++;
            return;
        }

        int mid = (l + r) / 2;

        build(a, node << 1, l, mid);
        build(a, node << 1 | 1, mid + 1, r);

        tree[node] = tree[node << 1];
        merge(tree[node], tree[node << 1 | 1]);
    }

    void build(const vector<ll> &a)
    {
        build(a, 1, 0, n - 1);
    }

    // Returns the frequency of x in [ql, qr]
    ll query(int node, int l, int r,
             int ql, int qr, ll x)
    {
        if (qr < l || r < ql)
            return 0;

        if (ql <= l && r <= qr)
        {
            auto it = tree[node].find(x);

            if (it == tree[node].end())
                return 0;

            return it->second;
        }

        int mid = (l + r) / 2;

        return query(node << 1, l, mid, ql, qr, x)
             + query(node << 1 | 1, mid + 1, r, ql, qr, x);
    }

    ll query(int l, int r, ll x)
    {
        return query(1, 0, n - 1, l, r, x);
    }
};


// Merge Sort Tree
// Each node stores the sorted values of its segment
// Useful for counting values <= x, < x, >= x, etc.
// Build: O(N log N)
// Query: O(log^2 N)

struct MergeSortTree
{
    int n;
    vector<vector<ll>> tree;

    MergeSortTree(int sz)
    {
        n = sz;
        tree.resize(4 * n);
    }

    // Builds sorted vectors for every segment
    void build(const vector<ll> &a, int node, int l, int r)
    {
        if (l == r)
        {
            tree[node] = {a[l]};
            return;
        }

        int mid = (l + r) / 2;

        build(a, node << 1, l, mid);
        build(a, node << 1 | 1, mid + 1, r);

        merge(
            tree[node << 1].begin(),
            tree[node << 1].end(),
            tree[node << 1 | 1].begin(),
            tree[node << 1 | 1].end(),
            back_inserter(tree[node])
        );
    }

    void build(const vector<ll> &a)
    {
        build(a, 1, 0, n - 1);
    }

    // Counts values <= x inside [ql, qr]
    ll query(int node, int l, int r,
             int ql, int qr, ll x)
    {
        if (qr < l || r < ql)
            return 0;

        if (ql <= l && r <= qr)
        {
            return upper_bound(
                tree[node].begin(),
                tree[node].end(),
                x
            ) - tree[node].begin();
        }

        int mid = (l + r) / 2;

        return query(node << 1, l, mid, ql, qr, x)
             + query(node << 1 | 1, mid + 1, r, ql, qr, x);
    }

    // Counts values <= x inside [l, r]
    ll query(int l, int r, ll x)
    {
        return query(1, 0, n - 1, l, r, x);
    }
};
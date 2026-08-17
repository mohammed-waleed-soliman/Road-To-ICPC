// Finds the largest rectangle that can be formed in a histogram
ll largestRectangle(vector<ll> h)
{
    stack<ll> st;
    ll ans = 0;

    // Sentinel forces all remaining bars to be processed
    h.push_back(0);

    for (ll i = 0; i < h.size(); i++)
    {
        // Current bar is smaller, so previous bars cannot extend further
        while (!st.empty() && h[st.top()] > h[i])
        {
            ll height = h[st.top()];
            st.pop();

            // Previous smaller element determines the left boundary
            ll left = st.empty() ? -1 : st.top();

            // i is the first smaller element on the right
            ll width = i - left - 1;

            ans = max(ans, height * width);
        }

        st.push(i);
    }

    return ans;
}


// Finds the nearest smaller element on the left of every position
vector<ll> previousSmaller(const vector<ll> &a)
{
    int n = a.size();
    vector<ll> ans(n, -1);
    stack<ll> st;

    for (int i = 0; i < n; i++)
    {
        // Remove elements that cannot be the answer
        while (!st.empty() && a[st.top()] >= a[i])
            st.pop();

        // Stack top is the nearest smaller element
        if (!st.empty())
            ans[i] = st.top();

        st.push(i);
    }

    return ans;
}

// Finds the nearest smaller element on the right of every position
vector<ll> nextSmaller(const vector<ll> &a)
{
    int n = a.size();
    vector<ll> ans(n, -1);
    stack<ll> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && a[st.top()] >= a[i])
            st.pop();

        if (!st.empty())
            ans[i] = st.top();

        st.push(i);
    }

    return ans;
}


vector<ll> nextGreaterCircular(const vector<ll> &a)
{
    int n = a.size();
    vector<ll> ans(n, -1);
    stack<ll> st;

    // Process the array twice to simulate circular behavior
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        int idx = i % n;

        // Remove elements that cannot be the next greater
        while (!st.empty() && a[st.top()] <= a[idx])
            st.pop();

        if (!st.empty())
            ans[idx] = st.top();

        st.push(idx);
    }

    return ans;
}
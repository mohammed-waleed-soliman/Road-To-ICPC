string bin(ll n, int width = 0) 
{
    string s;
    while (n) {
        s.push_back((n % 2) + '0');
        n >>= 1;
    }
    reverse(s.begin(), s.end());
    if (s.empty()) s = "0";
    if (width > 0 && (int)s.size() < width) {
        s = string(width - s.size(), '0') + s;
    }
    return s;
}
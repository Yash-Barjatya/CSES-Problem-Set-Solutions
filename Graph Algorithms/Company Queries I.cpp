///==================================================///
///                HELLO WORLD !!                    ///
///                  IT'S ME                         ///
///               YASH BARJATYA                    ///
///         [ yashbarjatya11@gmail.com ]              ///
///==================================================///
#include <bits/stdc++.h>
using namespace std;
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e9 + 10
#define INF_LL 1e18 + 10
#define FOR(a, b, c, d) for (int(a) = (b); (a) < (c); (a) = (a) + (d))
typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef pair<int, pair<int, int>> ppi;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t)
{
    cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(deque<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(unordered_set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(unordered_map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

bool is_prime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

void seive(int n)
{
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

ll fact(int n)
{
    if (n <= 1)
        return 1;
    return n * 1ll * fact(n - 1);
}
int ancestor[200005][25];
void solve()
{
    // one indexing based
    int n, q;
    cin >> n >> q;
    // parent of root
    memset(ancestor, 0, sizeof(ancestor));
    ancestor[1][0] = 0;
    // parent of other nodes
    for (int i = 2; i <= n; i++)
    {
        int u;
        cin >> u;
        ancestor[i][0] = u;
        // cout << ancestor[i][0] << " ";
    }
    // cout << endl;
    //  recursively finding kth ancestor of other nodes
    for (int k = 1; k <= log2(n) + 1; k++)
    {
        for (int node = 1; node <= n; node++)
        {
            ancestor[node][k] = ancestor[ancestor[node][k - 1]][k - 1];
            // cout << ancestor[node][k] << " ";
        }
        // cout << endl;
    }
    for (int i = 0; i < q; i++)
    {
        int k, node;
        cin >> node >> k;
        int kAncestor = node;
        for (int h = log2(n) + 1; h >= 0; h--)
        {
            if ((1 << h) > k)
                continue;
            kAncestor = ancestor[kAncestor][h];
            k -= (1 << h);
        }
        if (kAncestor == 0)
            cout << -1 << "\n";
        else
            cout << kAncestor << "\n";
    }
}
const ll M = 1e9 + 7;
int power(ll a, ll b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * 1ll * a) % M;
        a = (a * 1ll * a) % M;
        b >>= 1;
    }
    return ans;
}

int main()
{
    fastio();

#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);

#endif

    solve();
    return 0;
}
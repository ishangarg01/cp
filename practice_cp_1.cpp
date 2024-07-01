#include <bits/stdc++.h>
using namespace std;

typedef int int_main;
#define int long long

void init_code()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void dfs(int i, vector<int> &vis, vector<vector<int>> adj, vector<int> arr)
{
    vis[i] = 1;
    arr.push_back(i);
    for (auto x : adj[i])
    {
        if (!vis[i])
        {
            dfs(x, vis, adj, arr);
        }
    }
}

void solve()
{
    int n, q, a, b;
    cin >> n >> q;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> vis(n);
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        if (adj[i].size() == 1)
        {
            dfs(i, vis, adj, arr);
            break;
        }
    }

    for (auto x : arr)
    {
        cout << x;
    }
}

int_main main()
{
    init_code();

    int n = 1;
    // cin >> n;

    while (n--)
    {
        solve();
        cout << endl;
    }
}

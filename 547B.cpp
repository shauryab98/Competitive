#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define SZ(a) ((int)((a).size()))
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define INF ((int)1e9)
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define N 200005
int n, a[N];
int dp[N], longest[N] = {};
void pre() {
    stack<int> s;
    int ans[N];
    FOR0(i, n) {
        while(!s.empty() && a[s.top()] >= a[i]) {
            s.pop();
        }
        longest[i] += ans[i] = s.empty() ? i+1: i - s.top();
        s.push(i);
    }
}
int main() {
    SYNC
    cin >> n; FOR0(i, n) cin >> a[i]; a[n] = 1 + INF;
     FOR0(i, n+1) dp[i] = -1;
    pre();
    reverse(a,a+n); reverse(longest, longest + n);
    pre();
    FOR0(i, n) dp[longest[i]-1] = max(dp[longest[i]-1], a[i]);
    FORD(i,1,n) dp[i] = max(dp[i], dp[i+1]);
    FOR0(i, n) cout << dp[i+1] << " ";
}
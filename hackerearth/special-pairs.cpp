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
#define N 20
int main() {
    SYNC
    int t, n, a[100005], f[1 << N];
    cin >> t;
    while(t--) {
        cin >> n;
        memset(f, 0, sizeof f);
        FOR0(i, n) {
            cin >> a[i];
            f[a[i]]++;
        }
        FOR0(i, N) {
            FOR0(mask, 1 << N) {
                if(mask & (1 << i))
                    f[mask] += f[mask^(1 << i)];
            }
        }
        ll ans = 0;
        FOR0(i, n) ans += f[(~a[i])&((1 << N) - 1)];
        cout << ans << '\n';
    }
}
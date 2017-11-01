#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define INF (int)1e9
#define EPS 1e-9
#define SYNC std::ios::sync_with_stdio(false)
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define MOD ((int)1e9 + 7)
int main() {
	ll pow2[300000 + 5];
	pow2[0] = 1;
	FOR(i, 1, 300000 + 2) pow2[i] = (pow2[i-1]*2)%MOD;
	SYNC;
	int n, x[300000 + 5];
	cin >> n; FOR0(i, n) cin >> x[i];
	ll ans = 0;
	sort(x, x + n, greater<int>());
	FOR0(i, n) ans = (ans + ((ll)x[i])*(pow2[n-i-1] - pow2[i])) % MOD;
	if(ans < 0) ans = (ans+MOD)%MOD;
	cout << ans << endl;
}
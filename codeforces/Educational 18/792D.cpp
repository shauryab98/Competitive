#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define pb push_back
#define mp make_pair
#define INF (int)1e9
#define EPS 1e-9
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
ll n;
int q;
string s;

int main() {
	cin >> n >> q;
	ll head = (n+1) >> 1;
	while(q--) {
		ll x;
		cin >> x;
		cin >> s;
		ll level = x & (-x);
		FOR0(i, s.length()) {
			if(s[i] == 'U') {
				if (x != head) {
					x += ((x/level) % 4 == 1) ? level : -level;
					level <<= 1;
				}
			}
			else if(level>1) {
				level >>= 1L;
				if(s[i] == 'L') x = x - level;
				else x = x + level;
			}
		}
		cout << x << endl;
	}
}
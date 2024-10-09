#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int M = 2e5 + 10;
int n;
string s[M], t;
int nxt[N][26], tmp;
int cnt[N], to_str[N];
int dp[M];
void insert (string s, int id) {
	int u = 0, len = s.size();
	dp[id] = 1e9;
	for (int i = 0; i < len; i ++) {
		char ch = s[i] - 'a';
		int tot = 0;
		for (int c = 0; c <= ch; c ++) {
			tot += cnt[nxt[u][c]];
		}
		dp[id] = min(dp[id], i + tot + 1);
		if(!nxt[u][ch]) nxt[u][ch] = ++ tmp;
		u = nxt[u][ch];
		cnt[u] ++;
	}
	to_str[u] = id;
}
int getans (string s) {
	int u = 0, ans = s.size(), len = s.size();
	for (int i = 0; i < len; i ++) {
		int ch = s[i] - 'a';
		if(nxt[u][ch]) u = nxt[u][ch];
		else break;
		int id = to_str[u];
		if(id) ans = min(ans, len - i - 1 + dp[id]);
	}
	return ans;
}

signed main() {
//	freopen("data19.in", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> t;
	int mi = 1e9;
	for (int i = 1; i <= n; i ++) {
		cin >> s[i];
		insert(s[i], i);
		dp[i] = min(dp[i], mi + i);
		mi = min(mi, dp[i] - i);
	}
	cout << getans(t) << endl;
	return 0;
}

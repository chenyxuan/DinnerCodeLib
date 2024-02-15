int N = 1 << __lg(n + 5) + 1;
vector<int> tree(N << 1);

void init() {
  for (int i = 1; i <= n ++i)
      tree[i + N] = A[i];
  for (int i = N; i; --i)
      tree[i] = tree[i << 1] + tree[i << 1 | 1];
}

// 单点修改 区间查询
void update(int x, int d)
{
    for (int i = x + N; i; i >>= 1) 
        tree[i] += d;
}
int query(int l, int r)
{
    int ans = 0;
    for (l += N - 1, r += N + 1; l ^ r ^ 1; l >>= 1, r >>= 1)
    {
        if (~l & 1) ans += tree[l ^ 1]; // 左端点是左儿子
        if (r & 1) ans += tree[r ^ 1]; // 右端点是右儿子
    }
    return ans;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node {
    int deadline, value;
    //重载<号的定义，规定堆为关于价值的小根堆
    bool operator<(const node &v) const {
        if (value > v.value) return true;
        return false;
    }
} a[110000];
// 使用优先队列代替手写堆(节省Coding时间)
priority_queue<node> q;
int n;
ll ans = 0;

//自定义排序函数，将任务按截止时间从小到大排序
bool cmp(node x, node y) {
    if (x.deadline < y.deadline) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i].deadline >> a[i].value;
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; ++i) {
        //如果当前决定做的任务数小于截止日期也就是还有时间做当前任务
        if (a[i].deadline > q.size()) {
            ans += a[i].value;
            q.push(a[i]);
        } else {
            if (a[i].value > q.top().value) {
                ans -= q.top().value;
                q.pop();
                q.push(a[i]), ans += a[i].value;
            }//反悔操作 
        }//考虑是否反悔，不做之前做的任务 
    }
    cout << ans << "\n";
    return 0;
    }
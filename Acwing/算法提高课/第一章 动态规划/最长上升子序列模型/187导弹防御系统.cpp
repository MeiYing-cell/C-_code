#include<iostream>
using namespace std;
const int N = 60;
int ans, up[N], down[N], h[N];
int n;
void dfs(int u, int d, int t)// u表示上升的系统个数，d表示下降的系统个数,t表示第t个数
{
    if(u + d >= ans) return;// 剪枝，减少搜索空间，继续搜索无法得到更优解
    if(t == n){
        ans = min(ans, u + d);
        return;
    }
    int i;
    for(i = 1; i <= u; i ++)
        if(up[i] < h[t]) break;
    int temp = up[i];
    up[i] = h[t];
    dfs(max(u, i), d, t + 1);
    //恢复现场
    up[i] = temp;
    //现在开始看下降子序列
    for(i = 1; i <= d; i ++)
        if(down[i] > h[t]) break;
    temp = down[i];
    down[i] = h[t];
    dfs(u, max(d, i), t + 1);
    down[i] = temp;
}
int main(){
    while(cin >> n, n){
        ans = 100;
        for(int i = 0; i < n; i ++){
            cin >> h[i];
        }
        dfs(0, 0, 0);
        cout << ans << endl;
    }
    return 0;
}
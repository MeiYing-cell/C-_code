#include<iostream>
using namespace std;
const int N = 1010;
int h[N];
int f[N], g[N];//一个记录最长上升子序列，一个最长下降子序列
int n;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> h[i];
    
    for(int i = 1; i <= n; i ++){//最长上升子序列
        f[i] = 1;
        for(int j = 1; j < i; j ++){
            if(h[j] < h[i]) f[i] = max(f[i], f[j] + 1);
        }
    }
    for(int i = n; i >= 1; i --){//最长下降子序列
        g[i] = 1;
        for(int j = n; j > i; j --){
            if(h[j] < h[i]) g[i] = max(g[i], g[j] + 1);
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i ++) res = max(res, f[i] + g[i] - 1);
    cout << res << endl;
    return 0;
}
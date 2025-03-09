#include<iostream>
using namespace std;
const int N = 110;
int h[N];
int f[N], g[N]; // f记录最长上升子序列，g记录最长下降子序列
int n;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> h[i];
    for(int i = 1; i <= n; i ++){
        f[i] = 1;
        for(int j = 1; j < i; j ++){
            if(h[j] < h[i]) f[i] = max(f[i], f[j] + 1);
        }
    }
    for(int i = n; i >= 1; i --){
        g[i] = 1;
        for(int j = n; j > i; j --){
            if(h[j] < h[i]) g[i] = max(g[i], g[j] + 1);
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i ++) res = max(res, f[i] + g[i] - 1);
    cout << n - res << endl;
    return 0;
}
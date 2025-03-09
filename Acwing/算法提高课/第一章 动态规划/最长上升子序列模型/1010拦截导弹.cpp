#include<iostream>
using namespace std;
const int N = 1010;

int n;
int f[N], g[N];
int h[N];
int main(){
    int res1 = 0;
    while(cin >> h[n]) n ++;
    for(int i = 0; i < n; i ++){
        f[i] = 1;
        for(int j = 0; j < i; j ++){
            if(h[j] >= h[i]) f[i] = max(f[i], f[j] + 1);
        }
        res1 = max(res1, f[i]);
    }
    cout << res1 << endl;

    int res2 = 0;
    for(int i = 0; i < n; i ++){
        int k = 0;
        //数组g的每个元素代表一套导弹拦截系统的拦截序列，g[i]表示此时第i套导弹拦截系统所拦截的最后一个导弹的高度
        while(k < res2 && g[k] < h[i]) k ++;// g[k] 是第k组末尾的，需要 >= 后面插入的元素，当 < 时候需要看后面组是否满足
        g[k] = h[i];
        if(k == res2) res2 ++;
    }
    cout << res2 << endl;
    return 0;
}
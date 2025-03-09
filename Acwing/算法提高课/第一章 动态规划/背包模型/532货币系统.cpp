#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 110, M = 25010;
bool f[M];
int a[N];
int t, n;
int main(){
    cin >> t;
    while (t --)
    {
        cin >> n;
        for(int i = 1; i <= n; i ++) cin >> a[i];
        sort(a + 1, a + n + 1);
        memset(f, 0, sizeof f);
        f[0] = true;
        int m = a[n];
        int res = 0;
        for(int i = 1; i <= n; i ++){
            if(!f[a[i]]) res ++;
            for(int j = a[i]; j <= m; j ++){
                //筛掉当前最大无关向量组能线性表示的体积
                f[j] |= f[j - a[i]];
            }
        }
        cout << res << endl;
    }
    
    return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1005;
int n, m;
int v[N], w[N];// 体积,价值
int f[N];
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> v[i] >> w[i];
    
    for(int i = 1; i <= n; i++){
        for(int j = m; j >= v[i]; j--){
            f[j] = max(f[j] , f[j-v[i]] + w[i]);
        }
    }
    cout << f[m];
    return 0;
}
#include<iostream>
using namespace std;
const int M = 3010;
long long f[M];
int v[M];
int n, m;
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> v[i];
    f[0] = 1;
    for(int i = 1; i <= n; i ++){
        for(int j = v[i]; j <= m; j ++){
            f[j] += f[j - v[i]];
        }
    }
    cout << f[m] << endl;
    return 0;
}
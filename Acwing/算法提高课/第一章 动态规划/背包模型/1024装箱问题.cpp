#include<iostream>
using namespace std;
const int N = 2e5 + 10;
int V, n;
int v[N], w[N];
int f[N];
int main(){
    cin >> V >> n;
    for(int i = 1; i <= n; i ++){
        cin >> v[i];
        w[i] = v[i];
    }
    for(int i = 1; i <= n; i ++){
        for(int j = V; j >= v[i]; j --){
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << V - f[V] << endl;
    return 0;
}
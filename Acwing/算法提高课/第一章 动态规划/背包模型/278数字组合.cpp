#include<iostream>
using namespace std;
const int M = 1e5 + 10;
int n, m;
int f[M];

int main(){
    cin >> n >> m;
    f[0] = 1;// 初始化
    for(int i = 1; i <= n; i ++){
        int v;
        cin >> v;
        for(int j = m; j >= v; j --) f[j] += f[j - v];// 如果选择这个数字
    }
    cout << f[m] << endl;
    return 0;
}
#include<iostream>
using namespace std;
const int N = 1010;
int T, M;
int t[N], v[N];//这里的N是指M的最大范围
int f[N];//注意这里的N是指T的最大范围
int main(){
    cin >> T >> M;
    for(int i = 1; i <= M; i ++) cin >> t[i] >> v[i];
    for(int i = 1; i <= M; i ++){//外层循环是物品种类
        for(int j = T; j >= t[i]; j --){//里层循环是时间或体积
            f[j] = max(f[j], f[j - t[i]] + v[i]);
        }
    }
    cout << f[T] << endl;
    return 0;
}
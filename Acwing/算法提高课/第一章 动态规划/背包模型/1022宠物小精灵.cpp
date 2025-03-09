#include<iostream>
using namespace std;
const int N = 1010, M = 510, K = 110;
int V1, V2, n;// 两个限制条件，一个精灵球数量，一个体力值
int f[N][M];

int main(){
    cin >> V1 >> V2 >> n;
    for(int i = 1; i <= n; i ++){
        int v1, v2;
        cin >> v1 >> v2;
        for(int j = V1; j >= v1; j --){
            for(int k = V2; k > v2; k --){
                f[j][k] = max(f[j][k], f[j - v1][k - v2] + 1);
            }
        }
    }
    int t = V2;
    while(t > 0 && f[V1][t] == f[V1][V2]) t --;
    cout << f[V1][V2] <<' ' << V2 - t << endl;
    return 0;
}
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 21, M = 1 << N;
int f[M][N], w[N][N];
int n;
int main(){
    cin >> n;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            cin >> w[i][j];
        }
    }
    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;
    for(int i = 0; i < (1 << n); i ++){//i表示所有的情况
        for(int j = 0; j < n; j ++){//j表示走到哪一个点
            if(i >> j & 1){//第j位是1
                for(int k =0; k < n; k ++){//k表示走到j这个点之前,以k为终点的最短距离
                    if(i >> k & 1)  f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);
                }
            }
        }
    }
    cout << f[(1 << n) - 1][n - 1];
    return 0;
}
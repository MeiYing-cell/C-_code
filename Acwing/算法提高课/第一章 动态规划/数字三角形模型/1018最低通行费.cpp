#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 110;
int w[N][N], f[N][N];
int n;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            cin >> w[i][j];
        }
    }
    memset(f, 0x3f, sizeof f);

    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            if(i == 1 && j == 1) f[i][j] = w[i][j];
            else{
                if(i > 1) f[i][j] = min(f[i][j], f[i - 1][j] + w[i][j]); // 只有不在第一行的时候，才可以从上面过来
                if(j > 1) f[i][j] = min(f[i][j], f[i][j - 1] + w[i][j]); // 只有不在第一列的时候，才可以从左边过来
            }
        }
    }
    cout << f[n][n];
    return 0;
}
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 110;
int T;
int a[N][N], f[N][N];//a记录花生数目
int main(){
    cin >> T;
    while(T --){
        memset(f, 0, sizeof f);
        int raw, col;
        cin >> raw >> col;
        for(int i = 1; i <= raw; i ++){
            for(int j = 1; j <= col; j ++){
                cin >> a[i][j];
            }
        }
        for(int i = 1; i <= raw; i ++){
            for(int j = 1; j <= col; j ++){
                f[i][j] = max(f[i-1][j], f[i][j - 1]) + a[i][j];
            }
        }
        cout << f[raw][col] << endl;
    }
    return 0;
}
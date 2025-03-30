#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int w[N], f[N][2];
int T;
int main(){
    cin >> T;
    while(T --){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i ++) cin >> w[i];
        for(int i = 1; i <= n; i ++){
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            f[i][1] = f[i - 1][0] + w[i];
        }
        cout << max(f[n][0], f[n][1]) << endl;
    }
    return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 110;
int h[N], f[N];
int n;
int main(){
    int k;
    cin >> k;
    while(k --){
        cin >> n;
        for(int i = 1; i <= n; i ++) cin >> h[i];\
        int res1 = 0, res2 = 0;
        for(int i = 1; i <= n; i ++){//从右向左移动
            f[i] = 1;
            for(int j = 1; j < i; j ++){
                if(h[j] < h[i]) f[i] = max(f[i], f[j] + 1);
            }
            res1 = max(res1, f[i]);
        }
        for(int i = 1; i <= n; i ++){//从左往右移动
            f[i] = 1;
            for(int j = 1; j < i; j ++){
                if(h[j] > h[i]) f[i] = max(f[i], f[j] + 1);
            }
            res2 = max(res2, f[i]);
        }
        cout << max(res1, res2) << endl;
    }
}
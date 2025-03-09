#include<iostream>
#include<algorithm>
using namespace std;
const int N = 5e4 + 10;
typedef pair<int, int> PII;
int n;
int f[N];
PII city[N];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> city[i].first >> city[i].second;
    sort(city + 1, city + n + 1);
    for(int i = 1; i <= n; i ++){
        f[i] = 1;
        for(int j = 1; j < i; j ++){
            if(city[j].second < city[i].second) f[i] = max(f[i], f[j] + 1);
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i ++) res = max(res, f[i]);
    cout << res <<endl;
    return 0;
}
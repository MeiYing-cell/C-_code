#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1e5 + 10;
int n, m;
int a[N], b[N];
int main(){
    cin >> n >> m;
    for(int i = 0 ;i < n; i ++) cin >> a[i];
    for(int i = 0; i < m; i ++) cin >> b[i];
    int i = 0, j = 0;
    while(i < n && j < m){
        if(a[i] == b[j]) i ++ ;
        j ++;
    }
    if(i == n) printf("Yes");//i退出循环的时候，满足条件，i = n
    else printf("No");
    return 0;
}
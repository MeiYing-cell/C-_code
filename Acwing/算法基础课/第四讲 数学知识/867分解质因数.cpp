#include<iostream>

using namespace std;
int n;
void divide(int n){
    for(int i = 2; i <= n / i; i ++){
        if(n % i == 0){
            int s = 0;
            while(n % i == 0){
                n /= i;
                s ++ ;
            }
            printf("%d %d\n", i , s);
        }
    }
    if(n > 1) printf("%d 1\n", n);
    puts("");
}
int main(){
    cin >> n;
    while(n --){
        int a;
        cin >> a;
        divide(a);
    }
    return 0;
}
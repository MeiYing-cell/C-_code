#include<iostream>
using namespace std;
int n;
bool is_prime(int x){
    if(x < 2) return false;
    for(int i = 2; i <= x / i; i ++){
        if(x % i == 0) return false;
    }
    return true;
}
int main(){
    cin >> n;
    while(n --){
        int x;
        cin >> x;
        if(is_prime(x)) cout << "Yes" <<endl;
        else cout << "No" <<endl;
    }
    return 0;
}
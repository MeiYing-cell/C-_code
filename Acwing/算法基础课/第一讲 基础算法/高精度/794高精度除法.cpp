#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

vector<int> div(vector<int> &A, int b, int &r){
    r = 0;
    vector<int> C;
    for(int i = A.size() - 1; i >= 0; i --){
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    //目前是大的在前面，需要逆序
    reverse(C.begin(), C.end());
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main(){
    string a;
    int b;
    vector<int> A;

    cin >> a >> b;
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    int r;
    auto C = div(A, b, r);
    for(int i = C.size() - 1; i >= 0; i--)  cout << C[i];//大的要先输出
    cout << endl << r;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    if(n < 0){
    if(n < 0){
        cout << "n can't be negative";
        return 0;
    }
    if(n == 0){
        cout << 0;
        return 0;
    }
    int first = 1;
    int second = 1;
    for(int i = 0; i < n - 2; ++i){
        int p = first;
        first = second;
        second += p;
    }
    cout << second;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int INF = 100000000;

vector<int> buble_sort(vector<int> arr){
    for(int i = 0; i < arr.size(); ++i){
        bool change = false;
        for(int j = 0; j < arr.size() - 1; ++j){
            if(arr[j] > arr[j + 1]){
                int p = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = p;
                change = true;
            }
        }
        if(!change){
            break;
        }
    }
    return arr;
}

int main() {
    int n;
    cout << "Print the size of your array";
    cin >> n;
    if(n <= 0){
        cout << "Size should be natural number";
        return 0;
    }
    vector<int> arr(n);
    cout << "Print your array" << '\n';
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    arr = buble_sort(arr);
    for(int k : arr){
        cout << k << " ";
    }
    return 0;
}
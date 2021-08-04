#include <bits/stdc++.h>

using namespace std;

bool isUnique(vector<int> arr){
    set<int> values;
    for(int a : arr){
        values.insert(a);
    }
    return arr.size() == values.size();
}

int main() {
    int n;
    cin >> n;
    if(n <= 0){
        cout << "Go play Minecraft";
        return 0;
    }
    vector<int> arr;
    for(int i = 0; i < n; ++i){
        int p;
        cin >> p;
        arr.push_back(p);
    }
    if(isUnique(arr)){
        cout << "Yes";
    }else{
        cout << "No";
    }
    return 0;
}

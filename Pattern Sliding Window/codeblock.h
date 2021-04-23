#include <bits/stdc++.h>
using namespace std;

vector<double> input (){
    int size;
    cout << "Enter Size of an array : ";
    cin >> size;

    vector <double> arr(size);
    cout << "Enter elements in array : ";
    for(int i =0; i < size; i++){
        cin >> arr[i];
    }

    return arr;
}
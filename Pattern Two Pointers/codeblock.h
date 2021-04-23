#include<iostream>
#include<vector>
using namespace std;

vector<int> getInput()
{
    int n;
    cout << "Enter the size of array : ";
    cin >> n;
    vector <int> input(n);
    cout << "Enter elements in array : ";
    for(int i =0; i < n; i++){
        cin >> input[i];
    }
    return input;
    
}
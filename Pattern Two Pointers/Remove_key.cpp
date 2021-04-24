#include "codeblock.h"

int removeKey(vector <int> arr , int key)
{
    int nextElement = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] != key){
            arr[nextElement] = arr[i];
            nextElement++;
        }
    }
    return nextElement;
}

int main()
{
    vector <int> arr = getInput();
    int key;
    cout << "Enter the key you want to delete : ";
    cin >> key;
    cout << "The length after removing key: " << removeKey(arr,key) << endl;
    return 0;
}
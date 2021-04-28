#include "codeblock.h"
#include <algorithm>

void sortInPlace(vector <int> &arr)
{
    int left = 0;
    int right = arr.size()-1;
    int i =0;
    while(i <= right){
        if(arr[i] == 0){
            swap(arr[left], arr[i]);
            i++;
            left++;
        }else if(arr[i] == 1){
            i++;
        }else{
            swap(arr[i],arr[right]);
            right--;
        }
    }
}
int main()
{
    vector <int> arr = getInput();
    sortInPlace(arr);
    cout << "Sorted Array : ";
    for(auto i : arr){
        cout << i << " ";
    }
    return 0;
}

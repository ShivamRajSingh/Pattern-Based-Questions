#include "codeblock.h"

int removeDuplicates(vector <int> arr)
{
    int nextNonDuplicate = 1;
    for(int i = 1; i < arr.size(); i++){
        if(arr[nextNonDuplicate -1] != arr[i]){
            arr[nextNonDuplicate] = arr[i];
            nextNonDuplicate++;
        }
    }
    return nextNonDuplicate;
}

int main()
{
    vector <int> arr = getInput();
    cout << "The length after removing duplicates : " << removeDuplicates(arr) << endl;
    return 0;
}
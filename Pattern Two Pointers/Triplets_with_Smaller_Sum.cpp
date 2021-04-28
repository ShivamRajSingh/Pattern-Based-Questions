#include "codeblock.h"
#include <algorithm>
int searchPairs(const vector<int> &arr, int left, int targetSum)
{
    int count =0;
    int right = arr.size()-1;
    while(left < right)
    {
        int currentSum = arr[left] + arr[right];
        if(currentSum < targetSum){
            count += right-left;
            left++;
        }else{
            right--;
        }
    }
    return count;
}
int findTriplets(vector <int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    int count =0;
    for(int i =0; i < arr.size()-2; i++){
        count += searchPairs(arr,i+1, target-arr[i]);
    }
    return count;
}

int main()
{
    vector <int> arr = getInput();
    int target;
    cout << "Enter the target sum : ";
    cin >> target;
    cout <<"No. of triplets whose sum < target : "<< findTriplets(arr, target);

}

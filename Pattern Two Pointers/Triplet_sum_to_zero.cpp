#include "codeblock.h"
#include <algorithm>
void findTriplets(const vector <int> &arr, int targetSum , int left , vector<vector<int>> &triplets )
{
    int right = arr.size() -1;
    while(left < right){
        int currentSum = arr[left] + arr[right];
        if(currentSum == targetSum){
            triplets.push_back({-targetSum , arr[left] , arr[right]});

            left++;
            right--;

            while(left < right && arr[left] == arr[left-1]){
                left++;
            }
            while(left < right && arr[right] == arr[right+1]){
                right--;
            }

        }else if(currentSum < targetSum){
            left++;
        }else{
            right--;
        }
    }
}
vector<vector<int>> searchTriplets(vector <int> &arr){
    sort(arr.begin() , arr.end());
    vector< vector <int>> triplets;
    for(int i =0; i < arr.size()-2; i++)
    {
        if(i > 0 && arr[i] == arr[i-1]){
        //  to avoid the duplicate triplets
            continue;
        }
        findTriplets(arr, -arr[i] ,i+1,triplets);
    } 
    return triplets;
}

int main()
{
    vector <int> arr = getInput();
    vector<vector <int>> result = searchTriplets(arr);
    for(auto vec : result){
        for(auto i : vec){
            cout << i << " ";
        }
        cout << ",\n";
    }
}
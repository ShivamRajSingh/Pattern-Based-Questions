#include "codeblock.h"
int minSubarray(vector <double> arr, int sum){
    int n = arr.size();
    int windowStart = 0;
    double windowSum = 0;
    int result = numeric_limits<int>::max();

    for(int windowEnd =0; windowEnd < n; windowEnd++){
        windowSum += arr[windowEnd];

        while(windowSum >= sum){
            result = min (result, windowEnd-windowStart+1);
            windowSum -= arr[windowStart];
            windowStart++;
        }
    }

    return result == numeric_limits<int>::max()? 0 : result;
}
int main(){
    vector <double> arr = input();
    int sum;
    cout << "Enter the sum : ";
    cin >> sum;

    cout << "The size of smallest subarray with given sum : "<< minSubarray(arr,sum);

    return 0;
}
#include "codeblock.h"
using namespace std;
double findSum(vector <double> arr , int k)
{
    int windowStart = 0;
    double windowSum = 0;
    int n = arr.size();
    // vector <double> result(n-k+1);
    double result = INT_MIN;
    for(int windowEnd = 0; windowEnd < n; windowEnd++){
        windowSum += arr[windowEnd];

        if(windowEnd >= k-1){
            result = max(result, windowSum);
            windowSum -= arr[windowStart];
            windowStart++;
        }

    }

    return result;

}
int main()
{
    vector <double> arr = input();
    int windowSize;
    cout << "Enter Window Size : ";
    cin >> windowSize;

    cout << "Maximum sum in subarray :" << findSum(arr,windowSize);

    return 0;
}
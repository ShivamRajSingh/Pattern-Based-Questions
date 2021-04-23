#include "codeblock.h"
vector<double> findAverage(vector <double> arr , int k)
{
    int windowStart = 0;
    double windowSum = 0;
    int n = arr.size();
    vector <double> result(n-k+1);
    for(int windowEnd = 0; windowEnd < n; windowEnd++){
        windowSum += arr[windowEnd];

        if(windowEnd >= k-1){
            result[windowStart] = windowSum/k;
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

    vector <double> result = findAverage(arr,windowSize);
    for(double i : result)
        cout << i << " ";

    return 0;
}
#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int findLength(vector <int> arr ,int n,int k)
{
    int windowStart =0;
    int maxLength = 0;
    int maxOnesCount =0;
    
    for(int windowEnd = 0; windowEnd < n; windowEnd++){
        if(arr[windowEnd] == 1){
            maxOnesCount++;
        }

        if( (windowEnd-windowStart+1) - maxOnesCount > k){
            if(arr[windowStart] == 1){
                maxOnesCount--;
            }
            windowStart++;
        } 

        maxLength = max(maxLength , windowEnd-windowStart +1);
    } 
    
    return maxLength;
}
int main()
{
    int n;
    cout << "Enter the size of array : ";
    cin >> n;
    vector <int> arr(n);
    for(int i =0; i < n; i++){
        cin >> arr[i];
    }
    int k;
    cout << "Enter the no. of replacements possible : ";
    cin >> k;
    cout << "Longest Substring length with distinct characters : " << findLength(arr,n,k) << endl;
}
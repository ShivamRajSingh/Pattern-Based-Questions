#include "codeblock.h"
#include <math.h>

vector<int> squared (vector <int> arr)
{
    int n = arr.size();
    int highSquaredIndex = n-1;
    int left = 0;
    int right = n-1;

    vector <int> result(n);

    while(left < right)
    {
        int leftSquared = pow(arr[left] , 2);
        int rightSquared = pow(arr[right] , 2);

        if(leftSquared > rightSquared){
            result[highSquaredIndex--] = leftSquared;
            left++;
        }else{
            result[highSquaredIndex--] = rightSquared;
            right--;
        }
        
    }
    return result;
}
int main()
{
    vector <int> arr = getInput();
    vector <int> res = squared(arr);
    for(auto i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}
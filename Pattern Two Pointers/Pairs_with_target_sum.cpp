#include "codeblock.h"

pair<int,int> findPairs(vector <int> v , int targetSum){
    int left = 0;
    int right = v.size() -1;
    while(left <= right){
        int sum = v[left] + v[right];

        if(sum == targetSum){
            return make_pair(left,right);
        }
        
        if( sum < targetSum){
            left++;
        }else{
            right--;
        }
    }
    return make_pair(-1,-1);
}

int main()
{
    vector<int> input = getInput();
    int targetSum;
    cout << "Enter the required sum : ";
    cin >> targetSum;
    pair<int,int> result = findPairs(input , targetSum);
    cout <<"Fount at : " << result.first << " " << result.second << endl;
}
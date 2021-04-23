#include<iostream>
#include<climits>
#include<vector>
#include<unordered_map>
using namespace std;
int findNumberOfFruits(vector<char>&s , int k)
{
    int windowStart = 0;
    int maxlength = 0;
    unordered_map<char,int> mp;

    for(int windowEnd = 0; windowEnd < s.size(); windowEnd++){
        char rightChar = s[windowEnd];
        mp[rightChar]++;

        while(mp.size() > k){
            char leftChar = s[windowStart];
            mp[leftChar]--;
            if(mp[leftChar] == 0){
                mp.erase(leftChar);
            } 
            windowStart++;
        }

        maxlength = max(maxlength , windowEnd - windowStart +1);
    }
    return maxlength;

}
int main()
{
    int size;
    cout << "Enter the no. of trees available with us : ";
    cin >> size;
    vector<char> input(size);
    for(int i = 0; i < size; i++){
        cin >> input[i];
    }
    cout << "Maximum number of fruits in each basket : " << findNumberOfFruits(input,2) << endl;
}
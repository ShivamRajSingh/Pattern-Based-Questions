#include<iostream>
#include<string>
#include<unordered_map>
#include<climits>

using namespace std;

int findlength(string s , int k)
{
    int windowStart =0;
    int maxLength = 0;
    int maxRepeatLetterCount =0;
    unordered_map <char,int> mp;
    
    for(int windowEnd = 0; windowEnd < s.length(); windowEnd++){
        char rightChar = s[windowEnd];
        mp[rightChar]++;

        maxRepeatLetterCount = max(maxRepeatLetterCount , mp[rightChar]);

        if( (windowEnd-windowStart+1) - maxRepeatLetterCount > k){
            // that means we have more than k non repeating elements in our window 
            char leftChar = s[windowStart];
            mp[leftChar]--;
            windowStart++;
        } 

        maxLength = max(maxLength , windowEnd-windowStart +1);
    } 
    
    return maxLength;
}

int main()
{
    string s;
    cout << "Enter String : ";
    getline(cin , s);
    int k;
    cout << "Enter the no. of replacements possible : ";
    cin >> k;
    cout << "Maximum length after replacing k alphabets : " << findlength(s,k) << endl;
    return 0;
}
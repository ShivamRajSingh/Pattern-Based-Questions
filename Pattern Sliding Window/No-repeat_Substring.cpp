#include<iostream>
#include<climits>
#include<unordered_map>
#include<string>
using namespace std;

int findLength(string s)
{
    int windowStart = 0;
    int maxlength = 0;
    unordered_map <char,int> mp;
    for(int windowEnd = 0; windowEnd < s.length(); windowEnd++){
        char rightChar = s[windowEnd];

        if(mp.find(rightChar) != mp.end()){
            windowStart = max(windowStart , mp[rightChar] +1);
        }

        mp[rightChar] = windowEnd;
        maxlength = max(maxlength , windowEnd - windowStart +1);
    }
    return maxlength;
}
int main()
{
    string s;
    cout << "Enter String : ";
    getline(cin ,s);
    cout << "Longest substring with no characters repeating : " << findLength(s) << endl;
}
#include<iostream>
#include<climits>
#include<unordered_map>
using namespace std;
int findLength(string s , int k)
{
    int windowStart = 0;
    int maxlength = 0;
    unordered_map<char,int> mp;

    for(int windowEnd = 0; windowEnd < s.length(); windowEnd++){
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
    string s;
    getline(cin, s);
    int k;
    cin >> k;
    cout << "Longest Substring length with distinct characters : " << findLength(s,k);
}
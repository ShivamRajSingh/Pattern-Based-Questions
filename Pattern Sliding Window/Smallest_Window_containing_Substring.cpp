#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

string findSmallestSubstring(const string &txt , const string &pat){
    int windowStart = 0; 
    int subStrStart = 0;
    int minLength = txt.length() +1; // initialise with maximum length possible
    int matched = 0;
    unordered_map <char,int> mp;
    
    for(auto i : pat){
        // store the pattern in map 
        mp[i]++;
    }

    for(int windowEnd = 0; windowEnd < txt.length(); windowEnd++){
        char rightChar = txt[windowEnd];
        if(mp.find(rightChar) != mp.end()){
            mp[rightChar]--;
            
            if(mp[rightChar] >= 0){
                matched++;
            }
        }

        while(matched == pat.length()){
            if(minLength > (windowEnd-windowStart+1)){
                // update the minimum length of substring
                minLength = (windowEnd-windowStart+1);
                subStrStart = windowStart;
            }

            char leftChar = txt[windowStart];
            windowStart++;
            if(mp.find(leftChar) != mp.end()){
                if(mp[leftChar] == 0){
                    matched--;
                }
                mp[leftChar]++;
            }

        }
    }

    return (minLength > txt.length())? "": txt.substr(subStrStart , minLength);

}

int main()
{
    string txt;
    cout << "Enter Text : ";
    getline(cin , txt);
    string pat;
    cout << "Enter Pattern : ";
    getline(cin , pat);
    string s = findSmallestSubstring(txt,pat);
    cout << "Smallest Substring containing the pattern : " << s << endl;
    return 0;
}
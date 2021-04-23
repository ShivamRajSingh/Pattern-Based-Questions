#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

bool checkForPatternPermutation (string txt , string pat)
{
    int windowStart =0;
    int matched =0;
    unordered_map <char,int> mp;

    for(auto character : pat){
        mp[character]++;
    }

    for(int windowEnd =0; windowEnd < txt.length(); windowEnd++){
        char rightChar = txt[windowEnd];
        if(mp.find(rightChar) != mp.end()){
            // that means the current character is present in our pattern
            mp[rightChar]--;
            
            if(mp[rightChar] == 0)
                matched++;
        }
        if(matched == mp.size()){
            // permutation found 
            return true;    
        }

        if( windowEnd >= pat.length()-1){ 
            // shrink window
            char leftChar = txt[windowStart];
            
            if(mp.find(leftChar) != mp.end()){
                if(mp[leftChar] == 0)
                    matched--;
                
                mp[leftChar]++;
            }
            
            windowStart++;
        }
    }
    return false;
}
int main()
{
    string txt;
    cout << "Enter Text : ";
    getline(cin , txt);
    string pat;
    cout << "Enter Pattern : ";
    getline(cin , pat);
    (checkForPatternPermutation (txt,pat) == true) ? cout << "Found\n": cout <<"Not found\n";
    return 0;
}
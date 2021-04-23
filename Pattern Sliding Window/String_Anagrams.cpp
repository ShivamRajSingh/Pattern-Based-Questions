#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> findStringAnagram (string txt , string pat)
{
    int windowStart =0;
    int matched =0;
    unordered_map <char,int> mp;
    vector<int>result;

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
            result.push_back(windowStart);
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
    return result;
}
int main()
{
    string txt;
    cout << "Enter Text : ";
    getline(cin , txt);
    string pat;
    cout << "Enter Pattern : ";
    getline(cin , pat);
    vector <int> v = findStringAnagram(txt,pat);
    for(auto i : v){
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
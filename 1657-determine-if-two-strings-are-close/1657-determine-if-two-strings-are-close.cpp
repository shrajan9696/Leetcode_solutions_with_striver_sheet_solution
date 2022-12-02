class Solution {
public:
    bool closeStrings(string word1, string word2) {
       vector<int> v;
        vector<int> t;
        map<char,int> m1;
        map<char,int> m2;
        set<char> s1;
        set<char> s2;
        for(int i=0;i<word1.length();i++)
        {
            m1[word1[i]]++;
            s1.insert(word1[i]);
        }
        for(int i=0;i<word2.length();i++){
            m2[word2[i]]++;
            s2.insert(word2[i]);
        }
      
        for(auto p:m1){
            v.push_back(p.second);
        }
        for(auto p:m2){
            t.push_back(p.second);
        }
        sort(v.begin(),v.end());
        sort(t.begin(),t.end());
       if(v==t and s1==s2) return true;
        return false;
    }
};
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& s) {
        stack<int> st;
        
        for(int i=0;i<s.size();i++){
            int flag=0;
            int pt=0;
            if(st.empty()==true or ((st.top()>=0 and s[i]>=0)) or (st.top()<0 and  s[i]<0) or (st.top()<0 and s[i]>=0)){
                pt=1;
                st.push(s[i]);
            }
            else{
                
            
            while(!st.empty()  and (((st.top()>=0 and s[i]<0)  ))){
              if(abs(st.top())==abs(s[i])){
                  flag=1;
                  st.pop();
                  break;
              }
                else if(abs(st.top())<abs(s[i])){
                    st.pop();
                }
                else break;
                 
            }
            
            }
            
            if(st.empty()==true and flag==0 )  st.push(s[i]);
             else if(pt==0 and flag==0 and ( ((st.top()>=0 and s[i]>=0)) or (st.top()<0 and  s[i]<0))) st.push(s[i]);
                 
        }
          
        vector<int> v;
       while(st.empty()==false){
           v.push_back(st.top());
           st.pop();
       }
        reverse(v.begin() ,v.end());
        return v;
    }
};
class Solution {
public:
    bool backspaceCompare(string s, string t) {
     stack<char> st;

     for(int i=0;i<s.size();i++)
     {
         if(s[i]=='#')
         {
             if(!st.empty())
                st.pop();
            
               
         }
         else
          st.push(s[i]);
     } 
stack<char> st2;

         for(int i=0;i<t.size();i++)
     {
         if(t[i]=='#')
         {
             if(!st2.empty())
                st2.pop();
            
               
         }
         else
          st2.push(t[i]);
     } 
        if(st.size()!=st2.size())
            return false;
        while(!st.empty() && !st2.empty())
        {
            if(st.top()!=st2.top())
                return false;
            st.pop();
            st2.pop();
        }

        return true;

    }
};
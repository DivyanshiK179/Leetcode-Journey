class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i:asteroids)
        {
            bool des=false;
            while(!st.empty() && i<0 && st.top()>0)
            {
                int e=st.top();
                if(e>abs(i))
                {
                    des=true;
                    break;
                }
                else if(e==abs(i))
                {
                    st.pop();
                    des=true;
                    break;
                }
                else
                {
                    st.pop();
                }
            } 
            if(!des)
            {
                st.push(i);
            }       
        }

        vector<int> res(st.size());
        for(int i=st.size()-1; i>=0; i--)
        {
            res[i]=st.top();
            st.pop();
        }
        return res;

    }
};
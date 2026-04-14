class Solution {
public:
    int calPoints(vector<string>& operations) {
        int res = 0;
        int final_sum=0;
        stack<int> st;
        for(int i = 0 ; i < operations.size();i++){
            if(operations[i] == "+")
            {
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.push(val1);
                st.push(val1+val2);
            }
            else if(operations[i] == "C")
            {
                st.pop();
            }
            else if(operations[i] == "D")
            {
                int x = st.top();
                st.push(x*2);
            }
            else
            {
                st.push(stoi(operations[i]));
            }
        }
        while(!st.empty())
        {
            int x = st.top();
            final_sum +=x;
            st.pop();
        }
        return final_sum;
    }
};
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(int i=0;i<tokens.size();i++){

            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                int num1 = st.top();
                cout<<"num1"<<num1<<endl;
                st.pop();
                int num2 = st.top();
                cout<<"num2"<<num2<<endl;
                st.pop();

                if(tokens[i]=="+"){
                    st.push(num1+num2);
                }else if(tokens[i]=="-"){
                    st.push(num2-num1);
                }else if(tokens[i]=="*"){
                    st.push(num1*num2);
                }else if(tokens[i]=="/"){
                    st.push(num2/num1);
                }
            }
            else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};

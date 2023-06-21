void insert_(stack<int>& st, int x)
{
    if (st.empty()) {
        st.push(x);
    }
    else {
        int top = st.top();
        st.pop();
        insert_(st, x);
        st.push(top);
    }
}

void reverseStack(stack<int>& st)
{
    if (!st.empty()) {
        int x = st.top();
        st.pop();
        reverseStack(st);
        insert_(st, x);
    }
}

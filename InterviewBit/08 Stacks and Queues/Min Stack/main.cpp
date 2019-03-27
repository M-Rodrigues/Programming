vector<pair<int,int>> st;

MinStack::MinStack() {
    st.clear();
}

void MinStack::push(int x) {
    if (st.size() == 0)
        st.push_back({x,x});
    else
        st.push_back({x,min(x,st[st.size()-1].second)});
}

void MinStack::pop() {
    if (st.size() > 0) st.pop_back();
}

int MinStack::top() {
    return st.size() == 0 ? -1 : st[st.size()-1].first;
}

int MinStack::getMin() {
    return st.size() == 0 ? -1 : st[st.size()-1].second;
}


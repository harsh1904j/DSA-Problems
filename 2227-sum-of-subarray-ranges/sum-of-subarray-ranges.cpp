class Solution {
private:
vector<int> findNGE(vector<int>& arr){
    int n = arr.size();
    vector<int> nge(n);
    stack<int> st;
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
        nge[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nge;
}
vector<int> findPGE(vector<int>& arr){
    int n = arr.size();
    vector<int> pge(n);
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()] < arr[i]) st.pop();
        pge[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pge;
}
long long subMax(vector<int>& arr) {
    vector<int> nge = findNGE(arr);
    vector<int> pge = findPGE(arr);
    long long total = 0;
    for(int i = 0; i < arr.size(); i++){
        int left = i - pge[i];
        int right = nge[i] - i;
        total = (total + (right * left * 1LL * arr[i]));
    }
    return total;
}

vector<int>findNSE(vector<int>& arr){
    int n = arr.size();
    vector<int> nse(n);
    stack<int> st;
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        nse[i] = st.empty()? arr.size() : st.top();
        st.push(i);
    }
    return nse;
}
vector<int>findPSE(vector<int>& arr){
    int n = arr.size();
    vector<int> pse(n);
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
        pse[i] = st.empty()? -1 : st.top();
        st.push(i);
    }
    return pse;
}
long long subMin(vector<int>& arr){
    vector<int> nse = findNSE(arr);
    vector<int> pse = findPSE(arr);
    long long total = 0;
    for(int i = 0; i < arr.size(); i++){
        int left = i - pse[i];
        int right = nse[i] - i;
        total = (total + (right * left * 1LL * arr[i]));
    }
    return total;
}
public:
    long long subArrayRanges(vector<int>& arr) {
        return subMax(arr) - subMin(arr);
    }
};
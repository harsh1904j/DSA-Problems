class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxi = 0;
        int n = heights.size();
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty()? -1 : st.top();
                maxi = max(maxi, heights[element] * (nse - pse - 1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse = n;
            int element = st.top();
            st.pop();
            int pse = st.empty()? -1:st.top();
            maxi = max(maxi, heights[element] * (nse - pse - 1));
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxi = 0;
        vector<vector<int>> pSum(n, vector<int>(m, 0));
        for(int j = 0; j < m; j++){
            int sum = 0;
            for(int i = 0; i < n; i++){
                if(matrix[i][j] == '1') sum++;
                else sum = 0;
                pSum[i][j] = sum;
            }
        }
    for(int i = 0; i < n; i++){
        maxi = max(maxi, largestRectangleArea(pSum[i]));
    }
    return maxi;
}
};
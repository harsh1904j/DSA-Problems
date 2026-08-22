class Solution {
  public:
  int allocationIsPoss(vector<int>& arr, long long x){
      int n = arr.size();
	  int stu = 1;
	  long long pagesStu = 0;
	for(int i = 0; i < n; i++){
		if(pagesStu + arr[i] <= x){
			pagesStu += arr[i];
		}
		else{
		    stu++;
		    pagesStu = arr[i];
		}
	}
	return stu;
}
    int findPages(vector<int> &pages, int b) {
        int n = pages.size();
        if(b > n) return -1;
        long long low = *max_element(pages.begin(), pages.end());
		long long high = accumulate(pages.begin(), pages.end(), 0LL);
		while(low<=high){
			long long mid = low + (high-low)/2;
			int nofStu = allocationIsPoss(pages, mid);
			if(nofStu > b){
				low = mid + 1;
			}
			else{
				high = mid - 1;
			}
		}
		return (int)low;
        
    }
};
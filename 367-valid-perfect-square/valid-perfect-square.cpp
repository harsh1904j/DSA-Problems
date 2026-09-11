class Solution {
public:
    bool isPerfectSquare(int num) {
        long long low = 1;
        long long high = num;
        while(low <= high){
            double mid = low + (high-low)/2;
            double pro = mid*mid;
            if(pro == num) return true;
            else if(pro > num){
                high = mid-1;
            }
            else low = mid+1;
        }
        return false;
    }
};
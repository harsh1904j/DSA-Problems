class Solution {
  public:
    bool isRotated(string& s, string& goal) {
               if (s.size() != goal.size()) return false;
               int n = s.size();
               if (n < 2) return s == goal;

               // Correct Left Rotation by 2
               string leftRotated = s;
               reverse(leftRotated.begin(), leftRotated.begin() + 2);
               reverse(leftRotated.begin() + 2, leftRotated.end());
               reverse(leftRotated.begin(), leftRotated.end());

               // Correct Right Rotation by 2
               string rightRotated = s;
               reverse(rightRotated.begin(), rightRotated.end());
               reverse(rightRotated.begin(), rightRotated.begin() + 2);
               reverse(rightRotated.begin() + 2, rightRotated.end());

               return (leftRotated == goal || rightRotated == goal);
    }
};

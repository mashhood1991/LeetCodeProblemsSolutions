class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
            while(left < right) //checks if the length of the left part string is less than right part of the string until then swap
            {
                swap(s[left],s[right]); 
                left++;  //moves right from beginning
                right--; //moves left from the end
            }
    }
};

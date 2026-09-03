class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool allEven = true;
        for(int num : nums1) {
            if(num % 2 != 0) {
                allEven = false;
                break;
            }
        }
        if(allEven) return true; // if all even return true

        // If the array contains both odd and even elements. -> we have to all elemnents to odd.
        // find min element
        int mn = *min_element(nums1.begin(), nums1.begin());
        // since, there is no smaller element for min element -> it should be unchanged.
        // so, we have to all elements to odd.(since all are not even)
        // if min el is odd -> we can change the remaining even elements with the help of it (even - odd = odd).
        // if even min -> possible only when all elements are even.
        if(mn % 2 == 1) return true;
        return false;
    }
};
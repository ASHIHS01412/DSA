class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {

        int st = 0;
        int end = arr.size() - 1;

        while (st < end) {

            int mid = st + (end - st) / 2;

            if (mid % 2 == 1)
                mid--;

            if (arr[mid] == arr[mid + 1]) {
                st = mid + 2;
            } else {
                end = mid;
            }
        }

        return arr[st];
    }
};
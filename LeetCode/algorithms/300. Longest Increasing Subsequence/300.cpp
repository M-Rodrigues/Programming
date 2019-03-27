
/* O(n^2) */
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int N = (int)nums.size();
		vector<int> lis(N);

		int ans = 0;
		for (int i = 0; i < N; i++) {
			lis[i] = 1;

			for (int k = 0; k < i; k++) {
				if (nums[k] < nums[i])
					lis[i] = max(lis[i], lis[k] + 1);
			}

			ans = max(ans, lis[i]);
		}

		return ans;
	}
};

/* O(nlogn) */
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int N = (int)nums.size();
		if (N == 0) return 0;

		int lis[N];

		int len = 0;
		for (int i = 0; i < N; i++) {
			int k = lower_bound(lis, lis + len, nums[i]) - lis;

			lis[k] = nums[i];
			if (k == len) len++;
		}

		return len;
	}
};
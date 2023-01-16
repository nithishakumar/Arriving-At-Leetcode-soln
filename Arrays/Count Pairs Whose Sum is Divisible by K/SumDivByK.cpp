#include<iostream>
#include<vector>

// O(n) time, O(k) memory
long long countKdivPairs(int A[], int n, int K)
{
	unordered_map<int, int> rem2Vals;
	for (int i = 0; i < n; i++) {
		rem2Vals[A[i] % K]++;
	}
	unordered_set<int> vals;
	long long int ans = 0;
	for (auto it = rem2Vals.begin(); it != rem2Vals.end(); it++) {
		if (vals.find(K - it->first) != vals.end()) {
			ans += (rem2Vals[K - it->first] * rem2Vals[it->first]);
		}
		vals.insert(it->first);
	}
	// two numbers divisble by k will have sum divisible by k
	int num = rem2Vals[0];
	ans += ((num * (num - 1)) / 2);
	// important to check if even due to integer division
	if (K % 2 == 0) {
		// two numbers with remainder = k / 2
		num = rem2Vals[K / 2];
		ans += ((num * (num - 1)) / 2);
	}
	return ans;
}
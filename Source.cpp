#include <iostream>
#include <string>
#include <vector>

using namespace std;


int dp[400][400];
char ch[20];

//Regex Matching (Not solved)
//Median of Two Sorted Arrays (Solved)

class Solution {

private:
	bool comparre(vector<char> holder, string s) {
		if (holder.size() != s.length()) return false;
		for (int i = 0; i < holder.size(); i++) {
			if (holder[i] != s[i] && holder[i] != '.') {
				return false;
			}
		}
		return true;
	}

public:
	bool isMatch(string s, string p) {
		int k = 0;
		int f = 0;
		vector<char> holder;
		for (int i = 0; i < p.length(); i++) {
			if (p[i] == '*') {
				holder.pop_back();
			}
			else {
				holder.push_back(p[i]);
			}
			for (int j = 0; j < s.length(); j++) {
				if (comparre(holder,s.substr(0,j+1))) {
					dp[i][j] = 1;
				}
				else if (p[i] == '*') {
					if ((i > 0 && dp[i - 1][j] == 1) || (i>0 && j>0 && dp[i-1][j-1]==1)) {
						dp[i][j] = 1;
					}
					else if (i>=2 && dp[i-2][j]==1) {
						dp[i][j] = 1;
					}
					else {
						dp[i][j] = 0;
					}
				}
				else if (p[i] == '.'&& i>=j) {
					dp[i][j] = 1;
				}
				else if (p[i] == s[j] &&i>0&&j>0&& dp[i - 1][j - 1] == 1) {
					dp[i][j] = 1;
				}
				else {
					dp[i][j] = 0;
				}
				cout << dp[i][j];
			}
			cout << endl;
		}
		return dp[p.length()-1][s.length()-1];
	}

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int length = nums1.size() + nums2.size();
		bool divideByTwo = false;
		if (length % 2 == 0) {
			divideByTwo = true;
		}
		length = floor(length / 2) + 1;
		vector<int> holder = {};
		std::vector<int>::iterator it = nums1.begin();
		std::vector<int>::iterator jt = nums2.begin();
		while (holder.size() != length) {
			if (jt == nums2.end()) {
				holder.push_back(*it);
				it++;
			}
			else if (it == nums1.end()) {
				holder.push_back(*jt);
				jt++;
			}
			else {
				if (*jt > *it) {
					holder.push_back(*it);
					it++;
				}
				else {
					holder.push_back(*jt);
					jt++;
				}
			}

		}

		if (divideByTwo) {
			int x = holder.back();
			holder.pop_back();
			return  ((double)x + holder.back()) / 2;
		}
		else {
			return holder.back();
		}

	}

};



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	Solution a1;

	string s = "aaba";
	string p = "ab*a*c*a";
	cout << a1.isMatch(s, p);

	return 0;
}


#include<iostream>
#include<vector>
#include<string>
#include<stack>


// Recursive solution (Time Limit Exceeded):
string ans = to_string(INT_MAX);
void recursion(string num, int k) {
    if (k == 0) {
        if (num.empty()) {
            ans = "0";
            return;
        }
        if (num < ans) {
            ans = num;
        }
        return;
    }
    for (int i = 0; i < num.size() && ans != "0"; i++) {
        recursion(num.substr(0, i) + num.substr(i + 1, num.size()), k - 1);
    }
}
/*
string removeKdigits(string num, int k) {
    ans = num;
    recursion(num, k);
    // Remove preceeding 0s
    while (ans.size() > 1 && ans[0] == '0') {
        ans = ans.substr(1, ans.size());
    }
    return ans;
}
*/

// Stack Solution
string removeKdigits(string num, int k) {
    stack<char> digits;
    for (int i = 0; i < num.size(); i++) {
        while (!digits.empty() && num[i] - '0' < digits.top() - '0' && k > 0) {
            digits.pop();
            k--;
        }
        digits.push(num[i]);
    }
    while (k > 0) {
        digits.pop();
        k--;
    }
    string ans;
    while (!digits.empty()) {
        ans = digits.top() + ans;
        digits.pop();
    }
    int pos = 0;
    while (pos < ans.size() && ans[pos] == '0') {
        pos++;
    }
    if (pos >= ans.size()) {
        return "0";
    }
    else if (pos != 0) {
        return ans.substr(pos, ans.size());
    }
    else if (ans.empty()) {
        return "0";
    }
    return ans;
}


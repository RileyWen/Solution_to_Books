#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;

class Node {
public:
    long long a;
    long long b;
    long long c;
    long long d;

    Node(long long _a, long long _b, long long _c, long long _d) : a(_a), b(_b), c(_c), d(_d) {};

    void add(long long x) {
        Node* newnode = (new Node((a * 2) % MOD, (b + d) % MOD,
                                  ((a * x) % MOD) + ((10ll * c) % MOD) + ((a * x) % MOD),
                                  (((((d + (x * a) % MOD) % MOD + b) % MOD +
                                     ((c * 10ll) % MOD)) %
                                    MOD) + (a * x) % MOD) % MOD));
        a=newnode->a;
        b=newnode->b;
        c=newnode->c;
        d=newnode->d;
        delete newnode;
    }
};

int T;
string s;

int main() {
    //freopen("1.txt", "r", stdin);

    cin >> T;
    while (T--) {
        cin >> s;
        Node ans = *(new Node(1,0,s[0]-'0',s[0]-'0'));
        for (int i = 1; i < s.size(); i++)
            ans.add(s[i]-'0');
        cout << ans.d << endl;
    }
}
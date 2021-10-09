#include <bits/stdc++.h>
#define BIT(x,k) ((x) >> k & 1)
using namespace std;

class TRIE {
private:
    struct TrieNode {
        TrieNode* child[2];
        bool isFull;
        TrieNode() {
            child[0] = child[1] = NULL;
            isFull = false;
        }
    };
    TrieNode* root;

    void _insert(TrieNode* cur, int value, int i) {
        if (i == -1) {
            cur -> isFull = true;
            return;
        }

        int b = BIT(value, i);
        if (!cur -> child[b])
            cur -> child[b] = new TrieNode();

        _insert(cur -> child[b], value, i-1);
        bool leftFull = cur -> child[0] && cur -> child[0] -> isFull;
        bool rightFull = cur -> child[1] && cur -> child[1] -> isFull;
        cur -> isFull = leftFull && rightFull;
    }

    int _getMEX(TrieNode* cur, int value, int i) {
        if (i == -1) return 0;
        int b = BIT(value, i);

        if (!cur -> child[b]) return 0;

        if (!cur -> child[b] -> isFull)
            return _getMEX(cur -> child[b], value, i-1);

        if (!cur -> child[1-b]) return (1 << i);

        return (1 << i) + _getMEX(cur -> child[1-b], value, i-1);
    }

public:
    TRIE() { root = new TrieNode(); }

    void insert(int value) {
        _insert(root, value, 19);
    }

    int getMEX(int value) {
        return _getMEX(root, value, 19);
    }

} Trie;

int main() {
    ios :: sync_with_stdio (0);
    cin.tie (0);  cout.tie (0);

    // freopen ("842D.inp", "r", stdin);
    // freopen ("842D.out", "w", stdout);

    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        Trie.insert(x);
    }

    int totalW = 0;
    for (int i = 1; i <= q; i++) {
        int w; cin >> w;
        totalW  ^= w;
        cout << Trie.getMEX(totalW) << '\n';
    }

    return 0;
}
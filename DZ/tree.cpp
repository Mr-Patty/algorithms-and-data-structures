#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct tnode {
    tnode *ch[3];
    bool leaf;
    tnode () {
        ch[0] = ch[1] = ch[2] = nullptr;
        leaf = false;
    }
};

tnode* build_tree (vector<string> const &words, bool &ok) {
    tnode* root = new tnode();
    for (auto w : words) {
        tnode *cur = root;
        for (auto c : w) { // assert (c >= 'a' && c <= 'c');
            if (cur -> leaf) {ok = false; return root;}
            if (cur -> ch[c - 'a'] == nullptr) { // ch[c&0xFF]
                cur->ch[c - 'a'] = new tnode();
            }
            cur = cur -> ch[c - 'a'];
        }
        cur->leaf = true;
    }
    ok = true;
    return root;
}

bool cover (tnode const *root, string const &text) {
    tnode const *cur = root;
    for (auto c : text) {
        cur = cur -> ch[c - 'a']; // assert (c >= 'a' && c <= 'c');
        if (cur == nullptr) return false;
        if (cur -> leaf) cur = root;
    }
    return cur == root;
}

int main() { // вход
    vector<string> words;
    bool ok = true;
    tnode *root = build_tree(wors, ok);
    if (ok) ok = cover(root, text);
    // избавляемся от tnode

    return 0;
}

#include "trie.c++"
#include <iostream>
#include <vector>
using namespace std;

void printSuggestions(TrieNode *curr, vector<string> &temp, string prefix) {
  if (curr->isTerminal) {
    temp.push_back(prefix);
  }

  for (char ch = 'a'; ch <= 'z'; ch++) {
    TrieNode *next = curr->children[ch - 'a'];

    if (next != NULL) {
      prefix.push_back(ch);
      printSuggestions(next, temp, prefix);
      prefix.pop_back();
    }
  }
}

vector<vector<string>> getSuggestions(string str, TrieNode *&root) {
  TrieNode *prev = root;
  cout << root->data << endl;
  vector<vector<string>> output;
  string prefix = "";
  for (int i = 0; i < str.length(); i++) {
    char lastch = str[i];

    prefix.push_back(lastch);

    // check for lastch
    TrieNode *curr = prev->children[lastch - 'a'];

    // if not found
    if (curr == NULL) {
      break;
    }

    // if found
    vector<string> temp;
    printSuggestions(curr, temp, prefix);

    output.push_back(temp);
    temp.clear();
    prev = curr;
  }

  return output;
}

vector<vector<string>> phoneDirectory(vector<string> &contactList,
                                      string &queryStr) {
  Trie *t = new Trie();

  // insert contact in trie
  for (int i = 0; i < contactList.size(); i++) {
    string str = contactList[i];
    cout << str << " ";
    t->insertWord(str);
  }

  cout << t->searchWord("coly") << endl;
  cout << t->root->data << "1" << endl;
  // return ans
  return getSuggestions(queryStr, t->root);
}

int main() {
  vector<string> contacts = {"cod", "coding", "codding", "code", "coly"};
  string query = "co";
  vector<vector<string>> output = phoneDirectory(contacts, query);

  for (auto i : output) {
    for (auto j : i) {
      for (auto k : j) {
        cout << k;
      }
      cout << " ";
    }
  }
  cout << endl;

  return 0;
}

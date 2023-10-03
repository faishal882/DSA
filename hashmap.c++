#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;


/* 
             ** THEORY **
 * HASH FUNCTIONS FOR COMPRESSION
 * Examples for Hash Function
    -> 1) Identity Function 2) Alot of others 
 * Collision 
 * Open Hashing aka Separate chaining
 * Open Addressing 
 * Linear Probing
 * Quadratic Probing 
 * Closed Addressing
 * Load Factor (0.7)
 */ 
int main() {
  // creation
  unordered_map<string, int> m;

  // insertion
  pair<string, int> p = make_pair("fm", 1);
  m.insert(p);
  m["faishal"] = 2;

  // search
  cout << m["fm"] << " " << m.at("faishal") << endl;

  // size
  cout << m.size() << endl;

  // to check presence
  cout << m.count("fm") << endl;

  // iterator
  unordered_map<string, int>::iterator it = m.begin();
  while (it != m.end()) {
    cout << it->first << " " << it->second << endl;
    it++;
  }

  return 0;
}

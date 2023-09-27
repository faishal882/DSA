#include <iostream>
#include <stdint.h>
using namespace std;

// Count number of one bit in a unsigned int binary

class Solution {
 public:
   int count_one_bits(uint32_t n) {
    int count = 0;
    count <<n;
    while(n != 0) {
     // checking last bit
     if(n&1) {
      count++;
     }
     n = n>>1;
    }
    return count;
   }
};

int main() {
 uint32_t n;
 cin >> n;
 Solution x;
 int y = x.count_one_bits(n);
 cout <<y;
}
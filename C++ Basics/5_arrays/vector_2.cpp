#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums;
    nums.assign(10, 1);

    for(auto n: nums) {
        cout << n << " ";
    }

    // change value for an element by index vector
    nums[0] = 7;
    nums[3] = 8;
    nums[5] = 8;
    nums[9] = 7;

    cout<< endl;
    for(auto n: nums) {
        cout << n << " ";
    }

    // delete an element index[first element + 4 positions]
    nums.erase(nums.begin() + 4);

    cout<< endl;
    for(auto n: nums) {
        cout << n << " ";
    }

    // clear all elements in a vector
    nums.clear();

    cout<< "\n" << nums.size();

    return 0;
}
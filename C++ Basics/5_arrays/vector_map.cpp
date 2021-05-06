#include <iostream>
#include <vector>
using namespace std;

vector<int> map(vector<int> v, int(*fn)(int)) {
    vector<int> newVector;
    for(auto el: v) {
        newVector.push_back((*fn)(el));
    }
    return newVector;
}


int main() {
    auto square = [](int x) {return x * x;};
    auto triple = [](int x) {return 3 * x;};

    vector<int> nums = {2, 5, 8, 23, 56};
    vector<int> squares = map(nums, square);
    vector<int> triples = map(nums, triple);
    vector<int> sumTwo = map(nums, [](int x) {return 2 + x;});

    for(auto n: nums) cout << n << "\t";
    cout << "\n";
    for(auto sq: squares) cout << sq << "\t";
    cout << "\n";
    for(auto t: triples) cout << t << "\t";
    cout << "\n";
    for(auto st: sumTwo) cout << st << "\t";

    return 0;
}
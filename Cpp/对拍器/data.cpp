#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    
    // ????n?x??
    uniform_int_distribution<> n_dist(1, 1000);
    uniform_int_distribution<> x_dist(0, 10000);
    
    int n = n_dist(gen);
    int x = x_dist(gen);
    
    cout << n << " " << x << endl;
    
    vector<int> a(n);
    uniform_int_distribution<> num_dist(0, 10000);
    
    a[0] = num_dist(gen);
    
    for (int i = 1; i < n; i++)
        a[i] = a[i-1] + num_dist(gen) % 100;
    
    for (int num : a) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}

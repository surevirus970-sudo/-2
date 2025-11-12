
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double fractionalKnapsack(vector<pair<int, int>> items, int capacity) {
    vector<pair<double, pair<int, int>>> sorted;
    for (auto [w, v] : items)
        sorted.push_back({(double)v / w, {w, v}});
    sort(sorted.begin(), sorted.end(), greater<>());

    double totalValue = 0;
    int used = 0;

    for (auto [ratio, item] : sorted) {
        int w = item.first, v = item.second;
        if (used + w <= capacity) {
            totalValue += v;
            used += w;
        } else {
            int left = capacity - used;
            totalValue += ratio * left;
            break;
        }
    }
    return totalValue;
}

int main() {
    vector<pair<int, int>> items = {{2,10}, {3,20}, {4,15}, {5,25}};
    int capacity = 8;
    cout << "Максимальная стоимость: " << fractionalKnapsack(items, capacity) << endl;
    return 0;
}

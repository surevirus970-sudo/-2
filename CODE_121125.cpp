#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
    double ratio;
};

// Функция сравнения для сортировки по убыванию удельной стоимости
bool compareItems(const Item& a, const Item& b) {
    return a.ratio > b.ratio;
}

int main() {
    int n;
    cout << "Введите количество предметов: ";
    cin >> n;

    vector<Item> items(n);
    cout << "Введите вес и стоимость каждого предмета (по паре чисел на строку):\n";
    for (int i = 0; i < n; ++i) {
        cin >> items[i].weight >> items[i].value;
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    int capacity;
    cout << "Введите вместимость рюкзака: ";
    cin >> capacity;

    // Сортируем по убыванию удельной стоимости
    sort(items.begin(), items.end(), compareItems);

    double totalValue = 0.0;
    int used = 0;

    cout << "\nВыбор предметов:\n";
    for (int i = 0; i < n; ++i) {
        if (used + items[i].weight <= capacity) {
            totalValue += items[i].value;
            used += items[i].weight;
            cout << "Взят предмет целиком: вес=" << items[i].weight
                 << ", стоимость=" << items[i].value << endl;
        } else {
            int remaining = capacity - used;
            if (remaining > 0) {
                double partValue = items[i].ratio * remaining;
                totalValue += partValue;
                cout << "Взята часть предмета: " << remaining << " из "
                     << items[i].weight << " (стоимость=" << partValue << ")" << endl;
            }
            break;
        }
    }

    cout << "\nМаксимальная стоимость: " << totalValue << endl;
    return 0;
}

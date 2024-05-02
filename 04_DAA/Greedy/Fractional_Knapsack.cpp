#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int weight;
    int value;
};

bool compare(Item a, Item b) {
    double ratio1 = (double)a.value / a.weight;
    double ratio2 = (double)b.value / b.weight;
    return ratio1 > ratio2;
}

double fractionalKnapsack(int capacity, std::vector<Item>& items) {
    std::sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (const auto& item : items) {
        if (currentWeight + item.weight <= capacity) {
            currentWeight += item.weight;
            totalValue += item.value;
        } else {
            int remainingWeight = capacity - currentWeight;
            totalValue += (double)item.value / item.weight * remainingWeight;
            break;
        }
    }

    return totalValue;
}

int main() {
    int capacity;
    std::cout << "Enter the capacity of the knapsack: ";
    std::cin >> capacity;

    int n;
    std::cout << "Enter the number of items: ";
    std::cin >> n;

    std::vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        std::cout << "Enter the weight and value of item " << i + 1 << ": ";
        std::cin >> items[i].weight >> items[i].value;
    }

    double maxValue = fractionalKnapsack(capacity, items);
    std::cout << "Maximum value that can be obtained: " << maxValue << std::endl;

    return 0;
}
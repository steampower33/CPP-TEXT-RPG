#include <iostream>
#include <string>
#include <map>

using namespace std;

class PotionManager {
private:
    map<string, int> potionStock_;
    const int MAX_STOCK = 3;

public:
    void AddRecipe(const string& name) {
        potionStock_[name] = MAX_STOCK;
        cout << name << " stock: " << MAX_STOCK << "\n";
    }

    void DispensePotion(const string& name) {
        if (potionStock_.find(name) == potionStock_.end()) return;

        if (potionStock_[name] > 0) {
            potionStock_[name]--;
            cout << "-> Dispense " << name << "  (stock: " << potionStock_[name] << ")\n";
        }
        else {
            cout << "-> Dispense failed: out of stock!\n";
        }
    }

    void ReturnPotion(const string& name) {
        if (potionStock_.find(name) == potionStock_.end()) return;

        if (potionStock_[name] + 1 <= MAX_STOCK) {
            potionStock_[name] += 1;
            cout << "-> Return " << name << "   (stock: " << potionStock_[name] << ")\n";
        }
        else {
            cout << "-> Return failed: Cannot exceed MAX_STOCK(" << MAX_STOCK << ")\n";
        }
    }

    int GetStock(const string& name) {
        if (potionStock_.find(name) != potionStock_.end()) {
            return potionStock_[name];
        }
        return 0;
    }
};
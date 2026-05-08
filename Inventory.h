#include <iostream>
#include <algorithm>

template<typename T>
class Inventory {
private:
    T* pItems;
    int Capacity;
    int Size;

public:
    Inventory(int initialCapacity = 2) : Capacity(initialCapacity), Size(0) {
        pItems = new T[Capacity];
    }

    Inventory(const Inventory& other) : Capacity(other.Capacity), Size(other.Size) {
        pItems = new T[Capacity];
        for (int i = 0; i < Size; ++i) {
            pItems[i] = other.pItems[i];
        }
    }

    ~Inventory() {
        delete[] pItems;
    }

    void AddItem(const T& item) {
        cout << "Adding item... (" << Size << "/" << Capacity;

        if (Size == Capacity)
            cout << " full)" << endl;
        else
            cout << ")" << endl;

        if (Size >= Capacity)
        {
            cout << " -> Inventory auto-expanded! (" << Capacity << " -> " << Capacity * 2 << ")" << endl;
            cout << endl;

            Resize(Capacity * 2);

            pItems[Size] = item;
            Size++;

            SortItems();
        }
        else
        {
            pItems[Size] = item;
            Size++;
        }


        cout << " -> Item added" << endl;
    }

    void RemoveLastItem() {
        if (Size > 0) {
            Size--;
        }
    }

    void PrintAllItems() const {
        cout << "[Inventory(" << Size << " / " << Capacity << ")]\n";
        for (int i = 0; i < Size; i++)
        {
            T item = pItems[i];
            cout << i + 1 << ". " << item.name << "(" << item.price << "G)" << endl;
        }
    }

    int GetSize() const {
        return Size;
    }

    int GetCapacity() const {
        return Capacity;
    }

    void Resize(int newCapacity) {
        Capacity = newCapacity;
        T* p = new T[Capacity];
        for (int i = 0; i < Size; ++i) {
            p[i] = pItems[i];
        }

        delete[] pItems;

        pItems = p;
    }

    static bool compareByPrice(const T& a, const T& b)
    {
        return a.price < b.price;
    }

    void SortItems()
    {
        sort(pItems, pItems + Size, compareByPrice);

        cout << "[ Inventory sorted by price ]" << endl;
        for (int i = 0; i < Size; i++)
        {
            T item = pItems[i];
            cout << i + 1 << ". " << item.name << "(" << item.price << "G)" << endl;
        }
    }

    T* GetItem(int itemChoose)
    {
        if (itemChoose < Size
            && (pItems[itemChoose].name == string("HP Potion") || pItems[itemChoose].name == string("MP Potion")))
        {
            return &pItems[itemChoose];
        }
        else
            return nullptr;
    }

    bool RemoveItemAt(int index) {
        if (index < 0 || index >= Size) {
            std::cout << "Invalid index: " << index << std::endl;
            return false;
        }

        for (int i = index; i < Size - 1; ++i) {
            pItems[i] = std::move(pItems[i + 1]);
        }

        Size--;

        std::cout << "Item at index " << index << " removed." << std::endl;
        return true;
    }
};
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Carpet {
public:
    string name;
    string description;
    double price;
    int quantity;

    Carpet(string name, string description, double price, int quantity) {
        this->name = name;
        this->description = description;
        this->price = price;
        this->quantity = quantity;
    }
};

class CarpetStore {
private:
    vector<Carpet> carpetList;

public:
    CarpetStore() {
        carpetList.push_back(Carpet("Persian Carpet", "A beautiful hand-woven carpet from Iran", 499.99, 5));
        carpetList.push_back(Carpet("Turkish Carpet", "A colorful carpet from Turkey", 399.99, 7));
        carpetList.push_back(Carpet("Indian Carpet", "A luxurious carpet from India", 599.99, 3));
    }

    void displayCarpetList() {
        cout << "Carpet List:" << endl;
        for (int i = 0; i < carpetList.size(); i++) {
            cout << i + 1 << ". " << carpetList[i].name << " - " << carpetList[i].description << " - $" << carpetList[i].price << endl;
        }
    }

    void displayCarpetDetails(int index) {
        Carpet carpet = carpetList[index];
        cout << "Name: " << carpet.name << endl;
        cout << "Description: " << carpet.description << endl;
        cout << "Price: $" << carpet.price << endl;
        cout << "Quantity: " << carpet.quantity << endl;
    }

    void purchaseCarpet(int index, int quantity) {
        Carpet& carpet = carpetList[index];
        if (carpet.quantity >= quantity) {
            carpet.quantity -= quantity;
            cout << "Thank you for your purchase!" << endl;
        } else {
            cout << "Sorry, we don't have enough stock for your purchase." << endl;
        }
    }
};

int main() {
    CarpetStore store;

    while (true) {
        cout << "1. Display carpet list" << endl;
        cout << "2. Display carpet details" << endl;
        cout << "3. Purchase carpet" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            store.displayCarpetList();
        } else if (choice == 2) {
            int index;
            cout << "Enter the index of the carpet: ";
            cin >> index;
            store.displayCarpetDetails(index - 1);
        } else if (choice == 3) {
            int index, quantity;
            cout << "Enter the index of the carpet: ";
            cin >> index;
            cout << "Enter the quantity: ";
            cin >> quantity;
            store.purchaseCarpet(index - 1, quantity);
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

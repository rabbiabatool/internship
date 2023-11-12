
#include<iostream>
#include<string>
#include<cctype> // Added for isdigit
using namespace std;

class Customer {
    static const int Size = 3; // Changed Size to 3
    string description[Size];
    double price;
    int index;
    int countaddcomp;
    int i; // helping variable for iteration

public:
    Customer() {
        price = 0.0;
        index = 0;
        countaddcomp = 0;
        i = -1;
    }

    void set_components(string description) {
        if (index >= Size) {
            countaddcomp++;
        }

        this->description[index] = description;
        index++;
    }

    void display_components() {
        cout << "The basic and additional items you chose are:" << endl;
        for (int i = 0; i < index; i++) {
            cout << description[i] << endl;
        }
    }

    void set_price(double price) {
        this->price = price;
    }

    void display_price() {
        cout << "Total price is: " << price << endl;
    }

    string get_description() {
        i++;
        return description[i];
    }

    int get_addcomp_count() {
        return countaddcomp;
    }
};

class ComputerShop {
    Customer* customers;
    int customer_size;
    int customer_index;
    static const int Size = 14;
    string items_code[Size];
    string description[Size];
    double components_price[Size];
    double price;
    int count_total_components;

public:
    ComputerShop() {
        customer_size = 200;
        customers = new Customer[customer_size];
        customer_index = 0;
        price = 200;
        count_total_components = 0;

        for (int i = 0; i < Size; i++) {
            components_price[i] = 0.0;
        }
    }

    void add_customers(Customer& c) {
        customers[customer_index] = c;
        customer_index++;
        if (customer_index > 190) {
            customer_size++;
        }
    }

    void set_table() {
        for (int i = 0; i < 14; i++) {
            cout << "Enter item code, description, and price" << endl;
            cin >> items_code[i];
            cin >> description[i];
            cin >> components_price[i];
        }
    }

    void display_table() {
        for (int i = 0; i < Size; i++) {
            cout << "Description and price" << endl;
            cout << description[i] << endl;
            cout << components_price[i] << endl;
        }
    }

    void setting_customer_items(string description) {
        customers[customer_index].set_components(description);
        count_total_components++;
    }

    void display_customer_items() {
        customers[customer_index].display_components();
    }

    void calculate_price() {
        int count1 = customers[customer_index].get_addcomp_count();
        if (count1 == 0) {
            for (int i = 0; i < count_total_components; i++) {
                string descript = customers[customer_index].get_description();
                for (int j = 0; j < Size; j++) {
                    if (description[j] == descript) {
                        price += components_price[j];
                    }
                }
            }
        }
        if (count1 == 1) {
            price += 0.05;
        }
        if (count1 > 1) {
            price += 0.1;
        }
    }

    void set_customer_price() {
        customers[customer_index].set_price(price);
    }

    void display_customer_price() {
        customers[customer_index].display_price();
    }
};

int main() {
    string descript;
    string num;
    Customer c1;
    ComputerShop s1;
    s1.add_customers(c1);
    s1.set_table();
    s1.display_table();

    
        cout << "Enter description" << endl;
        cin >> descript;

       

        s1.setting_customer_items(descript);
    

    s1.display_customer_items();
    s1.calculate_price();
    s1.set_customer_price();
    s1.display_customer_price();

    cout << "Enter how many additional items would you like to add" << endl;
    cin >> num;

   

    int number = stoi(num);

    for (int j = 0; j < number; j++) {
        cout << "Enter description" << endl;
        cin >> descript;

 

        s1.setting_customer_items(descript);
    }

    s1.display_customer_items();
    s1.calculate_price();
    s1.set_customer_price();
    s1.display_customer_price();

    return 0;
}

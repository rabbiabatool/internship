#include<iostream>
#include<string>
using namespace std;
class customer
{
	string charity_name;
	int shopping_bill;
public:
	double total;
	customer()
	{
		charity_name = " ";
		shopping_bill = 0;
		total = 0.0;
	}
	void set(string charity, int bill)
	{
		charity_name = charity;
		shopping_bill = bill;
		total = static_cast<double>(shopping_bill) / 100;
	}
	void display()
	{
		cout << "The charity name is" << " " << ":" << charity_name << endl;
		cout << "The total donation is" << " " << ":" << total << endl;
	}
};
void InsertionSort(customer* arr, int size)
{
	double temp = 0.0;
	int j = 0;
	for (int i = 1; i < size; i++)
	{
		temp = arr[i].total;
		j = i - 1;
		while (j >= 0 && arr[j].total > temp)
		{
			arr[j + 1].total = arr[j].total;
			j--;
		}
		arr[j + 1].total = temp;

	}
}
int main()
{
	customer customers[5];
	string name = " ";
	string bill = " ";
	for (int i = 0; i < 5; i++)
	{
		cout << "Customer" << " " << i + 1 << endl;
		cout << "You have 3 charity choices" << endl;
		cout << "Select one charity name" << endl;
		cout << "1- Clothing" << endl;
		cout << "2- Shoes and Bags" << endl;
		cout << "3- Books" << endl;
		cin >> name;
		if (name != "clothing" && name != "shoes" && name != "books")
		{
			cout << "Incorrect input" << endl;
			cin.ignore();
			cin >> name;
		}
		cout << "Enter your shopping bill" << endl;
		cin >> bill;
		if (bill >= "a" && bill <= "z")
		{
			cout << "Incorrect input" << endl;
			cin >> bill;

		}
		int bill_int= stoi(bill);
		if (bill_int <= 0)
		{
			cout << "Incorrect input" << endl;
			cout << "Enter values greater than zero" << endl;
			cin >> bill_int;
		}
		customers[i].set(name, bill_int);
		
	}
	InsertionSort(customers , 5);
	for (int i = 0; i < 5; i++)
	{
		customers[i].display();
	}
	double grand_total = customers[0].total + customers[1].total + customers[2].total + customers[3].total + customers[4].total;
	cout << "GRAND TOTAL IS" << " " << ":" << grand_total << endl;
}
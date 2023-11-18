#include<iostream>
using namespace std;
void costSlab1(int arr[][3] , int rowSize, int coloumnSize) {
	int i = rowSize - rowSize;
	for (int j = 0; j < coloumnSize; j++)
	{
		arr[i][j] = arr[i][j] * 10;
		
	}
	cout << "Bill of Slab 1 is " << endl;
	for (int j = 0; j < coloumnSize; j++)
	{
		cout << arr[i][j] << '\t';
	}
	cout << endl;
	return;
}
void costSlab2(int arr[][3], int rowSize, int coloumnSize) {
	int i = rowSize - 2;
	for (int j = 0; j < coloumnSize; j++)
	{
		arr[i][j] = arr[i][j] * 15;
		
	}
	cout << "Bill of Slab 2  is"<< endl;

	for (int j = 0; j < coloumnSize; j++)
	{
		cout << arr[i][j] << '\t';
	}
	cout << endl;
	return;
}
void costSlab3(int arr[][3], int rowSize, int coloumnSize) {
	int i = rowSize - 1;
	for (int j = 0; j < coloumnSize; j++)
	{
		arr[i][j] = arr[i][j] * 20;
		
	}
	cout << "Bill of Slab 3 is" << endl;

	for (int j = 0; j < coloumnSize; j++)
	{
		cout << arr[i][j] << '\t';
	}
	cout << endl;
	return;
}
int main()
{
	string press = "abc";
	int twoD_array[3][3] = { {55,65,75},{120,150,170},{210,230,240} };
	cout << "My student ID is" << ":" << "2022-SE-04" << endl;
	cout << "Enter your choice" << endl;
	cout << "Press 1 to display the bill of slab 1 and slab 2 ." << endl;
	cout << "Press 2 to display the bill of slab 3" << endl;
	cout << "Press any other key to exit" << endl;
	cin >> press;
	do
	{
		if (press == "1")
		{
			costSlab1(twoD_array,3,3);
			costSlab2(twoD_array, 3, 3);
		}
		else 
		{
			costSlab3(twoD_array, 3, 3);
		}
		cout << "My student ID is" << ":" << "2022-SE-04" << endl;
		cout << "Enter your choice" << endl;
		cout << "Press 1 to display the bill of slab 1 and slab 2 ." << endl;
		cout << "Press 2 to display the bill of slab 3" << endl;
		cout << "Press any other key to exit" << endl;
		cin >> press;
		
	} while (press=="1" || press=="2");
	return 0;
}

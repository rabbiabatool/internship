#include<iostream>
using namespace std;
class Hexagon
{
	int length;
	int angle;
	int perimeter;
	double area;
	int angle_sum;
public:
	Hexagon() 
	{
		length = 8;
		angle = 120;
		perimeter = 0;
		area = 0.000;
		angle_sum = 0;

	}
	void calArea()
	{
		area = 1.5 * 1.732 * length;
	}
	void calPeri()
	{
		perimeter = 6 * length;
	}
	void calAngleSum()
	{
		angle_sum = 6 * angle;
	}
	void display()
	{
		cout << "Area of Hexagon is" << ":" << area << endl;
		cout << "Perimeter of Hexagon is" << ":" << perimeter << endl;
		cout << "Angle sum of Hexagon is" << ":" << angle_sum << endl;
	}
};
class Square
{
	int length;
	int perimeter;
	int area;
	
public:
	Square() 
	{
		length = 8+1;
		perimeter = 0;
		area = 0;
		

	}
	void calAreaSquare()
	{
		area = length * length;
	}
	void calPeriSquare()
	{
		perimeter = 4 * length;
	}
	
	void display()
	{
		cout << "Area of Square is" << ":" << area << endl;
		cout << "Perimeter of Square is" << ":" << perimeter << endl;
		
	}
};
int main()
{
	string press="abc";
	Hexagon hexagon;
	Square square;
	cout << "Enter 1 to calculate area, perimeter and sum of angles of Hexagon" << endl;
	cout << "Enter 2 to calculate area, perimeter  of Square" << endl;
	cout << "Press any other key to exit" << endl;
	cin >> press;
	do
	{
		if (press == "1")
		{
			hexagon.calArea();
			hexagon.calPeri();
			hexagon.calAngleSum();
			hexagon.display();
		}
		else
		{
			square.calAreaSquare();
			square.calPeriSquare();
			square.display();
		}
		cout << "Enter 1 to calculate area, perimeter and sum of angles of Hexagon" << endl;
		cout << "Enter 2 to calculate area, perimeter  of Square" << endl;
		cout << "Press any other key to exit" << endl;
		cin >> press;

	} while (press=="1" || press=="2");


}
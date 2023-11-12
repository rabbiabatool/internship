#include<iostream>
#include<string>
using namespace std;
class person
{
	string name;
	int age;
public:
	person()
	{
		name = "abc";
		age = 123;
	}
};
class coach
{
public:
	person * seats[80];
	coach* nextCoach;
	coach()
	{
		for (int i = 0; i < 80; i++)
		{
			seats[i] = 0;
		}
		nextCoach = 0;
	}

};
class ElectricMountainTrain
{
	coach* firstCoach;
	coach* lastCoach;
	int totalNumberofPassengers;
	int Total_amount;
public:
	int numoftickets;
	ElectricMountainTrain()
	{
		firstCoach = 0;
		lastCoach = 0;
		numoftickets = 480;
		totalNumberofPassengers=0; // Initializing total number of passengers
		Total_amount = 0; // Initializing total amount 

		for (int i = 0; i < 6; i++)
		{
			coach* new_coach = new coach;
			if (firstCoach == 0)
			{
				firstCoach = new_coach;
				lastCoach = new_coach;
				
			}
			else
			{
				lastCoach->nextCoach = new_coach;
				lastCoach = new_coach;
			}
		}



	}
	

	void purchaseticket()
	{
		string choice = "abc";
		int flag = 0;
		coach* temp = firstCoach;
		cout << "Do you want to purchase ticket for a single person or a group ? . Enter 'single' for single person and 'group' for a group" << endl;
		cin >> choice;
		
		 if (choice == "single")
		 {
			person* newperson = new person;
			while (temp != 0)
			{
				for (int i = 0; i < 80; i++)
				{
					if (temp->seats[i] == 0)
					{
						temp->seats[i] = new person;
						totalNumberofPassengers++;

						numoftickets--;
						calculateAmount(1);
						return;

					}

				}
				temp = temp->nextCoach;
			}


		}
		else if(choice=="group")
		{

			

			int iteration = 0; // consective 10 seats
			int condition = 10;
			int save_iteration = 0;
			int save_condition = 0;
			int coach_pos = 1;
			int save_coach_pos = 0; // keeping track of coach position
			int flag = 0;
			while (temp != 0)
			{
				int i = 0;
				for (int i = 0; i < 8; i++)
				{

					for (i = iteration; i < condition; i++)
					{
						if (temp->seats[i] != 0)
						{
							break;


						}

					}
					if (i == condition)
					{
						coach* temp2 = firstCoach;
						for (int i = 0; i < coach_pos - 1; i++)
						{
							temp2 = temp2->nextCoach;
						}


						for (int j = save_iteration; j < save_condition; j++)
						{
							temp2->seats[j] = new person;
						}
						totalNumberofPassengers++;
						numoftickets--;
						calculateAmount(10);
						return;
					}
					else
					{
						iteration += 10;
						condition += 10;
					}
				}

				
				
				temp = temp->nextCoach;
				coach_pos++;
			}
			

		}
			cout << "All tickets have been sold for this train!" << endl;
		
			

		

	}
	string numofTickets()
	{
		string tickets = to_string(numoftickets);
		return tickets;
	}
	void calculateAmount(int count)
	{
		if (count == 1)
		{
			Total_amount += 25;
		}
		else
		{
			Total_amount += 225; // every 10th passenger ticket is free
		}
	}
	void displayPassengers()
	{
		cout << "Total number of passengers for this train are :" << endl;
		cout << totalNumberofPassengers << endl;
		
	}
    int get_amount()
	{
		
		return Total_amount;
	}
	bool isfull()
	{
		return numoftickets != 0;
	}
	bool operator > (ElectricMountainTrain& other); // Train with most passengers calculation

};
bool ElectricMountainTrain::operator >(ElectricMountainTrain& other)
{
	return totalNumberofPassengers > other.totalNumberofPassengers;
}
int main()
{
	ElectricMountainTrain t[8];
	
	string number = "abc";
	string number2 = "abc";
	string press = "abc";
	 int amount1 = 0;
	int amount2 = 0;
	long int total_amount = 0;
	do
	{
		// start of the day
		cout << "******************Welcome to Electric mountain Railway Station***************" << endl;
		cout << "Departure timings for train 1 is : 9:00 am" << endl;
		number = t[0].numofTickets();
		cout << "Number of tickets for this train are :" << endl;
		cout << number << endl;
		cout << "Departure timings for train 2 is : 11:00 am" << endl;
		number = t[1].numofTickets();
		cout << "Number of tickets for this train are :" << endl;
		cout << number << endl;
		cout << "Departure timings for train 3 is : 13:00 am" << endl;
		number = t[2].numofTickets();
		cout << "Number of tickets for this train are :" << endl;
		cout << number << endl;
		cout << "Departure timings for train 4 is : 15:00 am" << endl;
		number = t[3].numofTickets();
		cout << "Number of tickets for this train are :" << endl;
		cout << number << endl;
		cout << "**************************************************" << endl;
		cout << "Return timings for train 10 is : 10:00 am" << endl;
		number = t[4].numofTickets();
		cout << "Number of tickets for this train are :" << endl;
		cout << number << endl;
		cout << "Return timings for train 12 is : 12:00 am" << endl;
		number = t[5].numofTickets();
		cout << "Number of tickets for this train are :" << endl;
		cout << number << endl;
		cout << "Return timings for train 14 is : 14:00 am" << endl;
		number = t[6].numofTickets();
		cout << "Number of tickets for this train are :" << endl;
		cout << number << endl;
		cout << "Return timings for train 16 is : 16:00 am" << endl;
		number = t[7].numofTickets();
		cout << "Number of tickets for this train are :" << endl;
		cout << number << endl;
		cout << "Enter any digit from 1 to 4 for selecting departure train" << endl;
		cin >> number;
		/*if (number[0] != '1' || number[0] != '2' || number[0] != '3' || number[0] != '4')
		{
			cout << "Enter only digit from 1 to 4 for selecting departure train" << endl;
			cin >> number;
		}*/
		cout << "Enter any digit from 5 to 8 for selecting return train train" << endl;
		cin >> number2;
	    /*if (number != "5" || number != "6" || number != "7" || number != "8")
		{
			cout << "Enter only digit from 5 to 8 for selecting return train" << endl;
			cin >> number;
		}*/

		/*if (number == "2")
		{
			if (number2 != "6" || number2 != "7" || number2 != "8")
			{
				cout << "Select digit from 6 to 8 for return time" << endl;
				cin >> number2;
			}
		}
		if (number == "3")
		{
			if (number2 != "7" || number2 != "8")
			{
				cout << "Select digit from 7 to 8 for return time" << endl;
				cin >> number2;
			}
		}
		if (number == "4")
		{
			if (number2 != "8")
			{
				cout << "Select digit from  8 for return time" << endl;
				cin >> number2;
			}
		}*/
		 int num = stoi(number);
		int num2 = stoi(number2);
		// purchasing tickets
		 t[num - 1].purchaseticket();
		t[num2- 1].purchaseticket();
		
		
		amount1 = t[num - 1].get_amount();
		amount2 = t[num2 - 1].get_amount();
		total_amount = long int(amount1 + amount2);
		cout << "Total amount is for both return and departure time :" << total_amount << endl;
		cout << "Press exit to stop purchasing tickets" << endl;
		cin >> press;

	} while (press!="exit" && (t[0].numoftickets != 0 || t[1].numoftickets != 0 || t[2].numoftickets != 0 || t[3].numoftickets != 0));

	// end of the day
	for (int i = 0; i < 8; i++)
	{
		cout << "Train"<<":" << i << endl;
		t[i].displayPassengers();
		total_amount= t[i].get_amount();
		cout << "Total amount is :" << total_amount << endl;
	}
	if (t[0] > t[1] && t[0] > t[2] && t[0] > t[3] && t[0] > t[4] && t[0] > t[5] && t[0] > t[6] && t[0] > t[7])
	{
		cout << "Train 1 has greater passengers !" << endl;
	}
	if (t[1] > t[0] && t[1] > t[2] && t[1] > t[3] && t[1] > t[4] && t[1] > t[5] && t[1] > t[6] && t[1] > t[7])
	{
		cout << "Train 2 has greater passengers !" << endl;
	}
	if (t[2] > t[1] && t[2] > t[0] && t[2] > t[3] && t[2] > t[4] && t[2] > t[5] && t[2] > t[6] && t[2] > t[7])
	{
		cout << "Train 3 has greater passengers !" << endl;
	}
	if (t[3] > t[1] && t[3] > t[2] && t[3] > t[0] && t[3] > t[4] && t[3] > t[5] && t[3] > t[6] && t[3] > t[7])
	{
		cout << "Train 4 has greater passengers !" << endl;
	}
	if (t[4] > t[1] && t[4] > t[2] && t[4] > t[3] && t[4] > t[0] && t[4] > t[5] && t[4] > t[6] && t[4] > t[7])
	{
		cout << "Train 5 has greater passengers !" << endl;
	}
	if (t[5] > t[1] && t[5] > t[2] && t[5] > t[3] && t[5] > t[4] && t[5] > t[0] && t[5] > t[6] && t[5] > t[7])
	{
		cout << "Train 6 has greater passengers !" << endl;
	}
	if (t[6] > t[1] && t[6] > t[2] && t[6] > t[3] && t[6] > t[4] && t[6] > t[5] && t[6] > t[0] && t[6] > t[7])
	{
		cout << "Train 7 has greater passengers !" << endl;
	}
	else
	{
		cout << "Train 8 has greater passengers !" << endl;
	}

}
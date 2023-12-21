//#include <iostream>
//#include <typeinfo>
//#include <type_traits>
//#include <sstream>
//#include <cstring>
//
//using namespace std;
//
//template <typename T = int>
//class Boat
//{
//    string returned_time;
//    int counter;
//    int amount;
//    float number_of_hours_hired;
//
//public:
//    string arrival_time;
//
//    Boat()
//    {
//        number_of_hours_hired = 0.0;
//        arrival_time = " ";
//        returned_time = " ";
//        counter = 0;
//        amount = 0;
//    }
//
//    int setTime(float hours, string arrival)
//    {
//        int hr = 0;
//        int minutes = 0;
//        char colon = ':';
//        number_of_hours_hired = hours;
//        int hire_hours = static_cast<int>(hours);
//
//        istringstream iss(arrival);
//        iss >> hr >> minutes >> colon;
//        hr += hire_hours;
//
//        if (hire_hours > 16)
//        {
//            cout << "Can't provide this board for these hours" << endl;
//            return -1;
//        }
//
//        minutes += 30;
//        if (minutes >= 60)
//        {
//            hire_hours += minutes / 60;
//            if (hire_hours > 16)
//            {
//                cout << "Can't provide this board for these hours" << endl;
//                return -1;
//            }
//            minutes %= 60;
//        }
//
//        ostringstream oss;
//        oss << hr << ":" << minutes;
//        returned_time = oss.str();
//        return 1;
//    }
//
//    void calculate_amount(float hours)
//    {
//        if (std::is_same<T, int>::value)
//        {
//            amount = hours * 20;
//        }
//        else
//        {
//            amount = hours * 20 + 12;
//        }
//    }
//
//    void setCounter()
//    {
//        counter++;
//    }
//
//    void display()
//    {
//        cout << "You have hired boat for " << number_of_hours_hired << " hours" << endl;
//        cout << "Return time is: " << returned_time << endl;
//        cout << "Your amount is: " << amount << endl;
//    }
//
//    int getCounter()
//    {
//        return counter;
//    }
//};
//
//class Customer
//{
//public:
//    void hireBoat(Boat<>& b)
//    {
//        string arrival="abc";
//        string hours="abc";
//        float hr = 0;
//        string temp="abc";
//        cout << "Enter your arrival time: " << endl;
//        cin >> arrival;
//        cout << "Enter number of hours for which you want to hire: " << endl;
//        cin >> hours;
//
//        if (hours >= "a" && hours <= "z" || hr > 0)
//        {
//            cout << "Enters hours in positive digits" << endl;
//            cin >> hours;
//            temp = hours;
//            hr = stof(temp);
//        }
//
//        int val = b.setTime(hr, arrival);
//
//        if (val == -1)
//        {
//            cout << "Enter number of hours for which you want to hire: " << endl;
//            cin >> hours;
//            val = b.setTime(hr, arrival);
//        }
//        else
//        {
//            b.calculate_amount(hr);
//        }
//    }
//
//    void viewAmountandReturnTime(Boat<>& b)
//    {
//        b.display();
//    }
//};
//
//class Owner
//{
//public:
//    void number_nonhired_boats(int count)
//    {
//        cout << "Number of non-hired boats are: " << count << endl;
//    }
//
//    void most_hired_boat(int maximum)
//    {
//        cout << "Most hired is boat: " << maximum + 1 << endl;
//    }
//};
//
//int max(Boat<> b[])
//{
//    int maximum = 0;
//
//    for (int i = 0; i < 10; i++)
//    {
//        if (b[maximum].getCounter() < b[i].getCounter())
//        {
//            maximum = i;
//        }
//    }
//
//    return maximum;
//}
//
//int min(int arr[])
//{
//    int minimum = 0;
//
//    for (int i = 0; i < 10; i++)
//    {
//        if (arr[minimum] > arr[i])
//        {
//            minimum = i;
//        }
//    }
//
//    return minimum;
//}
//
//int main()
//{
//    Boat<> b[10];
//    int number = 0;
//    string str_arr_hours[10] = {};
//    int arr_hours[10] = {};
//    Customer c1;
//    Customer c2;
//    Customer c3;
//
//    cout << "Boats are numbered from 1 to 10" << endl;
//    cout << "Enter which boat you want to hire ?" << endl;
//    cin >> number;
//
//    if (number < 1 || number > 10)
//    {
//        cout << "Invalid boat number. Please choose a number between 1 and 10." << endl;
//        return 1;
//    }
//
//    if (b[number - 1].getCounter() == 0)
//    {
//        c1.hireBoat(b[number - 1]); // Changed from number + 1 to number - 1
//        c1.viewAmountandReturnTime(b[number - 1]);
//    }
//    else
//    {
//        for (int i = 0; i < 10; i++)
//        {
//            istringstream iss(b[i].arrival_time);
//            iss >> arr_hours[i];
//            getline(iss, str_arr_hours[i], ':');
//            arr_hours[i] = stoi(str_arr_hours[i]);
//        }
//
//        int minimum = min(arr_hours);
//        cout << "Earliest time for boat to hire is as no boat is available right now" << endl;
//        cout << b[minimum].arrival_time;
//    }
//
//    int maximum = max(b);
//    Owner o1;
//    o1.most_hired_boat(maximum);
//    int count = 0;
//
//    for (int i = 0; i < 10; i++)
//    {
//        if (b[i].getCounter() == 0)
//        {
//            count++;
//        }
//    }
//
//    o1.number_nonhired_boats(count);
//
//    return 0;
//}
#include <iostream>
#include <sstream>
#include <typeinfo>
#include <type_traits>
#include <cstring>
using namespace std;
template<typename T=int>

class Boat
{
    string returned_time;
    int counter;
    int amount;
    float number_of_hours_hired;

public:
    string arrival_time;

    Boat()
    {
        number_of_hours_hired = 0.0;
        arrival_time = " ";
        returned_time = " ";
        counter = 0;
        amount = 0;
    }

    int setTime(float hours, string arrival)
    {
        int hr = 0;
        int minutes = 0;
        char colon = ':';
        number_of_hours_hired = hours;
        int hire_hours = static_cast<int>(hours);

        istringstream iss(arrival);
        iss >> hr >> colon >> minutes;
        hr += hire_hours;

        if (hire_hours > 16)
        {
            cout << "Can't provide this board for these hours" << endl;
            return -1;
        }

       /* minutes += 30;*/
        if (minutes >= 60)
        {
            hire_hours += minutes / 60;
            if (hire_hours > 16)
            {
                cout << "Can't provide this board for these hours" << endl;
                return -1;
            }
            minutes %= 60;
        }

        ostringstream oss;
        oss << hr << ":" << minutes;
        returned_time = oss.str();
        return 1;
    }

    void calculate_amount(float hours)
    {
        
        if (is_same<T,int>::value)
        {
            amount = hours * 20;
        }
        else
        {

            amount = hours * 20 + 12;
        }
    }

    void setCounter()
    {
        counter++;
    }

    void display()
    {
        cout << "You have hired boat for " << number_of_hours_hired << " hours" << endl;
        cout << "Return time is: " << returned_time << endl;
        cout << "Your amount is: " << amount << endl;
    }

    int getCounter()
    {
        return counter;
    }
};

class Customer
{
public:
    void hireBoat(Boat<>& b)
    {
        string arrival;
        float hr = 0;

        cout << "Enter your arrival time (HH:MM): " << endl;
        cin >> arrival;

        cout << "Enter number of hours for which you want to hire: " << endl;
        cin >> hr;

        if (hr <= 0)
        {
            cout << "Enter hours in positive digits" << endl;
            return;
        }

        int val = b.setTime(hr, arrival);

        if (val == -1)
        {
            return;
        }
        else
        {
            b.calculate_amount(hr);
            b.setCounter();
        }
    }

    void viewAmountandReturnTime(Boat<>& b)
    {
        b.display();
    }
};

class Owner
{
public:
    void number_nonhired_boats(int count)
    {
        cout << "Number of non-hired boats are: " << count << endl;
    }

    void most_hired_boat(int maximum)
    {
        cout << "Most hired boat is: " << maximum + 1 << endl;
    }
};

int max(Boat<>b[])
{
    int maximum = 0;

    for (int i = 0; i < 10; i++)
    {
        if (b[maximum].getCounter() < b[i].getCounter())
        {
            maximum = i;
        }
    }

    return maximum;
}

int main()
{
    Boat<> b[10];
    int number = 0;
    Customer c1;
    Owner o1;

    cout << "Boats are numbered from 1 to 10" << endl;
    cout << "Enter which boat you want to hire? " << endl;
    cin >> number;

    if (number < 1 || number > 10)
    {
        cout << "Invalid boat number. Please choose a number between 1 and 10." << endl;
        return 1;
    }

    if (b[number - 1].getCounter() == 0)
    {
        c1.hireBoat(b[number - 1]);
        c1.viewAmountandReturnTime(b[number - 1]);
    }
    else
    {
        cout << "The boat is not available right now." << endl;
    }

    int maximum = max(b);
    o1.most_hired_boat(maximum);
    int count = 0;

    for (int i = 0; i < 10; i++)
    {
        if (b[i].getCounter() == 0)
        {
            count++;
        }
    }

    o1.number_nonhired_boats(count);

    return 0;
}


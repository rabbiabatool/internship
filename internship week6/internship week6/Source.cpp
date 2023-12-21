#include<iostream>
#include<string>
#include<sstream>

using namespace std;

double min(double d1, double d2, double d3)
{
    return (d1 < d2 && d2 < d3) ? d1 : ((d2 < d1&& d2 < d3) ? d2 : d3);
}

class Sack
{
    static const int quantity = 10; // 10 each
    int track;
    string name;
    char letter;
    double weight;

public:
    Sack()
    {
        name = " ";
        letter = ' ';
        track = 0;
        weight = 0.00;
    }

    void setSack(string name, double weight)
    {
        this->name = name;
        this->weight = weight;

        if (this->name == "sand")
        {
            letter = 'S';
        }
        else if (this->name == "cement")
        {
            letter = 'C';
        }
        else if (this->name == "gravel")
        {
            letter = 'G';
        }

        track++;
    }

    void displaySack()
    {
        for (int i = 0; i < track; i++)
        {
            cout << letter << "-" << "\t" << name << "\t" << weight << endl;
        }
    }

    void calculate_price(string name[], double number[])
    {
        double cement_price = 0;
        double sand_price = 0;
        double gravel_price = 0;
        double total_price = 0;
        double discount = 0;
        double d1 = 0;
        double d2 = 0;
        double d3 = 0;
        for (int i = 0; i < 3; i++)
        {
            if (name[i] == "cement")
            {
                cement_price = number[i] * 3;
                d1 = number[i] / 1;
            }
            else if (name[i] == "sand")
            {
                sand_price = number[i] * 2;
                d2 = number[i] / 2;
            }
            else if (name[i] == "gravel")
            {
                gravel_price = number[i] * 2;
                d3 = number[i] / 2;
            }
        }

        double special_discount = min(d1, d2, d3);
       
        total_price = cement_price + sand_price + gravel_price;
        cout << "Total regular price is" << endl;
        cout << total_price << " " << "$" << endl;
        cout << "The amount after discount is " << endl;
        double new_price = total_price - (10 * special_discount);
        cout << new_price << " " << "$" << endl;
        cout << "The amount saved is" << endl;
        double saved = total_price - new_price;
        cout << saved << " " << "$" << endl;
    }

    void getOrderWeight(string name, double number)
    {
        cout << "Your order weight is" << endl;
        cout << number << " " << ":" << name << endl;
        
    }
};

int main()
{
    Sack s1;
    string name;
    double weight;
    string name_arr[3];
    double weight_arr[3] = {};

    // Task 1
    for (int i = 0; i < 3; i++)
    {
        cout << "\t" << "*********************************************************************************" << endl;
        cout << "\t" << "Enter all the three and correct contents of Sack which are cement , gravel and sand" << endl;
        cout << "\t" << "Also enter sand and gravel weight over 49.9 and under 50.1 Kg and cement weight over" << endl;
        cout << "\t" << "24.9  and under 25.1 Kg. Otherwise Sack would be rejected" << endl;
        cout << "\t" << "Note : Content 1 is Cement , Content 2 is Gravel  and Content 3 is Sand" << endl;
        cout << "\t" << "*********************************************************************************" << endl;

        cout << "Enter name of content" << " " << i + 1 << endl;
        cin >> name;
        
        //name[0] = tolower(name[0]);
        if (name != "cement" && name != "sand" && name != "gravel")
        {
            cout << "Sack is rejected because of incomplete contents" << endl;
            return 0;
        }

        cout << "Enter weight of content" << " " << i + 1 << endl;
        cin >> weight;
        if (weight <= 0 || weight >= 100)
        {
            cout << "Sack is rejected because of incorrect entry of weight" << endl;
            return 0;
        }
        
        if ((name == "sand" && (weight < 49.9 || weight > 50.1)) ||
            (name == "gravel" && (weight < 49.9 || weight > 50.1)) ||
            (name == "cement" && (weight < 24.9 || weight > 25.1)))
        {
            cout << "Sack is rejected because of incorrect weight for " << name << endl;
            return 0;
        }

        s1.setSack(name, weight);
    }

    // Task 2 and Task 3
    int number_of_sacks = 0;
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter name of sack" << " " << i + 1 << endl;
        cin >> name;
        name[0] = tolower(name[0]);
        name_arr[i] = name;

        cout << "Enter number for sack" << " " << i + 1 << endl;
        cin >> weight;
        weight_arr[i] = weight;

        if (weight <= 0 || weight >= 100 || (name != "cement" && name != "sand" && name != "gravel"))
        {
            number_of_sacks++;
            continue;
        }

        s1.getOrderWeight(name, weight);
    }

    s1.calculate_price(name_arr,weight_arr);
    cout << "Number of rejected sacks are: " << number_of_sacks << endl;

    return 0;
}

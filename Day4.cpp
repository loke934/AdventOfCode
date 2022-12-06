#include "Day4.h"
#include "Includes.h"

void Day4::Do()
{
    ifstream file("Day4.txt");
    string str;
    int contains = 0; //part1
    int overlapping = 0; //part2
    char delimiter1 = '-';
    char delimiter2 = ',';

    while (getline(file, str))
    {
        string first = str.substr(0, str.find(delimiter2));
        string second = str.substr(str.find(delimiter2) + 1, str.length() - 1);

        int firstMin = stoi(first.substr(0, first.find(delimiter1)));
        int firstMax = stoi(first.substr(first.find(delimiter1) + 1, first.length() - 1));

        int secondMin = stoi(second.substr(0, second.find(delimiter1)));
        int secondMax = stoi(second.substr(second.find(delimiter1) + 1, second.length() - 1));

        if (firstMin <= secondMin && firstMax >= secondMax || firstMin >= secondMin && firstMax <= secondMax)
        {
            contains++;
        }

        if (firstMax >= secondMin &&
            secondMax >= firstMin)
        {
            overlapping++;
        }
    }
    cout << overlapping << endl;
    cout << contains << endl;
}

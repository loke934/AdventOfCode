#include "Day1.h"
#include "Day1.h"
#include "Includes.h"

void Day1::Do()
{
    ifstream file("Day1Input.txt");
    string str;
    vector<int> calorieSums;
    calorieSums.push_back(0);
    while (getline(file, str))
    {
        int cal = 0;
        if (str.empty())
        {
            calorieSums.push_back(0);
        }
        else
        {
            int value = calorieSums.back();
            value += stoi(str);
            calorieSums.back() = value;
        }
    }
    sort(calorieSums.begin(), calorieSums.end());
    reverse(calorieSums.begin(), calorieSums.end());
    cout << calorieSums[0] << endl;
    cout << calorieSums[0] + calorieSums[1] + calorieSums[2] << endl;
}
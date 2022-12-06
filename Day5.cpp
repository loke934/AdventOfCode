#include "Day5.h"
#include "Includes.h"

void Day5::Do()
{
    ifstream file("Day5.txt");
    string str;
    string arr[10];

    while (getline(file, str))
    {
        int count = std::count(str.begin(), str.end(), '[');
        if (count != 0)
        {
            size_t e = 0;
            for (size_t i = 0; i < count; i++)
            {
                size_t s = str.find("[", e);
                e = str.find("]", s);
                string sub = str.substr(s + 1, e - s - 1);
                int index = (s / 4) + 1;
                arr[index] += sub;
            }
        }

        int move = std::count(str.begin(), str.end(), 'm');
        int movefromto[3] = { 0,0,0 };
        int index = 0;
        if (move != 0)
        {
            stringstream ss;
            ss << str;
            string temp;
            int found;
            while (!ss.eof())
            {
                ss >> temp;
                if (stringstream(temp) >> found) {

                    movefromto[index] = stoi(temp);
                    index++;
                }
                temp = "";
            }
        }

        string line = "";
        for (size_t i = 0; i < movefromto[0]; i++)
        {
            line += arr[movefromto[1]][0];
            arr[movefromto[1]].erase(0, 1);
        }
        arr[movefromto[2]] = line + arr[movefromto[2]];
    }

    for (size_t i = 1; i < 10; i++)
    {
        cout << arr[i][0];
    }
}

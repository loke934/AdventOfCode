#include "Day3.h"
#include "Includes.h"

void Day3::Do()
{
    map<char, int> priorityLookUp =
    {
        {'a', 1},{'b', 2}, {'c', 3},
        {'d', 4},{'e', 5}, {'f', 6},
        {'g', 7},{'h', 8}, {'i', 9},
        {'j', 10},{'k', 11}, {'l', 12},
        {'m', 13},{'n', 14}, {'o', 15},
        {'p', 16},{'q', 17}, {'r', 18},
        {'s', 19},{'t', 20}, {'u', 21},
        {'v', 22},{'w', 23}, {'x', 24},
        {'y', 25},{'z', 26}
    };

    ifstream file("Day3.txt");
    string str;
    int prioritySum = 0;
    //Part1
   /* while (getline(file, str))
    {
        int numberOfElements = str.length() - 1;
        int middleElement= numberOfElements / 2;
        int startPart2 = middleElement + 1;
        char itemType = 0;
        for (size_t i = 0; i < startPart2; i++)
        {
            for (size_t j = startPart2; j < str.length(); j++)
            {
                if (str[i] == str[j] && str[i] != itemType)
                {
                    itemType = str[j];
                    if (islower(itemType))
                    {
                        int add = priorityLookUp.at(itemType);
                        prioritySum += add;

                    }
                    else if (isupper(itemType))
                    {
                        char hello = tolower(itemType);
                        int add = priorityLookUp.at(hello) + 26;
                        prioritySum += add;
                    }
                }
            }
        }
    }*/
    //Part2
    int lineNo = 0;
    string elves[3];
    char itemType = 0;
    while (getline(file, str))
    {
        elves[lineNo] = str;
        lineNo++;
        if (lineNo == 3)
        {
            for (size_t i = 0; i < elves[0].length(); i++)
            {
                for (size_t j = 0; j < elves[1].length(); j++)
                {
                    if (elves[0].at(i) == elves[1].at(j))
                    {
                        for (size_t k = 0; k < elves[2].length(); k++)
                        {
                            if (elves[2].at(k) == elves[0].at(i) && itemType == 0)
                            {
                                itemType = elves[0].at(i);
                                int add = 0;
                                if (islower(itemType))
                                {
                                    add = priorityLookUp.at(itemType);
                                }
                                else if (isupper(itemType))
                                {
                                    add = priorityLookUp.at(tolower(itemType)) + 26;
                                }
                                prioritySum += add;
                            }
                        }
                    }
                }
            }
            lineNo = 0;
            itemType = 0;
        }
    }
    cout << prioritySum << endl;
}


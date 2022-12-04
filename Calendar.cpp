#include "Calendar.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<algorithm>
#include <map>
using namespace std;

void Calendar::Day1() 
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

void Calendar::Day2() 
{
    int part1 = 0;
    int part2 = 0;
    map<string, int> outcome =
    {
        {"A Y", 8},{"B Z", 9}, {"C X", 7}, //Win
        {"A Z", 3},{"B X", 1}, {"C Y", 2}, //Loss
        {"A X", 4},{"B Y", 5}, {"C Z", 6} //Draw
    };

    map<string, int> decrypted =
    {
        {"A Z", 8},{"B Z", 9}, {"C Z", 7}, //Win
        {"A X", 3},{"B X", 1}, {"C X", 2}, //Loss
        {"A Y", 4},{"B Y", 5}, {"C Y", 6} //Draw
    };

    ifstream file("Day2.txt");
    string str;
    while (getline(file, str))
    {
        part1 += outcome.at(str);
        part2 += decrypted.at(str);
    }

    cout << part1 << endl;
    cout << part2 << endl;
}

void Calendar::Day3()
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
    while(getline(file, str))
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

void Calendar::Day4()
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
        string second = str.substr(str.find(delimiter2) +1, str.length() - 1);

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

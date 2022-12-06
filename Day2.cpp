#include "Day2.h"
#include "Includes.h"

void Day2::Do()
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

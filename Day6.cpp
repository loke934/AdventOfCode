#include "Day6.h"
#include "Includes.h"

void Day6::Do()
{
    ifstream ifs("Day6.txt");
    string line((istreambuf_iterator<char>(ifs)),
        (istreambuf_iterator<char>()));

    int part1 = 4;
    int part2 = 14;
    
    set<char> previousFour;
    for (size_t index = part2; index < line.length(); index++)
    {
        for (size_t y = 1; y < part2 +1; y++)
        {
            if (previousFour.find(line[index - y]) != previousFour.end())
            {
                previousFour.clear();
                break;
            }
            previousFour.insert(line[index - y]);
        }

        if (previousFour.size() == part2)
        {
            cout << "Number of processed: " << index << endl;
            break;
        }
    }

}


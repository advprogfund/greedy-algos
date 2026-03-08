#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

void ReadInputData(std::string fileSource)
{
    // This code is REUSED from my previous Gale Shapley assignment, and only serves the purpose of reading input file.
    // Citation for methodology followed: https://www.geeksforgeeks.org/cpp/how-to-read-from-a-file-in-cpp/

    // Retrieve the data from the file
    std::ifstream source(fileSource);

    if (!source.is_open())
    {
        std::cout << "Unsuccessful in opening file." << std::endl;
    }
    else
    {

        std::string currLine;
        int capacity = 0;
        int numRequests = 0;
        bool isFirst = true;
        std::vector<int> intVec;

        // Parse the data line-by-line, using the formatting specified in the description
        while (getline(source, currLine))
        {
            std::cout << currLine << std::endl;

            if (isFirst)
            {
                // This line includes both cache capacity and number of requests.
                // The location of the whitespace between the two on the line must be determined to separate them,
                // as capacity and requests can be one or multiple digits (non-fixed character length).
                isFirst = false;

                // First, find where the whitespace takes place to know how long the capacity is
                int whitespaceIndex = -1;
                for (int i = 0; i < currLine.size(); i++)
                {
                    if (currLine.substr(i, 1) == " ")
                    {
                        if (whitespaceIndex == -1)
                        {
                            whitespaceIndex = i;
                        }
                        else
                        {
                            // Multiple white spaces, improper format
                            std::cout << "Error?" << std::endl;
                        }
                    }
                }

                // Now, create a substring from the beginning of the line to the whitespace index.
                // Convert this substring to the first integer for capacity.
                capacity = std::stoi(currLine.substr(0, whitespaceIndex));
                std::cout << "Capacity: " << capacity << std::endl;

                // The rest of the current line is the number of requests.
                // Substr uses size of after start index, so must subtract capacity's size and the newline symbol,
                // but not the whitespace.
                numRequests = std::stoi(currLine.substr(whitespaceIndex + 1, currLine.length() - 1 - capacity));
                std::cout << "Number of requests: " << numRequests << std::endl;
            }
            else
            {
                // The line represents a sequence of integer IDs
                // Citation: https://stackoverflow.com/questions/216068/parsing-integers-from-a-line
                std::stringstream ss(currLine);

                // Keep adding to the list m times
                for (int i = 0; i < numRequests; i++)
                {
                    int val;
                    ss >> val;

                    std::cout << "Int: " << val << std::endl;
                    intVec.push_back(val);
                }
            }
        }

        // All of the data from the input file---cache capcity, number of requests, and the integer sequence---should
        // now all be in the program and ready for computation.
        source.close();
    }
}


int main()
{
    std::cout << "Hello, World!" << std::endl;

    ReadInputData("example.in");

    return 0;
}
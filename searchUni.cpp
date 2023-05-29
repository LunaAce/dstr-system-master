#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cctype>
#include <vector>
#include <iomanip> 

const int ARRAY_SIZE = 1422;

struct University
{
    int rank;
    std::string name;
    std::string locationCode;
    std::string location;
    double arScore;
    int arRank;
    double erScore;
    int erRank;
    double fsrScore;
    int fsrRank;
    double cpfScore;
    int cpfRank;
    double ifrScore;
    int ifrRank;
    double isrScore;
    int isrRank;
    int irnRank;
    double irnScore;
    double gerScore;
    int gerRank;
    double scoreScaled;
};

void readUni(const std::string &filename, University universities[], int &numUniversities)
{
    std::ifstream inputFile(filename);
    if (!inputFile)
    {
        std::cout << "Failed to open the CSV file." << std::endl;
        return;
    }

    std::string line;
    std::getline(inputFile, line); // Skip the header line

    // while retrieving info from uni.csv, it will check for invalid data, for score-related it will convert invalid data to -1.0
    // for rank-related, convert to -1
    // if rank-related is 501+ OR 601+, it will set it as 501 and 601 respectively in array, but for display purpose, it will print it out as 501+ and 601+ respectively
    numUniversities = 0;
    while (std::getline(inputFile, line) && numUniversities < ARRAY_SIZE)
    {
        std::istringstream iss(line);
        std::string data;

        std::getline(iss, data, ','); // Rank
        try
        {
            universities[numUniversities].rank = std::stoi(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].rank = -1;
            data = "n/a";
        }

        std::getline(iss, universities[numUniversities].name, ',');
        std::getline(iss, universities[numUniversities].locationCode, ',');
        std::getline(iss, universities[numUniversities].location, ',');

        std::getline(iss, data, ','); // AR Score
        try
        {
            universities[numUniversities].arScore = std::stod(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].arScore = -1.0;
            data = "n/a";
        }

        std::getline(iss, data, ','); // AR Rank
        try
        {
            universities[numUniversities].arRank = std::stoi(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].arRank = -1;
            data = "n/a";
        }

        std::getline(iss, data, ','); // ER Score
        try
        {
            universities[numUniversities].erScore = std::stoi(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].erScore = -1.0;
        }

        std::getline(iss, data, ','); // ER Rank
        try
        {
            universities[numUniversities].erRank = std::stoi(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].erRank = -1;
            data = "n/a";
        }

        std::getline(iss, data, ','); // FSR Score
        try
        {
            universities[numUniversities].fsrScore = std::stoi(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].fsrScore = -1.0;
            data = "n/a";
        }

        std::getline(iss, data, ','); // FSR Rank
        try
        {
            universities[numUniversities].fsrRank = std::stoi(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].fsrRank = -1;
            data = "n/a";
        }

        std::getline(iss, data, ','); // CPF Score
        try
        {
            universities[numUniversities].cpfScore = std::stoi(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].cpfScore = -1.0;
        }

        std::getline(iss, data, ','); // CPF Rank
        try
        {
            universities[numUniversities].cpfRank = std::stoi(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].cpfRank = -1;
            data = "n/a";
        }

        std::getline(iss, data, ','); // IFR Score
        try
        {
            universities[numUniversities].ifrScore = std::stoi(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].ifrScore = -1.0;
            data = "n/a";
        }

        std::getline(iss, data, ','); // IFR Rank
        try
        {
            universities[numUniversities].ifrRank = std::stoi(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].ifrRank = -1;
            data = "n/a";
        }

        std::getline(iss, data, ','); // ISR Score
        try
        {
            universities[numUniversities].isrScore = std::stoi(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].isrScore = -1.0;
            data = "n/a";
        }

        std::getline(iss, data, ','); // ISR Rank
        try
        {
            universities[numUniversities].isrRank = std::stoi(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].isrRank = -1;
            data = "n/a";
        }

        std::getline(iss, data, ','); // IRN Score
        try
        {
            universities[numUniversities].irnScore = std::stoi(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].irnScore = -1.0;
            data = "n/a";
        }

        std::getline(iss, data, ','); // IRN Rank
        try
        {
            universities[numUniversities].irnRank = std::stoi(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].irnRank = -1;
            data = "n/a";
        }

        std::getline(iss, data, ','); // GER Score
        try
        {
            universities[numUniversities].gerScore = std::stoi(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].gerScore = -1.0;
            data = "n/a";
        }

        std::getline(iss, data, ','); // GER Rank
        try
        {
            universities[numUniversities].gerRank = std::stoi(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].gerRank = -1;
            data = "n/a";
        }

        std::getline(iss, data, ','); // Score Scaled Rank
        try
        {
            universities[numUniversities].scoreScaled = std::stoi(data);
        }
        catch (const std::exception &)
        {
            universities[numUniversities].scoreScaled = -1.0;
            data = "n/a";
        }

        numUniversities++;
    }

    inputFile.close();
}

std::string formatDouble(double value)

{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(3) << value;
    return oss.str();
}

int findUniversity(const University universities[], int numUniversities, int value)
{
    for (int i = 0; i < numUniversities; i++)
    {
        if (universities[i].rank == value)
        {
            return i;
        }
    }

    return -1;
}


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip> // for std::setprecision

#include "readUni.h"

void swap(University& a, University& b) {
    University temp = a;
    a = b;
    b = temp;
}

bool compareByRank(const University& a, const University& b) {

    return a.rank < b.rank;
}


// Function to partition the array and return the pivot index
int partition(University universities[], int low, int high, std::string searchCriteria) {
    std::string pivot = universities[high].name;
    int i = low - 1;

    if (searchCriteria == "rank") {
        // University pivot = universities[high];
        // int i = low - 1;

        // for (int j = low; j <= high - 1; j++) {
        //     if (compareByRank(universities[j], pivot)) {
        //         i++;
        //         swap(universities[i], universities[j]);
        //     }
        // }
    } else if (searchCriteria == "name") {
        for (int j = low; j <= high - 1; j++) {
            if (universities[j].name.compare(pivot) < 0) {
                i++;
                swap(universities[i], universities[j]);
            }
        }
    }


    swap(universities[i + 1], universities[high]);
    return i + 1;
}

void quickSort(University universities[], int low, int high, std::string searchCriteria) {
    if (low < high) {
        int pivotIndex = partition(universities, low, high, searchCriteria);
        quickSort(universities, low, pivotIndex - 1, searchCriteria);
        quickSort(universities, pivotIndex + 1, high, searchCriteria);
    }
}

// void readUni(const std::string &filename, University universities[], int &numUniversities)
// {
//     std::ifstream inputFile(filename);
//     if (!inputFile)
//     {
//         std::cout << "Failed to open the CSV file." << std::endl;
//         return;
//     }

//     std::string line;
//     std::getline(inputFile, line); // Skip the header line

//     // while retrieving info from uni.csv, it will check for invalid data, for score-related it will convert invalid data to -1.0
//     // for rank-related, convert to -1
//     // if rank-related is 501+ OR 601+, it will set it as 501 and 601 respectively in array, but for display purpose, it will print it out as 501+ and 601+ respectively
//     numUniversities = 0;
//     while (std::getline(inputFile, line) && numUniversities < ARRAY_SIZE)
//     {
//         std::istringstream iss(line);
//         std::string data;

//         std::getline(iss, data, ','); // Rank
//         try
//         {
//             universities[numUniversities].rank = std::stoi(data);
//         }
//         catch (const std::exception &)
//         {
//             universities[numUniversities].rank = -1;
//             data = "n/a";
//         }

//         // Check if the line starts with an integer (rank value)
//         bool startsWithRank = false;
//         try
//         {
//             std::stoi(line);
//             startsWithRank = true;
//         }
//         catch (const std::exception &) {}

//         // Read the name field
//         if (startsWithRank)
//         {
//             // If the line starts with a rank, consider the name field as the remaining part of the line
//             universities[numUniversities].name = line.substr(data.size() + 1);
//         }
//         else
//         {
//             // Otherwise, read the name field as usual
//             std::getline(iss, universities[numUniversities].name, ',');
//         }

//         std::getline(iss, universities[numUniversities].name, ',');
//         std::getline(iss, universities[numUniversities].locationCode, ',');
//         std::getline(iss, universities[numUniversities].location, ',');

//         std::getline(iss, data, ','); // AR Score
//         try
//         {
//             universities[numUniversities].arScore = std::stod(data);
//         }
//         catch (const std::exception &)
//         {
//             universities[numUniversities].arScore = -1.0;
//             data = "n/a";
//         }

//         std::getline(iss, data, ','); // AR Rank
//         try
//         {
//             universities[numUniversities].arRank = std::stoi(data);
//         }
//         catch (const std::exception &)
//         {
//             universities[numUniversities].arRank = -1;
//             data = "n/a";
//         }

//         std::getline(iss, data, ','); // ER Score
//         try
//         {
//             universities[numUniversities].erScore = std::stoi(data);
//         }
//         catch (const std::exception &)
//         {
//             universities[numUniversities].erScore = -1.0;
//         }

//         std::getline(iss, data, ','); // ER Rank
//         try
//         {
//             universities[numUniversities].erRank = std::stoi(data);
//         }
//         catch (const std::exception &)
//         {
//             universities[numUniversities].erRank = -1;
//             data = "n/a";
//         }

//         std::getline(iss, data, ','); // FSR Score
//         try
//         {
//             universities[numUniversities].fsrScore = std::stoi(data);
//         }
//         catch (const std::exception &)
//         {
//             universities[numUniversities].fsrScore = -1.0;
//             data = "n/a";
//         }

//         std::getline(iss, data, ','); // FSR Rank
//         try
//         {
//             universities[numUniversities].fsrRank = std::stoi(data);
//         }
//         catch (const std::exception &)
//         {
//             universities[numUniversities].fsrRank = -1;
//             data = "n/a";
//         }

//         std::getline(iss, data, ','); // CPF Score
//         try
//         {
//             universities[numUniversities].cpfScore = std::stoi(data);
//         }
//         catch (const std::exception &)
//         {
//             universities[numUniversities].cpfScore = -1.0;
//         }

//         std::getline(iss, data, ','); // CPF Rank
//         try
//         {
//             universities[numUniversities].cpfRank = std::stoi(data);
//         }
//         catch (const std::exception &)
//         {
//             universities[numUniversities].cpfRank = -1;
//             data = "n/a";
//         }

//         std::getline(iss, data, ','); // IFR Score
//         try
//         {
//             universities[numUniversities].ifrScore = std::stoi(data);
//         }
//         catch (const std::exception &)
//         {
//             universities[numUniversities].ifrScore = -1.0;
//             data = "n/a";
//         }

//         std::getline(iss, data, ','); // IFR Rank
//         try
//         {
//             universities[numUniversities].ifrRank = std::stoi(data);
//         }
//         catch (const std::exception &)
//         {
//             universities[numUniversities].ifrRank = -1;
//             data = "n/a";
//         }

//         std::getline(iss, data, ','); // ISR Score
//         try
//         {
//             universities[numUniversities].isrScore = std::stoi(data);
//         }
//         catch (const std::exception &)
//         {
//             universities[numUniversities].isrScore = -1.0;
//             data = "n/a";
//         }

//         std::getline(iss, data, ','); // ISR Rank
//         try
//         {
//             universities[numUniversities].isrRank = std::stoi(data);
//         }
//         catch (const std::exception &)
//         {
//             universities[numUniversities].isrRank = -1;
//             data = "n/a";
//         }

//         std::getline(iss, data, ','); // IRN Score
//         try
//         {
//             universities[numUniversities].irnScore = std::stoi(data);
//         }
//         catch (const std::exception &)
//         {
//             universities[numUniversities].irnScore = -1.0;
//             data = "n/a";
//         }

//         std::getline(iss, data, ','); // IRN Rank
//         try
//         {
//             universities[numUniversities].irnRank = std::stoi(data);
//         }
//         catch (const std::exception &)
//         {
//             universities[numUniversities].irnRank = -1;
//             data = "n/a";
//         }

//         std::getline(iss, data, ','); // GER Score
//         try
//         {
//             universities[numUniversities].gerScore = std::stoi(data);
//         }
//         catch (const std::exception &)
//         {
//             universities[numUniversities].gerScore = -1.0;
//             data = "n/a";
//         }

//         std::getline(iss, data, ','); // GER Rank
//         try
//         {
//             universities[numUniversities].gerRank = std::stoi(data);
//         }
//         catch (const std::exception &)
//         {
//             universities[numUniversities].gerRank = -1;
//             data = "n/a";
//         }

//         std::getline(iss, data, ','); // Score Scaled Rank
//         try
//         {
//             universities[numUniversities].scoreScaled = std::stoi(data);
//         }
//         catch (const std::exception &)
//         {
//             universities[numUniversities].scoreScaled = -1.0;
//             data = "n/a";
//         }

//         numUniversities++;
//     }

//     inputFile.close();
    
// }


bool binarySearchUni(const University universities[], int numUniversities, int targetRank, const std::string& targetName,  const std::string& searchCriteria)
{
    
    int low = 0;
    int high = numUniversities - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (searchCriteria == "rank")
        {
            if (universities[mid].rank == targetRank)
            {
                return true; // Found the target rank
            }
            else if (universities[mid].rank < targetRank)
            {
                low = mid + 1; // Search the upper half
            }
            else
            {
                high = mid - 1; // Search the lower half
            }
        }
        else if (searchCriteria == "name")
        {
            // Perform a lexicographic comparison for the target name
            int comparisonResult = universities[mid].name.compare(targetName);
            if (comparisonResult == 0)
            {
                return true; // Found the target name
            }
            else if (comparisonResult < 0)
            {
                low = mid + 1; // Search the upper half
            }
            else
            {
                high = mid - 1; // Search the lower half
            }
        }
        else
        {
            // Invalid search criteria
            return false;
        }
    }

    return false; // Target not found
}


void displayTarget()
{
    University universities[ARRAY_SIZE];
    int numUniversities = 0;

    readUni("uni.csv", universities, numUniversities);
    int targetRank;
    double targetScale;
    std::string targetName;
    std::string searchCriteria;
    std::cout << "Enter the search criteria (rank or name): ";
    std::cin >> searchCriteria;


    bool isFound = false;

    if (searchCriteria == "rank")
    {
        // quickSort(universities, 0, ARRAY_SIZE - 1, "rank");
        std::cout << "Enter the rank: ";
        std::cin >> targetRank;
        isFound = binarySearchUni(universities, numUniversities, targetRank, "","rank");
    }
    else if (searchCriteria == "name")
    {
        quickSort(universities, 0, ARRAY_SIZE - 1, "name");
        std::cout << "Enter the university name: ";
        std::cin.ignore();
        std::getline(std::cin, targetName);

        isFound = binarySearchUni(universities, numUniversities, -1, targetName,"name");
    }
    else
    {
        std::cout << "Invalid search criteria. Please choose either rank or name." << std::endl;
        return;
    }

    if (isFound)
    {
        std::cout << "University found!" << std::endl;

        // Find and display the specific details of the target
        for (int i = 0; i < numUniversities; i++)
        {
            if ((universities[i].rank == targetRank) ||
                (universities[i].name == targetName))
            {
                University &uni = universities[i];
                std::cout << "University #" << i + 1 << std::endl;
                std::cout << "Rank: " << (uni.rank == -1 ? "n/a" : std::to_string(uni.rank)) << std::endl;
                std::cout << "Name: " << uni.name << std::endl;
                std::cout << "Location Code: " << uni.locationCode << std::endl;
                std::cout << "Location: " << uni.location << std::endl;
                std::cout << "AR Score: " << (uni.arScore == -1.0 ? "n/a" : std::to_string(uni.arScore)) << std::endl;
                std::cout << "AR Rank: " << (uni.arRank == -1 ? "n/a" : (uni.arRank == 501 ? "501+" : (uni.arRank == 601 ? "601+" : std::to_string(uni.arRank)))) << std::endl;
                std::cout << "ER Score: " << (uni.erScore == -1.0 ? "n/a" : std::to_string(uni.erScore)) << std::endl;
                std::cout << "ER Rank: " << (uni.erRank == -1 ? "n/a" : (uni.erRank == 501 ? "501+" : (uni.erRank == 601 ? "601+" : std::to_string(uni.erRank)))) << std::endl;
                std::cout << "FSR Score: " << (uni.fsrScore == -1.0 ? "n/a" : std::to_string(uni.fsrScore)) << std::endl;
                std::cout << "FSR Rank: " << (uni.fsrRank == -1 ? "n/a" : (uni.fsrRank == 501 ? "501+" : (uni.fsrRank == 601 ? "601+" : std::to_string(uni.fsrRank)))) << std::endl;
                std::cout << "CPF Score: " << (uni.cpfScore == -1.0 ? "n/a" : std::to_string(uni.cpfScore)) << std::endl;
                std::cout << "CPF Rank: " << (uni.cpfRank == -1 ? "n/a" : (uni.cpfRank == 501 ? "501+" : (uni.cpfRank == 601 ? "601+" : std::to_string(uni.cpfRank)))) << std::endl;
                std::cout << "IFR Score: " << (uni.ifrScore == -1.0 ? "n/a" : std::to_string(uni.ifrScore)) << std::endl;
                std::cout << "IFR Rank: " << (uni.ifrRank == -1 ? "n/a" : (uni.ifrRank == 501 ? "501+" : (uni.ifrRank == 601 ? "601+" : std::to_string(uni.ifrRank)))) << std::endl;
                std::cout << "ISR Score: " << (uni.isrScore == -1.0 ? "n/a" : std::to_string(uni.isrScore)) << std::endl;
                std::cout << "ISR Rank: " << (uni.isrRank == -1 ? "n/a" : (uni.isrRank == 501 ? "501+" : (uni.isrRank == 601 ? "601+" : std::to_string(uni.isrRank)))) << std::endl;
                std::cout << "IRN Score: " << (uni.irnScore == -1.0 ? "n/a" : std::to_string(uni.irnScore)) << std::endl;
                std::cout << "IRN Rank: " << (uni.irnRank == -1 ? "n/a" : (uni.irnRank == 501 ? "501+" : (uni.irnRank == 601 ? "601+" : std::to_string(uni.irnRank)))) << std::endl;
                std::cout << "GER Score: " << (uni.gerScore == -1.0 ? "n/a" : std::to_string(uni.gerScore)) << std::endl;
                std::cout << "GER Rank: " << (uni.gerRank == -1 ? "n/a" : (uni.gerRank == 501 ? "501+" : (uni.gerRank == 601 ? "601+" : std::to_string(uni.gerRank)))) << std::endl;
                std::cout << "Score Scaled: " << (uni.scoreScaled == -1.0 ? "n/a" : std::to_string(uni.scoreScaled)) << std::endl;
                std::cout << std::endl;
                break;
            }
        }
    }
    else
    {
        std::cout << "University not found." << std::endl;
    }
}





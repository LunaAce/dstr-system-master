#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip> 

#include "readUni.h"
#include "exit.h"


// Swap function for universities
void swap(University &a, University &b)
{
    University temp = a;
    a = b;
    b = temp;
}

void quickSort(University universities[], int low, int high, const std::string &searchCriteria)
{
    if (low < high)
    {
        int pivotIndex;

        if (searchCriteria == "rank" || searchCriteria == "arRank" ||
            searchCriteria == "erRank" || searchCriteria == "fsrRank" ||
            searchCriteria == "cpfRank" || searchCriteria == "ifrRank" ||
            searchCriteria == "isrRank" || searchCriteria == "irnRank" ||
            searchCriteria == "gerRank")
        {
            pivotIndex = low;
        }
        else if (searchCriteria == "name" || searchCriteria == "location" ||
                 searchCriteria == "locationCode")
        {
            pivotIndex = low + (high - low) / 2;
        }
        else if (searchCriteria == "scoreScaled" || searchCriteria == "arScore" ||
                 searchCriteria == "erScore" || searchCriteria == "fsrScore" ||
                 searchCriteria == "cpfScore" || searchCriteria == "ifrScore" ||
                 searchCriteria == "isrScore" || searchCriteria == "irnScore" ||
                 searchCriteria == "gerScore")
        {
            pivotIndex = high;
        }
        else
        {
            // Invalid search criteria
            return;
        }

        University pivotValue = universities[pivotIndex];
        int i = low;
        int j = high;

        while (i <= j)
        {
            if (searchCriteria == "name")
            {
                while (universities[i].name.compare(pivotValue.name) < 0)
                {
                    i++;
                }

                while (universities[j].name.compare(pivotValue.name) > 0)
                {
                    j--;
                }
            }
            else if (searchCriteria == "locationCode")
            {
                while (universities[i].locationCode.compare(pivotValue.locationCode) < 0)
                {
                    i++;
                }

                while (universities[j].locationCode.compare(pivotValue.locationCode) > 0)
                {
                    j--;
                }
            }
            else if (searchCriteria == "location")
            {
                while (universities[i].location.compare(pivotValue.location) < 0)
                {
                    i++;
                }

                while (universities[j].location.compare(pivotValue.location) > 0)
                {
                    j--;
                }
            }

            else if (searchCriteria == "arRank")
            {
                while (universities[i].arRank < pivotValue.arRank)
                {
                    i++;
                }

                while (universities[j].arRank > pivotValue.arRank)
                {
                    j--;
                }
            }
            else if (searchCriteria == "erRank")
            {
                while (universities[i].erRank < pivotValue.erRank)
                {
                    i++;
                }

                while (universities[j].erRank > pivotValue.erRank)
                {
                    j--;
                }
            }
            else if (searchCriteria == "fsrRank")
            {
                while (universities[i].fsrRank < pivotValue.fsrRank)
                {
                    i++;
                }

                while (universities[j].fsrRank > pivotValue.fsrRank)
                {
                    j--;
                }
            }
            else if (searchCriteria == "cpfRank")
            {
                while (universities[i].cpfRank < pivotValue.cpfRank)
                {
                    i++;
                }

                while (universities[j].cpfRank > pivotValue.cpfRank)
                {
                    j--;
                }
            }
            else if (searchCriteria == "ifrRank")
            {
                while (universities[i].ifrRank < pivotValue.ifrRank)
                {
                    i++;
                }

                while (universities[j].ifrRank > pivotValue.ifrRank)
                {
                    j--;
                }
            }
            else if (searchCriteria == "isrRank")
            {
                while (universities[i].isrRank < pivotValue.isrRank)
                {
                    i++;
                }

                while (universities[j].isrRank > pivotValue.isrRank)
                {
                    j--;
                }
            }
            else if (searchCriteria == "irnRank")
            {
                while (universities[i].irnRank < pivotValue.irnRank)
                {
                    i++;
                }

                while (universities[j].irnRank > pivotValue.irnRank)
                {
                    j--;
                }
            }
            else if (searchCriteria == "gerRank")
            {
                while (universities[i].gerRank < pivotValue.gerRank)
                {
                    i++;
                }

                while (universities[j].gerRank > pivotValue.gerRank)
                {
                    j--;
                }
            }
            else if (searchCriteria == "scoreScaled")
            {
                while (universities[i].scoreScaled < pivotValue.scoreScaled)
                {
                    i++;
                }

                while (universities[j].scoreScaled > pivotValue.scoreScaled)
                {
                    j--;
                }
            }
            else if (searchCriteria == "arScore")
            {
                while (universities[i].arScore < pivotValue.arScore)
                {
                    i++;
                }

                while (universities[j].arScore > pivotValue.arScore)
                {
                    j--;
                }
            }
            else if (searchCriteria == "erScore")
            {
                while (universities[i].erScore < pivotValue.erScore)
                {
                    i++;
                }

                while (universities[j].erScore > pivotValue.erScore)
                {
                    j--;
                }
            }
            else if (searchCriteria == "fsrScore")
            {
                while (universities[i].fsrScore < pivotValue.fsrScore)
                {
                    i++;
                }

                while (universities[j].fsrScore > pivotValue.fsrScore)
                {
                    j--;
                }
            }
            else if (searchCriteria == "cpfScore")
            {
                while (universities[i].cpfScore < pivotValue.cpfScore)
                {
                    i++;
                }

                while (universities[j].cpfScore > pivotValue.cpfScore)
                {
                    j--;
                }
            }
            else if (searchCriteria == "ifrScore")
            {
                while (universities[i].ifrScore < pivotValue.ifrScore)
                {
                    i++;
                }

                while (universities[j].ifrScore > pivotValue.ifrScore)
                {
                    j--;
                }
            }
            else if (searchCriteria == "isrScore")
            {
                while (universities[i].isrScore < pivotValue.isrScore)
                {
                    i++;
                }

                while (universities[j].isrScore > pivotValue.isrScore)
                {
                    j--;
                }
            }
            else if (searchCriteria == "irnScore")
            {
                while (universities[i].irnScore < pivotValue.irnScore)
                {
                    i++;
                }

                while (universities[j].irnScore > pivotValue.irnScore)
                {
                    j--;
                }
            }
            else if (searchCriteria == "gerScore")
            {
                while (universities[i].gerScore < pivotValue.gerScore)
                {
                    i++;
                }

                while (universities[j].gerScore > pivotValue.gerScore)
                {
                    j--;
                }
            }

            if (i <= j)
            {
                swap(universities[i], universities[j]);
                i++;
                j--;
            }
        }

        if (low < j)
        {
            quickSort(universities, low, j, searchCriteria);
        }

        if (i < high)
        {
            quickSort(universities, i, high, searchCriteria);
        }
    }
}

bool binarySearchUni(const University universities[], int numUniversities, int targetRank, const std::string &targetName, double targetScore, const std::string &searchCriteria)
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
        else if (searchCriteria == "locationCode")
        {
            // Perform a lexicographic comparison for the target name
            int comparisonResult = universities[mid].locationCode.compare(targetName);
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
        else if (searchCriteria == "location")
        {
            // Perform a lexicographic comparison for the target name
            int comparisonResult = universities[mid].location.compare(targetName);
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
        else if (searchCriteria == "scoreScaled")
        {
            if (universities[mid].scoreScaled == targetScore)
            {
                return true; // Found the target score
            }
            else if (universities[mid].scoreScaled < targetScore)
            {
                low = mid + 1; // Search the upper half
            }
            else
            {
                high = mid - 1; // Search the lower half
            }
        }
        else if (searchCriteria == "arScore")
        {
            if (universities[mid].arScore == targetScore)
            {
                return true; // Found the target score
            }
            else if (universities[mid].arScore < targetScore)
            {
                low = mid + 1; // Search the upper half
            }
            else
            {
                high = mid - 1; // Search the lower half
            }
        }
        else if (searchCriteria == "erScore")
        {
            if (universities[mid].erScore == targetScore)
            {
                return true; // Found the target score
            }
            else if (universities[mid].erScore < targetScore)
            {
                low = mid + 1; // Search the upper half
            }
            else
            {
                high = mid - 1; // Search the lower half
            }
        }
        else if (searchCriteria == "fsrScore")
        {
            if (universities[mid].fsrScore == targetScore)
            {
                return true; // Found the target score
            }
            else if (universities[mid].fsrScore < targetScore)
            {
                low = mid + 1; // Search the upper half
            }
            else
            {
                high = mid - 1; // Search the lower half
            }
        }
        else if (searchCriteria == "cpfScore")
        {
            if (universities[mid].cpfScore == targetScore)
            {
                return true; // Found the target score
            }
            else if (universities[mid].cpfScore < targetScore)
            {
                low = mid + 1; // Search the upper half
            }
            else
            {
                high = mid - 1; // Search the lower half
            }
        }
        else if (searchCriteria == "ifrScore")
        {
            if (universities[mid].ifrScore == targetScore)
            {
                return true; // Found the target score
            }
            else if (universities[mid].ifrScore < targetScore)
            {
                low = mid + 1; // Search the upper half
            }
            else
            {
                high = mid - 1; // Search the lower half
            }
        }
        else if (searchCriteria == "isrScore")
        {
            if (universities[mid].isrScore == targetScore)
            {
                return true; // Found the target score
            }
            else if (universities[mid].isrScore < targetScore)
            {
                low = mid + 1; // Search the upper half
            }
            else
            {
                high = mid - 1; // Search the lower half
            }
        }
        else if (searchCriteria == "irnScore")
        {
            if (universities[mid].irnScore == targetScore)
            {
                return true; // Found the target score
            }
            else if (universities[mid].irnScore < targetScore)
            {
                low = mid + 1; // Search the upper half
            }
            else
            {
                high = mid - 1; // Search the lower half
            }
        }
        else if (searchCriteria == "gerScore")
        {
            if (universities[mid].gerScore == targetScore)
            {
                return true; // Found the target score
            }
            else if (universities[mid].gerScore < targetScore)
            {
                low = mid + 1; // Search the upper half
            }
            else
            {
                high = mid - 1; // Search the lower half
            }
        }
        else if (searchCriteria == "arRank")
        {
            if (universities[mid].arRank == targetRank)
            {
                return true; // Found the target rank
            }
            else if (universities[mid].arRank < targetRank)
            {
                low = mid + 1; // Search the upper half
            }
            else
            {
                high = mid - 1; // Search the lower half
            }
        }
        else if (searchCriteria == "erRank")
        {
            if (universities[mid].erRank == targetRank)
            {
                return true; // Found the target rank
            }
            else if (universities[mid].erRank < targetRank)
            {
                low = mid + 1; // Search the upper half
            }
            else
            {
                high = mid - 1; // Search the lower half
            }
        }
        else if (searchCriteria == "fsrRank")
        {
            if (universities[mid].fsrRank == targetRank)
            {
                return true; // Found the target rank
            }
            else if (universities[mid].fsrRank < targetRank)
            {
                low = mid + 1; // Search the upper half
            }
            else
            {
                high = mid - 1; // Search the lower half
            }
        }
        else if (searchCriteria == "cpfRank")
        {
            if (universities[mid].cpfRank == targetRank)
            {
                return true; // Found the target rank
            }
            else if (universities[mid].cpfRank < targetRank)
            {
                low = mid + 1; // Search the upper half
            }
            else
            {
                high = mid - 1; // Search the lower half
            }
        }
        else if (searchCriteria == "ifrRank")
        {
            if (universities[mid].ifrRank == targetRank)
            {
                return true; // Found the target rank
            }
            else if (universities[mid].ifrRank < targetRank)
            {
                low = mid + 1; // Search the upper half
            }
            else
            {
                high = mid - 1; // Search the lower half
            }
        }
        else if (searchCriteria == "isrRank")
        {
            if (universities[mid].isrRank == targetRank)
            {
                return true; // Found the target rank
            }
            else if (universities[mid].isrRank < targetRank)
            {
                low = mid + 1; // Search the upper half
            }
            else
            {
                high = mid - 1; // Search the lower half
            }
        }
        else if (searchCriteria == "irnRank")
        {
            if (universities[mid].irnRank == targetRank)
            {
                return true; // Found the target rank
            }
            else if (universities[mid].irnRank < targetRank)
            {
                low = mid + 1; // Search the upper half
            }
            else
            {
                high = mid - 1; // Search the lower half
            }
        }
        else if (searchCriteria == "gerRank")
        {
            if (universities[mid].gerRank == targetRank)
            {
                return true; // Found the target rank
            }
            else if (universities[mid].gerRank < targetRank)
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
    double targetScore;
    std::string targetName;

    bool isFound = false;
    std::string searchCriteria;

    int searchChoice;

    while (true)
    {
        std::cout << "Binary Search Menu" << std::endl;
        std::cout << "1. University Rank." << std::endl;
        std::cout << "2. University Name." << std::endl;
        std::cout << "3. University Scaled Score." << std::endl;
        std::cout << "4. Location Code." << std::endl;
        std::cout << "5. Location." << std::endl;
        std::cout << "6. AR Score." << std::endl;
        std::cout << "7. ER Score." << std::endl;
        std::cout << "8. FSR Score." << std::endl;
        std::cout << "9. CPF Score." << std::endl;
        std::cout << "10. IFR Score." << std::endl;
        std::cout << "11. ISR Score." << std::endl;
        std::cout << "12. IRN Score." << std::endl;
        std::cout << "13. GER Score." << std::endl;
        std::cout << "14. AR Rank." << std::endl;
        std::cout << "15. ER Rank." << std::endl;
        std::cout << "16. FSR Rank." << std::endl;
        std::cout << "17. CPF Rank." << std::endl;
        std::cout << "18. IFR Rank." << std::endl;
        std::cout << "19. ISR Rank." << std::endl;
        std::cout << "20. IRN Rank." << std::endl;
        std::cout << "21. GER Rank." << std::endl;
        std::cout << "22. Exit Program." << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> searchChoice;

        switch (searchChoice)
        {
        case 1:

            std::cout << "Enter the rank: ";
            std::cin >> targetRank;
            isFound = binarySearchUni(universities, numUniversities, targetRank, "", targetScore, "rank");

            if (isFound)
            {
                std::cout << "University found!" << std::endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (universities[i].rank == targetRank)
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
            break;
        case 2:
            quickSort(universities, 0, ARRAY_SIZE - 1, "name");
            std::cout << "Enter the university name: ";
            std::cin.ignore();
            std::getline(std::cin, targetName);
            isFound = binarySearchUni(universities, numUniversities, -1, targetName, targetScore, "name");

            if (isFound)
            {
                std::cout << "University found!" << std::endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if ((universities[i].name == targetName))
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
            break;
        case 3:
            quickSort(universities, 0, ARRAY_SIZE - 1, "scoreScaled");
            std::cout << "Enter the score scaled: ";
            std::cin >> targetScore;
            isFound = binarySearchUni(universities, numUniversities, -1, targetName, targetScore, "scoreScaled");

            if (isFound)
            {
                std::cout << "University found!" << std::endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].scoreScaled == targetScore))
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
            break;
        case 4:
            quickSort(universities, 0, ARRAY_SIZE - 1, "locationCode");
            std::cout << "Enter the location code: ";
            std::cin.ignore();
            std::getline(std::cin, targetName);
            isFound = binarySearchUni(universities, numUniversities, -1, targetName, -1.0, "locationCode");

            if (isFound)
            {
                std::cout << "University found!" << std::endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].locationCode == targetName))
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
            break;
        case 5:
            quickSort(universities, 0, ARRAY_SIZE - 1, "location");
            std::cout << "Enter the location: ";
            std::cin.ignore();
            std::getline(std::cin, targetName);
            isFound = binarySearchUni(universities, numUniversities, -1, targetName, -1.0, "location");

            if (isFound)
            {
                std::cout << "University found!" << std::endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].location == targetName))
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
            break;
        case 6:
            quickSort(universities, 0, ARRAY_SIZE - 1, "arScore");
            std::cout << "Enter the AR Score: ";
            std::cin >> targetScore;
            isFound = binarySearchUni(universities, numUniversities, -1, "", targetScore, "arScore");

            if (isFound)
            {
                std::cout << "University found!" << std::endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].arScore == targetScore))
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
            break;
        case 7:
            quickSort(universities, 0, ARRAY_SIZE - 1, "erScore");
            std::cout << "Enter the ER Score: ";
            std::cin >> targetScore;
            isFound = binarySearchUni(universities, numUniversities, -1, "", targetScore, "erScore");

            if (isFound)
            {
                std::cout << "University found!" << std::endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].erScore == targetScore))
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
            break;
        case 8:
            quickSort(universities, 0, ARRAY_SIZE - 1, "fsrScore");
            std::cout << "Enter the FSR Score: ";
            std::cin >> targetScore;
            isFound = binarySearchUni(universities, numUniversities, -1, "", targetScore, "fsrScore");

            if (isFound)
            {
                std::cout << "University found!" << std::endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].fsrScore == targetScore))
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
            break;
        case 9:
            quickSort(universities, 0, ARRAY_SIZE - 1, "cpfScore");
            std::cout << "Enter the CPF Score: ";
            std::cin >> targetScore;
            isFound = binarySearchUni(universities, numUniversities, -1, "", targetScore, "cpfScore");

            if (isFound)
            {
                std::cout << "University found!" << std::endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].cpfScore == targetScore))
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
            break;
        case 10:
            quickSort(universities, 0, ARRAY_SIZE - 1, "ifrScore");
            std::cout << "Enter the IFR Score: ";
            std::cin >> targetScore;
            isFound = binarySearchUni(universities, numUniversities, -1, "", targetScore, "ifrScore");

            if (isFound)
            {
                std::cout << "University found!" << std::endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].ifrScore == targetScore))
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
            break;
        case 11:
            quickSort(universities, 0, ARRAY_SIZE - 1, "isrScore");
            std::cout << "Enter the ISR Score: ";
            std::cin >> targetScore;
            isFound = binarySearchUni(universities, numUniversities, -1, "", targetScore, "isrScore");

            if (isFound)
            {
                std::cout << "University found!" << std::endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].isrScore == targetScore))
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
            break;
        case 12:
            quickSort(universities, 0, ARRAY_SIZE - 1, "irnScore");
            std::cout << "Enter the IRN Score: ";
            std::cin >> targetScore;
            isFound = binarySearchUni(universities, numUniversities, -1, "", targetScore, "irnScore");

            if (isFound)
            {
                std::cout << "University found!" << std::endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].irnScore == targetScore))
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
            break;
        case 13:
            quickSort(universities, 0, ARRAY_SIZE - 1, "gerScore");
            std::cout << "Enter the GER Score: ";
            std::cin >> targetScore;
            isFound = binarySearchUni(universities, numUniversities, -1, "", targetScore, "gerScore");

            if (isFound)
            {
                std::cout << "University found!" << std::endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].gerScore == targetScore))
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
            break;
        case 14:
            quickSort(universities, 0, ARRAY_SIZE - 1, "arRank");
            std::cout << "Enter the AR Rank: ";
            std::cin >> targetRank;
            isFound = binarySearchUni(universities, numUniversities, targetRank, "", -1.0, "arRank");

            if (isFound)
            {
                std::cout << "University found!" << std::endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if ((universities[i].arRank == targetRank))
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
            break;
        case 15:
            quickSort(universities, 0, ARRAY_SIZE - 1, "erRank");
            std::cout << "Enter the ER Rank: ";
            std::cin >> targetRank;
            isFound = binarySearchUni(universities, numUniversities, targetRank, "", -1.0, "erRank");

            if (isFound)
            {
                std::cout << "University found!" << std::endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].erRank == targetRank))
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
            break;
        case 16:
            quickSort(universities, 0, ARRAY_SIZE - 1, "fsrRank");
            std::cout << "Enter the FSR Rank: ";
            std::cin >> targetRank;
            isFound = binarySearchUni(universities, numUniversities, targetRank, "", -1.0, "fsrRank");

            if (isFound)
            {
                std::cout << "University found!" << std::endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].fsrRank == targetRank))
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
            break;
        case 17:
            quickSort(universities, 0, ARRAY_SIZE - 1, "cpfRank");
            std::cout << "Enter the CPF Rank: ";
            std::cin >> targetRank;
            isFound = binarySearchUni(universities, numUniversities, targetRank, "", -1.0, "cpfRank");

            if (isFound)
            {
                std::cout << "University found!" << std::endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].cpfRank == targetRank))
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
            break;
        case 18:
            quickSort(universities, 0, ARRAY_SIZE - 1, "ifrRank");
            std::cout << "Enter the IFR Rank: ";
            std::cin >> targetRank;
            isFound = binarySearchUni(universities, numUniversities, targetRank, "", -1.0, "ifrRank");

            if (isFound)
            {
                std::cout << "University found!" << std::endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].ifrRank == targetRank))
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
            break;
        case 19:
            quickSort(universities, 0, ARRAY_SIZE - 1, "isrRank");
            std::cout << "Enter the ISR Rank: ";
            std::cin >> targetRank;
            isFound = binarySearchUni(universities, numUniversities, targetRank, "", -1.0, "isrRank");

            if (isFound)
            {
                std::cout << "University found!" << std::endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].isrRank == targetRank))
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
            break;
        case 20:
            quickSort(universities, 0, ARRAY_SIZE - 1, "irnRank");
            std::cout << "Enter the IRN Rank: ";
            std::cin >> targetRank;
            isFound = binarySearchUni(universities, numUniversities, targetRank, "", -1.0, "irnRank");

            if (isFound)
            {
                std::cout << "University found!" << std::endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].irnRank == targetRank))
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
            break;
        case 21:
            quickSort(universities, 0, ARRAY_SIZE - 1, "gerRank");
            std::cout << "Enter the GER Rank: ";
            std::cin >> targetRank;
            isFound = binarySearchUni(universities, numUniversities, targetRank, "", -1.0, "gerRank");

            if (isFound)
            {
                std::cout << "University found!" << std::endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].gerRank == targetRank))
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
            break;
        
        case 22:
            exitProgram();

        default:
            std::cout << "Invalid search choice. Please try again." << std::endl;
        }

        std::cout << std::endl;
    }
}

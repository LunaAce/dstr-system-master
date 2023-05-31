#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

#include "readUni.h"

// celine quick sort
// Partition function for QuickSort
int partition(University universities[], int low, int high)
{
    string pivot = universities[high].name;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (universities[j].name <= pivot)
        {
            i++;
            swap(universities[i], universities[j]);
        }
    }
    swap(universities[i + 1], universities[high]);
    return (i + 1);
}

// QuickSort algorithm
void quickSort1(University universities[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(universities, low, high);

        quickSort1(universities, low, pivotIndex - 1);
        quickSort1(universities, pivotIndex + 1, high);
    }
}

void displaySortedUni()
{
    University universities[ARRAY_SIZE];
    int numUniversities = 0;

    readUni("uni.csv", universities, numUniversities);

    // Sort the universities array based on name in ascending order
    quickSort1(universities, 0, numUniversities - 1);

    const int pageSize = 20;
    int currentPage = 0;
    int totalPage = (numUniversities + pageSize - 1) / pageSize;

    while (currentPage < totalPage) {
        int startIndex = currentPage * pageSize;
        int endIndex = min(startIndex + pageSize, numUniversities);

        for (int i = startIndex; i < endIndex; i++) {
            University& uni = universities[i];
            cout << "University #" << i + 1 << endl;
            cout << "Name: " << uni.name << endl;
        }

        currentPage++;

        if (currentPage < totalPage) {
            cout << "Press Enter to continue or enter 'q' to quit: ";
            string input;
            getline(cin, input);

            if (input == "q") {
                break;
            }
        }
    }
}

// brian insertion sort
bool compareByName(const University &u1, const University &u2)
{
    return u1.name < u2.name;
}
void insertionSort(University *universities, int size, bool (*compare)(const University &, const University &))
{
    for (int i = 1; i < size; ++i)
    {
        University current = universities[i];
        int j = i - 1;
        while (j >= 0 && !compare(universities[j], current))
        { // Change the comparison condition
            universities[j + 1] = universities[j];
            --j;
        }
        universities[j + 1] = current;
    }
}

void displayInsertionSort()
{
    const int MAX_UNIVERSITIES = 1500;
    University universities[MAX_UNIVERSITIES];
    int count = 0;
    readUni("uni.csv", universities, count);
    insertionSort(universities, count, compareByName);

    cout << "Sorted universities:\n";
    for (int i = 0; i < count; ++i)
    {
        cout << "Rank: " << universities[i].rank << "\n ";
        cout << "Name: " << universities[i].name << "\n ";
        cout << "Location Code: " << universities[i].locationCode << "\n";
        cout << "Location: " << universities[i].location << "\n";
        cout << "Ar Score: " << universities[i].arScore << "\n";
        cout << "Ar Rank: " << universities[i].arRank << "\n";
        cout << "Er Score: " << universities[i].erScore << "\n";
        cout << "Er Rank: " << universities[i].erRank << "\n";
        cout << "Fsr Score: " << universities[i].fsrScore << "\n";
        cout << "Fsr Rank: " << universities[i].fsrRank << "\n";
        cout << "Cpf Score: " << universities[i].cpfScore << "\n";
        cout << "Cpf Rank: " << universities[i].cpfRank << "\n";
        cout << "Ifr Score: " << universities[i].ifrScore << "\n";
        cout << "Ifr Rank: " << universities[i].ifrRank << "\n";
        cout << "Isr Score: " << universities[i].isrScore << "\n";
        cout << "Isr Rank: " << universities[i].isrRank << "\n";
        cout << "Irn Score: " << universities[i].irnScore << "\n";
        cout << "Irn Rank: " << universities[i].irnRank << "\n";
        cout << "Ger Score: " << universities[i].gerScore << "\n";
        cout << "Ger Rank: " << universities[i].gerRank << "\n";
        cout << "Score Scaled: " << universities[i].scoreScaled << "\n";
        // Print other attributes accordingly
    }
    cout << '\n';
}

// Binary Search - HC
// Swap function for universities
void swap(University &a, University &b)
{
    University temp = a;
    a = b;
    b = temp;
}

void quickSort(University universities[], int low, int high, const string &searchCriteria)
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

bool binarySearchUni(const University universities[], int numUniversities, int targetRank, const string &targetName, double targetScore, const string &searchCriteria)
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
    string targetName;

    bool isFound = false;
    string searchCriteria;

    int searchChoice;

    while (true)
    {
        ofstream output_files("current_uni.csv");
        cout << "Binary Search Menu" << endl;
        cout << "1. University Rank." << endl;
        cout << "2. University Name." << endl;
        cout << "3. University Scaled Score." << endl;
        cout << "4. Location Code." << endl;
        cout << "5. Location." << endl;
        cout << "6. AR Score." << endl;
        cout << "7. ER Score." << endl;
        cout << "8. FSR Score." << endl;
        cout << "9. CPF Score." << endl;
        cout << "10. IFR Score." << endl;
        cout << "11. ISR Score." << endl;
        cout << "12. IRN Score." << endl;
        cout << "13. GER Score." << endl;
        cout << "14. AR Rank." << endl;
        cout << "15. ER Rank." << endl;
        cout << "16. FSR Rank." << endl;
        cout << "17. CPF Rank." << endl;
        cout << "18. IFR Rank." << endl;
        cout << "19. ISR Rank." << endl;
        cout << "20. IRN Rank." << endl;
        cout << "21. GER Rank." << endl;
        cout << "22. Exit Program." << endl;
        cout << "Enter your choice: ";
        cin >> searchChoice;

        switch (searchChoice)
        {
        case 1:

            cout << "Enter the rank: ";
            cin >> targetRank;
            isFound = binarySearchUni(universities, numUniversities, targetRank, "", targetScore, "rank");

            if (isFound)
            {
                cout << "University found!" << endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (universities[i].rank == targetRank)
                    {
                        University &uni = universities[i];
                        cout << "University #" << i + 1 << endl;
                        cout << "Rank: " << (uni.rank == -1 ? "n/a" : to_string(uni.rank)) << endl;
                        cout << "Name: " << uni.name << endl;
                        cout << "Location Code: " << uni.locationCode << endl;
                        cout << "Location: " << uni.location << endl;
                        cout << "AR Score: " << (uni.arScore == -1.0 ? "n/a" : to_string(uni.arScore)) << endl;
                        cout << "AR Rank: " << (uni.arRank == -1 ? "n/a" : (uni.arRank == 501 ? "501+" : (uni.arRank == 601 ? "601+" : to_string(uni.arRank)))) << endl;
                        cout << "ER Score: " << (uni.erScore == -1.0 ? "n/a" : to_string(uni.erScore)) << endl;
                        cout << "ER Rank: " << (uni.erRank == -1 ? "n/a" : (uni.erRank == 501 ? "501+" : (uni.erRank == 601 ? "601+" : to_string(uni.erRank)))) << endl;
                        cout << "FSR Score: " << (uni.fsrScore == -1.0 ? "n/a" : to_string(uni.fsrScore)) << endl;
                        cout << "FSR Rank: " << (uni.fsrRank == -1 ? "n/a" : (uni.fsrRank == 501 ? "501+" : (uni.fsrRank == 601 ? "601+" : to_string(uni.fsrRank)))) << endl;
                        cout << "CPF Score: " << (uni.cpfScore == -1.0 ? "n/a" : to_string(uni.cpfScore)) << endl;
                        cout << "CPF Rank: " << (uni.cpfRank == -1 ? "n/a" : (uni.cpfRank == 501 ? "501+" : (uni.cpfRank == 601 ? "601+" : to_string(uni.cpfRank)))) << endl;
                        cout << "IFR Score: " << (uni.ifrScore == -1.0 ? "n/a" : to_string(uni.ifrScore)) << endl;
                        cout << "IFR Rank: " << (uni.ifrRank == -1 ? "n/a" : (uni.ifrRank == 501 ? "501+" : (uni.ifrRank == 601 ? "601+" : to_string(uni.ifrRank)))) << endl;
                        cout << "ISR Score: " << (uni.isrScore == -1.0 ? "n/a" : to_string(uni.isrScore)) << endl;
                        cout << "ISR Rank: " << (uni.isrRank == -1 ? "n/a" : (uni.isrRank == 501 ? "501+" : (uni.isrRank == 601 ? "601+" : to_string(uni.isrRank)))) << endl;
                        cout << "IRN Score: " << (uni.irnScore == -1.0 ? "n/a" : to_string(uni.irnScore)) << endl;
                        cout << "IRN Rank: " << (uni.irnRank == -1 ? "n/a" : (uni.irnRank == 501 ? "501+" : (uni.irnRank == 601 ? "601+" : to_string(uni.irnRank)))) << endl;
                        cout << "GER Score: " << (uni.gerScore == -1.0 ? "n/a" : to_string(uni.gerScore)) << endl;
                        cout << "GER Rank: " << (uni.gerRank == -1 ? "n/a" : (uni.gerRank == 501 ? "501+" : (uni.gerRank == 601 ? "601+" : to_string(uni.gerRank)))) << endl;
                        cout << "Score Scaled: " << (uni.scoreScaled == -1.0 ? "n/a" : to_string(uni.scoreScaled)) << endl;
                        cout << endl;
                        output_files << uni.name;
                        output_files.close();
                        uni_menu();
                        break;
                    }
                }
            }
            else
            {
                cout << "University not found." << endl;
            }
            break;
        case 2:
            quickSort(universities, 0, ARRAY_SIZE - 1, "name");
            cout << "Enter the university name: ";
            cin.ignore();
            getline(cin, targetName);
            isFound = binarySearchUni(universities, numUniversities, -1, targetName, targetScore, "name");

            if (isFound)
            {
                cout << "University found!" << endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if ((universities[i].name == targetName))
                    {
                        University &uni = universities[i];
                        cout << "University #" << i + 1 << endl;
                        cout << "Rank: " << (uni.rank == -1 ? "n/a" : to_string(uni.rank)) << endl;
                        cout << "Name: " << uni.name << endl;
                        cout << "Location Code: " << uni.locationCode << endl;
                        cout << "Location: " << uni.location << endl;
                        cout << "AR Score: " << (uni.arScore == -1.0 ? "n/a" : to_string(uni.arScore)) << endl;
                        cout << "AR Rank: " << (uni.arRank == -1 ? "n/a" : (uni.arRank == 501 ? "501+" : (uni.arRank == 601 ? "601+" : to_string(uni.arRank)))) << endl;
                        cout << "ER Score: " << (uni.erScore == -1.0 ? "n/a" : to_string(uni.erScore)) << endl;
                        cout << "ER Rank: " << (uni.erRank == -1 ? "n/a" : (uni.erRank == 501 ? "501+" : (uni.erRank == 601 ? "601+" : to_string(uni.erRank)))) << endl;
                        cout << "FSR Score: " << (uni.fsrScore == -1.0 ? "n/a" : to_string(uni.fsrScore)) << endl;
                        cout << "FSR Rank: " << (uni.fsrRank == -1 ? "n/a" : (uni.fsrRank == 501 ? "501+" : (uni.fsrRank == 601 ? "601+" : to_string(uni.fsrRank)))) << endl;
                        cout << "CPF Score: " << (uni.cpfScore == -1.0 ? "n/a" : to_string(uni.cpfScore)) << endl;
                        cout << "CPF Rank: " << (uni.cpfRank == -1 ? "n/a" : (uni.cpfRank == 501 ? "501+" : (uni.cpfRank == 601 ? "601+" : to_string(uni.cpfRank)))) << endl;
                        cout << "IFR Score: " << (uni.ifrScore == -1.0 ? "n/a" : to_string(uni.ifrScore)) << endl;
                        cout << "IFR Rank: " << (uni.ifrRank == -1 ? "n/a" : (uni.ifrRank == 501 ? "501+" : (uni.ifrRank == 601 ? "601+" : to_string(uni.ifrRank)))) << endl;
                        cout << "ISR Score: " << (uni.isrScore == -1.0 ? "n/a" : to_string(uni.isrScore)) << endl;
                        cout << "ISR Rank: " << (uni.isrRank == -1 ? "n/a" : (uni.isrRank == 501 ? "501+" : (uni.isrRank == 601 ? "601+" : to_string(uni.isrRank)))) << endl;
                        cout << "IRN Score: " << (uni.irnScore == -1.0 ? "n/a" : to_string(uni.irnScore)) << endl;
                        cout << "IRN Rank: " << (uni.irnRank == -1 ? "n/a" : (uni.irnRank == 501 ? "501+" : (uni.irnRank == 601 ? "601+" : to_string(uni.irnRank)))) << endl;
                        cout << "GER Score: " << (uni.gerScore == -1.0 ? "n/a" : to_string(uni.gerScore)) << endl;
                        cout << "GER Rank: " << (uni.gerRank == -1 ? "n/a" : (uni.gerRank == 501 ? "501+" : (uni.gerRank == 601 ? "601+" : to_string(uni.gerRank)))) << endl;
                        cout << "Score Scaled: " << (uni.scoreScaled == -1.0 ? "n/a" : to_string(uni.scoreScaled)) << endl;
                        cout << endl;
                        output_files << uni.name;
                        output_files.close();
                        uni_menu();
                        break;
                    }
                }
            }
            else
            {
                cout << "University not found." << endl;
            }
            break;
        case 3:
            quickSort(universities, 0, ARRAY_SIZE - 1, "scoreScaled");
            cout << "Enter the score scaled: ";
            cin >> targetScore;
            isFound = binarySearchUni(universities, numUniversities, -1, targetName, targetScore, "scoreScaled");

            if (isFound)
            {
                cout << "University found!" << endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].scoreScaled == targetScore))
                    {
                        University &uni = universities[i];
                        cout << "University #" << i + 1 << endl;
                        cout << "Rank: " << (uni.rank == -1 ? "n/a" : to_string(uni.rank)) << endl;
                        cout << "Name: " << uni.name << endl;
                        cout << "Location Code: " << uni.locationCode << endl;
                        cout << "Location: " << uni.location << endl;
                        cout << "AR Score: " << (uni.arScore == -1.0 ? "n/a" : to_string(uni.arScore)) << endl;
                        cout << "AR Rank: " << (uni.arRank == -1 ? "n/a" : (uni.arRank == 501 ? "501+" : (uni.arRank == 601 ? "601+" : to_string(uni.arRank)))) << endl;
                        cout << "ER Score: " << (uni.erScore == -1.0 ? "n/a" : to_string(uni.erScore)) << endl;
                        cout << "ER Rank: " << (uni.erRank == -1 ? "n/a" : (uni.erRank == 501 ? "501+" : (uni.erRank == 601 ? "601+" : to_string(uni.erRank)))) << endl;
                        cout << "FSR Score: " << (uni.fsrScore == -1.0 ? "n/a" : to_string(uni.fsrScore)) << endl;
                        cout << "FSR Rank: " << (uni.fsrRank == -1 ? "n/a" : (uni.fsrRank == 501 ? "501+" : (uni.fsrRank == 601 ? "601+" : to_string(uni.fsrRank)))) << endl;
                        cout << "CPF Score: " << (uni.cpfScore == -1.0 ? "n/a" : to_string(uni.cpfScore)) << endl;
                        cout << "CPF Rank: " << (uni.cpfRank == -1 ? "n/a" : (uni.cpfRank == 501 ? "501+" : (uni.cpfRank == 601 ? "601+" : to_string(uni.cpfRank)))) << endl;
                        cout << "IFR Score: " << (uni.ifrScore == -1.0 ? "n/a" : to_string(uni.ifrScore)) << endl;
                        cout << "IFR Rank: " << (uni.ifrRank == -1 ? "n/a" : (uni.ifrRank == 501 ? "501+" : (uni.ifrRank == 601 ? "601+" : to_string(uni.ifrRank)))) << endl;
                        cout << "ISR Score: " << (uni.isrScore == -1.0 ? "n/a" : to_string(uni.isrScore)) << endl;
                        cout << "ISR Rank: " << (uni.isrRank == -1 ? "n/a" : (uni.isrRank == 501 ? "501+" : (uni.isrRank == 601 ? "601+" : to_string(uni.isrRank)))) << endl;
                        cout << "IRN Score: " << (uni.irnScore == -1.0 ? "n/a" : to_string(uni.irnScore)) << endl;
                        cout << "IRN Rank: " << (uni.irnRank == -1 ? "n/a" : (uni.irnRank == 501 ? "501+" : (uni.irnRank == 601 ? "601+" : to_string(uni.irnRank)))) << endl;
                        cout << "GER Score: " << (uni.gerScore == -1.0 ? "n/a" : to_string(uni.gerScore)) << endl;
                        cout << "GER Rank: " << (uni.gerRank == -1 ? "n/a" : (uni.gerRank == 501 ? "501+" : (uni.gerRank == 601 ? "601+" : to_string(uni.gerRank)))) << endl;
                        cout << "Score Scaled: " << (uni.scoreScaled == -1.0 ? "n/a" : to_string(uni.scoreScaled)) << endl;
                        cout << endl;
                        output_files << uni.name;
                        output_files.close();
                        uni_menu();
                        break;
                    }
                }
            }
            else
            {
                cout << "University not found." << endl;
            }
            break;
        case 4:
            quickSort(universities, 0, ARRAY_SIZE - 1, "locationCode");
            cout << "Enter the location code: ";
            cin.ignore();
            getline(cin, targetName);
            isFound = binarySearchUni(universities, numUniversities, -1, targetName, -1.0, "locationCode");

            if (isFound)
            {
                cout << "University found!" << endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].locationCode == targetName))
                    {
                        University &uni = universities[i];
                        cout << "University #" << i + 1 << endl;
                        cout << "Rank: " << (uni.rank == -1 ? "n/a" : to_string(uni.rank)) << endl;
                        cout << "Name: " << uni.name << endl;
                        cout << "Location Code: " << uni.locationCode << endl;
                        cout << "Location: " << uni.location << endl;
                        cout << "AR Score: " << (uni.arScore == -1.0 ? "n/a" : to_string(uni.arScore)) << endl;
                        cout << "AR Rank: " << (uni.arRank == -1 ? "n/a" : (uni.arRank == 501 ? "501+" : (uni.arRank == 601 ? "601+" : to_string(uni.arRank)))) << endl;
                        cout << "ER Score: " << (uni.erScore == -1.0 ? "n/a" : to_string(uni.erScore)) << endl;
                        cout << "ER Rank: " << (uni.erRank == -1 ? "n/a" : (uni.erRank == 501 ? "501+" : (uni.erRank == 601 ? "601+" : to_string(uni.erRank)))) << endl;
                        cout << "FSR Score: " << (uni.fsrScore == -1.0 ? "n/a" : to_string(uni.fsrScore)) << endl;
                        cout << "FSR Rank: " << (uni.fsrRank == -1 ? "n/a" : (uni.fsrRank == 501 ? "501+" : (uni.fsrRank == 601 ? "601+" : to_string(uni.fsrRank)))) << endl;
                        cout << "CPF Score: " << (uni.cpfScore == -1.0 ? "n/a" : to_string(uni.cpfScore)) << endl;
                        cout << "CPF Rank: " << (uni.cpfRank == -1 ? "n/a" : (uni.cpfRank == 501 ? "501+" : (uni.cpfRank == 601 ? "601+" : to_string(uni.cpfRank)))) << endl;
                        cout << "IFR Score: " << (uni.ifrScore == -1.0 ? "n/a" : to_string(uni.ifrScore)) << endl;
                        cout << "IFR Rank: " << (uni.ifrRank == -1 ? "n/a" : (uni.ifrRank == 501 ? "501+" : (uni.ifrRank == 601 ? "601+" : to_string(uni.ifrRank)))) << endl;
                        cout << "ISR Score: " << (uni.isrScore == -1.0 ? "n/a" : to_string(uni.isrScore)) << endl;
                        cout << "ISR Rank: " << (uni.isrRank == -1 ? "n/a" : (uni.isrRank == 501 ? "501+" : (uni.isrRank == 601 ? "601+" : to_string(uni.isrRank)))) << endl;
                        cout << "IRN Score: " << (uni.irnScore == -1.0 ? "n/a" : to_string(uni.irnScore)) << endl;
                        cout << "IRN Rank: " << (uni.irnRank == -1 ? "n/a" : (uni.irnRank == 501 ? "501+" : (uni.irnRank == 601 ? "601+" : to_string(uni.irnRank)))) << endl;
                        cout << "GER Score: " << (uni.gerScore == -1.0 ? "n/a" : to_string(uni.gerScore)) << endl;
                        cout << "GER Rank: " << (uni.gerRank == -1 ? "n/a" : (uni.gerRank == 501 ? "501+" : (uni.gerRank == 601 ? "601+" : to_string(uni.gerRank)))) << endl;
                        cout << "Score Scaled: " << (uni.scoreScaled == -1.0 ? "n/a" : to_string(uni.scoreScaled)) << endl;
                        cout << endl;
                        output_files << uni.name;
                        output_files.close();
                        uni_menu();
                        break;
                    }
                }
            }
            else
            {
                cout << "University not found." << endl;
            }
            break;
        case 5:
            quickSort(universities, 0, ARRAY_SIZE - 1, "location");
            cout << "Enter the location: ";
            cin.ignore();
            getline(cin, targetName);
            isFound = binarySearchUni(universities, numUniversities, -1, targetName, -1.0, "location");

            if (isFound)
            {
                cout << "University found!" << endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].location == targetName))
                    {
                        University &uni = universities[i];
                        cout << "University #" << i + 1 << endl;
                        cout << "Rank: " << (uni.rank == -1 ? "n/a" : to_string(uni.rank)) << endl;
                        cout << "Name: " << uni.name << endl;
                        cout << "Location Code: " << uni.locationCode << endl;
                        cout << "Location: " << uni.location << endl;
                        cout << "AR Score: " << (uni.arScore == -1.0 ? "n/a" : to_string(uni.arScore)) << endl;
                        cout << "AR Rank: " << (uni.arRank == -1 ? "n/a" : (uni.arRank == 501 ? "501+" : (uni.arRank == 601 ? "601+" : to_string(uni.arRank)))) << endl;
                        cout << "ER Score: " << (uni.erScore == -1.0 ? "n/a" : to_string(uni.erScore)) << endl;
                        cout << "ER Rank: " << (uni.erRank == -1 ? "n/a" : (uni.erRank == 501 ? "501+" : (uni.erRank == 601 ? "601+" : to_string(uni.erRank)))) << endl;
                        cout << "FSR Score: " << (uni.fsrScore == -1.0 ? "n/a" : to_string(uni.fsrScore)) << endl;
                        cout << "FSR Rank: " << (uni.fsrRank == -1 ? "n/a" : (uni.fsrRank == 501 ? "501+" : (uni.fsrRank == 601 ? "601+" : to_string(uni.fsrRank)))) << endl;
                        cout << "CPF Score: " << (uni.cpfScore == -1.0 ? "n/a" : to_string(uni.cpfScore)) << endl;
                        cout << "CPF Rank: " << (uni.cpfRank == -1 ? "n/a" : (uni.cpfRank == 501 ? "501+" : (uni.cpfRank == 601 ? "601+" : to_string(uni.cpfRank)))) << endl;
                        cout << "IFR Score: " << (uni.ifrScore == -1.0 ? "n/a" : to_string(uni.ifrScore)) << endl;
                        cout << "IFR Rank: " << (uni.ifrRank == -1 ? "n/a" : (uni.ifrRank == 501 ? "501+" : (uni.ifrRank == 601 ? "601+" : to_string(uni.ifrRank)))) << endl;
                        cout << "ISR Score: " << (uni.isrScore == -1.0 ? "n/a" : to_string(uni.isrScore)) << endl;
                        cout << "ISR Rank: " << (uni.isrRank == -1 ? "n/a" : (uni.isrRank == 501 ? "501+" : (uni.isrRank == 601 ? "601+" : to_string(uni.isrRank)))) << endl;
                        cout << "IRN Score: " << (uni.irnScore == -1.0 ? "n/a" : to_string(uni.irnScore)) << endl;
                        cout << "IRN Rank: " << (uni.irnRank == -1 ? "n/a" : (uni.irnRank == 501 ? "501+" : (uni.irnRank == 601 ? "601+" : to_string(uni.irnRank)))) << endl;
                        cout << "GER Score: " << (uni.gerScore == -1.0 ? "n/a" : to_string(uni.gerScore)) << endl;
                        cout << "GER Rank: " << (uni.gerRank == -1 ? "n/a" : (uni.gerRank == 501 ? "501+" : (uni.gerRank == 601 ? "601+" : to_string(uni.gerRank)))) << endl;
                        cout << "Score Scaled: " << (uni.scoreScaled == -1.0 ? "n/a" : to_string(uni.scoreScaled)) << endl;
                        cout << endl;
                        output_files << uni.name;
                        output_files.close();
                        uni_menu();
                        break;
                    }
                }
            }
            else
            {
                cout << "University not found." << endl;
            }
            break;
        case 6:
            quickSort(universities, 0, ARRAY_SIZE - 1, "arScore");
            cout << "Enter the AR Score: ";
            cin >> targetScore;
            isFound = binarySearchUni(universities, numUniversities, -1, "", targetScore, "arScore");

            if (isFound)
            {
                cout << "University found!" << endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].arScore == targetScore))
                    {
                        University &uni = universities[i];
                        cout << "University #" << i + 1 << endl;
                        cout << "Rank: " << (uni.rank == -1 ? "n/a" : to_string(uni.rank)) << endl;
                        cout << "Name: " << uni.name << endl;
                        cout << "Location Code: " << uni.locationCode << endl;
                        cout << "Location: " << uni.location << endl;
                        cout << "AR Score: " << (uni.arScore == -1.0 ? "n/a" : to_string(uni.arScore)) << endl;
                        cout << "AR Rank: " << (uni.arRank == -1 ? "n/a" : (uni.arRank == 501 ? "501+" : (uni.arRank == 601 ? "601+" : to_string(uni.arRank)))) << endl;
                        cout << "ER Score: " << (uni.erScore == -1.0 ? "n/a" : to_string(uni.erScore)) << endl;
                        cout << "ER Rank: " << (uni.erRank == -1 ? "n/a" : (uni.erRank == 501 ? "501+" : (uni.erRank == 601 ? "601+" : to_string(uni.erRank)))) << endl;
                        cout << "FSR Score: " << (uni.fsrScore == -1.0 ? "n/a" : to_string(uni.fsrScore)) << endl;
                        cout << "FSR Rank: " << (uni.fsrRank == -1 ? "n/a" : (uni.fsrRank == 501 ? "501+" : (uni.fsrRank == 601 ? "601+" : to_string(uni.fsrRank)))) << endl;
                        cout << "CPF Score: " << (uni.cpfScore == -1.0 ? "n/a" : to_string(uni.cpfScore)) << endl;
                        cout << "CPF Rank: " << (uni.cpfRank == -1 ? "n/a" : (uni.cpfRank == 501 ? "501+" : (uni.cpfRank == 601 ? "601+" : to_string(uni.cpfRank)))) << endl;
                        cout << "IFR Score: " << (uni.ifrScore == -1.0 ? "n/a" : to_string(uni.ifrScore)) << endl;
                        cout << "IFR Rank: " << (uni.ifrRank == -1 ? "n/a" : (uni.ifrRank == 501 ? "501+" : (uni.ifrRank == 601 ? "601+" : to_string(uni.ifrRank)))) << endl;
                        cout << "ISR Score: " << (uni.isrScore == -1.0 ? "n/a" : to_string(uni.isrScore)) << endl;
                        cout << "ISR Rank: " << (uni.isrRank == -1 ? "n/a" : (uni.isrRank == 501 ? "501+" : (uni.isrRank == 601 ? "601+" : to_string(uni.isrRank)))) << endl;
                        cout << "IRN Score: " << (uni.irnScore == -1.0 ? "n/a" : to_string(uni.irnScore)) << endl;
                        cout << "IRN Rank: " << (uni.irnRank == -1 ? "n/a" : (uni.irnRank == 501 ? "501+" : (uni.irnRank == 601 ? "601+" : to_string(uni.irnRank)))) << endl;
                        cout << "GER Score: " << (uni.gerScore == -1.0 ? "n/a" : to_string(uni.gerScore)) << endl;
                        cout << "GER Rank: " << (uni.gerRank == -1 ? "n/a" : (uni.gerRank == 501 ? "501+" : (uni.gerRank == 601 ? "601+" : to_string(uni.gerRank)))) << endl;
                        cout << "Score Scaled: " << (uni.scoreScaled == -1.0 ? "n/a" : to_string(uni.scoreScaled)) << endl;
                        cout << endl;
                        output_files << uni.name;
                        output_files.close();
                        uni_menu();
                        break;
                    }
                }
            }
            else
            {
                cout << "University not found." << endl;
            }
            break;
        case 7:
            quickSort(universities, 0, ARRAY_SIZE - 1, "erScore");
            cout << "Enter the ER Score: ";
            cin >> targetScore;
            isFound = binarySearchUni(universities, numUniversities, -1, "", targetScore, "erScore");

            if (isFound)
            {
                cout << "University found!" << endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].erScore == targetScore))
                    {
                        University &uni = universities[i];
                        cout << "University #" << i + 1 << endl;
                        cout << "Rank: " << (uni.rank == -1 ? "n/a" : to_string(uni.rank)) << endl;
                        cout << "Name: " << uni.name << endl;
                        cout << "Location Code: " << uni.locationCode << endl;
                        cout << "Location: " << uni.location << endl;
                        cout << "AR Score: " << (uni.arScore == -1.0 ? "n/a" : to_string(uni.arScore)) << endl;
                        cout << "AR Rank: " << (uni.arRank == -1 ? "n/a" : (uni.arRank == 501 ? "501+" : (uni.arRank == 601 ? "601+" : to_string(uni.arRank)))) << endl;
                        cout << "ER Score: " << (uni.erScore == -1.0 ? "n/a" : to_string(uni.erScore)) << endl;
                        cout << "ER Rank: " << (uni.erRank == -1 ? "n/a" : (uni.erRank == 501 ? "501+" : (uni.erRank == 601 ? "601+" : to_string(uni.erRank)))) << endl;
                        cout << "FSR Score: " << (uni.fsrScore == -1.0 ? "n/a" : to_string(uni.fsrScore)) << endl;
                        cout << "FSR Rank: " << (uni.fsrRank == -1 ? "n/a" : (uni.fsrRank == 501 ? "501+" : (uni.fsrRank == 601 ? "601+" : to_string(uni.fsrRank)))) << endl;
                        cout << "CPF Score: " << (uni.cpfScore == -1.0 ? "n/a" : to_string(uni.cpfScore)) << endl;
                        cout << "CPF Rank: " << (uni.cpfRank == -1 ? "n/a" : (uni.cpfRank == 501 ? "501+" : (uni.cpfRank == 601 ? "601+" : to_string(uni.cpfRank)))) << endl;
                        cout << "IFR Score: " << (uni.ifrScore == -1.0 ? "n/a" : to_string(uni.ifrScore)) << endl;
                        cout << "IFR Rank: " << (uni.ifrRank == -1 ? "n/a" : (uni.ifrRank == 501 ? "501+" : (uni.ifrRank == 601 ? "601+" : to_string(uni.ifrRank)))) << endl;
                        cout << "ISR Score: " << (uni.isrScore == -1.0 ? "n/a" : to_string(uni.isrScore)) << endl;
                        cout << "ISR Rank: " << (uni.isrRank == -1 ? "n/a" : (uni.isrRank == 501 ? "501+" : (uni.isrRank == 601 ? "601+" : to_string(uni.isrRank)))) << endl;
                        cout << "IRN Score: " << (uni.irnScore == -1.0 ? "n/a" : to_string(uni.irnScore)) << endl;
                        cout << "IRN Rank: " << (uni.irnRank == -1 ? "n/a" : (uni.irnRank == 501 ? "501+" : (uni.irnRank == 601 ? "601+" : to_string(uni.irnRank)))) << endl;
                        cout << "GER Score: " << (uni.gerScore == -1.0 ? "n/a" : to_string(uni.gerScore)) << endl;
                        cout << "GER Rank: " << (uni.gerRank == -1 ? "n/a" : (uni.gerRank == 501 ? "501+" : (uni.gerRank == 601 ? "601+" : to_string(uni.gerRank)))) << endl;
                        cout << "Score Scaled: " << (uni.scoreScaled == -1.0 ? "n/a" : to_string(uni.scoreScaled)) << endl;
                        cout << endl;
                        output_files << uni.name;
                        output_files.close();
                        uni_menu();
                        break;
                    }
                }
            }
            else
            {
                cout << "University not found." << endl;
            }
            break;
        case 8:
            quickSort(universities, 0, ARRAY_SIZE - 1, "fsrScore");
            cout << "Enter the FSR Score: ";
            cin >> targetScore;
            isFound = binarySearchUni(universities, numUniversities, -1, "", targetScore, "fsrScore");

            if (isFound)
            {
                cout << "University found!" << endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].fsrScore == targetScore))
                    {
                        University &uni = universities[i];
                        cout << "University #" << i + 1 << endl;
                        cout << "Rank: " << (uni.rank == -1 ? "n/a" : to_string(uni.rank)) << endl;
                        cout << "Name: " << uni.name << endl;
                        cout << "Location Code: " << uni.locationCode << endl;
                        cout << "Location: " << uni.location << endl;
                        cout << "AR Score: " << (uni.arScore == -1.0 ? "n/a" : to_string(uni.arScore)) << endl;
                        cout << "AR Rank: " << (uni.arRank == -1 ? "n/a" : (uni.arRank == 501 ? "501+" : (uni.arRank == 601 ? "601+" : to_string(uni.arRank)))) << endl;
                        cout << "ER Score: " << (uni.erScore == -1.0 ? "n/a" : to_string(uni.erScore)) << endl;
                        cout << "ER Rank: " << (uni.erRank == -1 ? "n/a" : (uni.erRank == 501 ? "501+" : (uni.erRank == 601 ? "601+" : to_string(uni.erRank)))) << endl;
                        cout << "FSR Score: " << (uni.fsrScore == -1.0 ? "n/a" : to_string(uni.fsrScore)) << endl;
                        cout << "FSR Rank: " << (uni.fsrRank == -1 ? "n/a" : (uni.fsrRank == 501 ? "501+" : (uni.fsrRank == 601 ? "601+" : to_string(uni.fsrRank)))) << endl;
                        cout << "CPF Score: " << (uni.cpfScore == -1.0 ? "n/a" : to_string(uni.cpfScore)) << endl;
                        cout << "CPF Rank: " << (uni.cpfRank == -1 ? "n/a" : (uni.cpfRank == 501 ? "501+" : (uni.cpfRank == 601 ? "601+" : to_string(uni.cpfRank)))) << endl;
                        cout << "IFR Score: " << (uni.ifrScore == -1.0 ? "n/a" : to_string(uni.ifrScore)) << endl;
                        cout << "IFR Rank: " << (uni.ifrRank == -1 ? "n/a" : (uni.ifrRank == 501 ? "501+" : (uni.ifrRank == 601 ? "601+" : to_string(uni.ifrRank)))) << endl;
                        cout << "ISR Score: " << (uni.isrScore == -1.0 ? "n/a" : to_string(uni.isrScore)) << endl;
                        cout << "ISR Rank: " << (uni.isrRank == -1 ? "n/a" : (uni.isrRank == 501 ? "501+" : (uni.isrRank == 601 ? "601+" : to_string(uni.isrRank)))) << endl;
                        cout << "IRN Score: " << (uni.irnScore == -1.0 ? "n/a" : to_string(uni.irnScore)) << endl;
                        cout << "IRN Rank: " << (uni.irnRank == -1 ? "n/a" : (uni.irnRank == 501 ? "501+" : (uni.irnRank == 601 ? "601+" : to_string(uni.irnRank)))) << endl;
                        cout << "GER Score: " << (uni.gerScore == -1.0 ? "n/a" : to_string(uni.gerScore)) << endl;
                        cout << "GER Rank: " << (uni.gerRank == -1 ? "n/a" : (uni.gerRank == 501 ? "501+" : (uni.gerRank == 601 ? "601+" : to_string(uni.gerRank)))) << endl;
                        cout << "Score Scaled: " << (uni.scoreScaled == -1.0 ? "n/a" : to_string(uni.scoreScaled)) << endl;
                        cout << endl;
                        output_files << uni.name;
                        output_files.close();
                        uni_menu();
                        break;
                    }
                }
            }
            else
            {
                cout << "University not found." << endl;
            }
            break;
        case 9:
            quickSort(universities, 0, ARRAY_SIZE - 1, "cpfScore");
            cout << "Enter the CPF Score: ";
            cin >> targetScore;
            isFound = binarySearchUni(universities, numUniversities, -1, "", targetScore, "cpfScore");

            if (isFound)
            {
                cout << "University found!" << endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].cpfScore == targetScore))
                    {
                        University &uni = universities[i];
                        cout << "University #" << i + 1 << endl;
                        cout << "Rank: " << (uni.rank == -1 ? "n/a" : to_string(uni.rank)) << endl;
                        cout << "Name: " << uni.name << endl;
                        cout << "Location Code: " << uni.locationCode << endl;
                        cout << "Location: " << uni.location << endl;
                        cout << "AR Score: " << (uni.arScore == -1.0 ? "n/a" : to_string(uni.arScore)) << endl;
                        cout << "AR Rank: " << (uni.arRank == -1 ? "n/a" : (uni.arRank == 501 ? "501+" : (uni.arRank == 601 ? "601+" : to_string(uni.arRank)))) << endl;
                        cout << "ER Score: " << (uni.erScore == -1.0 ? "n/a" : to_string(uni.erScore)) << endl;
                        cout << "ER Rank: " << (uni.erRank == -1 ? "n/a" : (uni.erRank == 501 ? "501+" : (uni.erRank == 601 ? "601+" : to_string(uni.erRank)))) << endl;
                        cout << "FSR Score: " << (uni.fsrScore == -1.0 ? "n/a" : to_string(uni.fsrScore)) << endl;
                        cout << "FSR Rank: " << (uni.fsrRank == -1 ? "n/a" : (uni.fsrRank == 501 ? "501+" : (uni.fsrRank == 601 ? "601+" : to_string(uni.fsrRank)))) << endl;
                        cout << "CPF Score: " << (uni.cpfScore == -1.0 ? "n/a" : to_string(uni.cpfScore)) << endl;
                        cout << "CPF Rank: " << (uni.cpfRank == -1 ? "n/a" : (uni.cpfRank == 501 ? "501+" : (uni.cpfRank == 601 ? "601+" : to_string(uni.cpfRank)))) << endl;
                        cout << "IFR Score: " << (uni.ifrScore == -1.0 ? "n/a" : to_string(uni.ifrScore)) << endl;
                        cout << "IFR Rank: " << (uni.ifrRank == -1 ? "n/a" : (uni.ifrRank == 501 ? "501+" : (uni.ifrRank == 601 ? "601+" : to_string(uni.ifrRank)))) << endl;
                        cout << "ISR Score: " << (uni.isrScore == -1.0 ? "n/a" : to_string(uni.isrScore)) << endl;
                        cout << "ISR Rank: " << (uni.isrRank == -1 ? "n/a" : (uni.isrRank == 501 ? "501+" : (uni.isrRank == 601 ? "601+" : to_string(uni.isrRank)))) << endl;
                        cout << "IRN Score: " << (uni.irnScore == -1.0 ? "n/a" : to_string(uni.irnScore)) << endl;
                        cout << "IRN Rank: " << (uni.irnRank == -1 ? "n/a" : (uni.irnRank == 501 ? "501+" : (uni.irnRank == 601 ? "601+" : to_string(uni.irnRank)))) << endl;
                        cout << "GER Score: " << (uni.gerScore == -1.0 ? "n/a" : to_string(uni.gerScore)) << endl;
                        cout << "GER Rank: " << (uni.gerRank == -1 ? "n/a" : (uni.gerRank == 501 ? "501+" : (uni.gerRank == 601 ? "601+" : to_string(uni.gerRank)))) << endl;
                        cout << "Score Scaled: " << (uni.scoreScaled == -1.0 ? "n/a" : to_string(uni.scoreScaled)) << endl;
                        cout << endl;
                        output_files << uni.name;
                        output_files.close();
                        uni_menu();
                        break;
                    }
                }
            }
            else
            {
                cout << "University not found." << endl;
            }
            break;
        case 10:
            quickSort(universities, 0, ARRAY_SIZE - 1, "ifrScore");
            cout << "Enter the IFR Score: ";
            cin >> targetScore;
            isFound = binarySearchUni(universities, numUniversities, -1, "", targetScore, "ifrScore");

            if (isFound)
            {
                cout << "University found!" << endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].ifrScore == targetScore))
                    {
                        University &uni = universities[i];
                        cout << "University #" << i + 1 << endl;
                        cout << "Rank: " << (uni.rank == -1 ? "n/a" : to_string(uni.rank)) << endl;
                        cout << "Name: " << uni.name << endl;
                        cout << "Location Code: " << uni.locationCode << endl;
                        cout << "Location: " << uni.location << endl;
                        cout << "AR Score: " << (uni.arScore == -1.0 ? "n/a" : to_string(uni.arScore)) << endl;
                        cout << "AR Rank: " << (uni.arRank == -1 ? "n/a" : (uni.arRank == 501 ? "501+" : (uni.arRank == 601 ? "601+" : to_string(uni.arRank)))) << endl;
                        cout << "ER Score: " << (uni.erScore == -1.0 ? "n/a" : to_string(uni.erScore)) << endl;
                        cout << "ER Rank: " << (uni.erRank == -1 ? "n/a" : (uni.erRank == 501 ? "501+" : (uni.erRank == 601 ? "601+" : to_string(uni.erRank)))) << endl;
                        cout << "FSR Score: " << (uni.fsrScore == -1.0 ? "n/a" : to_string(uni.fsrScore)) << endl;
                        cout << "FSR Rank: " << (uni.fsrRank == -1 ? "n/a" : (uni.fsrRank == 501 ? "501+" : (uni.fsrRank == 601 ? "601+" : to_string(uni.fsrRank)))) << endl;
                        cout << "CPF Score: " << (uni.cpfScore == -1.0 ? "n/a" : to_string(uni.cpfScore)) << endl;
                        cout << "CPF Rank: " << (uni.cpfRank == -1 ? "n/a" : (uni.cpfRank == 501 ? "501+" : (uni.cpfRank == 601 ? "601+" : to_string(uni.cpfRank)))) << endl;
                        cout << "IFR Score: " << (uni.ifrScore == -1.0 ? "n/a" : to_string(uni.ifrScore)) << endl;
                        cout << "IFR Rank: " << (uni.ifrRank == -1 ? "n/a" : (uni.ifrRank == 501 ? "501+" : (uni.ifrRank == 601 ? "601+" : to_string(uni.ifrRank)))) << endl;
                        cout << "ISR Score: " << (uni.isrScore == -1.0 ? "n/a" : to_string(uni.isrScore)) << endl;
                        cout << "ISR Rank: " << (uni.isrRank == -1 ? "n/a" : (uni.isrRank == 501 ? "501+" : (uni.isrRank == 601 ? "601+" : to_string(uni.isrRank)))) << endl;
                        cout << "IRN Score: " << (uni.irnScore == -1.0 ? "n/a" : to_string(uni.irnScore)) << endl;
                        cout << "IRN Rank: " << (uni.irnRank == -1 ? "n/a" : (uni.irnRank == 501 ? "501+" : (uni.irnRank == 601 ? "601+" : to_string(uni.irnRank)))) << endl;
                        cout << "GER Score: " << (uni.gerScore == -1.0 ? "n/a" : to_string(uni.gerScore)) << endl;
                        cout << "GER Rank: " << (uni.gerRank == -1 ? "n/a" : (uni.gerRank == 501 ? "501+" : (uni.gerRank == 601 ? "601+" : to_string(uni.gerRank)))) << endl;
                        cout << "Score Scaled: " << (uni.scoreScaled == -1.0 ? "n/a" : to_string(uni.scoreScaled)) << endl;
                        cout << endl;
                        output_files << uni.name;
                        output_files.close();
                        uni_menu();
                        break;
                    }
                }
            }
            else
            {
                cout << "University not found." << endl;
            }
            break;
        case 11:
            quickSort(universities, 0, ARRAY_SIZE - 1, "isrScore");
            cout << "Enter the ISR Score: ";
            cin >> targetScore;
            isFound = binarySearchUni(universities, numUniversities, -1, "", targetScore, "isrScore");

            if (isFound)
            {
                cout << "University found!" << endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].isrScore == targetScore))
                    {
                        University &uni = universities[i];
                        cout << "University #" << i + 1 << endl;
                        cout << "Rank: " << (uni.rank == -1 ? "n/a" : to_string(uni.rank)) << endl;
                        cout << "Name: " << uni.name << endl;
                        cout << "Location Code: " << uni.locationCode << endl;
                        cout << "Location: " << uni.location << endl;
                        cout << "AR Score: " << (uni.arScore == -1.0 ? "n/a" : to_string(uni.arScore)) << endl;
                        cout << "AR Rank: " << (uni.arRank == -1 ? "n/a" : (uni.arRank == 501 ? "501+" : (uni.arRank == 601 ? "601+" : to_string(uni.arRank)))) << endl;
                        cout << "ER Score: " << (uni.erScore == -1.0 ? "n/a" : to_string(uni.erScore)) << endl;
                        cout << "ER Rank: " << (uni.erRank == -1 ? "n/a" : (uni.erRank == 501 ? "501+" : (uni.erRank == 601 ? "601+" : to_string(uni.erRank)))) << endl;
                        cout << "FSR Score: " << (uni.fsrScore == -1.0 ? "n/a" : to_string(uni.fsrScore)) << endl;
                        cout << "FSR Rank: " << (uni.fsrRank == -1 ? "n/a" : (uni.fsrRank == 501 ? "501+" : (uni.fsrRank == 601 ? "601+" : to_string(uni.fsrRank)))) << endl;
                        cout << "CPF Score: " << (uni.cpfScore == -1.0 ? "n/a" : to_string(uni.cpfScore)) << endl;
                        cout << "CPF Rank: " << (uni.cpfRank == -1 ? "n/a" : (uni.cpfRank == 501 ? "501+" : (uni.cpfRank == 601 ? "601+" : to_string(uni.cpfRank)))) << endl;
                        cout << "IFR Score: " << (uni.ifrScore == -1.0 ? "n/a" : to_string(uni.ifrScore)) << endl;
                        cout << "IFR Rank: " << (uni.ifrRank == -1 ? "n/a" : (uni.ifrRank == 501 ? "501+" : (uni.ifrRank == 601 ? "601+" : to_string(uni.ifrRank)))) << endl;
                        cout << "ISR Score: " << (uni.isrScore == -1.0 ? "n/a" : to_string(uni.isrScore)) << endl;
                        cout << "ISR Rank: " << (uni.isrRank == -1 ? "n/a" : (uni.isrRank == 501 ? "501+" : (uni.isrRank == 601 ? "601+" : to_string(uni.isrRank)))) << endl;
                        cout << "IRN Score: " << (uni.irnScore == -1.0 ? "n/a" : to_string(uni.irnScore)) << endl;
                        cout << "IRN Rank: " << (uni.irnRank == -1 ? "n/a" : (uni.irnRank == 501 ? "501+" : (uni.irnRank == 601 ? "601+" : to_string(uni.irnRank)))) << endl;
                        cout << "GER Score: " << (uni.gerScore == -1.0 ? "n/a" : to_string(uni.gerScore)) << endl;
                        cout << "GER Rank: " << (uni.gerRank == -1 ? "n/a" : (uni.gerRank == 501 ? "501+" : (uni.gerRank == 601 ? "601+" : to_string(uni.gerRank)))) << endl;
                        cout << "Score Scaled: " << (uni.scoreScaled == -1.0 ? "n/a" : to_string(uni.scoreScaled)) << endl;
                        cout << endl;
                        output_files << uni.name;
                        output_files.close();
                        uni_menu();
                        break;
                    }
                }
            }
            else
            {
                cout << "University not found." << endl;
            }
            break;
        case 12:
            quickSort(universities, 0, ARRAY_SIZE - 1, "irnScore");
            cout << "Enter the IRN Score: ";
            cin >> targetScore;
            isFound = binarySearchUni(universities, numUniversities, -1, "", targetScore, "irnScore");

            if (isFound)
            {
                cout << "University found!" << endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].irnScore == targetScore))
                    {
                        University &uni = universities[i];
                        cout << "University #" << i + 1 << endl;
                        cout << "Rank: " << (uni.rank == -1 ? "n/a" : to_string(uni.rank)) << endl;
                        cout << "Name: " << uni.name << endl;
                        cout << "Location Code: " << uni.locationCode << endl;
                        cout << "Location: " << uni.location << endl;
                        cout << "AR Score: " << (uni.arScore == -1.0 ? "n/a" : to_string(uni.arScore)) << endl;
                        cout << "AR Rank: " << (uni.arRank == -1 ? "n/a" : (uni.arRank == 501 ? "501+" : (uni.arRank == 601 ? "601+" : to_string(uni.arRank)))) << endl;
                        cout << "ER Score: " << (uni.erScore == -1.0 ? "n/a" : to_string(uni.erScore)) << endl;
                        cout << "ER Rank: " << (uni.erRank == -1 ? "n/a" : (uni.erRank == 501 ? "501+" : (uni.erRank == 601 ? "601+" : to_string(uni.erRank)))) << endl;
                        cout << "FSR Score: " << (uni.fsrScore == -1.0 ? "n/a" : to_string(uni.fsrScore)) << endl;
                        cout << "FSR Rank: " << (uni.fsrRank == -1 ? "n/a" : (uni.fsrRank == 501 ? "501+" : (uni.fsrRank == 601 ? "601+" : to_string(uni.fsrRank)))) << endl;
                        cout << "CPF Score: " << (uni.cpfScore == -1.0 ? "n/a" : to_string(uni.cpfScore)) << endl;
                        cout << "CPF Rank: " << (uni.cpfRank == -1 ? "n/a" : (uni.cpfRank == 501 ? "501+" : (uni.cpfRank == 601 ? "601+" : to_string(uni.cpfRank)))) << endl;
                        cout << "IFR Score: " << (uni.ifrScore == -1.0 ? "n/a" : to_string(uni.ifrScore)) << endl;
                        cout << "IFR Rank: " << (uni.ifrRank == -1 ? "n/a" : (uni.ifrRank == 501 ? "501+" : (uni.ifrRank == 601 ? "601+" : to_string(uni.ifrRank)))) << endl;
                        cout << "ISR Score: " << (uni.isrScore == -1.0 ? "n/a" : to_string(uni.isrScore)) << endl;
                        cout << "ISR Rank: " << (uni.isrRank == -1 ? "n/a" : (uni.isrRank == 501 ? "501+" : (uni.isrRank == 601 ? "601+" : to_string(uni.isrRank)))) << endl;
                        cout << "IRN Score: " << (uni.irnScore == -1.0 ? "n/a" : to_string(uni.irnScore)) << endl;
                        cout << "IRN Rank: " << (uni.irnRank == -1 ? "n/a" : (uni.irnRank == 501 ? "501+" : (uni.irnRank == 601 ? "601+" : to_string(uni.irnRank)))) << endl;
                        cout << "GER Score: " << (uni.gerScore == -1.0 ? "n/a" : to_string(uni.gerScore)) << endl;
                        cout << "GER Rank: " << (uni.gerRank == -1 ? "n/a" : (uni.gerRank == 501 ? "501+" : (uni.gerRank == 601 ? "601+" : to_string(uni.gerRank)))) << endl;
                        cout << "Score Scaled: " << (uni.scoreScaled == -1.0 ? "n/a" : to_string(uni.scoreScaled)) << endl;
                        cout << endl;
                        output_files << uni.name;
                        output_files.close();
                        uni_menu();
                        break;
                    }
                }
            }
            else
            {
                cout << "University not found." << endl;
            }
            break;
        case 13:
            quickSort(universities, 0, ARRAY_SIZE - 1, "gerScore");
            cout << "Enter the GER Score: ";
            cin >> targetScore;
            isFound = binarySearchUni(universities, numUniversities, -1, "", targetScore, "gerScore");

            if (isFound)
            {
                cout << "University found!" << endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].gerScore == targetScore))
                    {
                        University &uni = universities[i];
                        cout << "University #" << i + 1 << endl;
                        cout << "Rank: " << (uni.rank == -1 ? "n/a" : to_string(uni.rank)) << endl;
                        cout << "Name: " << uni.name << endl;
                        cout << "Location Code: " << uni.locationCode << endl;
                        cout << "Location: " << uni.location << endl;
                        cout << "AR Score: " << (uni.arScore == -1.0 ? "n/a" : to_string(uni.arScore)) << endl;
                        cout << "AR Rank: " << (uni.arRank == -1 ? "n/a" : (uni.arRank == 501 ? "501+" : (uni.arRank == 601 ? "601+" : to_string(uni.arRank)))) << endl;
                        cout << "ER Score: " << (uni.erScore == -1.0 ? "n/a" : to_string(uni.erScore)) << endl;
                        cout << "ER Rank: " << (uni.erRank == -1 ? "n/a" : (uni.erRank == 501 ? "501+" : (uni.erRank == 601 ? "601+" : to_string(uni.erRank)))) << endl;
                        cout << "FSR Score: " << (uni.fsrScore == -1.0 ? "n/a" : to_string(uni.fsrScore)) << endl;
                        cout << "FSR Rank: " << (uni.fsrRank == -1 ? "n/a" : (uni.fsrRank == 501 ? "501+" : (uni.fsrRank == 601 ? "601+" : to_string(uni.fsrRank)))) << endl;
                        cout << "CPF Score: " << (uni.cpfScore == -1.0 ? "n/a" : to_string(uni.cpfScore)) << endl;
                        cout << "CPF Rank: " << (uni.cpfRank == -1 ? "n/a" : (uni.cpfRank == 501 ? "501+" : (uni.cpfRank == 601 ? "601+" : to_string(uni.cpfRank)))) << endl;
                        cout << "IFR Score: " << (uni.ifrScore == -1.0 ? "n/a" : to_string(uni.ifrScore)) << endl;
                        cout << "IFR Rank: " << (uni.ifrRank == -1 ? "n/a" : (uni.ifrRank == 501 ? "501+" : (uni.ifrRank == 601 ? "601+" : to_string(uni.ifrRank)))) << endl;
                        cout << "ISR Score: " << (uni.isrScore == -1.0 ? "n/a" : to_string(uni.isrScore)) << endl;
                        cout << "ISR Rank: " << (uni.isrRank == -1 ? "n/a" : (uni.isrRank == 501 ? "501+" : (uni.isrRank == 601 ? "601+" : to_string(uni.isrRank)))) << endl;
                        cout << "IRN Score: " << (uni.irnScore == -1.0 ? "n/a" : to_string(uni.irnScore)) << endl;
                        cout << "IRN Rank: " << (uni.irnRank == -1 ? "n/a" : (uni.irnRank == 501 ? "501+" : (uni.irnRank == 601 ? "601+" : to_string(uni.irnRank)))) << endl;
                        cout << "GER Score: " << (uni.gerScore == -1.0 ? "n/a" : to_string(uni.gerScore)) << endl;
                        cout << "GER Rank: " << (uni.gerRank == -1 ? "n/a" : (uni.gerRank == 501 ? "501+" : (uni.gerRank == 601 ? "601+" : to_string(uni.gerRank)))) << endl;
                        cout << "Score Scaled: " << (uni.scoreScaled == -1.0 ? "n/a" : to_string(uni.scoreScaled)) << endl;
                        cout << endl;
                        output_files << uni.name;
                        output_files.close();
                        uni_menu();
                        break;
                    }
                }
            }
            else
            {
                cout << "University not found." << endl;
            }
            break;
        case 14:
            quickSort(universities, 0, ARRAY_SIZE - 1, "arRank");
            cout << "Enter the AR Rank: ";
            cin >> targetRank;
            isFound = binarySearchUni(universities, numUniversities, targetRank, "", -1.0, "arRank");

            if (isFound)
            {
                cout << "University found!" << endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if ((universities[i].arRank == targetRank))
                    {
                        University &uni = universities[i];
                        cout << "University #" << i + 1 << endl;
                        cout << "Rank: " << (uni.rank == -1 ? "n/a" : to_string(uni.rank)) << endl;
                        cout << "Name: " << uni.name << endl;
                        cout << "Location Code: " << uni.locationCode << endl;
                        cout << "Location: " << uni.location << endl;
                        cout << "AR Score: " << (uni.arScore == -1.0 ? "n/a" : to_string(uni.arScore)) << endl;
                        cout << "AR Rank: " << (uni.arRank == -1 ? "n/a" : (uni.arRank == 501 ? "501+" : (uni.arRank == 601 ? "601+" : to_string(uni.arRank)))) << endl;
                        cout << "ER Score: " << (uni.erScore == -1.0 ? "n/a" : to_string(uni.erScore)) << endl;
                        cout << "ER Rank: " << (uni.erRank == -1 ? "n/a" : (uni.erRank == 501 ? "501+" : (uni.erRank == 601 ? "601+" : to_string(uni.erRank)))) << endl;
                        cout << "FSR Score: " << (uni.fsrScore == -1.0 ? "n/a" : to_string(uni.fsrScore)) << endl;
                        cout << "FSR Rank: " << (uni.fsrRank == -1 ? "n/a" : (uni.fsrRank == 501 ? "501+" : (uni.fsrRank == 601 ? "601+" : to_string(uni.fsrRank)))) << endl;
                        cout << "CPF Score: " << (uni.cpfScore == -1.0 ? "n/a" : to_string(uni.cpfScore)) << endl;
                        cout << "CPF Rank: " << (uni.cpfRank == -1 ? "n/a" : (uni.cpfRank == 501 ? "501+" : (uni.cpfRank == 601 ? "601+" : to_string(uni.cpfRank)))) << endl;
                        cout << "IFR Score: " << (uni.ifrScore == -1.0 ? "n/a" : to_string(uni.ifrScore)) << endl;
                        cout << "IFR Rank: " << (uni.ifrRank == -1 ? "n/a" : (uni.ifrRank == 501 ? "501+" : (uni.ifrRank == 601 ? "601+" : to_string(uni.ifrRank)))) << endl;
                        cout << "ISR Score: " << (uni.isrScore == -1.0 ? "n/a" : to_string(uni.isrScore)) << endl;
                        cout << "ISR Rank: " << (uni.isrRank == -1 ? "n/a" : (uni.isrRank == 501 ? "501+" : (uni.isrRank == 601 ? "601+" : to_string(uni.isrRank)))) << endl;
                        cout << "IRN Score: " << (uni.irnScore == -1.0 ? "n/a" : to_string(uni.irnScore)) << endl;
                        cout << "IRN Rank: " << (uni.irnRank == -1 ? "n/a" : (uni.irnRank == 501 ? "501+" : (uni.irnRank == 601 ? "601+" : to_string(uni.irnRank)))) << endl;
                        cout << "GER Score: " << (uni.gerScore == -1.0 ? "n/a" : to_string(uni.gerScore)) << endl;
                        cout << "GER Rank: " << (uni.gerRank == -1 ? "n/a" : (uni.gerRank == 501 ? "501+" : (uni.gerRank == 601 ? "601+" : to_string(uni.gerRank)))) << endl;
                        cout << "Score Scaled: " << (uni.scoreScaled == -1.0 ? "n/a" : to_string(uni.scoreScaled)) << endl;
                        cout << endl;
                        output_files << uni.name;
                        output_files.close();
                        uni_menu();
                        break;
                    }
                }
            }
            else
            {
                cout << "University not found." << endl;
            }
            break;
        case 15:
            quickSort(universities, 0, ARRAY_SIZE - 1, "erRank");
            cout << "Enter the ER Rank: ";
            cin >> targetRank;
            isFound = binarySearchUni(universities, numUniversities, targetRank, "", -1.0, "erRank");

            if (isFound)
            {
                cout << "University found!" << endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].erRank == targetRank))
                    {
                        University &uni = universities[i];
                        cout << "University #" << i + 1 << endl;
                        cout << "Rank: " << (uni.rank == -1 ? "n/a" : to_string(uni.rank)) << endl;
                        cout << "Name: " << uni.name << endl;
                        cout << "Location Code: " << uni.locationCode << endl;
                        cout << "Location: " << uni.location << endl;
                        cout << "AR Score: " << (uni.arScore == -1.0 ? "n/a" : to_string(uni.arScore)) << endl;
                        cout << "AR Rank: " << (uni.arRank == -1 ? "n/a" : (uni.arRank == 501 ? "501+" : (uni.arRank == 601 ? "601+" : to_string(uni.arRank)))) << endl;
                        cout << "ER Score: " << (uni.erScore == -1.0 ? "n/a" : to_string(uni.erScore)) << endl;
                        cout << "ER Rank: " << (uni.erRank == -1 ? "n/a" : (uni.erRank == 501 ? "501+" : (uni.erRank == 601 ? "601+" : to_string(uni.erRank)))) << endl;
                        cout << "FSR Score: " << (uni.fsrScore == -1.0 ? "n/a" : to_string(uni.fsrScore)) << endl;
                        cout << "FSR Rank: " << (uni.fsrRank == -1 ? "n/a" : (uni.fsrRank == 501 ? "501+" : (uni.fsrRank == 601 ? "601+" : to_string(uni.fsrRank)))) << endl;
                        cout << "CPF Score: " << (uni.cpfScore == -1.0 ? "n/a" : to_string(uni.cpfScore)) << endl;
                        cout << "CPF Rank: " << (uni.cpfRank == -1 ? "n/a" : (uni.cpfRank == 501 ? "501+" : (uni.cpfRank == 601 ? "601+" : to_string(uni.cpfRank)))) << endl;
                        cout << "IFR Score: " << (uni.ifrScore == -1.0 ? "n/a" : to_string(uni.ifrScore)) << endl;
                        cout << "IFR Rank: " << (uni.ifrRank == -1 ? "n/a" : (uni.ifrRank == 501 ? "501+" : (uni.ifrRank == 601 ? "601+" : to_string(uni.ifrRank)))) << endl;
                        cout << "ISR Score: " << (uni.isrScore == -1.0 ? "n/a" : to_string(uni.isrScore)) << endl;
                        cout << "ISR Rank: " << (uni.isrRank == -1 ? "n/a" : (uni.isrRank == 501 ? "501+" : (uni.isrRank == 601 ? "601+" : to_string(uni.isrRank)))) << endl;
                        cout << "IRN Score: " << (uni.irnScore == -1.0 ? "n/a" : to_string(uni.irnScore)) << endl;
                        cout << "IRN Rank: " << (uni.irnRank == -1 ? "n/a" : (uni.irnRank == 501 ? "501+" : (uni.irnRank == 601 ? "601+" : to_string(uni.irnRank)))) << endl;
                        cout << "GER Score: " << (uni.gerScore == -1.0 ? "n/a" : to_string(uni.gerScore)) << endl;
                        cout << "GER Rank: " << (uni.gerRank == -1 ? "n/a" : (uni.gerRank == 501 ? "501+" : (uni.gerRank == 601 ? "601+" : to_string(uni.gerRank)))) << endl;
                        cout << "Score Scaled: " << (uni.scoreScaled == -1.0 ? "n/a" : to_string(uni.scoreScaled)) << endl;
                        cout << endl;
                        output_files << uni.name;
                        output_files.close();
                        uni_menu();
                        break;
                    }
                }
            }
            else
            {
                cout << "University not found." << endl;
            }
            break;
        case 16:
            quickSort(universities, 0, ARRAY_SIZE - 1, "fsrRank");
            cout << "Enter the FSR Rank: ";
            cin >> targetRank;
            isFound = binarySearchUni(universities, numUniversities, targetRank, "", -1.0, "fsrRank");

            if (isFound)
            {
                cout << "University found!" << endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].fsrRank == targetRank))
                    {
                        University &uni = universities[i];
                        cout << "University #" << i + 1 << endl;
                        cout << "Rank: " << (uni.rank == -1 ? "n/a" : to_string(uni.rank)) << endl;
                        cout << "Name: " << uni.name << endl;
                        cout << "Location Code: " << uni.locationCode << endl;
                        cout << "Location: " << uni.location << endl;
                        cout << "AR Score: " << (uni.arScore == -1.0 ? "n/a" : to_string(uni.arScore)) << endl;
                        cout << "AR Rank: " << (uni.arRank == -1 ? "n/a" : (uni.arRank == 501 ? "501+" : (uni.arRank == 601 ? "601+" : to_string(uni.arRank)))) << endl;
                        cout << "ER Score: " << (uni.erScore == -1.0 ? "n/a" : to_string(uni.erScore)) << endl;
                        cout << "ER Rank: " << (uni.erRank == -1 ? "n/a" : (uni.erRank == 501 ? "501+" : (uni.erRank == 601 ? "601+" : to_string(uni.erRank)))) << endl;
                        cout << "FSR Score: " << (uni.fsrScore == -1.0 ? "n/a" : to_string(uni.fsrScore)) << endl;
                        cout << "FSR Rank: " << (uni.fsrRank == -1 ? "n/a" : (uni.fsrRank == 501 ? "501+" : (uni.fsrRank == 601 ? "601+" : to_string(uni.fsrRank)))) << endl;
                        cout << "CPF Score: " << (uni.cpfScore == -1.0 ? "n/a" : to_string(uni.cpfScore)) << endl;
                        cout << "CPF Rank: " << (uni.cpfRank == -1 ? "n/a" : (uni.cpfRank == 501 ? "501+" : (uni.cpfRank == 601 ? "601+" : to_string(uni.cpfRank)))) << endl;
                        cout << "IFR Score: " << (uni.ifrScore == -1.0 ? "n/a" : to_string(uni.ifrScore)) << endl;
                        cout << "IFR Rank: " << (uni.ifrRank == -1 ? "n/a" : (uni.ifrRank == 501 ? "501+" : (uni.ifrRank == 601 ? "601+" : to_string(uni.ifrRank)))) << endl;
                        cout << "ISR Score: " << (uni.isrScore == -1.0 ? "n/a" : to_string(uni.isrScore)) << endl;
                        cout << "ISR Rank: " << (uni.isrRank == -1 ? "n/a" : (uni.isrRank == 501 ? "501+" : (uni.isrRank == 601 ? "601+" : to_string(uni.isrRank)))) << endl;
                        cout << "IRN Score: " << (uni.irnScore == -1.0 ? "n/a" : to_string(uni.irnScore)) << endl;
                        cout << "IRN Rank: " << (uni.irnRank == -1 ? "n/a" : (uni.irnRank == 501 ? "501+" : (uni.irnRank == 601 ? "601+" : to_string(uni.irnRank)))) << endl;
                        cout << "GER Score: " << (uni.gerScore == -1.0 ? "n/a" : to_string(uni.gerScore)) << endl;
                        cout << "GER Rank: " << (uni.gerRank == -1 ? "n/a" : (uni.gerRank == 501 ? "501+" : (uni.gerRank == 601 ? "601+" : to_string(uni.gerRank)))) << endl;
                        cout << "Score Scaled: " << (uni.scoreScaled == -1.0 ? "n/a" : to_string(uni.scoreScaled)) << endl;
                        cout << endl;
                        output_files << uni.name;
                        output_files.close();
                        uni_menu();
                        break;
                    }
                }
            }
            else
            {
                cout << "University not found." << endl;
            }
            break;
        case 17:
            quickSort(universities, 0, ARRAY_SIZE - 1, "cpfRank");
            cout << "Enter the CPF Rank: ";
            cin >> targetRank;
            isFound = binarySearchUni(universities, numUniversities, targetRank, "", -1.0, "cpfRank");

            if (isFound)
            {
                cout << "University found!" << endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].cpfRank == targetRank))
                    {
                        University &uni = universities[i];
                        cout << "University #" << i + 1 << endl;
                        cout << "Rank: " << (uni.rank == -1 ? "n/a" : to_string(uni.rank)) << endl;
                        cout << "Name: " << uni.name << endl;
                        cout << "Location Code: " << uni.locationCode << endl;
                        cout << "Location: " << uni.location << endl;
                        cout << "AR Score: " << (uni.arScore == -1.0 ? "n/a" : to_string(uni.arScore)) << endl;
                        cout << "AR Rank: " << (uni.arRank == -1 ? "n/a" : (uni.arRank == 501 ? "501+" : (uni.arRank == 601 ? "601+" : to_string(uni.arRank)))) << endl;
                        cout << "ER Score: " << (uni.erScore == -1.0 ? "n/a" : to_string(uni.erScore)) << endl;
                        cout << "ER Rank: " << (uni.erRank == -1 ? "n/a" : (uni.erRank == 501 ? "501+" : (uni.erRank == 601 ? "601+" : to_string(uni.erRank)))) << endl;
                        cout << "FSR Score: " << (uni.fsrScore == -1.0 ? "n/a" : to_string(uni.fsrScore)) << endl;
                        cout << "FSR Rank: " << (uni.fsrRank == -1 ? "n/a" : (uni.fsrRank == 501 ? "501+" : (uni.fsrRank == 601 ? "601+" : to_string(uni.fsrRank)))) << endl;
                        cout << "CPF Score: " << (uni.cpfScore == -1.0 ? "n/a" : to_string(uni.cpfScore)) << endl;
                        cout << "CPF Rank: " << (uni.cpfRank == -1 ? "n/a" : (uni.cpfRank == 501 ? "501+" : (uni.cpfRank == 601 ? "601+" : to_string(uni.cpfRank)))) << endl;
                        cout << "IFR Score: " << (uni.ifrScore == -1.0 ? "n/a" : to_string(uni.ifrScore)) << endl;
                        cout << "IFR Rank: " << (uni.ifrRank == -1 ? "n/a" : (uni.ifrRank == 501 ? "501+" : (uni.ifrRank == 601 ? "601+" : to_string(uni.ifrRank)))) << endl;
                        cout << "ISR Score: " << (uni.isrScore == -1.0 ? "n/a" : to_string(uni.isrScore)) << endl;
                        cout << "ISR Rank: " << (uni.isrRank == -1 ? "n/a" : (uni.isrRank == 501 ? "501+" : (uni.isrRank == 601 ? "601+" : to_string(uni.isrRank)))) << endl;
                        cout << "IRN Score: " << (uni.irnScore == -1.0 ? "n/a" : to_string(uni.irnScore)) << endl;
                        cout << "IRN Rank: " << (uni.irnRank == -1 ? "n/a" : (uni.irnRank == 501 ? "501+" : (uni.irnRank == 601 ? "601+" : to_string(uni.irnRank)))) << endl;
                        cout << "GER Score: " << (uni.gerScore == -1.0 ? "n/a" : to_string(uni.gerScore)) << endl;
                        cout << "GER Rank: " << (uni.gerRank == -1 ? "n/a" : (uni.gerRank == 501 ? "501+" : (uni.gerRank == 601 ? "601+" : to_string(uni.gerRank)))) << endl;
                        cout << "Score Scaled: " << (uni.scoreScaled == -1.0 ? "n/a" : to_string(uni.scoreScaled)) << endl;
                        cout << endl;
                        output_files << uni.name;
                        output_files.close();
                        uni_menu();
                        break;
                    }
                }
            }
            else
            {
                cout << "University not found." << endl;
            }
            break;
        case 18:
            quickSort(universities, 0, ARRAY_SIZE - 1, "ifrRank");
            cout << "Enter the IFR Rank: ";
            cin >> targetRank;
            isFound = binarySearchUni(universities, numUniversities, targetRank, "", -1.0, "ifrRank");

            if (isFound)
            {
                cout << "University found!" << endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].ifrRank == targetRank))
                    {
                        University &uni = universities[i];
                        cout << "University #" << i + 1 << endl;
                        cout << "Rank: " << (uni.rank == -1 ? "n/a" : to_string(uni.rank)) << endl;
                        cout << "Name: " << uni.name << endl;
                        cout << "Location Code: " << uni.locationCode << endl;
                        cout << "Location: " << uni.location << endl;
                        cout << "AR Score: " << (uni.arScore == -1.0 ? "n/a" : to_string(uni.arScore)) << endl;
                        cout << "AR Rank: " << (uni.arRank == -1 ? "n/a" : (uni.arRank == 501 ? "501+" : (uni.arRank == 601 ? "601+" : to_string(uni.arRank)))) << endl;
                        cout << "ER Score: " << (uni.erScore == -1.0 ? "n/a" : to_string(uni.erScore)) << endl;
                        cout << "ER Rank: " << (uni.erRank == -1 ? "n/a" : (uni.erRank == 501 ? "501+" : (uni.erRank == 601 ? "601+" : to_string(uni.erRank)))) << endl;
                        cout << "FSR Score: " << (uni.fsrScore == -1.0 ? "n/a" : to_string(uni.fsrScore)) << endl;
                        cout << "FSR Rank: " << (uni.fsrRank == -1 ? "n/a" : (uni.fsrRank == 501 ? "501+" : (uni.fsrRank == 601 ? "601+" : to_string(uni.fsrRank)))) << endl;
                        cout << "CPF Score: " << (uni.cpfScore == -1.0 ? "n/a" : to_string(uni.cpfScore)) << endl;
                        cout << "CPF Rank: " << (uni.cpfRank == -1 ? "n/a" : (uni.cpfRank == 501 ? "501+" : (uni.cpfRank == 601 ? "601+" : to_string(uni.cpfRank)))) << endl;
                        cout << "IFR Score: " << (uni.ifrScore == -1.0 ? "n/a" : to_string(uni.ifrScore)) << endl;
                        cout << "IFR Rank: " << (uni.ifrRank == -1 ? "n/a" : (uni.ifrRank == 501 ? "501+" : (uni.ifrRank == 601 ? "601+" : to_string(uni.ifrRank)))) << endl;
                        cout << "ISR Score: " << (uni.isrScore == -1.0 ? "n/a" : to_string(uni.isrScore)) << endl;
                        cout << "ISR Rank: " << (uni.isrRank == -1 ? "n/a" : (uni.isrRank == 501 ? "501+" : (uni.isrRank == 601 ? "601+" : to_string(uni.isrRank)))) << endl;
                        cout << "IRN Score: " << (uni.irnScore == -1.0 ? "n/a" : to_string(uni.irnScore)) << endl;
                        cout << "IRN Rank: " << (uni.irnRank == -1 ? "n/a" : (uni.irnRank == 501 ? "501+" : (uni.irnRank == 601 ? "601+" : to_string(uni.irnRank)))) << endl;
                        cout << "GER Score: " << (uni.gerScore == -1.0 ? "n/a" : to_string(uni.gerScore)) << endl;
                        cout << "GER Rank: " << (uni.gerRank == -1 ? "n/a" : (uni.gerRank == 501 ? "501+" : (uni.gerRank == 601 ? "601+" : to_string(uni.gerRank)))) << endl;
                        cout << "Score Scaled: " << (uni.scoreScaled == -1.0 ? "n/a" : to_string(uni.scoreScaled)) << endl;
                        cout << endl;
                        output_files << uni.name;
                        output_files.close();
                        uni_menu();
                        break;
                    }
                }
            }
            else
            {
                cout << "University not found." << endl;
            }
            break;
        case 19:
            quickSort(universities, 0, ARRAY_SIZE - 1, "isrRank");
            cout << "Enter the ISR Rank: ";
            cin >> targetRank;
            isFound = binarySearchUni(universities, numUniversities, targetRank, "", -1.0, "isrRank");

            if (isFound)
            {
                cout << "University found!" << endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].isrRank == targetRank))
                    {
                        University &uni = universities[i];
                        cout << "University #" << i + 1 << endl;
                        cout << "Rank: " << (uni.rank == -1 ? "n/a" : to_string(uni.rank)) << endl;
                        cout << "Name: " << uni.name << endl;
                        cout << "Location Code: " << uni.locationCode << endl;
                        cout << "Location: " << uni.location << endl;
                        cout << "AR Score: " << (uni.arScore == -1.0 ? "n/a" : to_string(uni.arScore)) << endl;
                        cout << "AR Rank: " << (uni.arRank == -1 ? "n/a" : (uni.arRank == 501 ? "501+" : (uni.arRank == 601 ? "601+" : to_string(uni.arRank)))) << endl;
                        cout << "ER Score: " << (uni.erScore == -1.0 ? "n/a" : to_string(uni.erScore)) << endl;
                        cout << "ER Rank: " << (uni.erRank == -1 ? "n/a" : (uni.erRank == 501 ? "501+" : (uni.erRank == 601 ? "601+" : to_string(uni.erRank)))) << endl;
                        cout << "FSR Score: " << (uni.fsrScore == -1.0 ? "n/a" : to_string(uni.fsrScore)) << endl;
                        cout << "FSR Rank: " << (uni.fsrRank == -1 ? "n/a" : (uni.fsrRank == 501 ? "501+" : (uni.fsrRank == 601 ? "601+" : to_string(uni.fsrRank)))) << endl;
                        cout << "CPF Score: " << (uni.cpfScore == -1.0 ? "n/a" : to_string(uni.cpfScore)) << endl;
                        cout << "CPF Rank: " << (uni.cpfRank == -1 ? "n/a" : (uni.cpfRank == 501 ? "501+" : (uni.cpfRank == 601 ? "601+" : to_string(uni.cpfRank)))) << endl;
                        cout << "IFR Score: " << (uni.ifrScore == -1.0 ? "n/a" : to_string(uni.ifrScore)) << endl;
                        cout << "IFR Rank: " << (uni.ifrRank == -1 ? "n/a" : (uni.ifrRank == 501 ? "501+" : (uni.ifrRank == 601 ? "601+" : to_string(uni.ifrRank)))) << endl;
                        cout << "ISR Score: " << (uni.isrScore == -1.0 ? "n/a" : to_string(uni.isrScore)) << endl;
                        cout << "ISR Rank: " << (uni.isrRank == -1 ? "n/a" : (uni.isrRank == 501 ? "501+" : (uni.isrRank == 601 ? "601+" : to_string(uni.isrRank)))) << endl;
                        cout << "IRN Score: " << (uni.irnScore == -1.0 ? "n/a" : to_string(uni.irnScore)) << endl;
                        cout << "IRN Rank: " << (uni.irnRank == -1 ? "n/a" : (uni.irnRank == 501 ? "501+" : (uni.irnRank == 601 ? "601+" : to_string(uni.irnRank)))) << endl;
                        cout << "GER Score: " << (uni.gerScore == -1.0 ? "n/a" : to_string(uni.gerScore)) << endl;
                        cout << "GER Rank: " << (uni.gerRank == -1 ? "n/a" : (uni.gerRank == 501 ? "501+" : (uni.gerRank == 601 ? "601+" : to_string(uni.gerRank)))) << endl;
                        cout << "Score Scaled: " << (uni.scoreScaled == -1.0 ? "n/a" : to_string(uni.scoreScaled)) << endl;
                        cout << endl;
                        output_files << uni.name;
                        output_files.close();
                        uni_menu();
                        break;
                    }
                }
            }
            else
            {
                cout << "University not found." << endl;
            }
            break;
        case 20:
            quickSort(universities, 0, ARRAY_SIZE - 1, "irnRank");
            cout << "Enter the IRN Rank: ";
            cin >> targetRank;
            isFound = binarySearchUni(universities, numUniversities, targetRank, "", -1.0, "irnRank");

            if (isFound)
            {
                cout << "University found!" << endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].irnRank == targetRank))
                    {
                        University &uni = universities[i];
                        cout << "University #" << i + 1 << endl;
                        cout << "Rank: " << (uni.rank == -1 ? "n/a" : to_string(uni.rank)) << endl;
                        cout << "Name: " << uni.name << endl;
                        cout << "Location Code: " << uni.locationCode << endl;
                        cout << "Location: " << uni.location << endl;
                        cout << "AR Score: " << (uni.arScore == -1.0 ? "n/a" : to_string(uni.arScore)) << endl;
                        cout << "AR Rank: " << (uni.arRank == -1 ? "n/a" : (uni.arRank == 501 ? "501+" : (uni.arRank == 601 ? "601+" : to_string(uni.arRank)))) << endl;
                        cout << "ER Score: " << (uni.erScore == -1.0 ? "n/a" : to_string(uni.erScore)) << endl;
                        cout << "ER Rank: " << (uni.erRank == -1 ? "n/a" : (uni.erRank == 501 ? "501+" : (uni.erRank == 601 ? "601+" : to_string(uni.erRank)))) << endl;
                        cout << "FSR Score: " << (uni.fsrScore == -1.0 ? "n/a" : to_string(uni.fsrScore)) << endl;
                        cout << "FSR Rank: " << (uni.fsrRank == -1 ? "n/a" : (uni.fsrRank == 501 ? "501+" : (uni.fsrRank == 601 ? "601+" : to_string(uni.fsrRank)))) << endl;
                        cout << "CPF Score: " << (uni.cpfScore == -1.0 ? "n/a" : to_string(uni.cpfScore)) << endl;
                        cout << "CPF Rank: " << (uni.cpfRank == -1 ? "n/a" : (uni.cpfRank == 501 ? "501+" : (uni.cpfRank == 601 ? "601+" : to_string(uni.cpfRank)))) << endl;
                        cout << "IFR Score: " << (uni.ifrScore == -1.0 ? "n/a" : to_string(uni.ifrScore)) << endl;
                        cout << "IFR Rank: " << (uni.ifrRank == -1 ? "n/a" : (uni.ifrRank == 501 ? "501+" : (uni.ifrRank == 601 ? "601+" : to_string(uni.ifrRank)))) << endl;
                        cout << "ISR Score: " << (uni.isrScore == -1.0 ? "n/a" : to_string(uni.isrScore)) << endl;
                        cout << "ISR Rank: " << (uni.isrRank == -1 ? "n/a" : (uni.isrRank == 501 ? "501+" : (uni.isrRank == 601 ? "601+" : to_string(uni.isrRank)))) << endl;
                        cout << "IRN Score: " << (uni.irnScore == -1.0 ? "n/a" : to_string(uni.irnScore)) << endl;
                        cout << "IRN Rank: " << (uni.irnRank == -1 ? "n/a" : (uni.irnRank == 501 ? "501+" : (uni.irnRank == 601 ? "601+" : to_string(uni.irnRank)))) << endl;
                        cout << "GER Score: " << (uni.gerScore == -1.0 ? "n/a" : to_string(uni.gerScore)) << endl;
                        cout << "GER Rank: " << (uni.gerRank == -1 ? "n/a" : (uni.gerRank == 501 ? "501+" : (uni.gerRank == 601 ? "601+" : to_string(uni.gerRank)))) << endl;
                        cout << "Score Scaled: " << (uni.scoreScaled == -1.0 ? "n/a" : to_string(uni.scoreScaled)) << endl;
                        cout << endl;
                        output_files << uni.name;
                        output_files.close();
                        uni_menu();
                        break;
                    }
                }
            }
            else
            {
                cout << "University not found." << endl;
            }
            break;
        case 21:
            quickSort(universities, 0, ARRAY_SIZE - 1, "gerRank");
            cout << "Enter the GER Rank: ";
            cin >> targetRank;
            isFound = binarySearchUni(universities, numUniversities, targetRank, "", -1.0, "gerRank");

            if (isFound)
            {
                cout << "University found!" << endl;

                // Find and display the specific details of the target
                for (int i = 0; i < numUniversities; i++)
                {
                    if (
                        (universities[i].gerRank == targetRank))
                    {
                        University &uni = universities[i];
                        cout << "University #" << i + 1 << endl;
                        cout << "Rank: " << (uni.rank == -1 ? "n/a" : to_string(uni.rank)) << endl;
                        cout << "Name: " << uni.name << endl;
                        cout << "Location Code: " << uni.locationCode << endl;
                        cout << "Location: " << uni.location << endl;
                        cout << "AR Score: " << (uni.arScore == -1.0 ? "n/a" : to_string(uni.arScore)) << endl;
                        cout << "AR Rank: " << (uni.arRank == -1 ? "n/a" : (uni.arRank == 501 ? "501+" : (uni.arRank == 601 ? "601+" : to_string(uni.arRank)))) << endl;
                        cout << "ER Score: " << (uni.erScore == -1.0 ? "n/a" : to_string(uni.erScore)) << endl;
                        cout << "ER Rank: " << (uni.erRank == -1 ? "n/a" : (uni.erRank == 501 ? "501+" : (uni.erRank == 601 ? "601+" : to_string(uni.erRank)))) << endl;
                        cout << "FSR Score: " << (uni.fsrScore == -1.0 ? "n/a" : to_string(uni.fsrScore)) << endl;
                        cout << "FSR Rank: " << (uni.fsrRank == -1 ? "n/a" : (uni.fsrRank == 501 ? "501+" : (uni.fsrRank == 601 ? "601+" : to_string(uni.fsrRank)))) << endl;
                        cout << "CPF Score: " << (uni.cpfScore == -1.0 ? "n/a" : to_string(uni.cpfScore)) << endl;
                        cout << "CPF Rank: " << (uni.cpfRank == -1 ? "n/a" : (uni.cpfRank == 501 ? "501+" : (uni.cpfRank == 601 ? "601+" : to_string(uni.cpfRank)))) << endl;
                        cout << "IFR Score: " << (uni.ifrScore == -1.0 ? "n/a" : to_string(uni.ifrScore)) << endl;
                        cout << "IFR Rank: " << (uni.ifrRank == -1 ? "n/a" : (uni.ifrRank == 501 ? "501+" : (uni.ifrRank == 601 ? "601+" : to_string(uni.ifrRank)))) << endl;
                        cout << "ISR Score: " << (uni.isrScore == -1.0 ? "n/a" : to_string(uni.isrScore)) << endl;
                        cout << "ISR Rank: " << (uni.isrRank == -1 ? "n/a" : (uni.isrRank == 501 ? "501+" : (uni.isrRank == 601 ? "601+" : to_string(uni.isrRank)))) << endl;
                        cout << "IRN Score: " << (uni.irnScore == -1.0 ? "n/a" : to_string(uni.irnScore)) << endl;
                        cout << "IRN Rank: " << (uni.irnRank == -1 ? "n/a" : (uni.irnRank == 501 ? "501+" : (uni.irnRank == 601 ? "601+" : to_string(uni.irnRank)))) << endl;
                        cout << "GER Score: " << (uni.gerScore == -1.0 ? "n/a" : to_string(uni.gerScore)) << endl;
                        cout << "GER Rank: " << (uni.gerRank == -1 ? "n/a" : (uni.gerRank == 501 ? "501+" : (uni.gerRank == 601 ? "601+" : to_string(uni.gerRank)))) << endl;
                        cout << "Score Scaled: " << (uni.scoreScaled == -1.0 ? "n/a" : to_string(uni.scoreScaled)) << endl;
                        cout << endl;
                        output_files << uni.name;
                        output_files.close();
                        uni_menu();
                        break;
                    }
                }
            }
            else
            {
                cout << "University not found." << endl;
            }
            break;

        case 22:
            return;

        default:
            cout << "Invalid search choice. Please try again." << endl;
        }

        cout << endl;
    }
}

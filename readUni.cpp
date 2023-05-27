#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip> // for std::setprecision

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

int main()
{
    University universities[ARRAY_SIZE];
    int numUniversities;

    readUni("uni.csv", universities, numUniversities);

    for (int i = 0; i < numUniversities; i++)
    {
        University &uni = universities[i];
        std::cout << "University #" << i + 1 << std::endl;
        std::cout << "Rank: " << (uni.rank == -1 ? "n/a" : std::to_string(uni.rank)) << std::endl;
        std::cout << "Name: " << uni.name << std::endl;
        std::cout << "Location Code: " << uni.locationCode << std::endl;
        std::cout << "Location: " << uni.location << std::endl;
        std::cout << "AR Score: " << (uni.arScore == -1.0 ? "n/a" : formatDouble(uni.arScore)) << std::endl;
        std::cout << "AR Rank: " << (uni.arRank == -1 ? "n/a" : (uni.arRank == 501 ? "501+" : (uni.arRank == 601 ? "601+" : std::to_string(uni.arRank)))) << std::endl;
        std::cout << "ER Score: " << (uni.erScore == -1.0 ? "n/a" : formatDouble(uni.erScore)) << std::endl;
        std::cout << "ER Rank: " << (uni.erRank == -1 ? "n/a" : (uni.erRank == 501 ? "501+" : (uni.erRank == 601 ? "601+" : std::to_string(uni.erRank)))) << std::endl;
        std::cout << "FSR Score: " << (uni.fsrScore == -1.0 ? "n/a" : formatDouble(uni.fsrScore)) << std::endl;
        std::cout << "FSR Rank: " << (uni.fsrRank == -1 ? "n/a" : (uni.fsrRank == 501 ? "501+" : (uni.fsrRank == 601 ? "601+" : std::to_string(uni.fsrRank)))) << std::endl;
        std::cout << "CPF Score: " << (uni.cpfScore == -1.0 ? "n/a" : formatDouble(uni.cpfScore)) << std::endl;
        std::cout << "CPF Rank: " << (uni.cpfRank == -1 ? "n/a" : (uni.cpfRank == 501 ? "501+" : (uni.cpfRank == 601 ? "601+" : std::to_string(uni.cpfRank)))) << std::endl;
        std::cout << "IFR Score: " << (uni.ifrScore == -1.0 ? "n/a" : formatDouble(uni.ifrScore)) << std::endl;
        std::cout << "IFR Rank: " << (uni.ifrRank == -1 ? "n/a" : (uni.ifrRank == 501 ? "501+" : (uni.ifrRank == 601 ? "601+" : std::to_string(uni.ifrRank)))) << std::endl;
        std::cout << "ISR Score: " << (uni.isrScore == -1.0 ? "n/a" : formatDouble(uni.isrScore)) << std::endl;
        std::cout << "ISR Rank: " << (uni.isrRank == -1 ? "n/a" : (uni.isrRank == 501 ? "501+" : (uni.isrRank == 601 ? "601+" : std::to_string(uni.isrRank)))) << std::endl;
        std::cout << "IRN Score: " << (uni.irnScore == -1.0 ? "n/a" : formatDouble(uni.irnScore)) << std::endl;
        std::cout << "IRN Rank: " << (uni.irnRank == -1 ? "n/a" : (uni.irnRank == 501 ? "501+" : (uni.irnRank == 601 ? "601+" : std::to_string(uni.irnRank)))) << std::endl;
        std::cout << "GER Score: " << (uni.gerScore == -1.0 ? "n/a" : formatDouble(uni.gerScore)) << std::endl;
        std::cout << "GER Rank: " << (uni.gerRank == -1 ? "n/a" : (uni.gerRank == 501 ? "501+" : (uni.gerRank == 601 ? "601+" : std::to_string(uni.gerRank)))) << std::endl;
        std::cout << "Score Scaled: " << (uni.scoreScaled == -1.0 ? "n/a" : formatDouble(uni.scoreScaled)) << std::endl;
        std::cout << std::endl;
    }

    // for (int i = 0; i < numUniversities; i++)
    // {
    //     University &uni = universities[i];
    //     std::cout << "University #" << i + 1 << std::endl;
    //     std::cout << "Rank: " << (uni.rank == -1 ? "n/a" : std::to_string(uni.rank)) << std::endl;
    //     std::cout << "Name: " << uni.name << std::endl;
    //     std::cout << "Location Code: " << uni.locationCode << std::endl;
    //     std::cout << "Location: " << uni.location << std::endl;
    //     std::cout << "AR Score: " << (uni.arScore == -1.0 ? "n/a" : std::to_string(uni.arScore)) << std::endl;
    //     std::cout << "AR Rank: " << (uni.arRank == -1 ? "n/a" : (uni.arRank == 501 ? "501+" : (uni.arRank == 601 ? "601+" : std::to_string(uni.arRank)))) << std::endl;
    //     std::cout << "ER Score: " << (uni.erScore == -1.0 ? "n/a" : std::to_string(uni.erScore)) << std::endl;
    //     std::cout << "ER Rank: " << (uni.erRank == -1 ? "n/a" : (uni.erRank == 501 ? "501+" : (uni.erRank == 601 ? "601+" : std::to_string(uni.erRank)))) << std::endl;
    //     std::cout << "FSR Score: " << (uni.fsrScore == -1.0 ? "n/a" : std::to_string(uni.fsrScore)) << std::endl;
    //     std::cout << "FSR Rank: " << (uni.fsrRank == -1 ? "n/a" : (uni.fsrRank == 501 ? "501+" : (uni.fsrRank == 601 ? "601+" : std::to_string(uni.fsrRank)))) << std::endl;
    //     std::cout << "CPF Score: " << (uni.cpfScore == -1.0 ? "n/a" : std::to_string(uni.cpfScore)) << std::endl;
    //     std::cout << "CPF Rank: " << (uni.cpfRank == -1 ? "n/a" : (uni.cpfRank == 501 ? "501+" : (uni.cpfRank == 601 ? "601+" : std::to_string(uni.cpfRank)))) << std::endl;
    //     std::cout << "IFR Score: " << (uni.ifrScore == -1.0 ? "n/a" : std::to_string(uni.ifrScore)) << std::endl;
    //     std::cout << "IFR Rank: " << (uni.ifrRank == -1 ? "n/a" : (uni.ifrRank == 501 ? "501+" : (uni.ifrRank == 601 ? "601+" : std::to_string(uni.ifrRank)))) << std::endl;
    //     std::cout << "ISR Score: " << (uni.isrScore == -1.0 ? "n/a" : std::to_string(uni.isrScore)) << std::endl;
    //     std::cout << "ISR Rank: " << (uni.isrRank == -1 ? "n/a" : (uni.isrRank == 501 ? "501+" : (uni.isrRank == 601 ? "601+" : std::to_string(uni.isrRank)))) << std::endl;
    //     std::cout << "IRN Score: " << (uni.irnScore == -1.0 ? "n/a" : std::to_string(uni.irnScore)) << std::endl;
    //     std::cout << "IRN Rank: " << (uni.irnRank == -1 ? "n/a" : (uni.irnRank == 501 ? "501+" : (uni.irnRank == 601 ? "601+" : std::to_string(uni.irnRank)))) << std::endl;
    //     std::cout << "GER Score: " << (uni.gerScore == -1.0 ? "n/a" : std::to_string(uni.gerScore)) << std::endl;
    //     std::cout << "GER Rank: " << (uni.gerRank == -1 ? "n/a" : (uni.gerRank == 501 ? "501+" : (uni.gerRank == 601 ? "601+" : std::to_string(uni.gerRank)))) << std::endl;
    //     std::cout << "Score Scaled: " << (uni.scoreScaled == -1.0 ? "n/a" : std::to_string(uni.scoreScaled)) << std::endl;
    //     std::cout << std::endl;
    // }

    return 0;
}

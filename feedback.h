#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <string>
#include <sstream>
#include <iomanip>

// #include "searchUni.h"

void replyFeedback()
{
    // Read feedback for all users from the CSV file
    string feedback_file_name = "feedback.csv";
    ifstream feedback_file(feedback_file_name);

    if (!feedback_file.is_open())
    {
        cerr << "Could not open the file - " << feedback_file_name << endl;
        return;
    }

    string line;
    vector<string> feedback_lines;

    while (getline(feedback_file, line))
    {
        feedback_lines.push_back(line);
    }

    feedback_file.close();

    if (feedback_lines.empty())
    {
        cout << "No feedback found." << endl;
        return;
    }

    // Display a list of feedbacks
    cout << "Feedbacks:" << endl;

    for (int i = 0; i < feedback_lines.size(); i++)
    {
        istringstream iss(feedback_lines[i]);
        string username, university, feedback_text, feedback_reply, feedback_time;
        getline(iss, username, ',');
        getline(iss, university, ',');
        getline(iss, feedback_text, ',');
        getline(iss, feedback_reply, ',');
        getline(iss, feedback_time, '\n');

        cout << i + 1 << "." << endl;
        cout << "   Feedback for University " << university << " by " << username << endl;
        cout << "   Feedback: " << feedback_text << endl;
        cout << "   Reply   : " << feedback_reply << endl;
        cout << "   Time    : " << feedback_time << endl;
    }

    // Prompt the admin to select a feedback to reply to
    int selection = 0;

    while (selection < 1 || selection > feedback_lines.size())
    {
        cout << "Select a feedback to reply to (1-" << feedback_lines.size() << "): ";
        cin >> selection;
    }

    // Modify the selected feedback
    istringstream iss(feedback_lines[selection - 1]);
    string username, university, feedback_text, feedback_reply, feedback_time;
    getline(iss, username, ',');
    getline(iss, university, ',');
    getline(iss, feedback_text, ',');
    getline(iss, feedback_reply, ',');
    getline(iss, feedback_time, '\n');

    cout << "Feedback for University " << university << " by " << username << ":" << endl;
    cout << "Feedback: " << feedback_text << endl;
    cout << "Reply   : " << feedback_reply << endl;

    string new_reply;
    cout << "Enter your reply: ";
    cin.ignore();
    getline(cin, new_reply);
    feedback_reply = new_reply;

    feedback_lines[selection - 1] = username + "," + university + "," + feedback_text + "," + feedback_reply + "," + feedback_time;

    // Write the modified contents back to the file
    ofstream feedback_file_out(feedback_file_name);

    if (!feedback_file_out.is_open())
    {
        cerr << "Could not open the file - " << feedback_file_name << endl;
        return;
    }

    for (const auto &line : feedback_lines)
    {
        feedback_file_out << line << endl;
    }

    feedback_file_out.close();
}

void giveFeedback()
{
    string line;
    string feedback;
    ofstream output_file("feedback.csv", ios::out | ios::app);

    // Read the current user's username from the CSV file
    string currentuser, currentuni;
    ifstream current_user_file("current_user.csv");
    ifstream current_uni_file("current_uni.csv");

    if (!current_user_file.is_open())
    {
        cerr << "Could not open the file - 'current_user.csv'" << endl;
        return;
    }

    getline(current_user_file, currentuser);
    current_user_file.close();

    // Read feedback for the current user from the CSV file

    if (!current_uni_file.is_open())
    {
        cerr << "Could not open the file - 'current_uni.csv'" << endl;
        return;
    }

    time_t now = time(0);
    tm *ltm = localtime(&now);

    stringstream time_ss;
    time_ss << std::setw(4) << 1900 + ltm->tm_year << "-"
            << std::setfill('0') << std::setw(2) << 1 + ltm->tm_mon << "-"
            << std::setw(2) << ltm->tm_mday;

    string time_str = time_ss.str();

    getline(current_uni_file, currentuni);
    current_user_file.close();
    cout << "Enter your feedback: ";
    cin >> feedback;
    output_file << currentuser << "," << currentuni << "," << feedback << ","
                << "No-Reply"
                << "," << time_str
                << "\n";
    cout << "Added to Feedback! " << endl;
    output_file.close();
}

void readfeedback()
{
    // Read the current user's username from the CSV file
    string currentuser;
    ifstream current_user_file("current_user.csv");

    if (!current_user_file.is_open())
    {
        cerr << "Could not open the file - 'current_user.csv'" << endl;
        return;
    }

    getline(current_user_file, currentuser);
    current_user_file.close();

    // Read feedback for the current user from the CSV file
    string feedback_file_name = "feedback.csv";
    ifstream feedback_file(feedback_file_name);

    if (!feedback_file.is_open())
    {
        cerr << "Could not open the file - " << feedback_file_name << endl;
        return;
    }

    string line;
    bool feedback_found = false;

    while (getline(feedback_file, line))
    {
        istringstream iss(line);
        string username, feedback_text;
        string university, feedback_reply, feedback_time;
        getline(iss, username, ',');
        getline(iss, university, ',');
        getline(iss, feedback_text, ',');
        getline(iss, feedback_reply, ',');
        getline(iss, feedback_time, '\n');

        if (username == currentuser)
        {
            cout << "Feedback for University " << university << ":" << endl;
            cout << "Date of Feedback " << feedback_time << ":" << endl;
            cout << "Your Feedback: " << feedback_text << endl;
            cout << "Admin Reply  : " << endl;
            cout << endl;
            feedback_found = true;
        }
    }

    feedback_file.close();

    if (!feedback_found)
    {
        cout << "No feedback found for " << currentuser << endl;
    }
}

void savefavourite()
{
    string line;
    ofstream output_file("favourite.csv", ios::out | ios::app);

    // Read the current user's username from the CSV file
    string currentuser, currentuni;
    string checkuser, checkuni;
    ifstream current_user_file("current_user.csv");
    ifstream current_uni_file("current_uni.csv");
    ifstream check_file("favourite.csv");

    if (!current_user_file.is_open())
    {
        cerr << "Could not open the file - 'current_user.csv'" << endl;
        return;
    }
    while (getline(current_user_file, line))
    {
        istringstream iss(line);
        getline(iss, currentuser);
    }
    current_user_file.close();

    // Read feedback for the current user from the CSV file

    if (!current_uni_file.is_open())
    {
        cerr << "Could not open the file - 'current_uni.csv'" << endl;
        return;
    }

    while (getline(current_uni_file, line))
    {
        istringstream iss(line);
        getline(iss, currentuni);
    }
    current_user_file.close();

    if (!check_file.is_open())
    {
        cerr << "Could not open the file - 'favourite_file.csv'" << endl;
        return;
    }
    while (getline(check_file, line))
    {
        istringstream iss(line);
        getline(iss, checkuser, ',');
        getline(iss, checkuni, '\n');
    }
    current_user_file.close();

    if (currentuser == checkuser && currentuni == checkuni)
    {
        cout << "You have added to favourite before! " << endl;
    }
    else
    {
        output_file << currentuser << "," << currentuni << "\n";
        cout << "Added to Favourite! " << endl;
        output_file.close();
        return;
    }
}

void viewfavourite()
{
    // Read the current user's username from the CSV file
    string currentuser;
    ifstream current_user_file("current_user.csv");

    if (!current_user_file.is_open())
    {
        cerr << "Could not open the file - 'current_user.csv'" << endl;
        return;
    }

    getline(current_user_file, currentuser);
    current_user_file.close();

    // Read feedback for the current user from the CSV file
    string feedback_file_name = "favourite.csv";
    ifstream feedback_file(feedback_file_name);

    if (!feedback_file.is_open())
    {
        cerr << "Could not open the file - " << feedback_file_name << endl;
        return;
    }

    string line;
    bool feedback_found = false;
    cout << "Your favourite University: " << endl;
    while (getline(feedback_file, line))
    {
        istringstream iss(line);
        string username, feedback_text;
        string university, feedback_reply;
        getline(iss, username, ',');
        getline(iss, university, '\n');

        if (username == currentuser)
        {
            cout << university << endl;
            feedback_found = true;
        }
    }

    feedback_file.close();

    if (!feedback_found)
    {
        cout << "No favourite University found for " << currentuser << endl;
    }
}

void uni_menu()
{
    while (true)
    {
        int choice;
        cout << "1. Save to Favourite" << endl;
        cout << "2. Write Feedback" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            std::cout << "Exiting program." << std::endl;
            std::exit(0);
            break;

        case 1:
            savefavourite();
            break;

        case 2:
            giveFeedback();
            break;
        }
    }
}

#include <iostream>
#include <fstream>
#include <sstream>

struct Feedback
{
    std::string username;
    std::string universityName;
    std::string userFeedback;
    std::string adminReply;
    std::string feedbackDate;
};

class FeedbackList
{
public:
    struct FeedbackNode
    {
        FeedbackNode *prev;
        FeedbackNode *next;
        Feedback feedback;

        FeedbackNode(const Feedback &feedback)
            : feedback(feedback), prev(nullptr), next(nullptr) {}
    };

    FeedbackNode *head;
    FeedbackNode *tail;

public:
    FeedbackList() : head(nullptr), tail(nullptr) {}

    void addFeedback(const std::string &username, const std::string &universityName,
                     const std::string &userFeedback, const std::string &adminReply, const std::string &feedbackDate)
    {
        Feedback feedback{username, universityName, userFeedback, adminReply, feedbackDate};
        FeedbackNode *newFeedback = new FeedbackNode(feedback);

        if (head == nullptr)
        {
            head = newFeedback;
            tail = newFeedback;
        }
        else
        {
            tail->next = newFeedback;
            newFeedback->prev = tail;
            tail = newFeedback;
        }
    }

    void viewSingleFeedback()
    {
        if (head == nullptr)
        {
            std::cout << "No feedback available." << std::endl;
            return;
        }

        char option = ' ';
        FeedbackNode *curr = head;

        while (curr != nullptr)
        {
            // Display the feedback data
            std::cout << "\nUsername: " << curr->feedback.username << std::endl;
            std::cout << "University Name: " << curr->feedback.universityName << std::endl;
            std::cout << "User Feedback: " << curr->feedback.userFeedback << std::endl;
            std::cout << "Admin Reply: " << curr->feedback.adminReply << std::endl;
            std::cout << "Feedback Date: " << curr->feedback.feedbackDate << std::endl;

            std::cout << "\nEnter 'P' to view the previous feedback, 'N' to view the next feedback, or 'Q' to quit viewing: ";
            std::cin >> option;
            option = std::toupper(option);

            if (option == 'Q')
            {
                break;
            }
            else if (option == 'P')
            {
                if (curr->prev != nullptr)
                {
                    curr = curr->prev;
                }
                else
                {
                    std::cout << "No previous feedback available. Moving to the last feedback." << std::endl;
                    curr = tail;
                }
            }
            else if (option == 'N')
            {
                if (curr->next != nullptr)
                {
                    curr = curr->next;
                }
                else
                {
                    std::cout << "No next feedback available. Moving to the first feedback." << std::endl;
                    curr = head;
                }
            }
            else
            {
                std::cout << "Invalid option. Please try again." << std::endl;
            }
        }
    }

    void quicksortDate(FeedbackNode *low, FeedbackNode *high)
    {
        if (low != nullptr && high != nullptr && low != high && low != high->next)
        {
            FeedbackNode *pivot = partition(low, high);
            quicksortDate(low, pivot->prev);
            quicksortDate(pivot->next, high);
        }
    }

    FeedbackNode *partition(FeedbackNode *low, FeedbackNode *high)
    {
        std::string pivot = high->feedback.feedbackDate;
        FeedbackNode *i = low->prev;

        for (FeedbackNode *j = low; j != high; j = j->next)
        {
            if (j->feedback.feedbackDate >= pivot)
            {
                i = (i == nullptr) ? low : i->next;
                swapFeedback(i, j);
            }
        }

        i = (i == nullptr) ? low : i->next;
        swapFeedback(i, high);

        return i;
    }

    void swapFeedback(FeedbackNode *a, FeedbackNode *b)
    {
        Feedback temp = a->feedback;
        a->feedback = b->feedback;
        b->feedback = temp;
    }
};

const int MAX_FEEDBACKS = 100; // Maximum number of feedbacks

void readFeedbackCSV(const std::string &filename, FeedbackList &feedbackList)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cout << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    int numFeedbacks = 0;

    while (std::getline(file, line) && numFeedbacks < MAX_FEEDBACKS)
    {
        std::istringstream iss(line);
        Feedback feedback;

        std::getline(iss, feedback.username, ',');
        std::getline(iss, feedback.universityName, ',');
        std::getline(iss, feedback.userFeedback, ',');
        std::getline(iss, feedback.adminReply, ',');
        std::getline(iss, feedback.feedbackDate, ',');

        feedbackList.addFeedback(feedback.username, feedback.universityName,
                                 feedback.userFeedback, feedback.adminReply, feedback.feedbackDate);

        numFeedbacks++;
    }

    file.close();
}

void navigateFeedback()
{
    FeedbackList feedbackList;

    // Read feedback from the CSV file and insert it into the feedback list
    readFeedbackCSV("feedback.csv", feedbackList);

    // Sort the feedback list by date in descending order
    feedbackList.quicksortDate(feedbackList.head, feedbackList.tail);

    // View the feedback
    feedbackList.viewSingleFeedback();
}

#include <iostream>
#include <chrono>

using namespace std;

#include "feedback.h"
#include "searchUni.h"
#include "modify_user.h"
#include "adminpage.h"
#include "navigateFeedback.h"
#include "linearsearchUni.h"
#include "exit.h"

int main()
{

    auto start = std::chrono::high_resolution_clock::now();

    displayTarget();

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;

    std::cout << "Execution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}
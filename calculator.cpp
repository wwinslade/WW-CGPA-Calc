#include <iostream>
#include <fstream>

using namespace std;

double calcGradePoints(int hours, string grade) {
    double retval;
    if (grade == "A" || grade == "a") {
        retval = hours * 4.0;
    } else if (grade == "A-" || grade == "a-") {
        retval = hours * 3.7;
    } else if (grade == "B+" || grade == "b+") {
        retval = hours * 3.3;
    } else if (grade == "B" || grade == "b") {
        retval = hours * 3.0;
    } else if (grade == "B-" || grade == "b-") {
        retval = hours * 2.7;
    } else if (grade == "C+" || grade == "c+") {
        retval = hours * 2.3;
    } else if (grade == "C" || grade == "c") {
        retval = hours * 2.0;
    } else if (grade == "C-" || grade == "c-") {
        retval = hours * 1.7;
    } else if (grade == "D+" || grade == "d+") {
        retval = hours * 1.3;
    } else if (grade == "D" || grade == "d") {
        retval = hours * 1.0;
    } else if (grade == "D-" || grade == "d-") {
        retval = hours * 0.7;
    } else if (grade == "F" || grade == "f") {
        retval = hours * 0;
    }
    return retval;
}

int main(int argc, char** argv) {
    // Variables
    ifstream fin;
    int h;
    string g;
    int totalHours = 0;
    double totalGradePoints = 0;
    double cgpa;

    // Input validation
    if (argc != 2) {
        cerr << "Usage: ./calculator file_name" << endl;
        return 1;
    }

    // Get the file into an fstream
    fin.open(argv[1]);
    if (!fin.is_open()) {
        cerr << "Error: Could not open file " << argv[1] << endl;
        return 1;
    }

    // Read in data from file
    while (fin >> h >> g) {
        totalHours += h;
        totalGradePoints += calcGradePoints(h, g);
    }

    // Calculate the values
    cgpa = totalGradePoints / totalHours;
    printf("Total Hours: %d\nTotal Grade Points: %0.2f\nCumulative GPA: %0.2f\n", totalHours, totalGradePoints, cgpa);

    // Done
    return 0;
}
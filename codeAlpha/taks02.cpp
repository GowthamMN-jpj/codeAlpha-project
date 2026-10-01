#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Structure to hold individual course details
struct Course {
    double grade;
    int credits;
};

int main() {
    int numCourses;
    
    cout << "Enter the number of courses taken this semester: ";
    cin >> numCourses;

    vector<Course> courses(numCourses);
    double totalGradePoints = 0.0;
    int currentCredits = 0;

    // Input loop for each course
    for (int i = 0; i < numCourses; i++) {
        cout << "\nCourse " << i + 1 << ":" << endl;
        cout << "Enter Grade Point (e.g., 9.5 or 4.0): ";
        cin >> courses[i].grade;
        cout << "Enter Credit Hours: ";
        cin >> courses[i].credits;

        // Calculate running totals
        totalGradePoints += (courses[i].grade * courses[i].credits);
        currentCredits += courses[i].credits;
    }

    // Calculate Semester GPA
    double semesterGPA = 0.0;
    if (currentCredits > 0) {
        semesterGPA = totalGradePoints / currentCredits;
    }

    // Ask for previous academic records to compute Overall CGPA
    char hasPreviousHistory;
    cout << "\nDo you have previous semester records to calculate overall CGPA? (y/n): ";
    cin >> hasPreviousHistory;

    double overallCGPA = semesterGPA; // Defaults to semester GPA if first semester

    if (hasPreviousHistory == 'y' || hasPreviousHistory == 'Y') {
        double prevCGPA;
        int prevCredits;
        
        cout << "Enter your previous Overall CGPA: ";
        cin >> prevCGPA;
        cout << "Enter your total previous Credit Hours: ";
        cin >> prevCredits;

        // Calculate Overall CGPA including past semesters
        double totalOverallPoints = (prevCGPA * prevCredits) + totalGradePoints;
        int totalOverallCredits = prevCredits + currentCredits;
        
        if (totalOverallCredits > 0) {
            overallCGPA = totalOverallPoints / totalOverallCredits;
        }
    }

    // Display Output
    cout << "\n====================================\n";
    cout << "        ACADEMIC REPORT             \n";
    cout << "====================================\n";
    
    for (int i = 0; i < numCourses; i++) {
        cout << "Course " << i + 1 << " | Grade: " << fixed << setprecision(2) << courses[i].grade 
             << " | Credits: " << courses[i].credits << endl;
    }

    cout << "------------------------------------\n";
    cout << "Total Semester Credits : " << currentCredits << endl;
    cout << "Total Grade Points     : " << fixed << setprecision(2) << totalGradePoints << endl;
    cout << "Semester GPA           : " << fixed << setprecision(2) << semesterGPA << endl;
    cout << "Overall CGPA           : " << fixed << setprecision(2) << overallCGPA << endl;
    cout << "====================================\n";

    return 0;
}
#include "../include/Global.h"
#include "../include/Student.h"
#include "../include/Professor.h"
#include "../include/Library.h"
#include "../include/Announcement.h"
#include "../include/LostAndFound.h"
#include <iostream>
using namespace std;

int main() {
    // Load all system data at startup
    loadCredentials();
    loadCourses();
    loadEnrollments();
    loadPendingEnrollments();
    loadBooks();
    loadBorrowed();
    Announcement::loadAnnouncements();
    LostAndFound::load();

    int choice;
    cout << "\n--- Virtual Smart Campus System ---\n";
    cout << "1. Student Signup\n";
    cout << "2. Student Login\n";
    cout << "3. Professor Signup\n";
    cout << "4. Professor Login\n";
    cout << "Choice: ";
    cin >> choice;

    if (choice == 1) {
        Student s;
        s.signup();
    } else if (choice == 2) {
        Student s;
        if (s.login()) {
            Library lib;
            int opt;
            do {
                cout << "\n--- Student Menu ---\n";
                cout << "1. View All Courses\n";
                cout << "2. View My Courses\n";
                cout << "3. Request Enrollment\n";
                cout << "4. View Library Books\n";
                cout << "5. Search Library Books\n";
                cout << "6. Borrow Book\n";
                cout << "7. Return Book\n";
                cout << "8. View Campus Announcements\n";
                cout << "9. Report Lost/Found Item\n";
                cout << "10. View Lost & Found Board\n";
                cout << "0. Logout\n";
                cout << "Choice: ";
                cin >> opt;
                switch (opt) {
                    case 1: s.viewAvailableCourses(); break;
                    case 2: s.viewMyCourses(); break;
                    case 3: s.enrollInCourse(); break;
                    case 4: lib.viewAllBooks(); break;
                    case 5: lib.searchBook(); break;
                    case 6: lib.borrowBook(s.getUsername()); break;
                    case 7: lib.returnBook(s.getUsername()); break;
                    case 8: Announcement::viewAnnouncements(); break;
                    case 9: LostAndFound::reportItem(s.getUsername()); break;
                    case 10: LostAndFound::viewItems(); break;
                    case 0: break;
                    default: cout << "Invalid option!\n";
                }
            } while (opt != 0);
        }
    } else if (choice == 3) {
        Professor p;
        p.signup();
    } else if (choice == 4) {
        Professor p;
        if (p.login()) {
            int opt;
            do {
                cout << "\n--- Professor Menu ---\n";
                cout << "1. Create Course\n";
                cout << "2. View My Courses\n";
                cout << "3. Review Enrollment Requests\n";
                cout << "4. Post Campus Announcement\n";
                cout << "0. Logout\n";
                cout << "Choice: ";
                cin >> opt;
                switch (opt) {
                    case 1: p.createCourse(); break;
                    case 2: p.viewMyCourses(); break;
                    case 3: p.reviewEnrollmentRequests(); break;
                    case 4: {
                        cin.ignore();
                        string text;
                        cout << "Enter announcement: ";
                        getline(cin, text);
                        Announcement::addAnnouncement(text);
                        cout << "Announcement posted.\n";
                        break;
                    }
                    case 0: break;
                    default: cout << "Invalid option!\n";
                }
            } while (opt != 0);
        }
    } else {
        cout << "Invalid choice!\n";
    }

    // Save all data before exit
    saveCredentials();
    saveCourses();
    saveEnrollments();
    savePendingEnrollments();
    saveBooks();
    saveBorrowed();
    // Announcements and Lost/Found saved immediately on action
    return 0;
}
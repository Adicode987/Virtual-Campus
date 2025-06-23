#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "User.h"
#include "Global.h"
#include <iostream>
using namespace std;

class Professor : public User {
public:
    void signup() override {
        cout << "Enter new professor username: ";
        cin >> username;
        if (professorCredentials.count(username)) {
            cout << "Username already exists!\n";
            return;
        }
        cout << "Enter password: ";
        cin >> password;
        professorCredentials[username] = password;
        cout << "Professor registered successfully!\n";
    }

    bool login() override {
        cout << "Enter professor username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        if (professorCredentials.count(username) && professorCredentials[username] == password) {
            cout << "Login successful!\n";
            return true;
        }
        cout << "Invalid credentials!\n";
        return false;
    }

    void createCourse() {
        string cid;
        cout << "Enter Course ID to create: ";
        cin >> cid;
        if (courseData.count(cid)) {
            cout << "Course ID already exists!\n";
            return;
        }
        courseData[cid] = username;
        cout << "Course created successfully!\n";
    }

    void viewMyCourses() {
        cout << "\nCourses Created By You:\n";
        for (auto& it : courseData) {
            if (it.second == username)
                cout << "Course ID: " << it.first << "\n";
        }
    }

    void reviewEnrollmentRequests() {
        cout << "\n Pending Enrollment Requests:\n";
        for (auto it = pendingEnrollments.begin(); it != pendingEnrollments.end(); ) {
            string key = it->first;
            string cid = it->second;

            if (courseData[cid] == username) {
                string student = key.substr(0, key.find("_"));
                cout << "Student: " << student << " | Course ID: " << cid << "\nApprove? (y/n): ";
                char choice; cin >> choice;

                if (choice == 'y' || choice == 'Y') {
                    enrollments[key] = cid;
                    it = pendingEnrollments.erase(it);
                    cout << " Approved.\n";
                } else {
                    ++it;
                    cout << "⏭ Skipped.\n";
                }
            } else {
                ++it;
            }
        }
    }
};

#endif
#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include "LostAndFound.h"
#include "Global.h"
#include <iostream>
using namespace std;

class Student : public User {
public:
    void signup() override {
        cout << "Enter new student username: ";
        cin >> username;
        if (studentCredentials.count(username)) {
            cout << "Username already exists!\n";
            return;
        }
        cout << "Enter password: ";
        cin >> password;
        studentCredentials[username] = password;
        cout << "Student registered successfully!\n";
    }

    bool login() override {
        cout << "Enter student username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        if (studentCredentials.count(username) && studentCredentials[username] == password) {
            cout << "Login successful!\n";
            return true;
        }
        cout << "Invalid credentials!\n";
        return false;
    }

    void viewAvailableCourses() {
        cout << "\nAvailable Courses:\n";
        for (auto& it : courseData)
            cout << "Course ID: " << it.first << ", Professor: " << it.second << "\n";
    }

    void viewMyCourses() {
        cout << "\nYour Enrolled Courses:\n";
        for (auto& it : enrollments) {
            if (it.first.find(username + "_") == 0)
                cout << "Course ID: " << it.second << "\n";
        }
    }

    void enrollInCourse() {
        string cid;
        cout << "Enter Course ID to request enrollment: ";
        cin >> cid;

        if (courseData.count(cid)) {
            string key = username + "_" + cid;

            if (enrollments.count(key)) {
                cout << " Already enrolled!\n";
                return;
            }

            if (pendingEnrollments.count(key)) {
                cout << " Request already sent. Awaiting professor approval.\n";
                return;
            }

            pendingEnrollments[key] = cid;
            cout << " Enrollment request submitted. Waiting for approval.\n";
        } else {
            cout << " Invalid Course ID!\n";
        }
    }
};

#endif
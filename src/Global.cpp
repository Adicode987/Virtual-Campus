#include "../include/Global.h"
#include <fstream>
#include <sstream>

// Definitions for Credential & Course Management
std::map<std::string, std::string> studentCredentials;
std::map<std::string, std::string> professorCredentials;
std::map<std::string, std::string> courseData;
std::map<std::string, std::string> enrollments;
std::map<std::string, std::string> pendingEnrollments;

// Definitions for Library Management
std::map<std::string, Book> libraryInventory;
std::map<std::string, std::vector<std::string>> borrowedBooks;

// ------------ Credential & Course Functions ------------

void loadCredentials() {
    std::ifstream fin("data/students.txt");
    std::string u, p;
    while (fin >> u >> p)
        studentCredentials[u] = p;
    fin.close();

    fin.open("data/professors.txt");
    while (fin >> u >> p)
        professorCredentials[u] = p;
    fin.close();
}

void saveCredentials() {
    std::ofstream fout("data/students.txt");
    std::map<std::string, std::string>::iterator it;
    for (it = studentCredentials.begin(); it != studentCredentials.end(); ++it)
        fout << it->first << " " << it->second << "\n";
    fout.close();

    fout.open("data/professors.txt");
    for (it = professorCredentials.begin(); it != professorCredentials.end(); ++it)
        fout << it->first << " " << it->second << "\n";
    fout.close();
}

void loadCourses() {
    std::ifstream fin("data/courses.txt");
    std::string id, prof;
    while (fin >> id >> prof)
        courseData[id] = prof;
    fin.close();
}

void saveCourses() {
    std::ofstream fout("data/courses.txt");
    std::map<std::string, std::string>::iterator it;
    for (it = courseData.begin(); it != courseData.end(); ++it)
        fout << it->first << " " << it->second << "\n";
    fout.close();
}

void loadEnrollments() {
    std::ifstream fin("data/enrollments.txt");
    std::string key, course;
    while (fin >> key >> course)
        enrollments[key] = course;
    fin.close();
}

void saveEnrollments() {
    std::ofstream fout("data/enrollments.txt");
    std::map<std::string, std::string>::iterator it;
    for (it = enrollments.begin(); it != enrollments.end(); ++it)
        fout << it->first << " " << it->second << "\n";
    fout.close();
}

void loadPendingEnrollments() {
    std::ifstream fin("data/pending.txt");
    std::string key, course;
    while (fin >> key >> course)
        pendingEnrollments[key] = course;
    fin.close();
}

void savePendingEnrollments() {
    std::ofstream fout("data/pending.txt");
    std::map<std::string, std::string>::iterator it;
    for (it = pendingEnrollments.begin(); it != pendingEnrollments.end(); ++it)
        fout << it->first << " " << it->second << "\n";
    fout.close();
}

// ---------------- Library Functions ----------------

void loadBooks() {
    std::ifstream fin("data/books.txt");
    std::string id, title, author, qtyStr;
    while (getline(fin, id)) {
        getline(fin, title, '|');
        getline(fin, author, '|');
        getline(fin, qtyStr);
        int qty = std::stoi(qtyStr);
        libraryInventory[id] = Book{id, title, author, qty};
    }
    fin.close();
}

void saveBooks() {
    std::ofstream fout("data/books.txt");
    std::map<std::string, Book>::iterator it;
    for (it = libraryInventory.begin(); it != libraryInventory.end(); ++it) {
        fout << it->first << "\n"
             << it->second.title << "|" << it->second.author << "|" << it->second.quantity << "\n";
    }
    fout.close();
}

void loadBorrowed() {
    std::ifstream fin("data/borrowed.txt");
    std::string line;
    while (getline(fin, line)) {
        std::stringstream ss(line);
        std::string user, bookId;
        ss >> user >> bookId;
        borrowedBooks[user].push_back(bookId);
    }
    fin.close();
}

void saveBorrowed() {
    std::ofstream fout("data/borrowed.txt");
    std::map<std::string, std::vector<std::string>>::iterator it;
    for (it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
        std::vector<std::string>::iterator vecIt;
        for (vecIt = it->second.begin(); vecIt != it->second.end(); ++vecIt)
            fout << it->first << " " << *vecIt << "\n";
    }
    fout.close();
}

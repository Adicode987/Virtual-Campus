#ifndef GLOBAL_H
#define GLOBAL_H

#include <map>
#include <string>
#include <vector>
#include "Book.h"

// User credential and course mappings
extern std::map<std::string, std::string> studentCredentials;
extern std::map<std::string, std::string> professorCredentials;
extern std::map<std::string, std::string> courseData;
extern std::map<std::string, std::string> enrollments;
extern std::map<std::string, std::string> pendingEnrollments;

// Library system
extern std::map<std::string, Book> libraryInventory;
extern std::map<std::string, std::vector<std::string>> borrowedBooks;

// File loading
void loadCredentials();
void loadCourses();
void loadEnrollments();
void loadPendingEnrollments();
void loadBooks();
void loadBorrowed();

// File saving
void saveCredentials();
void saveCourses();
void saveEnrollments();
void savePendingEnrollments();
void saveBooks();
void saveBorrowed();

#endif
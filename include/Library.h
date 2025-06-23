#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "Global.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;

class Library {
public:
    void viewAllBooks() {
        cout << "\nAll Available Books:\n";
        map<string, Book>::iterator it;
        for (it = libraryInventory.begin(); it != libraryInventory.end(); ++it) {
            string id = it->first;
            Book b = it->second;
            cout << "ID: " << id << ", Title: " << b.title << ", Author: " << b.author
                 << ", Available: " << b.quantity << "\n";
        }
    }

    void searchBook() {
        string query;
        cout << "Enter title or author to search: ";
        cin.ignore();
        getline(cin, query);
        cout << "\nSearch Results:\n";
        map<string, Book>::iterator it;
        for (it = libraryInventory.begin(); it != libraryInventory.end(); ++it) {
            string id = it->first;
            Book b = it->second;
            if (b.title.find(query) != string::npos || b.author.find(query) != string::npos) {
                cout << "ID: " << id << ", Title: " << b.title << ", Author: " << b.author
                     << ", Available: " << b.quantity << "\n";
            }
        }
    }

    void borrowBook(const string & student) {
        string id;
        cout << "Enter Book ID to borrow: ";
        cin >> id;
        if (libraryInventory.count(id) == 0) {
            cout << "Book ID not found.\n";
            return;
        }
        Book & b = libraryInventory[id];
        if (b.quantity <= 0) {
            cout << "No copies available.\n";
            return;
        }
        vector<string> & books = borrowedBooks[student];
        if (find(books.begin(), books.end(), id) != books.end()) {
            cout << "You already borrowed this book.\n";
            return;
        }
        b.quantity--;
        books.push_back(id);
        cout << "Book borrowed successfully!\n";
    }

    void returnBook(const string & student) {
        vector<string> & books = borrowedBooks[student];
        if (books.empty()) {
            cout << "You haven't borrowed any books.\n";
            return;
        }
        cout << "Books you've borrowed:\n";
        for (int i = 0; i < static_cast<int>(books.size()); ++i) {
            string id = books[i];
            cout << i + 1 << ". " << id << " (" << libraryInventory[id].title << ")\n";
        }
        int choice;
        cout << "Enter number to return (0 to cancel): ";
        cin >> choice;
        if (choice <= 0 || choice > static_cast<int>(books.size())) return;
        string id = books[choice - 1];
        libraryInventory[id].quantity++;
        books.erase(books.begin() + (choice - 1));
        cout << "Book returned successfully!\n";
    }
};

#endif

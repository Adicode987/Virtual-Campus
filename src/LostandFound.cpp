#include "../include/LostAndFound.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

vector<LostFoundEntry> LostAndFound::entries;

void LostAndFound::load() {
    entries.clear();
    ifstream fin("data/lost_and_found.txt");
    string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        LostFoundEntry entry;
        getline(ss, entry.type, '|');
        getline(ss, entry.username, '|');
        getline(ss, entry.item, '|');
        getline(ss, entry.location, '|');
        getline(ss, entry.description);
        entries.push_back(entry);
    }
    fin.close();
}

void LostAndFound::save() {
    ofstream fout("data/lost_and_found.txt");
    for (auto &e : entries)
        fout << e.type << "|" << e.username << "|" << e.item << "|"
             << e.location << "|" << e.description << "\n";
    fout.close();
}

void LostAndFound::reportItem(const string &username) {
    LostFoundEntry e;
    cout << "Is this a LOST or FOUND item? ";
    cin >> e.type;
    cin.ignore();
    cout << "Enter item name: ";
    getline(cin, e.item);
    cout << "Enter location: ";
    getline(cin, e.location);
    cout << "Enter description: ";
    getline(cin, e.description);
    e.username = username;
    entries.push_back(e);
    save();
    cout << "Report submitted.\n";
}

void LostAndFound::viewItems() {
    cout << "\n--- Lost and Found Board ---\n";
    if (entries.empty()) {
        cout << "No items have been reported yet.\n";
    } else {
        for (auto &e : entries) {
            cout << e.type << " | " << e.username << " | " << e.item
                 << " @ " << e.location << " — " << e.description << "\n";
        }
    }
}
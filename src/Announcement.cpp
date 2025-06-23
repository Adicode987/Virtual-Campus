#include "../include/Announcement.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "../include/Announcement.h"
#include <fstream>
using namespace std;
std::vector<std::string> Announcement::announcements;

void Announcement::loadAnnouncements() {
    announcements.clear();
    std::ifstream fin("data/announcements.txt");
    std::string line;
    while (getline(fin, line)) {
        if (!line.empty())
            announcements.push_back(line);
    }
    fin.close();
}

void Announcement::saveAnnouncements() {
    std::ofstream fout("data/announcements.txt");
    for (auto &ann : announcements)
        fout << ann << "\n";
    fout.close();
}

void Announcement::addAnnouncement(const std::string &text) {
    announcements.push_back(text);
    saveAnnouncements();
}

void Announcement::viewAnnouncements() {
    std::cout << "\n--- Campus Announcements ---\n";
    if (announcements.empty()) {
        std::cout << "No announcements available.\n";
    } else {
        for (auto &ann : announcements)
            std::cout << "- " << ann << "\n";
    }
}
#ifndef ANNOUNCEMENT_H
#define ANNOUNCEMENT_H

#include <string>
#include <vector>
#include <iostream>

class Announcement {
public:
    static std::vector<std::string> announcements;

    static void loadAnnouncements();
    static void saveAnnouncements();
    static void addAnnouncement(const std::string &text);
    static void viewAnnouncements();
};

#endif
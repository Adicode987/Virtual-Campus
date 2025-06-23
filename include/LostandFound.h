#ifndef LOST_AND_FOUND_H
#define LOST_AND_FOUND_H

#include <string>
#include <vector>

struct LostFoundEntry {
    std::string type;       // "LOST" or "FOUND"
    std::string username;
    std::string item;
    std::string location;
    std::string description;
};

class LostAndFound {
public:
    static std::vector<LostFoundEntry> entries;

    static void load();
    static void save();
    static void reportItem(const std::string &username);
    static void viewItems();
};

#endif
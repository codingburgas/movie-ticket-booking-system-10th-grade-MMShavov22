#pragma once
#include <string>
#include <vector>
#include "show.h"

class hall {
public:
    hall(const std::string& name, int capacity);

    void addShow(const show& show);
    std::string getName() const;
    int getCapacity() const;
    std::vector<show> getShows() const;

private:
    std::string name;
    int capacity;
    std::vector<show> shows;
};
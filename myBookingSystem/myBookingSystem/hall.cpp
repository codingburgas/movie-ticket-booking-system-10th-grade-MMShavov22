#include "hall.h"

hall::hall(const std::string& name, int capacity) : name(name), capacity(capacity) {}

void hall::addShow(const show& show) {
    shows.push_back(show);
}

std::string hall::getName() const {
    return name;
}

int hall::getCapacity() const {
    return capacity;
}

std::vector<show> hall::getShows() const {
    return shows;
}
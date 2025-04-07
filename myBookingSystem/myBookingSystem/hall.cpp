#include "hall.h"

Hall::Hall(const std::string& name, int capacity) : name(name), capacity(capacity) {}

void Hall::addShow(const show& show) {
    shows.push_back(show);
}

std::string Hall::getName() const {
    return name;
}

int Hall::getCapacity() const {
    return capacity;
}

std::vector<show> Hall::getShows() const {
    return shows;
}
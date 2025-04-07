#include "Cinema.h"

Cinema::Cinema(const std::string& name, const std::string& city) : name(name), city(city) {}

void Cinema::addHall(const Hall& hall) {
    halls.push_back(hall);
}

std::string Cinema::getName() const {
    return name;
}

std::string Cinema::getCity() const {
    return city;
}

std::vector<Hall> Cinema::getHalls() const {
    return halls;
}
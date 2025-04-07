#pragma once
#include <string>
#include <vector>
#include "hall.h"

class Cinema {
public:
    Cinema(const std::string& name, const std::string& city);

    void addHall(const Hall& hall);
    std::string getName() const;
    std::string getCity() const;
    std::vector<Hall> getHalls() const;

private:
    std::string name;
    std::string city;
    std::vector<Hall> halls;
};
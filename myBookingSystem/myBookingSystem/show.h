#pragma once
#include <string>
#include <vector>
#include "movie.h"

class show {
public:
    show(const std::string& time);

    std::string getTime() const;

    std::vector<movie> getmovies() const;

private:
    std::string time;
};
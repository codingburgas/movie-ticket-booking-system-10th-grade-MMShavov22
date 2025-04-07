#pragma once
#include <string>
#include <vector>
#include "hall.h"
#include "movie.h"

class Cinema {
public:
    Cinema(const std::string& name, const std::string& city);

    void addHall(const hall& hall);
    std::string getName() const;
    std::string getCity() const;
    std::vector<hall> getHalls() const;
    std::vector<movie> searchMovies(const std::string& title, const std::string& language,
        const std::string& genre, const std::string& releaseDate) const;

private:
    std::string name;
    std::string city;
    std::vector<hall> halls;
};
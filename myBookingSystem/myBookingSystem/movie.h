#pragma once
#include <string>
#include <vector>
#include "show.h"

class movie {
public:
    movie(const std::string& title, const std::string& language, const std::string& genre, const std::string& releaseDate);

    void addShow(const show& show);
    std::string getTitle() const;
    std::string getLanguage() const;
    std::string getGenre() const;
    std::string getReleaseDate() const;
    std::vector<show> getShows() const;

private:
    std::string title;
    std::string language;
    std::string genre;
    std::string releaseDate;
    std::vector<show> shows;
};
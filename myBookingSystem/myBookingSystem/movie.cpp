#include "movie.h"

movie::movie(const std::string& title, const std::string& language, const std::string& genre, const std::string& releaseDate)
    : title(title), language(language), genre(genre), releaseDate(releaseDate) {
}

void movie::addShow(const show& show) {
    shows.push_back(show);
}

std::string movie::getTitle() const {
    return title;
}

std::string movie::getLanguage() const {
    return language;
}

std::string movie::getGenre() const {
    return genre;
}

std::string movie::getReleaseDate() const {
    return releaseDate;
}

std::vector<show> movie::getShows() const {
    return shows;
}
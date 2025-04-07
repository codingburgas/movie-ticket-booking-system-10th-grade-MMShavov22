#include "Cinema.h"

Cinema::Cinema(const std::string& name, const std::string& city) : name(name), city(city) {}

void Cinema::addHall(const hall& hall) {
    halls.push_back(hall);
}

std::string Cinema::getName() const {
    return name;
}

std::string Cinema::getCity() const {
    return city;
}

std::vector<hall> Cinema::getHalls() const {
    return halls;
}

std::vector<movie> Cinema::searchMovies(const std::string& title, const std::string& language,
    const std::string& genre, const std::string& releaseDate) const {
    std::vector<movie> results;
    for (const auto& hall : halls) {
        for (const auto& show : hall.getShows()) {
            for (const auto& movie : show.getMovies()) {  
                if ((title.empty() || movie.getTitle() == title) &&
                    (language.empty() || movie.getLanguage() == language) &&
                    (genre.empty() || movie.getGenre() == genre) &&
                    (releaseDate.empty() || movie.getReleaseDate() == releaseDate)) {
                    results.push_back(movie);
                }
            }
        }
    }
    return results;
}
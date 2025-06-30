#include "bookingSystem.h"
#include "manager.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

int BookingSystem::selectCity() {
    std::cout << "Select a city:\n1. Burgas\n2. Varna\n3. Sofiq\n";
    int choice;
    std::cin >> choice;
    return (choice >= 1 && choice <= 3) ? choice : -1;
}

int BookingSystem::selectCinema(int cityChoice) {
    std::cout << "Select a cinema in City " << cityChoice << ":\n1. CinemaCity \n2. Cineby\n";
    int choice;
    std::cin >> choice;
    return (choice >= 1 && choice <= 2) ? choice : -1;
}

int BookingSystem::selectGenre() {
    std::cout << "Select a genre:\n1. Action\n2. Comedy\n3. Drama\n";
    int choice;
    std::cin >> choice;
    return (choice >= 1 && choice <= 3) ? choice : -1;
}

int BookingSystem::selectMovie(int genreChoice) {
    std::vector<std::string> movies;
    switch (genreChoice) {
    case 1:
        movies = {
            "Die Hard",
            "Mad Max: Fury Road",
            "John Wick",
            "The Dark Knight",
            "Gladiator"
        };
        break;
    case 2:
        movies = {
            "Superbad",
            "The Hangover",
            "Step Brothers",
            "Anchorman",
            "Groundhog Day"
        };
        break;
    case 3:
        movies = {
            "The Shawshank Redemption",
            "Forrest Gump",
            "Fight Club",
            "The Godfather",
            "A Beautiful Mind"
        };
        break;
    default:
        std::cout << "Invalid genre.\n";
        return -1;
    }

    std::cout << "Select a movie:\n";
    for (size_t i = 0; i < movies.size(); ++i) {
        std::cout << (i + 1) << ". " << movies[i] << "\n";
    }
    int choice;
    std::cin >> choice;
    if (choice < 1 || choice > static_cast<int>(movies.size())) {
        std::cout << "Invalid movie selection.\n";
        return -1;
    }
    return choice;
}

void BookingSystem::printBookingDetails(int cityChoice, int cinemaChoice, int movieChoice) {
    std::cout << "Booking Details:\n";
    std::cout << "City: " << cityChoice << "\nCinema: " << cinemaChoice << "\nMovie: " << movieChoice << "\n";
}

void BookingSystem::completeBooking(int cityChoice, int cinemaChoice, int movieChoice, const std::vector<Seat>& bookedSeats, bool isOnlineCustomer) {
    std::cout << "Booking completed successfully!\n";
    std::cout << "Seats booked: " << bookedSeats.size() << "\n";
}

double BookingSystem::calculateTotalPrice(const std::vector<Seat>& selectedSeats) {
    const double pricePerSeat = 10.0;
    return selectedSeats.size() * pricePerSeat;
}


std::string sanitize(const std::string& s) {
    std::string out = s;
    std::replace(out.begin(), out.end(), ' ', '_');
    return out;
}


void saveSeatsToFile(const std::string& city, const std::string& cinema, const std::string& movie,
    const std::vector<std::vector<Seat>>& seats, const std::string& filename) {
    
    std::ifstream in(filename);
    std::vector<std::string> lines;
    std::string line;
    std::string key = sanitize(city) + "|" + sanitize(cinema) + "|" + sanitize(movie) + "|";
    while (std::getline(in, line)) {
        
        if (line.substr(0, key.size()) != key) {
            lines.push_back(line);
        }
    }
    in.close();

   
    for (const auto& row : seats) {
        for (const auto& seat : row) {
            std::ostringstream oss;
            oss << sanitize(city) << "|" << sanitize(cinema) << "|" << sanitize(movie) << "|"
                << seat.row << " " << seat.col << " " << seat.type << " " << seat.isBooked;
            lines.push_back(oss.str());
        }
    }

   
    std::ofstream out(filename, std::ios::trunc);
    for (const auto& l : lines) {
        out << l << "\n";
    }
}


void loadSeatsFromFile(const std::string& city, const std::string& cinema, const std::string& movie,
    std::vector<std::vector<Seat>>& seats, const std::string& filename) {
    std::ifstream in(filename);
    if (!in) return;
    std::string line;
    std::string key = sanitize(city) + "|" + sanitize(cinema) + "|" + sanitize(movie) + "|";
    while (std::getline(in, line)) {
        if (line.substr(0, key.size()) == key) {
            std::istringstream iss(line.substr(key.size()));
            int row, col, typeInt;
            bool isBooked;
            if (iss >> row >> col >> typeInt >> isBooked) {
                if (row > 0 && col > 0 && row <= (int)seats.size() && col <= (int)seats[0].size()) {
                    seats[row - 1][col - 1].isBooked = isBooked;
                    seats[row - 1][col - 1].type = static_cast<SeatType>(typeInt);
                }
            }
        }
    }
}

void bookSeat() {
    BookingSystem bookingSystem;

    
    clearScreen();
    paddingUp(1);
    centerText("Welcome to the Booking System");
    paddingUp(1);
    int cityChoice = bookingSystem.selectCity();
    if (cityChoice == -1) {
        centerText("Invalid city selection.");
        return;
    }

    clearScreen();
    paddingUp(1);
    centerText("Select a Cinema");
    paddingUp(1);
    int cinemaChoice = bookingSystem.selectCinema(cityChoice);
    if (cinemaChoice == -1) {
        centerText("Invalid cinema selection.");
        return;
    }

    clearScreen();
    paddingUp(1);
    centerText("Select a Genre");
    paddingUp(1);
    int genreChoice = bookingSystem.selectGenre();
    if (genreChoice == -1) {
        centerText("Invalid genre selection.");
        return;
    }

    clearScreen();
    paddingUp(1);
    centerText("Select a Movie");
    paddingUp(1);
    int movieChoice = bookingSystem.selectMovie(genreChoice);
    if (movieChoice == -1) {
        centerText("Invalid movie selection.");
        return;
    }

    
    const char* cities[] = { "Burgas", "Varna", "Sofiq" };
    const char* cinemas[] = { "CinemaCity", "Cineby" };
    std::vector<std::string> movies;
    switch (genreChoice) {
    case 1:
        movies = { "Die Hard", "Mad Max: Fury Road", "John Wick", "The Dark Knight", "Gladiator" };
        break;
    case 2:
        movies = { "Superbad", "The Hangover", "Step Brothers", "Anchorman", "Groundhog Day" };
        break;
    case 3:
        movies = { "The Shawshank Redemption", "Forrest Gump", "Fight Club", "The Godfather", "A Beautiful Mind" };
        break;
    }
    std::string cityName = cities[cityChoice - 1];
    std::string cinemaName = cinemas[cinemaChoice - 1];
    std::string movieName = movies[movieChoice - 1];

    const std::string seatFile = "seatGrids.txt";

    
    const int ROWS = 5, COLS = 5;
    std::vector<std::vector<Seat>> seats(ROWS, std::vector<Seat>(COLS));
    for (int r = 0; r < ROWS; ++r)
        for (int c = 0; c < COLS; ++c)
            seats[r][c] = Seat(r + 1, c + 1, SILVER, false);

    
    loadSeatsFromFile(cityName, cinemaName, movieName, seats, seatFile);

    clearScreen();
    paddingUp(1);
    centerText("Available Seats (row x col):");
    for (int r = 0; r < ROWS; ++r) {
        std::string rowStr;
        for (int c = 0; c < COLS; ++c) {
            if (seats[r][c].isBooked)
                rowStr += "[\\] ";
            else {
                rowStr += "[" + std::to_string(r + 1) + "," + std::to_string(c + 1) + "] ";
            }
        }
        centerText(rowStr);
    }
    paddingUp(1);

    std::vector<Seat> selectedSeats;
    char more = 'y';
    while (more == 'y' || more == 'Y') {
        int row, col;
        centerText("Enter seat row (1-" + std::to_string(ROWS) + "): ");
        std::cin >> row;
        centerText("Enter seat column (1-" + std::to_string(COLS) + "): ");
        std::cin >> col;
        std::cin.ignore();

        if (row < 1 || row > ROWS || col < 1 || col > COLS) {
            centerText("Invalid seat coordinates.");
        }
        else if (seats[row - 1][col - 1].isBooked) {
            centerText("Seat already booked.");
        }
        else {
            seats[row - 1][col - 1].isBooked = true;
            selectedSeats.push_back(seats[row - 1][col - 1]);
            centerText("Seat [" + std::to_string(row) + "," + std::to_string(col) + "] selected.");
        }

        centerText("Book another seat? (y/n): ");
        std::cin >> more;
        std::cin.ignore();
    }

    if (selectedSeats.empty()) {
        centerText("No seats selected. Booking cancelled.");
        return;
    }

    
    saveSeatsToFile(cityName, cinemaName, movieName, seats, seatFile);

    clearScreen();
    paddingUp(2);
    centerText("Booking Details");
    paddingUp(1);
    centerText("City: " + cityName);
    centerText("Cinema: " + cinemaName);
    centerText("Movie: " + movieName);
    paddingUp(3);
    double totalPrice = bookingSystem.calculateTotalPrice(selectedSeats);
    centerText("Total price: $" + std::to_string(totalPrice));
    paddingUp(2);

    centerText("Press Enter to continue...");
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');

    bookingSystem.completeBooking(cityChoice, cinemaChoice, movieChoice, selectedSeats, true);
    clearScreen();
}
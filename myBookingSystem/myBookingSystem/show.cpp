#include "show.h"

show::show(const std::string& time) : time(time) {}

std::string show::getTime() const {
    return time;
}
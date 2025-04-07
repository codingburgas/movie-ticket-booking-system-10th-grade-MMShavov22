#pragma once
#include <string>

class show {
public:
    show(const std::string& time);

    std::string getTime() const;

private:
    std::string time;
};
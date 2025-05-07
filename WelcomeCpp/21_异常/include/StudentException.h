#pragma once

#include <stdexcept>
#include <string>

class StudentException : public std::exception
{
private:
    std::string message_;

public:
    StudentException(const std::string message);
    const char *what() const noexcept override;
};
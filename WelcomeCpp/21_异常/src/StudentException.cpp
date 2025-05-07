#include "StudentException.h"
#include <string>
#include <sstream>

StudentException::StudentException(const std::string message) {
    std::stringstream ss;
    ss << "学生成绩必须在0-100, 你输入的成绩是: " << message;
    message_ = ss.str();
}

const char* StudentException::what() const noexcept {
    return message_.c_str();
}
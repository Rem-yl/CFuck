#pragma once
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

class KeyNotFoundException: public std::exception {
private:
    std::string message;

public:
    KeyNotFoundException(const std::string message_);
    const char* what() const noexcept override;
};

class ConfigLoader {
private:
    std::unordered_map<std::string, std::string> data;
    const std::string& file_name;
    std::ifstream file;
    
public:
    ConfigLoader(const std::string& file_name_);
    ~ConfigLoader();

    void load();
    std::string getValue(const std::string& key) const;
};
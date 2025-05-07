#include "ConfigLoader.h"
#include <sstream>
#include <fstream>
#include <string>


KeyNotFoundException::KeyNotFoundException(const std::string message_) {
    message = "Key: " + message + " Not Find.";
}
    

const char* KeyNotFoundException::what() const noexcept {
    return message.c_str();
}


ConfigLoader::ConfigLoader(const std::string& file_name_)
    :file_name(file_name_), file(file_name_) 
    {};

ConfigLoader::~ConfigLoader() {
    file.close();
}

std::string ConfigLoader::getValue(const std::string& key) const {
    auto it = data.find(key);
    if (it != data.end()) {
        return it->second;
    } else {
        throw KeyNotFoundException(key);
    }
}

void ConfigLoader::load() {
    if(file.is_open()) {
        std::string line;
        while(std::getline(file, line)) {
            line.erase(0, line.find_first_not_of(" \t\r\n")); // 去除首部空格
            line.erase(line.find_last_not_of(" \t\r\n") + 1); // 去除尾部空格
            
            std::istringstream iss(line);
            std::string key, value;
            if(std::getline(iss, key, '=')) {
                if(std::getline(iss, value)) {
                    data[key] = value;
                } else {
                    if(key[0] == '#') {
                        continue;
                    } else {
                        std::string msg = key + "'s value is null";
                        throw std::runtime_error(msg);
                    }
                }
            }
        }
    }
}
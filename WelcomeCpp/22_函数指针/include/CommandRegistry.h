#pragma once

#include <string>
#include <unordered_map>
#include <functional>

class CommandRegistry
{
private:
    std::unordered_map<std::string, std::function<int(int, int)>> cmdMap;

public:
    void registerCommand(const std::string& name, std::function<int(int, int)> func);
    int execute(const std::string& name, int a, int b);
};
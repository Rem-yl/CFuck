#include "CommandRegistry.h"

#include <string>

void CommandRegistry::registerCommand(const std::string& name, std::function<int(int, int)> func) {
    cmdMap[name] = func;
}

int CommandRegistry::execute(const std::string& name, int a, int b) {
    auto it = cmdMap.find(name);
    if (it != cmdMap.end()) {
        return it->second(a, b);
    } else {
        throw std::runtime_error("Unknown Func: " + name);
    }
}
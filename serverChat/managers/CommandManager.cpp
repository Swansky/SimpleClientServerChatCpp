//
// Created by swansky on 17/10/2021.
//

#include "CommandManager.h"


CommandManager::CommandManager() = default;

std::string CommandManager::executeCommand(std::string *name) {
    std::string returnValue{};
    if (strcmp("test", name->c_str()) == 0) {
        returnValue = "test command !";
    } else if (strcmp("command", name->c_str()) == 0) {
      returnValue = "command command execute ! ";
    }
    else {
        returnValue = "Command not found ! ";
    }

    return returnValue;
}



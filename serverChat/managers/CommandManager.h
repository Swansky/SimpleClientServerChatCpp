//
// Created by swansky on 17/10/2021.
//

#ifndef SERVERCHAT_COMMANDMANAGER_H
#define SERVERCHAT_COMMANDMANAGER_H


#include <vector>
#include "../models/SimpleCommand.h"

class CommandManager {

public:
    static constexpr const char *const TAG{"S!"};

    CommandManager();
    static std::string executeCommand(std::string* name);
};


#endif //SERVERCHAT_COMMANDMANAGER_H

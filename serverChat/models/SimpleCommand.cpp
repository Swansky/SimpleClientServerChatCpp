//
// Created by swansky on 17/10/2021.
//

#include "SimpleCommand.h"


SimpleCommand::SimpleCommand(std::string *name, std::string *description) : name(name), description(description) {}

std::string *SimpleCommand::getName() const {
    return name;
}

void SimpleCommand::setName(std::string *name) {
    SimpleCommand::name = name;
}

std::string *SimpleCommand::getDescription() const {
    return description;
}

void SimpleCommand::setDescription(std::string *description) {
    SimpleCommand::description = description;
}

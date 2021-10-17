//
// Created by swansky on 17/10/2021.
//

#ifndef SERVERCHAT_SIMPLECOMMAND_H
#define SERVERCHAT_SIMPLECOMMAND_H


#include <string>

class SimpleCommand {
private:
    std::string* name;
    std::string* description;
public:
    SimpleCommand(std::string *name, std::string *description);

    std::string *getName() const;

    void setName(std::string *name);

    std::string *getDescription() const;

    void setDescription(std::string *description);
};


#endif //SERVERCHAT_SIMPLECOMMAND_H

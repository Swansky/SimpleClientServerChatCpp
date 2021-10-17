
#include "managers/CommandManager.h"
#include "managers/ServerManager.h"


int main() {
    CommandManager commandManager{};
    ServerManager serverManager{&commandManager};
    serverManager.startServer();


    return 0;
}

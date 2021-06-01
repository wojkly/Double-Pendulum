#include "Application.h"
#include "ArgumentParser.h"

int main(int argc, char *argv[]) {
    //todo get parameters form the console
    ArgumentParser argumentParser{};
    argumentParser.init(argv[1]);

    Simulation simulation(30,0.02,0.004);

    Application application;
    application.initApp(simulation);
    exit(EXIT_SUCCESS);
}
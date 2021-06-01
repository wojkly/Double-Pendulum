#include "Application.h"
#include "ArgumentParser.h"

int main(int argc, char *argv[]) {
    //get parameters
    ArgumentParser argumentParser{};
    argumentParser.init(argv[1]);

    //init simulation object
    Simulation simulation(argumentParser);

    //init visualizer
    Application application(argumentParser);

    //begin simulation
    application.initApp(simulation);
    exit(EXIT_SUCCESS);
}
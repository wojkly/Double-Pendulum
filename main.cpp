#include "Application.h"
#include "ArgumentParser.h"

int main(int argc, char *argv[]) {
    //check number if args
    if (argc != 2){
        perror("wrong argument count");
        exit(EXIT_FAILURE);
    }
    //get parameters
    ArgumentParser argumentParser{};
    argumentParser.init(argv[1]);

    //init simulation object
    Simulation simulation(argumentParser);

    //init visualizer
    Application application(argumentParser);
//    if (fork())
//        application.initApp(simulation);
//    else
        application.initApp(simulation);

    //begin simulation
    exit(EXIT_SUCCESS);
}
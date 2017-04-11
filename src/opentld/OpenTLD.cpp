#include "Main.h"
#include "Config.h"
#include "ImAcq.h"
#include "Gui.h"
#include "OpenTLD.h"

using tld::Config;
using tld::Gui;
using tld::Settings;

int init_x1,init_y1,init_x2,init_y2;

int main(int argc, char **argv)
{

    Main *main = new Main();
    Config config;
    ImAcq *imAcq = imAcqAlloc();
    Gui *gui = new Gui();

    main->gui = gui;
    main->imAcq = imAcq;

    if(config.init(argc, argv) == PROGRAM_EXIT)
    {
        return EXIT_FAILURE;
    }

    config.configure(main);

    srand(main->seed);

    imAcqInit(imAcq);

    if(main->showOutput)
    {
        gui->init();
    }

    main->doWork();

    delete main;
    main = NULL;
    delete gui;
    gui = NULL;

    return EXIT_SUCCESS;
}

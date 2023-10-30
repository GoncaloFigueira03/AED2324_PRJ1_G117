
#ifndef CODE_APP_H
#define CODE_APP_H

#include "Reader.h"
#include "Menu.h"

class App {
public:
    // Initializes the App with a Reader
    explicit App(Reader reader);

    // Runs the App
    int run();

};

#endif //CODE_APP_H
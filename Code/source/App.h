
#ifndef CODE_APP_H
#define CODE_APP_H

#include "Reader.h"
#include "Menu.h"

class App
{
public:
    explicit App(Reader reader);
    int run();

};

#endif //CODE_APP_H
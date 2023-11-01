
#include "App.h"

App::App(Reader reader) { }

int App::run() {
    classes_per_uc();
    classes();
    students_classes();
}
#include "TestOne.h"
#include "Namespace.h"
#include <iostream>

// trunc8 option, look in truncstruct.hpp for more detail
void Trunc8::Button_CB(Fl_Widget*, void* userdata) {
    char help[100];
    std::string str;
    strcpy_s(help, test_input->value());
    str = help;
    str = trunc8(str).str;
    test_output->value(str.c_str());
}

// quit option
void Exit::Terminate(Fl_Widget*, void* userdata) {
    exit(0);
}
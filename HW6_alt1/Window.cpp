// Source.cpp Hiromi Kageyama
// Write a c++ program that uses the trunc function in FLTK

// generated by Fast Light User Interface Designer (fluid) version 1.0305

#include "TestOne.h"
#include "Namespace.h"
#include <iostream>

Fl_Input* test_input = (Fl_Input*)0;
Fl_Output* test_output = (Fl_Output*)0;

int main(int argc, char** argv) {
    StringInfo act;
    std::string str;

    Fl_Double_Window* w;

    { Fl_Double_Window* o = new Fl_Double_Window(300, 150);
    w = o; if (w) {/* empty */ }

    { Fl_Box* w = new Fl_Box(55, 20, 10, 10, "Type in a word");
    } // Fl_Box* w

    { Fl_Button* o = new Fl_Button(155, 50, 90, 30, "Trunc It!");
    o->callback((Fl_Callback*)Trunc8::Button_CB);
    } // Fl_Button* o

    { Fl_Button* o = new Fl_Button(200, 110, 90, 30, "Quit");
    o->callback((Fl_Callback*)Exit::Terminate);
    } // Fl_Button* o

    { test_input = new Fl_Input(50, 50, 100, 30, "Input:");
    const char* Fl_Input(const char* fmt, const char* defstr = 0);
    } // Fl_Input* test_input

    { test_output = new Fl_Output(50, 80, 100, 30, "Result:");
    }

    o->end();
    } // Fl_Double_Window* o

    w->show(argc, argv);
    return Fl::run();
}
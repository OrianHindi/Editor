#include <iostream>
#include "Editor.h"


using namespace std;


int main(int argc, char* argv[]) {
    switch (argc) {
        case 1:{
            Editor editor;
            editor.loop();
            break;
        }
        case 2:
            Editor editor1(argv[1]);
            editor1.loop();
            break;

    }


   return 0;
}

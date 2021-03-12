//
// Created by orian on 10/03/2021.
//

#pragma once
#include <string>
#include "Document.h"
using namespace std;

class Editor{

private:
   Document* doc;

public:
    Editor(){this->doc = new Document;}
    Editor(string file);
    void print();
    void loop();


};
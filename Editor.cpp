//
// Created by orian on 10/03/2021.
//
#include "Editor.h"
#include <stdio.h>
#include <iostream>
#include <fstream>


using namespace std;


Editor::Editor(string file) {
    this->doc = new Document(file);
}
void Editor::loop() {
    string write;
    getline(cin,write);
    while(write!= "q"){
        if(write == "a"){doc->addAfter();}
        else if(write =="$"){doc->pointEnd();}
        else if(write == "c"){doc->changeLines();}
        else if(write == "i"){doc->addBefore();}
        else if(write == "d"){doc->erase();}
        else if(write == "j"){doc->merge();}
        else if(write.at(0) == '/' && write.at(write.size()-1) == '/'){doc->find(write.substr(1,write.size()-2));}
        else if(write.at(0)=='s' && write.at(1)== '/' && write.at(write.size()-1)=='/'){doc->swap(write.substr(2,write.size()-3));}
        else if(write.at(0) == 'w' && write.at(1) == ' '){cout<<"try to writre"<<endl;doc->write(write.substr(2));}
        else if(write =="print"){doc->print();}
        else{doc->changePos(write);}
        getline(cin,write);
    }

}

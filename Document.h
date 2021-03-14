//
// Created by orian on 10/03/2021.
//

#pragma once
#include <vector>
#include <string>
using namespace std;


class Document{

private:
    vector<string> vec;
    int pos;
    void validate(int marker,bool check);

public:
    Document(){pos = 0;}
    Document(string file);
    vector<string> getVec(){return this->vec;}
    void pointEnd();
    void changeLines();
    void changePos(string line);
    void addAfter();
    void addBefore();
    void erase();
    void merge();
    void find(string line);
    void swap(string line);
    void print();
    void write(string file);


};

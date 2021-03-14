//
// Created by orian on 10/03/2021.
//

#include "Document.h"
#include <iostream>
#include <fstream>


using namespace std;

Document::Document(string file) {
    this->pos=-1;
    ifstream infile(file);
    if(!infile) cout<<"Failed"<<endl;
    string line;
    while(getline(infile,line) && line!=""){
        vec.push_back(line);
        this->pos++;
    }
}


void Document::validate(int marker,bool check) {
    bool ans = true;
    if(check){
        if(pos+marker>=vec.size()){pos=vec.size()-1;}
        else if(pos+marker<0){pos=0;}
        else pos=pos+marker;
    }
    if(!check){
        if(marker>vec.size()){pos = vec.size()-1;}
        else if(marker<0){pos = 0;}
        else pos = marker-1;
    }



}


void Document::changePos(string line) {
    int marker;
    try{
        marker = stoi(line);
        if(line.at(0) =='+' || line.at(0)== '-'){
            validate(marker,true);

        }
        else{
            validate(marker,false);

        }
    } catch (invalid_argument e) {}

}


void Document::pointEnd() {
    this->pos = this->vec.size()-1;
}


void Document::addAfter() {
    string line;
    getline(cin,line);
    vector<string>::iterator it = vec.begin()+pos;
    while(line!= "."){
        if(pos == vec.size()-1 || pos == 0 || it == vec.end()){vec.push_back(line);pos++;}
        else{
            vec.insert(next(it),line);
            pos++;
        }
        getline(cin,line);
    }
}


void Document::addBefore() {
    string line;
    getline(cin,line);
    while(line!= "."){
        vector<string>::iterator it = vec.begin()+pos;
        vec.insert(it,line);
        pos++;
        getline(cin,line);
    }
    pos--;
}


void Document::erase(){
    vector<string>::iterator it = vec.begin()+pos;
    vec.erase(it);
    pos--;
    if(pos<0) pos =0;

}


void Document::changeLines() {
    string line;
    getline(cin,line);
    vec.at(pos) = line;
    addAfter();

}


void Document::merge() {
    if(pos == vec.size() -1){return;}
    vector<string>::iterator it = vec.begin()+pos;
    vector<string>::iterator it2 = next(it);
    string last = *it2;
    *it = *it + " " + last;
    vec.erase(it2);
}

void Document::find(string line) {
    bool found=false;
    for (int i = pos +1; i <vec.size() ; ++i) {
        if(vec.at(i).find(line) != string::npos){pos =i;found = true;}
    }
    if(!found){
        for(int j =0;j<=pos;j++){
            if(vec.at(j).find(line)!= string::npos){pos = j;}
        }
    }

}


void Document::swap(string line) {
    int delimetr =line.find('/');
    string old = line.substr(0,delimetr);
    string fresh = line.substr(delimetr+1);
    delimetr = vec.at(pos).find(old);
    if(delimetr!=string::npos){    vec.at(pos).replace(delimetr,old.size(),fresh);}
}


void Document::print() {
    cout<<"pos:"<<pos<<"           "<<"vec size:"<<vec.size()<<endl;
    for(auto it = vec.begin();it!= vec.end();it++){
        cout<<*it<<endl;
    }
}

void Document::write(string file){
    ofstream oFile;
    oFile.open(file);
    if(!oFile.is_open()){cout<<"Failed to open file"<<endl;return;}
    for(string line: vec){
        oFile<<line<<endl;
    }
    oFile.close();

}









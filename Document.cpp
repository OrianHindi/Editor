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


bool Document::validate(int marker,bool check) {
    bool ans = true;
    if(check && (pos+marker>=vec.size() || pos+marker<0)){ans=false;}
    else if(!check && (marker>vec.size() || marker<0)){ans = false;}
    return ans;
}


void Document::changePos(string line) {
    int marker;
    try{
        marker = stoi(line);
        if(line.at(0) =='+' || line.at(0)== '-'){
            if(validate(marker,true)) {pos +=marker;}
            else{cout<<"?"<<endl;}
        }
        else{
            if (validate(marker,false)){pos = marker-1;}
            else{cout<<"?"<<endl;}
        }
    } catch (invalid_argument e) {}

}


void Document::pointEnd() {
    this->pos = this->vec.size()-1;
}
void Document::addAfter() {
    string line;
    getline(cin,line);
    while(line!= "."){
        if(pos == vec.size()-1){vec.push_back(line);pos++;}
        else{
            vector<string>::iterator it = vec.begin()+pos;
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
    line.replace(delimetr,old.size(),fresh);

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









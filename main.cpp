#include <iostream>
#include "Editor.h"


using namespace std;


int main(int argc, char* argv[]) {
    string file = "/home/orian/Desktop/AdvProg/months.txt";
    Editor d(file);
    d.loop();
//        string a ="w hello";
//        string b = "changed";
//        string search ="name";
//        int ax = a.find(search);
//       // cout<<a.replace(ax,search.size(),b)<<endl;
//        cout<<a.substr(2);

   return 0;
}

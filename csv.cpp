#include <iostream>
#include <fstream>
using namespace std;

int main(){
    fstream fin;
    string line;

    fin.open("numbers.csv", ios::in);

    while(fin){

        // read a line
        getline(fin, line);
        // print the line
        cout << line << endl;

    }    
    fin.close();
}
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

// short tech demo for my boss for a project that ended up going in a different direction. this program iterates through csv files and prints it out in console

int main(){
    int cont = 1;
    while(cont){
        fstream fin;
        string line, word, temp, filename;

        // get the name of the file

        cout << "Enter the file name(without extension): ";
        cin >> filename;
        filename.append(".csv");

        vector<vector<string>> content;
        vector<string> row;

        fstream file (filename, ios::in);
        if(file.is_open()){
                                            // add contents of the csv to a 2d array
            while(getline(file, line)){
                                            // ensure row object does not have pre-existing data
                row.clear();
                                            // split input into words
                stringstream str(line);
                while(getline(str, word, ','))
                row.push_back(word);
                content.push_back(row);
            }       
        }
        else{
            cout<<"Could not open the file\n";
        }
                                            // print the array out in console
        for(int i=0;i<content.size();i++){
            for(int j=0;j<content[i].size();j++){
                cout<<content[i][j]<<" ";
            }
            cout<<"\n";
        }
        char response;
        cout << "input another file? (y/n): ";
        cin >> response;
        if(response != 'y'){
            cont = 0;
        }
    } 
}

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    cout<<"Startup\n";
    bool rem_space=false;
    bool rem_numbers=false;

    cout<<"What to remove?\n1. Spaces\n2. Numbers\n:";
    string line;
    getline(cin,line);
    if(line=="1") rem_space=true;
    if(line=="2") rem_numbers=true;
    if(line=="12"||line=="21"||line=="2 1"||line=="2 1"||line=="2,1"||line=="2,1")
    {
        rem_space=true;
        rem_numbers=true;
    }

    //read input
    string text,text_cut;
    ifstream in_file("INPUT.txt");
    if(in_file==0)
    {
        cout<<"ERROR: Could not find INPUT.txt\n";
        return 1;
    }
    while(getline(in_file,line))
    {
        text.append(line);
    }
    in_file.close();

    //cut text
    for(int i=0;i<(int)text.length();i++)
    {
        bool skip=false;
        if(rem_space)
        {
            if(text[i]==' ')
             skip=true;
        }
        if(rem_numbers)
        {
            if(text[i]=='0'||text[i]=='1'||text[i]=='2'||text[i]=='3'||text[i]=='4'||
               text[i]=='5'||text[i]=='6'||text[i]=='7'||text[i]=='8'||text[i]=='9')
             skip=true;
        }
        if(!skip) text_cut.append(1,text[i]);
    }

    //print
    ofstream out_file("OUTPUT.txt");
    if(out_file==0)
    {
        cout<<"ERROR: Could not create OUTPUT.txt\n";
        return 2;
    }
    out_file<<text_cut<<endl;
    out_file.close();

    cout<<"Done\n";
    return 0;
}

#include<string>
#include<algorithm>
#include"splitline.h"
using namespace std;

void splitline(string line){
    int position=0,i=0;
    string element;
        for(i=0;i<=3;i++){
            if((position=line.find(','))!=line.npos){
                element=line.substr(0,position);
                substrings[i]=element;
                line.erase(0,position+1);
                }
        }
}

#include<iostream>
#include<map>
#include<iterator>
#include<sstream>
using namespace std;

int stringinterger(string str){
    int value=0;
    for(int i=0;i<str.length();i++){
        switch(str[i]){
            case '1':value=(value*10)+1;
            break;
            case '2':value=(value*10)+2;
            break;
            case '3':value=(value*10)+3;
            break;
            case '4':value=(value*10)+4;
            break;
            case '5':value=(value*10)+5;
            break;
            case '6':value=(value*10)+6;
            break;
            case '7':value=(value*10)+7;
            break;
            case '8':value=(value*10)+8;
            break;
            case '9':value=(value*10)+9;
            break;
            default:value=(value*10)+0;
    }
    }
    return value;
}

string obfuscate(string input, int charOffset, map<string, string> wordMap){
    map<string,string>::iterator itr;
    for(itr=wordMap.begin();itr!=wordMap.end();itr++){
        if(itr->first==input){
            return itr->second;
        }
    }
    int i=0,count=0;
    while(i!=input.length()&&input[i]>47&&input[i]<58){
            i++;
            count++;
    }
    if(count==input.length()){
        int value=stringinterger(input)*charOffset;
        stringstream s;
        s<<value;
        return s.str();
    }
    for(int i=0;i<input.length();i++)
            input[i]=input[i]+charOffset;
    return input;
}


int main(){
    map<string, string> map1;
    string input;
    map1.insert(pair<string,string>("happy","morning"));
    map1.insert(pair<string,string>("programming","language"));
    map1.insert(pair<string,string>("analtical","skills"));
    map1.insert(pair<string,string>("java","coding"));
    map1.insert(pair<string,string>("data","analytics"));
    cin>>input;
    input=obfuscate(input,2,map1);
    cout<<input;
}


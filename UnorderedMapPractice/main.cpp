#include<iostream>
#include<sstream>
#include<unordered_map>
using namespace std;



void countWordFrequency(string str){

    unordered_map<string, int> freqWord;

    stringstream ss(str);
    string word;
    while(ss>>word){
        freqWord[word]++;
    }

    for(auto x:freqWord){
        cout<<x.first<<" "<<x.second<<endl;
    }
  
}

int main(){

    string str= "Ashish Govind my man is Ashish Govind";

    countWordFrequency(str);


    return 0;
}
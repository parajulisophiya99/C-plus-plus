#include<iostream>
using namespace std;

class cs{
public:
    //Decleration of static data member.Static members belong to the class itself,not to the individual objects 
static int modelCount;
    //Constructor - automatically called when a Mercedes object is created
Mercedes(){
    //Increment modelCount for each object created .modelCount is ststic,it keeps its value accross all object
modelCount++;
   }
};

//Defination and initialization of static data memder outside the class
//This is allocated memory for he static variable
//Must be done excately once in excately one source file
int Mercedes::modelCount=0;

int main(){
    //Creating 
}

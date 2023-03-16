#include<iostream>
#include<string>
#include"character.h"
#include"Bar.h"
#include"Land.h"

using namespace std;

int main()
{
    {
        Land *A = new Character;
        cout<<"Check fall: "<<A->check_fall()<<endl;
        cout<<"X location: "<<A->get_x()<<endl;
        cout<<"Y location: "<<A->get_y()<<endl;
        cout<<"Lives: "<<A->get_life()<<endl;
    }
    return 0;
}
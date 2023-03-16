#include<iostream>
#include<string>
#include"character.h"
#include"Land.h"
#include"Trap.h"

using namespace std;

int main()
{
    {
        Trap *A = new Character;
        cout<<"Check fall: "<<A->check_fall()<<endl;
        cout<<"X location: "<<A->get_x()<<endl;
        cout<<"Y location: "<<A->get_y()<<endl;
        cout<<"Lives: "<<A->get_life()<<endl;
    }
    return 0;
}
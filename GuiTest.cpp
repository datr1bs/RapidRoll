#include<iostream>
#include<string>
#include"gui.h"

using namespace std;

int main()
{
    {
        GUI gui;
        if(gui.setFont() == "font")
        {
            cout<<gui.setFont()<<"\nTest complete!"<<endl;
        }
        else{
            cout<<gui.setFont()<<"\nTest failed!"<<endl;
        }
    }
    {
        GUI gui;
        if(gui.setString() == "FALL GUY")
        {
            cout<<gui.setString()<<"\nTest complete!"<<endl;
        }
        else{
            cout<<gui.setString()<<"\nTest failed!"<<endl;
        }
    }
    {
        GUI gui;
        if(gui.setFillColor() == "Blue")
        {
            cout<<gui.setFillColor()<<"\nTest complete!"<<endl;
        }
        else{
            cout<<gui.setFillColor()<<"\nTest failed!"<<endl;
        }
    }
    {
        GUI gui;
        if(gui.setCharactersiSize() == 100)
        {
            cout<<gui.setCharactersiSize()<<"\nTest complete!"<<endl;
        }
        else{
            cout<<gui.setCharactersiSize()<<"\nTest failed!"<<endl;
        }
    }
    {
        GUI gui;
        if(gui.setPosition() == (280,50))
        {
            cout<<gui.setPosition()<<"\nTest complete!"<<endl;
        }
        else{
            cout<<gui.setPosition()<<"\nTest failed!"<<endl;
        }
    }
    return 0;
}
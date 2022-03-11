#include <iostream>
#include <sstream>
#include "menu.h"
#include "read.hpp"
#define menuCount 6 //Number of menu items

using namespace std;

bool check(int a){return a>=0&&a<=menuCount;}

void Menu::run()
{

    int v;
    do{
        v = menuPrint();
        switch(v)
        {
        case 1:
            putIn();
            print();
            break;
        case 2:
            takeOut();
            print();
            break;
        case 3:
            maxItem();
            print();
            break;
        case 4:
            isEmpty();
            print();
            break;
        case 5:
            print();
            break;
        case 6:
            loadTest();
            break;
        default:
            cout<<"\n Goodbye!\n";
            break;
        }

    }while(v!=0);
}



int Menu::menuPrint()
{

    int choice;
    cout<<"\n*******************************\n";
    cout<<"0. Exit\n";
    cout<<"1. Put in\n";
    cout<<"2. Take out\n";
    cout<<"3. Query the max\n";
    cout<<"4. Is Empty\n";
    cout<<"5. Print\n";
    cout<<"6. Load test(How many items can we put in)\n";
    cout<<"\n*******************************\n";

    ostringstream s;
    s<<"Choose a number between 0 and " <<menuCount << "!";
    string errmsg = s.str();
    choice = read<int>("choose a menu item: ", errmsg, check);
    return choice;
}


void Menu::putIn()
{
    Item e;
    cout<<"Item :\n";
    cin>> e;
    q.add(e);
}



void Menu::takeOut()
{
    Item e;
    bool error = false;
    try{
        e = q.remMax();
    }catch(PrQueue::PrQueueError err)
    {
        error = true;
        if(err ==PrQueue::EMPTY_QUEUE)
        {
            cerr<<"Take out is unsuccessful, the queue is empty!\n";
        }else{
            cerr<<"Unknown error\n";
        }
    }
     if(!error) cout<<"Got item: \n" <<e <<endl;
}



void Menu::maxItem()
{
    Item e;
    bool error = false;
    try{
        cout<<"Max"<<endl;
        e = q.getMaxElement();
    }catch(PrQueue::PrQueueError err)
    {
        error = true;
        if(err ==PrQueue::EMPTY_QUEUE)
        {
            cerr<<"Maximum cannot be checked as the queue is empty\n";
        }else{
            cerr<<"Unknown error\n";
        }
    }
    if (!error) cout<<"Maximal element is: \n" << e<<endl;
}


void Menu::isEmpty()
{

    if(q.isEmpty())
    {
        cout<<"Queue is empty\n";

    }
    else{
        cout<<"Queue is not empty\n";
    }
}


void Menu::print()
{
    cout<<q;
}

void Menu::loadTest()
{
    const int size=1000000000;
    PrQueue q;
    cout<<"Follow the current size of the queue:\n";
    try{
        for(int i=1;i<size;++i)
        {
            if(i%1000000000==0) cout<<i<<endl;
            q.add(Item(i,"a"));
        }
    }catch(...)
    {
        cerr<<"Run out of memory!\n";
        //cerr<"The size of the vector: "<<q.getLength()<<endl;
    }
}

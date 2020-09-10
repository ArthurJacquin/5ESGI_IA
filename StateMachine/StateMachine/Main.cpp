#include <iostream>
#include "StateMachine.h"
#include <conio.h>

using namespace std;

int main()
{
    //Start History
    int foodAmount;
    int waterAmount;
    string name;
    
    cout << "Welcome to TAMAGOCHI !" << endl;
    cout << "Let's set some parameters !" << endl;
    cout << "Choose a name ?" << endl;
    cin >> name;
    cout << "Food amout ?" << endl;
    cin >> foodAmount;
    cout << "Water amout ?" << endl;
    cin >> waterAmount;

    //Init
    GameState gs(foodAmount, waterAmount);
    Tamagochi tama(name);
    State initialState = State("Life", [](Tamagochi* t, GameState* gs) {});
    StateMachine sm(&tama, &gs, &initialState);

    sm.CreateStateMachine();

    while (tama.IsAlive())
    {
        gs.DisplayResources();
        tama.DisplayStats();
        tama.UpdateStats();

        sm.ProcessState();
    }

    return 0;
}

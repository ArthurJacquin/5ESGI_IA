#include <iostream>
#include "StateMachine.h"

int main()
{
    //Start History


    //Init
    GameState gs(100, 100);
    Tamagochi tama;
    State initialState = State("Life", [] {});
    //StateMachine(&tama, &gs, &initialState);

    int water;
    cout << "j'ai besoin d'eau !\n";
    cin >> water;

    gs.getWaterAmount();

    return 0;
}

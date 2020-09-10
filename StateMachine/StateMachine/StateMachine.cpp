#include "StateMachine.h"
#include<functional>
#include <iostream>

StateMachine::StateMachine()
{
    currentState = nullptr;
    tamagochi = nullptr;
    gameState = nullptr;
}

StateMachine::StateMachine(Tamagochi* tama, GameState* gs, State* initialState)
    :tamagochi(tama), gameState(gs), currentState(initialState)
{
}

StateMachine::~StateMachine()
{
    delete currentState;
    delete tamagochi;
    delete gameState;
}

void StateMachine::CreateStateMachine()
{
    State* life = new State("Life", [](Tamagochi* t) {});
    State* thirsty = new State("Thirsty", [](Tamagochi* t) {});
    State* drink = new State("Drink", [](Tamagochi* t) { t->Drink(); });
    State* death = new State("Death", [](Tamagochi* t) { t->Die(); });

    //Life -> Thirsty
    auto checkThirstiness = [](Tamagochi* t, GameState* gs) { return t->GetCurrentThirst() <= gs->GetThirstThreshold(); } ;
    Transition* lifeToThirsty = new Transition(checkThirstiness);
    life->AddTransition(lifeToThirsty, thirsty);

    //Drink -> Thirsty
    Transition* drinkToThirsty = new Transition(checkThirstiness);
    life->AddTransition(drinkToThirsty, thirsty);

    //Thirsty -> Drink
    auto checkWaterAmount = [](Tamagochi* t, GameState* gs) { return gs->getWaterAmount() > 0; };
    Transition* thirstyToDrink = new Transition(checkWaterAmount);
    life->AddTransition(thirstyToDrink, drink);

    //Thirsty -> Death
    auto checkDehydration = [](Tamagochi* t, GameState* gs) { return t->GetCurrentThirst() <= 0; };
    Transition* thirstyToDeath = new Transition(checkDehydration);
    life->AddTransition(thirstyToDeath, death);

    //Drink -> Life
    auto checkHydration = [](Tamagochi* t, GameState* gs) { return t->GetCurrentThirst() > gs->GetThirstThreshold(); };
    Transition* drinkToLife = new Transition(checkHydration);
    life->AddTransition(drinkToLife, life);
}

void StateMachine::ProcessState()
{
    int N = currentState->GetPairs().size();
    for (size_t i = 0; i < N; i++)
    {
        if (currentState->GetPairs()[i].transition->Process(tamagochi, gameState))
        {
            ChangeState(currentState->GetPairs()[i].endState);
        }
    }
}

void StateMachine::ChangeState(State* s)
{
    currentState = s;
    s->ProcessAction(tamagochi);
}
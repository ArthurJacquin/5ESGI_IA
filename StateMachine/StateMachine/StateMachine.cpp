#include "StateMachine.h"
#include<functional>
#include <iostream>

StateMachine::StateMachine()
{
    currentState = nullptr;
    tamagochi = nullptr;
    gameState = nullptr;
}

StateMachine::StateMachine(Tamagochi* const tama, GameState* const gs,const State* initialState)
    :tamagochi(tama), gameState(gs), currentState(initialState)
{
}

StateMachine::~StateMachine()
{
    delete currentState;
}

void StateMachine::CreateStateMachine()
{
    State* life = new State("Life", [](Tamagochi* const t, GameState* const gs) {});
    State* thirsty = new State("Thirsty", [](Tamagochi* const t, GameState* const gs) {});
    State* drink = new State("Drink", [](Tamagochi* const t, GameState* const gs) { t->Drink(gs); });
    State* death = new State("Death", [](Tamagochi* const t, GameState* const gs) { t->Die(); });

    //Life -> Thirsty
    auto checkThirstiness = [](const Tamagochi* const t, const GameState* const gs)->const bool { return t->GetCurrentThirst() >= gs->GetThirstThreshold(); } ;
    Transition* lifeToThirsty = new Transition(checkThirstiness);
    life->AddTransition(lifeToThirsty, thirsty);

    //Drink -> Thirsty
    Transition* drinkToThirsty = new Transition(checkThirstiness);
    drink->AddTransition(drinkToThirsty, thirsty);

    //Thirsty -> Drink
    auto checkWaterAmount = [](const Tamagochi* const t, const GameState* const gs)->const bool { return gs->getWaterAmount() > 0; };
    Transition* thirstyToDrink = new Transition(checkWaterAmount);
    thirsty->AddTransition(thirstyToDrink, drink);

    //Thirsty -> Death
    auto checkDehydration = [](const Tamagochi* const t, const GameState* const gs)->const bool { return t->GetCurrentThirst() >= 100; };
    Transition* thirstyToDeath = new Transition(checkDehydration);
    thirsty->AddTransition(thirstyToDeath, death);

    //Drink -> Life
    auto checkHydration = [](const Tamagochi* const t, const GameState* const gs)->const bool { return t->GetCurrentThirst() > gs->GetThirstThreshold(); };
    Transition* drinkToLife = new Transition(checkHydration);
    drink->AddTransition(drinkToLife, life);

    currentState = life;
}

void StateMachine::ProcessState()
{
    int N = currentState->GetPairs().size();
    for (size_t i = 0; i < N; i++)
    {
        if (currentState->GetPairs()[i].first->Process(tamagochi, gameState))
        {
            ChangeState(currentState->GetPairs()[i].second, gameState);
        }
    }
}

void StateMachine::ChangeState(const State* const s, GameState* const gs)
{
    currentState = s;
    s->ProcessAction(tamagochi, gs);
}
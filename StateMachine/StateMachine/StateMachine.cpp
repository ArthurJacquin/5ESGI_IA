#include "StateMachine.h"
#include<functional>

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
    State* life = new State("Life", [] {});
    State* thirsty = new State("Thirsty", [] {});
    State* drink = new State("", tamagochi->Drink());
    State* death = new State("Death");

    //Life -> Thirsty
    auto lambda = [](Tamagochi* t, GameState* gs) { return t->GetCurrentThirst() <= gs->GetThirstThreshold(); } ;
    Transition* lifeToThirsty = new Transition(lambda);
    life->AddTransition(lifeToThirsty, thirsty);

    //Drink -> Thirsty
    Transition* drinkToThirsty = new Transition(lambda);
    life->AddTransition(drinkToThirsty, thirsty);

    //Thirsty -> Drink
    auto lambda = [](Tamagochi* t, GameState* gs) { return gs->getWaterAmount() > 0; };
    Transition* thirstyToDrink = new Transition(lambda);
    life->AddTransition(thirstyToDrink, drink);

    //Thirsty -> Death
    auto lambda = [](Tamagochi* t, GameState* gs) { return t->GetCurrentThirst() <= 0; };
    Transition* thirstyToDeath = new Transition(lambda);
    life->AddTransition(thirstyToDeath, death);

    //Drink -> Life
    auto lambda = [](Tamagochi* t, GameState* gs) { return t->GetCurrentThirst() > gs->GetThirstThreshold(); };
    Transition* drinkToLife = new Transition(lambda);
    life->AddTransition(drinkToLife, life);
}

void StateMachine::ProcessState()
{
    int N = currentState->GetPairs().size();
    for (size_t i = 0; i < N; i++)
    {
        if (currentState->GetPairs()[i].transition->Process(tamagochi, gameState))
        {
            ChangeState(currentState->GetPairs()[i].)
        }
    }

}

void StateMachine::ChangeState(State* s)
{
    currentState = s;
    s
}
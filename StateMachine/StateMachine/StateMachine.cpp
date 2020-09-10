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
}

void StateMachine::CreateStateMachine()
{
    State* life = new State("Life", [](Tamagochi* t, GameState* gs) {});
    State* thirsty = new State("Thirsty", [](Tamagochi* t, GameState* gs) {});
    State* drink = new State("Drink", [](Tamagochi* t, GameState* gs) { t->Drink(gs); });
    State* hungry = new State("Hungry", [](Tamagochi* t, GameState* gs) {});
    State* eat = new State("Eat", [](Tamagochi* t, GameState* gs) { t->Eat(gs); });
    State* death = new State("Death", [](Tamagochi* t, GameState* gs) { t->Die(); });

    //---------------------------Thirsthy-----------------
    //Life -> Thirsty
    auto checkThirstiness = [](Tamagochi* t, GameState* gs) { return t->GetCurrentThirst() >= gs->GetThirstThreshold(); } ;
    Transition* lifeToThirsty = new Transition(checkThirstiness);
    life->AddTransition(lifeToThirsty, thirsty);

    //Thirsty -> Drink
    auto checkWaterAmount = [](Tamagochi* t, GameState* gs) { return gs->getWaterAmount() > 0; };
    Transition* thirstyToDrink = new Transition(checkWaterAmount);
    thirsty->AddTransition(thirstyToDrink, drink);

    //Thirsty -> Death
    auto checkDehydration = [](Tamagochi* t, GameState* gs) { return t->GetCurrentThirst() >= t->GetMaxThirst(); };
    Transition* thirstyToDeath = new Transition(checkDehydration);
    thirsty->AddTransition(thirstyToDeath, death);

    //Drink -> Thirsty
    Transition* drinkToThirsty = new Transition(checkThirstiness);
    drink->AddTransition(drinkToThirsty, thirsty);

    //Drink -> Life
    auto checkHydration = [](Tamagochi* t, GameState* gs) { return t->GetCurrentThirst() > gs->GetThirstThreshold(); };
    Transition* drinkToLife = new Transition(checkHydration);
    drink->AddTransition(drinkToLife, life);

    //--------------------Hungry------------------
    //Life-> Hungry
    auto checkHunger = [](Tamagochi* t, GameState* gs) { return t->GetCurrentHunger() >= gs->GetHungerThreshold(); };
    Transition* lifeToHunger = new Transition(checkHunger);
    life->AddTransition(lifeToHunger, hungry);

    //Hungry -> Eat
    auto checkFoodAmount = [](Tamagochi* t, GameState* gs) {  return gs->getFoodAmount() > 0; };
    Transition* HungryToEat = new Transition(checkFoodAmount);
    hungry->AddTransition(HungryToEat, eat);

    //Hungry -> Death
    auto checkStarvation = [](Tamagochi* t, GameState* gs) { return t->GetCurrentHunger() >= t->GetMaxHunger(); };
    Transition* hungerToDeath = new Transition(checkStarvation);
    hungry->AddTransition(hungerToDeath, death);

    //Eat -> Hungry
    Transition* eatToHungry = new Transition(checkHunger);
    eat->AddTransition(eatToHungry, hungry);

    //Eat -> Life
    auto checkSatiety = [](Tamagochi* t, GameState* gs) { return t->GetCurrentHunger() > gs->GetHungerThreshold(); };
    Transition* eatToLife = new Transition(checkSatiety);
    eat->AddTransition(eatToLife, life);
    
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

void StateMachine::ChangeState(State* s, GameState* gs)
{
    currentState = s;
    s->ProcessAction(tamagochi, gs);
}
#include<functional>
#include <iostream>
#include "StateMachine.h"
#include "ConstValues.h"

StateMachine::StateMachine()
{
    currentState = nullptr;
    tamagochi = nullptr;
    gameState = nullptr;
}

StateMachine::StateMachine(Tamagochi* const tama, GameState* const gs, const State* initialState)
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
    State* hungry = new State("Hungry", [](Tamagochi* const t, GameState* const gs) {});
    State* eat = new State("Eat", [](Tamagochi* const t, GameState* const gs) { t->Eat(gs); });
    State* tired = new State("Tired", [](Tamagochi* const t, GameState* const gs) { });
    State* stopMusic = new State("Stop Music", [](Tamagochi* const t, GameState* const gs) { t->StopMusic(gs); });
    State* sleep = new State("Sleep", [](Tamagochi* const t, GameState* const gs) { t->Sleep(gs);  });
    State* death = new State("Death", [](Tamagochi* const t, GameState* const gs) { t->Die(); });

    //---------------------------Thirsthy-----------------
    //Life -> Thirsty
    auto checkThirstiness = [](const Tamagochi* const t, const GameState* const gs)->const bool { return t->GetCurrentThirst() >= ConstValues::thirstThreshold; } ;
    Transition* lifeToThirsty = new Transition(checkThirstiness);
    life->AddTransition(lifeToThirsty, thirsty);

    //Thirsty -> Drink
    auto checkWaterAmount = [](const Tamagochi* const t, const GameState* const gs)->const bool { return gs->getWaterAmount() > 0; };
    Transition* thirstyToDrink = new Transition(checkWaterAmount);
    thirsty->AddTransition(thirstyToDrink, drink);

    //Thirsty -> Death
    auto checkDehydration = [](const Tamagochi* const t, const GameState* const gs)->const bool { return t->GetCurrentThirst() >= ConstValues::maxThirst; };
    Transition* thirstyToDeath = new Transition(checkDehydration);
    thirsty->AddTransition(thirstyToDeath, death);

    //Drink -> Thirsty
    Transition* drinkToThirsty = new Transition(checkThirstiness);
    drink->AddTransition(drinkToThirsty, thirsty);

    //Drink -> Life
    auto checkHydration = [](const Tamagochi* const t, const GameState* const gs)->const bool { return t->GetCurrentThirst() < ConstValues::thirstThreshold; };
    Transition* drinkToLife = new Transition(checkHydration);
    drink->AddTransition(drinkToLife, life);

    //--------------------Hungry------------------
    //Life-> Hungry
    auto checkHunger = [](const Tamagochi* const t, const GameState* const gs)->const bool { return t->GetCurrentHunger() >= ConstValues::hungerThreshold; };
    Transition* lifeToHunger = new Transition(checkHunger);
    life->AddTransition(lifeToHunger, hungry);

    //Hungry -> Eat
    auto checkFoodAmount = [](const Tamagochi* const t, const GameState* const gs)->const bool {  return gs->getFoodAmount() > 0; };
    Transition* HungryToEat = new Transition(checkFoodAmount);
    hungry->AddTransition(HungryToEat, eat);

    //Hungry -> Death
    auto checkStarvation = [](const Tamagochi* const t, const GameState* const gs)->const bool { return t->GetCurrentHunger() >= ConstValues::maxHunger; };
    Transition* hungerToDeath = new Transition(checkStarvation);
    hungry->AddTransition(hungerToDeath, death);

    //Eat -> Hungry
    Transition* eatToHungry = new Transition(checkHunger);
    eat->AddTransition(eatToHungry, hungry);

    //Eat -> Life
    auto checkSatiety = [](const Tamagochi* const t, const GameState* const gs)->const bool { return t->GetCurrentHunger() < ConstValues::hungerThreshold; };
    Transition* eatToLife = new Transition(checkSatiety);
    eat->AddTransition(eatToLife, life);
    
    //-------------------Tired-------------------
    //Life-> Tired
    auto checkTiredness = [](const Tamagochi* const t, const GameState* const gs)->const bool { return t->GetCurrentTiredness() >= ConstValues::tiredThreshold; };
    Transition* lifeToTired = new Transition(checkTiredness);
    life->AddTransition(lifeToTired, tired);

    //Tired -> Sleep
    auto checkMusicVolume = [](const Tamagochi* const t, const GameState* const gs)->const bool {  return gs->getMusicVolume() < 50; };
    Transition* TiredToSleep = new Transition(checkMusicVolume);
    tired->AddTransition(TiredToSleep, sleep);

    //Tired -> StopMusic
    auto checkMusicVolumeDown = [](const Tamagochi* const t, const GameState* const gs)->const bool {  return gs->getMusicVolume() > 50; };
    Transition* TiredToStopMusic = new Transition(checkMusicVolumeDown);
    tired->AddTransition(TiredToStopMusic, stopMusic);

    //StopMusic -> Sleep
    auto checkStopMusic = [](const Tamagochi* const t, const GameState* const gs)->const bool { return gs->getMusicVolume() <= 1; };
    Transition* StopMusicToSleep = new Transition(checkStopMusic);
    stopMusic->AddTransition(StopMusicToSleep, sleep);

    //Tired -> Death
    auto checkExhaustion = [](const Tamagochi* const t, const GameState* const gs)->const bool { return t->GetCurrentTiredness() >= ConstValues::maxTiredness; };
    Transition* tiredToDeath = new Transition(checkExhaustion);
    tired->AddTransition(tiredToDeath, death);

    //Sleep -> Tired
    Transition* sleepToTired = new Transition(checkTiredness);
    sleep->AddTransition(sleepToTired, tired);

    //Sleep -> Life
    auto checkRest = [](const Tamagochi* const t, const GameState* const gs)->const bool { return t->GetCurrentTiredness() < ConstValues::tiredThreshold; };
    Transition* sleepToLife = new Transition(checkRest);
    sleep->AddTransition(sleepToLife, life);

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
            break;
        }
    }
}

void StateMachine::ChangeState(const State* s, GameState* gs)
{
    currentState = s;
    s->ProcessAction(tamagochi, gs);
}
#include "Goap.h"

GoapSolver::GoapSolver()
{
	goalAction = nullptr;
}

GoapSolver::GoapSolver(Action* goal)
{
	goalAction = goal;
}

GoapSolver::~GoapSolver()
{
	int N = allActions.size();
	for (size_t i = 0; i < N; i++)
	{
		delete allActions[i];
	}

	delete goalAction;
}

void GoapSolver::CreateSolver()
{
	allActions.reserve(10);
	
	Action* cookPancake = new Action("Cook Pancake");
	allActions.push_back(cookPancake);

	//Mix actions
	Action* addMixedEggs = new Action("Add Mixed Eggs");
	Action* addMixedFlour = new Action("Add Mixed Flour");
	Action* addMixedNut = new Action("Add Mixed Nut");
	allActions.push_back(addMixedEggs);
	allActions.push_back(addMixedFlour);
	allActions.push_back(addMixedNut);

	//Eggs actions
	Action* collectEggs = new Action("Collect Eggs", 2);
	Action* buyEggs = new Action("Buy Eggs", 3);
	allActions.push_back(collectEggs);
	allActions.push_back(buyEggs);

	//Flour actions
	Action* grindFlour = new Action("Grind Flour");
	Action* harvestWheat = new Action("Harvest Wheat", 2);
	Action* buyFlour = new Action("Buy Flour", 4);
	allActions.push_back(grindFlour);
	allActions.push_back(harvestWheat);
	allActions.push_back(buyFlour);

	//Nut Actions
	Action* buyNut = new Action("Buy Nut");
	allActions.push_back(buyNut);

	//Cook Pancake links
	cookPancake->SetEffect(new Effect("Get Pancake", [](GameState* const gs) { gs->AddPancake(1); }));
	cookPancake->AddPrecondition(new Precondition("Mixed Eggs", [](const GameState* const gs)->const bool { return gs->GetMixedEggsAmount() > 0; }));
	cookPancake->AddPrecondition(new Precondition("Mixed Flour", [](const GameState* const gs)->const bool { return gs->GetMixedFlourAmount() > 0; }));
	cookPancake->AddPrecondition(new Precondition("Mixed Nut", [](const GameState* const gs)->const bool { return gs->GetMixedNutAmount() > 0; }));

	//Add Mixed Eggs links
	addMixedEggs->SetEffect(new Effect("Mixed Eggs", [](GameState* const gs) { gs->AddMixedEggs(1); }));
	addMixedEggs->AddPrecondition(new Precondition("Collect Egg", [](const GameState* const gs)->const bool { return gs->GetEggsAmount() > 0; }));

	//Collect Eggs links
	collectEggs->SetEffect(new Effect("Collect Egg", [](GameState* const gs) { gs->AddEggs(1); }));
	collectEggs->AddPrecondition(new Precondition("Have Chicken", [](const GameState* const gs)->const bool { return gs->GetChickenAmount() > 0; }));

	//Buy Eggs links
	buyEggs->SetEffect(new Effect("Collect Egg", [](GameState* const gs) { gs->AddEggs(1); }));

	//Mixed Flour links
	addMixedFlour->SetEffect(new Effect("Mixed Flour", [](GameState* const gs) { gs->AddMixedFlour(1); }));
	addMixedFlour->AddPrecondition(new Precondition("Collect Flour", [](const GameState* const gs)->const bool { return gs->GetFlourAmount() > 0; }));

	//Grind flour links
	grindFlour->SetEffect(new Effect("Collect Flour", [](GameState* const gs) { gs->AddFlour(1); }));
	grindFlour->AddPrecondition(new Precondition("Collect Wheat", [](const GameState* const gs)->const bool { return gs->GetWheatAmount() > 0; }));

	//Harvest Wheat links
	harvestWheat->SetEffect(new Effect("Collect Wheat", [](GameState* const gs) { gs->AddWheat(1); }));
	harvestWheat->AddPrecondition(new Precondition("Have Field", [](const GameState* const gs)->const bool { return gs->GetFieldAmount() > 0; }));

	//Buy flour links
	buyFlour->SetEffect(new Effect("Collect Flour", [](GameState* const gs) { gs->AddFlour(1); }));
	
	//Mixed Nut links
	addMixedNut->SetEffect(new Effect("Mixed Nut", [](GameState* const gs) { gs->AddMixedNut(1); }));
	addMixedNut->AddPrecondition(new Precondition("Collect Nut", [](const GameState* const gs)->const bool { return gs->GetNutAmount() > 0; }));

	//Buy Nut links
	buyNut->SetEffect(new Effect("Collect Nut", [](GameState* const gs) { gs->AddNut(1); }));
}

void GoapSolver::Solve(GameState gs)const
{
	int nbPrecondition = goalAction->GetPreconditions().size();
	Action* chosenAction = nullptr;

	for (size_t i = 0; i < nbPrecondition; ++i)
	{
		if (!goalAction->GetPreconditions()[i]->Process(gs))
		{

		}
	}

	chosenAction->GetEffect()->ProcessAction(gs);
}

vector<Action*> GoapSolver::SolveTree(const Action* const head)const
{
	vector<Action*> bestPath;
	vector<Action*> currentTestPath;
	vector<Action*> actionsFromPrecondition;

	int bestCost = 999;
	int currentCost = 999;

	actionsFromPrecondition = GetActionsResolvingPrecondition(head->GetPreconditions()[0]);
	int N = actionsFromPrecondition.size();
	for (size_t i = 0; i < N; i++)
	{
		actionsFromPrecondition[N]
	}
}

vector<Action*> GoapSolver::GetActionsResolvingPrecondition(const Precondition* const p)const
{
	vector<Action*> actions;
	int N = allActions.size();
	for (size_t i = 0; i < N; i++)
	{
		if (p->GetName() == allActions[i]->GetEffect()->GetName())
		{
			actions.push_back(allActions[i]);
		}
	}

	return actions;
}
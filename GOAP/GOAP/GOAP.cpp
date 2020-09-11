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
	cookPancake->SetEffect(new Effect(PreconditionName::GetPancake, [](GameState* const gs) { gs->AddPancake(1); }));
	cookPancake->AddPrecondition(new Precondition(PreconditionName::MixedEggs, [](const GameState* const gs)->const bool { return gs->GetMixedEggsAmount() > 0; }));
	cookPancake->AddPrecondition(new Precondition(PreconditionName::MixedFlour, [](const GameState* const gs)->const bool { return gs->GetMixedFlourAmount() > 0; }));
	cookPancake->AddPrecondition(new Precondition(PreconditionName::MixedNut, [](const GameState* const gs)->const bool { return gs->GetMixedNutAmount() > 0; }));

	//Add Mixed Eggs links
	addMixedEggs->SetEffect(new Effect(PreconditionName::MixedEggs, [](GameState* const gs) { gs->AddMixedEggs(1); }));
	addMixedEggs->AddPrecondition(new Precondition(PreconditionName::CollectEgg, [](const GameState* const gs)->const bool { return gs->GetEggsAmount() > 0; }));

	//Collect Eggs links
	collectEggs->SetEffect(new Effect(PreconditionName::CollectEgg, [](GameState* const gs) { gs->AddEggs(1); }));
	collectEggs->AddPrecondition(new Precondition(PreconditionName::HaveChicken, [](const GameState* const gs)->const bool { return gs->GetChickenAmount() > 0; }));

	//Buy Eggs links
	buyEggs->SetEffect(new Effect(PreconditionName::CollectEgg, [](GameState* const gs) { gs->AddEggs(1); }));

	//Mixed Flour links
	addMixedFlour->SetEffect(new Effect(PreconditionName::MixedFlour, [](GameState* const gs) { gs->AddMixedFlour(1); }));
	addMixedFlour->AddPrecondition(new Precondition(PreconditionName::CollectFlour, [](const GameState* const gs)->const bool { return gs->GetFlourAmount() > 0; }));

	//Grind flour links
	grindFlour->SetEffect(new Effect(PreconditionName::CollectFlour, [](GameState* const gs) { gs->AddFlour(1); }));
	grindFlour->AddPrecondition(new Precondition(PreconditionName::CollectWheat, [](const GameState* const gs)->const bool { return gs->GetWheatAmount() > 0; }));

	//Harvest Wheat links
	harvestWheat->SetEffect(new Effect(PreconditionName::CollectWheat, [](GameState* const gs) { gs->AddWheat(1); }));
	harvestWheat->AddPrecondition(new Precondition(PreconditionName::HaveField, [](const GameState* const gs)->const bool { return gs->GetFieldAmount() > 0; }));

	//Buy flour links
	buyFlour->SetEffect(new Effect(PreconditionName::CollectFlour, [](GameState* const gs) { gs->AddFlour(1); }));
	
	//Mixed Nut links
	addMixedNut->SetEffect(new Effect(PreconditionName::MixedNut, [](GameState* const gs) { gs->AddMixedNut(1); }));
	addMixedNut->AddPrecondition(new Precondition(PreconditionName::CollectNut, [](const GameState* const gs)->const bool { return gs->GetNutAmount() > 0; }));

	//Buy Nut links
	buyNut->SetEffect(new Effect(PreconditionName::CollectNut, [](GameState* const gs) { gs->AddNut(1); }));
}

void GoapSolver::Solve(GameState* gs)
{
	int nbPrecondition = goalAction->GetPreconditions().size();
	vector<const Action*> path;
	int pathCost = 0;
	vector<const Action*> bestPath;
	int bestCost = 9999;

	for (size_t i = 0; i < nbPrecondition; ++i)
	{
		if (goalAction->GetPreconditions()[i]->Process(gs))
		{
			continue;
		}

		vector<const Action*> actions = GetActionsResolvingPrecondition(goalAction->GetPreconditions()[i]);
		int nbActions = actions.size();
		for (size_t i = 0; i < nbActions; ++i)
		{
			SolveTree(actions[i], path, pathCost, bestPath, bestCost, gs);
			bestPaths.push_back(bestPath);
		}
	}
}

void GoapSolver::ExecuteActions(GameState* const gs) const
{
	int nbPaths = bestPaths.size();
	for (size_t i = 0; i < nbPaths; ++i)
	{
		int nbAction = bestPaths[i].size();
		for (size_t j = 0; j < nbAction; ++j)
		{
			bestPaths[i][j]->GetEffect()->ProcessAction(gs);
		}
	}
}

void GoapSolver::SolveTree(const Action* const currentAction, vector<const Action*> path, int pathCost, vector<const Action*>& bestPath, int& bestCost, const GameState* const gs)
{
	path.push_back(currentAction);
	pathCost += currentAction->GetCost();

	//Est ce qu'il y a des preconditions/enfants ?
	if (currentAction->GetPreconditions().size() == 0)
	{
		if (pathCost < bestCost)
		{
			bestPath = path;
			bestCost = pathCost;
		}
		return;
	}

	vector<const Action*> actionsFromPrecondition;

	//Si toutes les preconditions sont vraies -> return
	bool preconditionAreTrue = true;
	for (size_t i = 0; i < currentAction->GetPreconditions().size(); i++)
	{
		if (!currentAction->GetPreconditions()[i]->Process(gs))
		{
			preconditionAreTrue = false;
			break;
		}
	}

	if (preconditionAreTrue)
	{
		if (pathCost < bestCost)
		{
			bestPath = path;
			bestCost = pathCost;
		}
		return;
	}

	//Recupere les enfants
	//Fonctionne qu'avec 1 seul enfant
	actionsFromPrecondition = GetActionsResolvingPrecondition(currentAction->GetPreconditions()[0]);

	int N = actionsFromPrecondition.size();
	//Si aucun effet ne répond a la précondition
	if (N == 0)
	{
		if (pathCost < bestCost)
		{
			bestPath = path;
			bestCost = pathCost;
		}
		return;
	}

	//Parcours des enfants++
	for (size_t i = 0; i < N; i++)
	{
		SolveTree(actionsFromPrecondition[i], path, pathCost, bestPath, bestCost, gs);
	}
}

vector<const Action*> GoapSolver::GetActionsResolvingPrecondition(const Precondition* const p)const
{
	vector<const Action*> actions;
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
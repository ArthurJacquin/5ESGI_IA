#include <iostream>
#include "Goap.h"

GoapSolver::GoapSolver()
{
	goalAction = nullptr;
}

GoapSolver::GoapSolver(const Action* const goal)
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
}

void GoapSolver::CreateSolver()
{
	cout << "Creating solver" << endl;
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
	cookPancake->AddEffect( new Effect(PreconditionName::GetPancake, [](GameState* const gs) { gs->CookPancake(1); }));
	cookPancake->AddPrecondition(new Precondition(PreconditionName::MixedEggs, [](const GameState* const gs)->const bool { return gs->GetMixedEggsAmount() > 0; }));
	cookPancake->AddPrecondition(new Precondition(PreconditionName::MixedFlour, [](const GameState* const gs)->const bool { return gs->GetMixedFlourAmount() > 0; }));
	cookPancake->AddPrecondition(new Precondition(PreconditionName::MixedNut, [](const GameState* const gs)->const bool { return gs->GetMixedNutAmount() > 0; }));

	//Add Mixed Eggs links
	addMixedEggs->AddEffect(new Effect(PreconditionName::MixedEggs, [](GameState* const gs) { gs->AddMixedEggs(1); }));
	addMixedEggs->AddPrecondition(new Precondition(PreconditionName::CollectEgg, [](const GameState* const gs)->const bool { return gs->GetEggsAmount() > 0; }));

	//Collect Eggs links
	collectEggs->AddEffect(new Effect(PreconditionName::CollectEgg, [](GameState* const gs) { gs->CollectEggs(1); }));
	collectEggs->AddPrecondition(new Precondition(PreconditionName::HaveChicken, [](const GameState* const gs)->const bool { return gs->GetChickenAmount() > 0; }));

	//Buy Eggs links
	buyEggs->AddEffect(new Effect(PreconditionName::CollectEgg, [](GameState* const gs) { gs->BuyEggs(1); }));

	//Mixed Flour links
	addMixedFlour->AddEffect(new Effect(PreconditionName::MixedFlour, [](GameState* const gs) { gs->AddMixedFlour(1); }));
	addMixedFlour->AddPrecondition(new Precondition(PreconditionName::CollectFlour, [](const GameState* const gs)->const bool { return gs->GetFlourAmount() > 0; }));

	//Grind flour links
	grindFlour->AddEffect(new Effect(PreconditionName::CollectFlour, [](GameState* const gs) { gs->GrindFlour(1); }));
	grindFlour->AddPrecondition(new Precondition(PreconditionName::CollectWheat, [](const GameState* const gs)->const bool { return gs->GetWheatAmount() > 0; }));

	//Harvest Wheat links
	harvestWheat->AddEffect(new Effect(PreconditionName::CollectWheat, [](GameState* const gs) { gs->HarvestWheat(1); }));
	harvestWheat->AddPrecondition(new Precondition(PreconditionName::HaveField, [](const GameState* const gs)->const bool { return gs->GetFieldAmount() > 0; }));

	//Buy flour links
	buyFlour->AddEffect(new Effect(PreconditionName::CollectFlour, [](GameState* const gs) { gs->BuyFlour(1); }));
	
	//Mixed Nut links
	addMixedNut->AddEffect(new Effect(PreconditionName::MixedNut, [](GameState* const gs) {	gs->AddMixedNut(1);	}));
	addMixedNut->AddPrecondition(new Precondition(PreconditionName::CollectNut, [](const GameState* const gs)->const bool { return gs->GetNutAmount() > 0; }));

	//Buy Nut links
	buyNut->AddEffect(new Effect(PreconditionName::CollectNut, [](GameState* const gs) { gs->BuyNut(1); }));

	goalAction = cookPancake;

	cout << "Solver created !!!!" << endl;
}

//Retourne les meilleurs chemins lors de multiples préconditions (stock dans bestPaths)
void GoapSolver::Solve(GameState* gs)
{
	int nbPrecondition = goalAction->GetPreconditions().size();

	for (size_t i = 0; i < nbPrecondition; ++i)
	{
		vector<const Action*> path;
		int pathCost = 0;
		vector<const Action*> bestPath;
		int bestCost = 9999;

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

//Execute toutes les actions du meilleur chemin et l'action finale (get Pancake)
void GoapSolver::ExecuteActions(GameState* const gs)
{
	int nbPaths = bestPaths.size();
	bool everythingOK = true;
	//Tous les chemins
	for (size_t i = 0; i < nbPaths; ++i)
	{
		int nbAction = bestPaths[i].size();
		//Toutes les actions
		for (int j = nbAction - 1; j >= 0 ; --j)
		{
			int nbPrecond = bestPaths[i][j]->GetPreconditions().size();
			//Toutes les preconditions OK
			for (size_t k = 0; k < nbPrecond; ++k)
			{
				if (!bestPaths[i][j]->GetPreconditions()[k]->Process(gs))
				{
					everythingOK = false;
					break;
				}
			}

			if (!everythingOK)
				break;

			int nbEffects = bestPaths[i][j]->GetEffect().size();
			for (size_t k = 0; k < nbEffects; ++k)
			{
				bestPaths[i][j]->GetEffect()[k]->ProcessAction(gs);
			}
		}

		bestPaths[i].clear();
	}
	bestPaths.clear();

	if (everythingOK)
	{
		int nbEffects = goalAction->GetEffect().size();
		for (size_t i = 0; i < nbEffects; ++i)
		{
			goalAction->GetEffect()[i]->ProcessAction(gs);
		}
	}
}

//Retourne le chemin le moins couteux dans bestPath
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
	vector<const Action*> actionsFromPrecondition;
	actionsFromPrecondition = GetActionsResolvingPrecondition(currentAction->GetPreconditions()[0]);

	int N = actionsFromPrecondition.size();
	//Si aucun effet ne répond a la précondition
	if (N == 0)
	{
		return;
	}

	//Parcours des enfants++
	for (size_t i = 0; i < N; i++)
	{
		SolveTree(actionsFromPrecondition[i], path, pathCost, bestPath, bestCost, gs);
	}
}

//Récupère toutes les actions en fonction d'une précondition
vector<const Action*> GoapSolver::GetActionsResolvingPrecondition(const Precondition* const p)const
{
	vector<const Action*> actions;
	int N = allActions.size();
	for (size_t i = 0; i < N; i++)//Preconditions
	{
		for (size_t j = 0; j < allActions[i]->GetEffect().size(); j++)//Effets
		{
			if (p->GetName() == allActions[i]->GetEffect()[j]->GetName())
			{
				actions.push_back(allActions[i]);
			}
		}
	}

	return actions;
}
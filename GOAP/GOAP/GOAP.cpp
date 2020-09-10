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
	allActions.reserve(11);
	
	Action* cookPancake = new Action("Cook Pancake");
	Action* addEggs = new Action("Add Eggs");
	Action* addFlour = new Action("Add Flour");
	Action* addNut = new Action("Add Nut");
	Action* collectEggs = new Action("Collect Eggs");
	Action* findEggs = new Action("Find Eggs In Coop");
	Action* collectWheat = new Action("Collect Wheat");
	Action* grindWheat = new Action("Grind Wheat");
	Action* collectNut = new Action("Collect Nut");
	Action* collectWheat = new Action("Collect Wheat");
	Action* harvestWheat = new Action("Harvest Wheat");
	Action* getAChicken = new Action("Get A Chicken");

	//TODO : les liens


}

void GoapSolver::Solve()
{
	//TODO
}

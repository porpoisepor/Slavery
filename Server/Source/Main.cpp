#include <iostream>
#include <ParabolaCore/NetworkServer.h>
using namespace pE;

#include "GameSession.h"
#include "Hero.h"

int main(int argc, char **argv){

	enet_initialize();

	GameSession game;

	game.startListening();

	Hero grimshaw;
	grimshaw.nick = "Grimshaw";
	game.addHeroTeam1(grimshaw);

	Hero liryea;
	liryea.nick = "Liryea";	
	liryea.maxHealth = 200;
	liryea.healthRegen = 3;
	game.addHeroTeam2(liryea);

	game.start();

	game.killPlayer("Liryea");

	while(1 == 1){
		game.update();
	}

	return 0;
}
#pragma once
#include <iostream>
#include <string>
#include "Game.hpp"

using namespace std;
const int co=10;
const int amount=7;
const int minPlayers=2;
namespace coup{
    class Game;

    class Player{
        public:
            string name;
            int _coins;
            int stole;
            Game* game;
            bool inGame;
            int last_action;
            Player* onHim;
            Player(Game* game,const string& name);
            void income();
            void foreign_aid();
            virtual void coup(Player& p);
            virtual string role();
            int coins() const;
            string get_name()const;
    };

}
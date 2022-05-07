#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"
#include <unordered_map>
using namespace std;

const int AID=0;
const int COU=1;
const int STE=2;
const int TRA=3;
const int TAX=4;
const int COU2=5;
const int INC=6;

namespace coup{
    class Player;

    class Game{
        public:
            vector<string> names;
            unordered_map<Player*,string>moves;
            vector<Player*> _players;
            size_t numPlayers;
            bool started;
            int CurrPlayer;
            Game();
            void set_player(Player* p);
            string turn();
            vector<string> players();
            string winner();
            Player* get_next();
            bool valid_action(Player*);
};
}
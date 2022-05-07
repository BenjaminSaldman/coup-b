#include "Contessa.hpp"

#include <iostream>
#include <string>

using namespace std;
namespace coup{
    Contessa::Contessa(Game& game,const string& name):Player(&game,name){}
    string Contessa::role(){return "Contessa";}
    void Contessa::block(Player& p){ 
        if(!(game->started))
        {
            game->started=true;
        }
        if(p.last_action!=COU2)
        {
            throw invalid_argument{"Contessa can't block this action."};
        }
        p.onHim->inGame=true;
        game->numPlayers++;
    }
}
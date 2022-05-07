#include "Duke.hpp"

#include <iostream>
#include <string>

using namespace std;
namespace coup{
    Duke::Duke(Game& game,const string& name):Player(&game,name){}
    string Duke::role(){return "Duke";}
    void Duke::tax(){
        if(game->numPlayers<minPlayers)
        {
            throw invalid_argument{"Not Enough players."};
        }
         if(game->get_next()->name!=this->name)
        {
            throw invalid_argument{"Not players turn."};
        }
        if(_coins>=co)
        {
            throw invalid_argument{"Should coup some player."};
        }
        if(!(game->started))
        {
            game->started=true;
        }
        this->_coins+=3;
        game->CurrPlayer++;
        last_action=TAX;
    }
    void Duke::block(Player& p){
        if(!(game->started))
        {
            game->started=true;
        }
        if(p.last_action!=AID)
        {
            throw invalid_argument{"Duke can't block this action."};
        }
        p._coins-=2;
    }
}

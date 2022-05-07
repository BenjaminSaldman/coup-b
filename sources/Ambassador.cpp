#include "Ambassador.hpp"

#include <iostream>
#include <string>

using namespace std;
namespace coup{
    Ambassador::Ambassador(Game& game,const string& name):Player(&game,name){}
    string Ambassador::role(){return "Ambassador";}
    void Ambassador::block(Player& p){
         if(p.last_action!=STE)
        {
            throw invalid_argument{"Ambassador can't block this action."};
        }
         if(!(game->started))
        {
            game->started=true;
        }
        p.onHim->_coins+=p.stole;
        p._coins-=p.stole;
    }
    void Ambassador::transfer(Player& src, Player& dest){
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
        if(src._coins<=0)
        {
            throw invalid_argument{"can't transfer money."};
        }
        if(!(game->started))
        {
            game->started=true;
        }
        src._coins--;
        dest._coins++;
        last_action=TRA;
        game->CurrPlayer++;
    }
}
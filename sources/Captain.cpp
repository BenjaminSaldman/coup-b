#include "Captain.hpp"

#include <iostream>
#include <string>

using namespace std;
const int minAmount1=0;
const int minAmount2=1;
namespace coup{
    Captain::Captain(Game& game,const string& name):Player(&game,name){}
    string Captain::role(){return "Captain";}

    void Captain::block(Player& p){
        if(p.last_action!=STE)
        {
            throw invalid_argument{"Captain can't block this action."};
        }
         if(!(game->started))
        {
            game->started=true;
        }
        p.onHim->_coins+=p.stole;
        p._coins-=p.stole;
    }
    void Captain::steal(Player& p){
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
        if(p._coins<=minAmount1)
        {
            last_action=STE;
            stole=0;

        }
        else {
            if(p._coins==minAmount2)
            {
            
                p._coins--;
                this->_coins++;
                stole=1;
            }
            else{
                 p._coins-=2;
                this->_coins+=2;
                stole=2;
            }
        }
        last_action=STE;
        onHim=&p;
        game->CurrPlayer++;

    }
}
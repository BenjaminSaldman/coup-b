#include "Assassin.hpp"

#include <iostream>
#include <string>

using namespace std;
const int as=3;
const int _minus=7;
namespace coup{
    Assassin::Assassin(Game& game,const string& name):Player(&game,name){}
    string Assassin::role(){return "Assassin";}
    void Assassin::coup(Player& p){
         if(game->numPlayers<minPlayers)
        {
            throw invalid_argument{"Not Enough players."};
        }
         if(game->get_next()->name!=this->name)
        {
            throw invalid_argument{"Not players turn."};
        }
        if(_coins<as)
        {
            throw invalid_argument{"Not Enough money for assassin."};
        }
         if(!p.inGame)
        {
            throw invalid_argument{"Player already coued."};
        }
        if(!(game->started))
        {
            game->started=true;
        }
        game->CurrPlayer++;
        p.inGame=false;
        game->numPlayers--;
        if(_coins<amount){
            last_action=COU2;
            _coins-=as;
            onHim=&p;
        }else{
            last_action=COU;
            _coins-=_minus;
        }
        
    }
}

#include "Player.hpp"
#include <iostream>
#include <string>

using namespace std;
const int _minus=7;
namespace coup{
    Player::Player(Game* game,const string& name): game(game),name(name){_coins=0;last_action=-1;game->set_player(this);inGame=true;stole=0;onHim=NULL;}
    void Player::income(){
         if(game->numPlayers<minPlayers)
        {
            throw invalid_argument{"Not Enough players."};
        }
         if(game->get_next()!=this)
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
        game->CurrPlayer++;
        _coins++;
        last_action=INC;
    }
    int Player::coins()const{return _coins;}
    void Player::foreign_aid(){
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
        game->CurrPlayer++;
        _coins+=2;
        last_action=AID;
    }
    string Player::role(){return "Player";}
    void Player::coup(Player& p){
          if(game->numPlayers<minPlayers)
        {
            throw invalid_argument{"Not Enough players."};
        }
         if(game->get_next()->name!=this->name)
        {
            throw invalid_argument{"Not players turn."};
        }
        if(_coins<amount)
        {
            throw invalid_argument{"Not Enough pmoney."};
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
        last_action=COU;
        _coins-=_minus;
    }
    string Player::get_name()const{return this->name;}
}
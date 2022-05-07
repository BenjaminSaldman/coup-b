#include "Game.hpp"
namespace coup{
    const int Max=6;
    const int Min=2;
    const int win=1;
    Game::Game(){this->CurrPlayer=0; this->numPlayers=0;started=false;}
    vector<string> Game::players(){
        vector<string>ans;
        for(unsigned i=0;i<_players.size();i++)
        {
            if(_players.at(i)->inGame)
            {
                ans.push_back(_players.at(i)->name);
            }
        }
        return ans;
    }
    string Game::turn(){return get_next()->name;}
    string Game::winner()
    {
        if(numPlayers>win || !started)
        {
            throw invalid_argument{"More than one player is active."};
        } 
 
        return get_next()->name;
    }

    Player* Game::get_next()
    {
    
        if(CurrPlayer>=_players.size())
        {
            CurrPlayer=0;
        }
        if(CurrPlayer==_players.size()-1 && !(_players.at((unsigned)CurrPlayer)->inGame))
        {
            CurrPlayer=0;
        }
        for(int i=CurrPlayer;i<_players.size();i++)
        {
            if(_players.at((unsigned)i)->inGame)
            {
                CurrPlayer=i;
                break;
            }
        }
        if(!(_players.at((unsigned)CurrPlayer)->inGame))
        {
         for(int i=0;i<_players.size();i++)
        {
            if(_players.at((unsigned)i)->inGame)
            {
                CurrPlayer=i;
                break;
            }
        }
        }
        return _players.at((unsigned)CurrPlayer);
    }
    bool Game::valid_action(Player* p)
    {
        bool ans=true;
        if(get_next()!=p || numPlayers<Min)
        {
            ans=false;
        }
        return ans;

    }
    void Game::set_player(Player* p)
    {
        if(numPlayers>=Max)
        {
            throw invalid_argument{"Max Players reached"};
        }
        if(started)
        {
            throw invalid_argument{"The game is already started"};
        }
        _players.push_back(p);
        names.push_back(p->name);
        numPlayers++;
    }
}
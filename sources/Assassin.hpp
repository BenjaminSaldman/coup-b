#include "Player.hpp"

namespace coup{

    class Assassin: public Player{

        public:
            Assassin(Game &game,const string& name);
            void coup(Player &p);
            string role();

    };
}
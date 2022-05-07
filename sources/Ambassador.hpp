#include "Player.hpp"

namespace coup{

    class Ambassador:public Player{

        public:
            Ambassador(Game &game,const string& name);
            void block(Player &p);
            void transfer(Player &src,Player &dest);
            string role();
    };
}
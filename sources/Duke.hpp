
#include "Player.hpp"

namespace coup{

    class Duke: public Player{

        public:
            Duke(Game &game,const string& name);
            void tax();
            void block(Player &p);
            string role();
    };
}
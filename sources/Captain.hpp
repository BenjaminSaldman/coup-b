#include "Player.hpp"

namespace coup{

    class Captain: public Player
    {

        public:
            Captain(Game &game,const string& name);
            void block(Player &p);
            string role();
            void steal(Player &p);

    };

}
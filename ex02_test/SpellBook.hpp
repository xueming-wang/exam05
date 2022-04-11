#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

#include <vector>
#include <iterator>
#include <iostream>

#include "ASpell.hpp"

class SpellBook {
    public:
        SpellBook();
        virtual ~SpellBook();

        void learnSpell(ASpell*spell);
        void forgetSpell(std::string const &spellname);
        ASpell* createSpell(std::string const &spellname);

    private:
        SpellBook(SpellBook const& src);
        SpellBook &operator=(SpellBook const& rhs);

        std::vector<ASpell *>spells;

};

#endif
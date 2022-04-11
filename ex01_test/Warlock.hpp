#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <vector>
#include <iterator>

class Warlock {
    public:
        Warlock(std::string const& name, std::string const& title);
        virtual~Warlock();

        std::string const& getName()const;
        std::string const& getTitle()const;
        void setTitle(std::string const& title);
        void introduce() const;

        void learnSpell(ASpell *spell);
        void forgetSpell(std::string const& spellname);
        void launchSpell(std::string const& spellname, ATarget & target);

    private:
        std::string name;
        std::string title;
        std::vector<ASpell *> spells;

        Warlock(Warlock const& src);
        Warlock &operator=(Warlock const& rhs);
        Warlock();
};

#endif


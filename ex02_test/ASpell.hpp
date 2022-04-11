#ifndef ASPELL_HPP
# define ASPELL_HPP

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell{
    public:
        ASpell();
        ASpell(ASpell const& src);
        ASpell(std::string const& name, std::string const& effects);
        ASpell &operator=(ASpell const& rhs);
        virtual~ASpell();

        std::string const& getName()const;
        std::string const& getEffects()const;
        virtual ASpell *clone() const = 0;
        void launch(ATarget const& target);

    protected:
        std::string name;
        std::string effects;
};

#endif


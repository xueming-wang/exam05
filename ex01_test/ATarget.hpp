#ifndef ATARGET_HPP
# define ATARGET_HPP

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget{
    public:
        ATarget();
        ATarget(ATarget const& src);
        ATarget(std::string const& type);
        ATarget &operator=(ATarget const& rhs);
        virtual~ATarget();

        std::string const& getType()const;
        virtual ATarget *clone() const = 0;
        void getHitBySpell(ASpell const& spell)const;

    protected:
        std::string type;
};

#endif

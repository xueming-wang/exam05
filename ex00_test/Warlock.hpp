#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>

class Warlock {
    public:
        Warlock(std::string const& name, std::string const& title);
        virtual~Warlock();

        std::string const& getName()const;
        std::string const& getTitle()const;
        void setTitle(std::string const& title);
        void introduce() const;

    private:
        std::string name;
        std::string title;

        Warlock(Warlock const& src);
        Warlock &operator=(Warlock const& rhs);
        Warlock();
};

#endif
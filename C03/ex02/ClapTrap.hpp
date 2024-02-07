#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
public:
	// Constructors
	ClapTrap(std::string name);
	ClapTrap(std::string name, int health, int energy, int damage);
	ClapTrap(const ClapTrap &obj);

	// Desctrustor
	~ClapTrap();

	// Operators
	ClapTrap& operator=(ClapTrap& other);

	// Member Functions
	/* Getters */
	std::string getName();
	int			getHealth();
	int			getEnergy();
	int			getDamage();

	bool checkStamina();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

protected:
	std::string _name;
	int	_health ;
	int _energy;
	int	_damage;
};

#endif

#include "Player.h" // Player class header

// Player constructor
Player::Player(std::string name, int number)
{
	SetPlayer(name, number);
}

// Setter
void Player::SetPlayer(std::string name, int number)
{
	m_number = number;
	m_name = name;
}

// Getters
std::string Player::getName() { return m_name; }
int Player::getNumber() { return m_number; }
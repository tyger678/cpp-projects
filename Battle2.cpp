#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


class Player {
private:
	int health;
public:
	void takeDamage(int damage) {
		health = health - damage;
		if(health <= 0) {
			cout << "The end" << endl;
		}
	}
	void heal(int amount) {
		health = health + amount;
		if(health > 100) {
			health = 100;
		}
	}
	Player(int startHealth) {
		health = startHealth;
	}
	int getHealth() {
		return health;
	}
	
};

class Enemy {
private:
	int health;
public:
	void takeDamage(int damage) {
		health = health - damage;
		if(health <= 0) {
			cout << "The end" << endl;
		}
	}
	void heal(int amount) {
		health = health + amount;
		if(health > 100) {
			health = 100;
		}
	}
	Enemy(int startHealth) {
		health = startHealth;
	}
	int getHealth() {
		return health;
	}
	
};

int main() {
	srand(time(0));
	
	while(true) {
		Player hero(100);
		Enemy enemy(120);
		while(hero.getHealth() > 0 && enemy.getHealth() > 0) {
			int choice;
			int damag = rand() % 21 + 10;
			

			cout << "1 - attack, 2 - treatment" << endl;
			cin >> choice;
			
			if(choice == 1) {
				enemy.takeDamage(damag);
			}
			else if(choice == 2) {
				hero.heal(10);
			}
			if(enemy.getHealth() <= 0) { break; }
			int enemyDamage = rand() % 31 + 1; 
			hero.takeDamage(enemyDamage);
			cout << "Enemy dealt " << enemyDamage << " damage!" << endl; 
			cout << endl;
			
			if(hero.getHealth() <= 0) { break; }
			cout << "Player has " << hero.getHealth() << " HP" << endl;
			cout << endl;
			
		}
		if(hero.getHealth() <= 0) {
			cout << "You lose!" << endl;
		}
		if(enemy.getHealth() <= 0) {
			cout << "You win!!" << endl;
		}
		char answer;
		while(true) {
			cout << "Do you want to play again? (y/n): ";
			cin >> answer;
			if(answer == 'y' || answer == 'n') {
				break;
			}
			cout << "Error! Please enter y or n." << endl;
		}
		if(answer == 'n') {
			break;
		}
		
		
		
	}
}


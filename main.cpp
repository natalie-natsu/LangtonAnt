#include <iostream>
#include <cstdlib>
#include <vector>
#include "include/Board.h"
#include "include/Ant.h"
#include "include/AntSchizo.h"

using namespace std;

int main()
{
	int n, antType, confirm, x, y, speed, nbAnt = 0;
	Board board;

	double stats[4];
	for(int i = 0; i < 4; i++)
		stats[i] = 0;

    cout << "// 2ADS - SUPINFO LYON - AUTOMATE CELLULAIRE - 158390 //" << endl << endl;
    cout << "[DEFAULT]Fourmi de base     [2]Turmite" << endl;
    cin >> antType;

    cout << "[DEFAULT]Cases blanches par defaut     [2]Placer des cases noires" << endl;
    cin >> confirm;

	if(confirm == 2){
		int exit = 0;
		cout << "Entrer les coordonnes des cases a modifier (les cases en dehors du plateau ne sont pas prises en compte) :" << endl;
		do
		{
			cout << "[X]:" << endl;
			cin >> x;
			cout << "[Y]:" << endl;
			cin >> y;

			if(board.getTab(x, y))
			{
				State* state(0);
				state = board.getTab(x, y);
				state->setColor(2);
			}

			cout << "[DEFAULT]Terminer     [0]Continuer" << endl;
			cin >> exit;
		}
		while(exit == 0);
	}

	system("cls");
	cout << "// 2ADS - SUPINFO LYON - AUTOMATE CELLULAIRE - 158390 //" << endl << endl;
	cout << "Combien de generation voulez-vous ?" << endl;
	cin >> n;
	cout << "Quelle vitesse voulez-vous ?" << endl;
	cin >> speed;

	if (antType != 2)
	{
		do
		{
			cout << "Combien de fourmi voulez-vous ? (4 maximum) ?" << endl;
			cin >> nbAnt;
		}
		while(nbAnt <= 0 || nbAnt > 4);
		std::vector<Ant> ants(nbAnt, Ant(board));
		for(int i = 0; i <= n; i++)
		{
			for(unsigned int j = 0; j < ants.size(); j++)
			{
				if(i % speed == 0)
				{
					system("cls");
					cout << "// 2ADS - SUPINFO LYON - AUTOMATE CELLULAIRE - 158390 //" << endl;
					cout << "Generation " << i << "/" << n << endl << endl;
					board.display();
					board.display_file();
				}
				ants[j].moving(board);
				stats[ants[j].getDirection()-1]++;
			}
		}
	}
	else
	{
		AntSchizo ant(board);
		for(int i = 0; i <= n; i++)
		{
			if(i % speed == 0)
			{
				system("cls");
				cout << "// 2ADS - SUPINFO LYON - AUTOMATE CELLULAIRE - 158390 //" << endl;
				cout << "Generation " << i << "/" << n << endl << endl;
				board.display();
				board.display_file();
			}
			ant.moving(board);
			stats[ant.getDirection()-1]++;
		}
	}

	cout << "[NORD]     " << stats[0] << " occurences    " << (stats[0] / (n+1)) * 100 << "%" << endl;
	cout << "[OUEST]    " << stats[1] << " occurences    " << (stats[1] / (n+1)) * 100 << "%" << endl;
	cout << "[SUD]      " << stats[2] << " occurences    " << (stats[2] / (n+1)) * 100 << "%" << endl;
	cout << "[EST]      " << stats[3] << " occurences    " << (stats[3] / (n+1)) * 100 << "%" << endl;

    return 0;
}

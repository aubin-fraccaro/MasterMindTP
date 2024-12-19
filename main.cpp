#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

void clearScreen() {
    for (int i = 0; i < 50; i++) {
        cout << endl;
    }
}

void uncontreun() {
    char tabJoueur[4] = {};
    char tabOrdi[4] = {};
    int nbTentatives = 10;
    int nbPoints = 10000;

    clearScreen();

    // Saisie des couleurs à faire deviner
    cout << "Player 1: Enter the colors to be guessed (R)ed (G)reen (B)lue (Y)ellow for, \n";
    for (int i = 0; i < size(tabOrdi); i++) {
        cout << "Position " << i + 1 << "/4 : ";
        cin >> tabOrdi[i];
        tabOrdi[i] = static_cast<char>(toupper((tabOrdi[i])));

        // Vérification de la saisie
        while (tabOrdi[i] != 'R' && tabOrdi[i] != 'G' && tabOrdi[i] != 'B' && tabOrdi[i] != 'Y') {
            cout << "Invalid color, please enter (R)ed (G)reen (B)lue (Y)ellow : ";
            cin >> tabOrdi[i];
            tabOrdi[i] = static_cast<char>(toupper((tabOrdi[i])));
        }
    }

    clearScreen();
    cout << "\n   --- Starting the game ---\n";

    int tour = 1;

    // Déroulement du jeu
    for (int i = 0; i < nbTentatives; i++) {
        cout << "\nRound number : " << tour << endl;
        cout << "Points : " << nbPoints << "\n";

        int compteur = 0; // Réinitialisation du compteur pour ce tour

        // Saisie des tentatives
        cout << "Enter your guess attempts for the 4 positions :\n";
        for (int j = 0; j < 4; j++) {
            cout << "Position " << j + 1 << "/4 : ";
            cin >> tabJoueur[j];
            tabJoueur[j] = static_cast<char>(toupper((tabJoueur[j])));

            // Vérification de la saisie
            while (tabJoueur[j] != 'R' && tabJoueur[j] != 'V' && tabJoueur[j] != 'B' && tabJoueur[j] != 'J') {
                cout << "Invalid color. Please enter (R/G/B/Y) : ";
                cin >> tabJoueur[j];
                tabJoueur[j] = static_cast<char>(toupper(tabJoueur[j]));
            }
        }

        // Comparaison avec la solution
        for (int j = 0; j < 4; j++) {
            if (tabJoueur[j] == tabOrdi[j]) {
                compteur++;
            }
        }

        // Résultat après le tour
        cout << "\nPoints : " << nbPoints << "\n";

        // Condition de victoire
        if (compteur == 4) {
            clearScreen();
            cout << "\nCongratulations! You've guessed all the colors.\n";
            cout << "Final score : " << nbPoints << " points\n";
            break;
        } else {
            // Mise à jour des points et préparation pour le tour suivant
            nbPoints -= 1000;
            // Si le joueur n'a plus de points, la partie est terminée et il a perdu
            if (nbPoints <= 0) {
                clearScreen();
                cout << "\nYou have no more points. Game over!\n";
                cout << "The solution was : ";
                for (char c : tabOrdi) {
                    cout << "|" << c << "|";
                }
                cout << endl;
                break;
            }

            cout << "\n   --- Next Tour ---\n\n";
            cout << compteur << " correct attempts on the last round";
            tour++;
        }
    }
} // Terminé


void uncontrebot() {
    char couleurs [4] = {'R','G','B','Y'};
    char tabJoueur [4] = {};
    char tabOrdi [4] = {};
    for (char &c :tabOrdi) {
        c = couleurs[(rand()%4)];
    }
    int nbTentatives = 10;
    int nbPoints = 10000;
    int tour = 1;
    // Generation des couleurs à faire deviner aleatoirement
    for (char &c :tabOrdi) {
        c = couleurs[(rand()%4)];
    }
    cout << "\n   --- Starting the game ---\n";
    // Déroulement du jeu
    for (int i = 0; i < nbTentatives; i++) {
        cout << "\nRound number : " << tour << endl;
        cout << "Points : " << nbPoints << "\n";

        int compteur = 0; // Réinitialisation du compteur pour ce tour

        // Saisie des tentatives de devinettes
        cout << "Enter your guess attempts for the 4 positions :\n";
        for (int j = 0; j < 4; j++) {
            cout << "Position " << j + 1 << "/4 : ";
            cin >> tabJoueur[j];
            tabJoueur[j] = static_cast<char>(toupper((tabJoueur[j])));

            // Vérification de la saisie
            while (tabJoueur[j] != 'R' && tabJoueur[j] != 'G' && tabJoueur[j] != 'B' && tabJoueur[j] != 'Y') {
                cout << "Invalid color. Please enter (R/G/B/Y) : ";
                cin >> tabJoueur[j];
                tabJoueur[j] = static_cast<char>(toupper((tabJoueur[j])));
            }
        }

        // Comparaison avec la solution tabOrdi
        for (int j = 0; j < 4; j++) {
            if (tabJoueur[j] == tabOrdi[j]) {
                compteur++;
            }
        }

        // Résultat après le tour
        cout << "\nPoints : " << nbPoints << "\n";

        // Condition de victoire
        if (compteur == 4) {
            clearScreen();
            cout << "\nCongratulations! You've guessed all the colors.\n";
            cout << "Final score : " << nbPoints << " points\n";
            break;
        } else {
            // Mise à jour des points et préparation pour le tour suivant
            nbPoints -= 1000;
            // Si le joueur n'a plus de points, la partie est terminée et il a perdu
            if (nbPoints <= 0) {
                clearScreen();
                cout << "\nYou have no more points. Game over !\n";
                cout << "The solution was : ";
                for (char c : tabOrdi) {
                    cout << "|" << c << "|";
                }
                cout << endl;
                break;
            }

            cout << "\n   --- Next Round ---\n\n";
            cout << compteur << " correct attempts on the last round";
            tour++;
        }
    }
} // Terminé


void UnContreBotFacile() {
    char couleurs [4] = {'R','G','B','Y'};
    char tabJoueur [4] = {};
    char tabOrdi [4] = {};
    // Remplir tabOrdi avec des couleurs uniques (Utilisation de ChatGPT pour explications)
    for (int i = 0; i < 4; i++) {
        char couleurGenerée;
        bool couleurExistante;

        do {
            couleurGenerée = couleurs[rand() % 4]; // Choisir une couleur aléatoire
            couleurExistante = false;

            // Vérifier si la couleur existe déjà dans tabOrdi
            for (int j = 0; j < i; j++) {
                if (tabOrdi[j] == couleurGenerée) {
                    couleurExistante = true;
                    break;
                }
            }

        } while (couleurExistante); // Tant que la couleur est déjà dans tabOrdi, on recommence

        tabOrdi[i] = couleurGenerée; // Ajouter la couleur générée unique dans tabOrdi
    }
    cout << tabOrdi;
    int nbTentatives = 10;
    int nbPoints = 10000;
    int tour = 1;
    cout << "\n   --- Starting the game ---\n";
    // Déroulement du jeu
    for (int i = 0; i < nbTentatives; i++) {
        cout << "\nRound number : " << tour << endl;
        cout << "Points : " << nbPoints << "\n";

        int compteur = 0; // Réinitialisation du compteur

        // Saisie des tentatives de devinettes
        cout << "Enter your guess attempts for the 4 positions :\n";
        for (int j = 0; j < 4; j++) {
            cout << "Position " << j + 1 << "/4 : ";
            cin >> tabJoueur[j];
            tabJoueur[j] = static_cast<char>(toupper((tabJoueur[j])));

            // Vérification de la saisie
            while (tabJoueur[j] != 'R' && tabJoueur[j] != 'G' && tabJoueur[j] != 'B' && tabJoueur[j] != 'Y') {
                cout << "Invalid color. Please enter (R/G/B/Y) : ";
                cin >> tabJoueur[j];
                tabJoueur[j] = static_cast<char>(toupper((tabJoueur[j])));
            }
        }

        // Comparaison avec la solution tabOrdi
        for (int j = 0; j < 4; j++) {
            if (tabJoueur[j] == tabOrdi[j]) {
                compteur++;
            }
        }

        // Résultat après le tour
        cout << "\nPoints : " << nbPoints << "\n";

        // vérification des conditions de victoire
        if (compteur == 4) {
            clearScreen();
            cout << "\nCongratulations! You've guessed all the colors.\n";
            cout << "Final score : " << nbPoints << " points\n";
            break;
        } else {
            // Si pas de victoire mise à jour des points et préparation pour le tour suivant
            nbPoints -= 1000;
            // Si le joueur n'a plus de points, la partie est terminée et il a perdu
            if (nbPoints <= 0) {
                clearScreen();
                cout << "\nYou have no more points. Game over!\n";
                cout << "The solution was : ";
                for (char c : tabOrdi) {
                    cout << "|" << c << "|";
                }
                cout << endl;
                break;
            }
            //Affichage tour suivant et partie des informations
            cout << "\n   --- Next Round ---\n\n";
            cout << compteur << " correct attempts on the last round";
            tour++;
        }
    }
} // Fin


int main() {
    srand(time(nullptr));
    int choix = 0;
    cout << "\n\n     ---MasterMind Main menu---   \n\n 1- 1vs1\n 2- 1vsBot(Easy)\n 3- 1vsBot(100%random)\n\nInput : ";
    cin >> choix;
    while (true) {
        clearScreen();
        switch (choix) {
            case 1:uncontreun();
            break;
            case 2: UnContreBotFacile();
            break;
            case 3: uncontreun();
            break;
            default:
                cout << "\n\n     ---MasterMind Main menu---   \n\n 1- 1vs1\n 2- 1vsBot(Easy)\n 3- 1vsBot(100%random)\n\n";
                cout << "(Try with a number included in the menu : ) :"; }
        cin >> choix;
    }
}

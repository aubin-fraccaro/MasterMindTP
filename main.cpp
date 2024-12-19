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
    cout << "Joueur 1 : Saisissez les couleurs a faire deviner\n(R)ouge (V)ert (B)leu (J)aune pour, \n";
    for (int i = 0; i < size(tabOrdi); i++) {
        cout << "Position " << i + 1 << "/4 : ";
        cin >> tabOrdi[i];
        tabOrdi[i] = toupper(tabOrdi[i]);

        // Vérification de la saisie
        while (tabOrdi[i] != 'R' && tabOrdi[i] != 'V' && tabOrdi[i] != 'B' && tabOrdi[i] != 'J') {
            cout << "Couleur invalide, veuillez saisir (R)ouge (V)ert (B)leu (J)aune : ";
            cin >> tabOrdi[i];
            tabOrdi[i] = toupper(tabOrdi[i]);
        }
    }

    clearScreen();
    cout << "\n   --- Debut de la partie ---\n";

    int tour = 1;

    // Déroulement du jeu
    for (int i = 0; i < nbTentatives; i++) {
        cout << "\nTour numero : " << tour << endl;
        cout << "Points : " << nbPoints << "\n";

        int compteur = 0; // Réinitialisation du compteur pour ce tour

        // Saisie des tentatives
        cout << "Entrez vos tentatives de devinettes pour les 4 positions :\n";
        for (int j = 0; j < 4; j++) {
            cout << "Position " << j + 1 << "/4 : ";
            cin >> tabJoueur[j];
            tabJoueur[j] = toupper(tabJoueur[j]);

            // Vérification de la saisie
            while (tabJoueur[j] != 'R' && tabJoueur[j] != 'V' && tabJoueur[j] != 'B' && tabJoueur[j] != 'J') {
                cout << "Couleur invalide. Veuillez entrer (R/V/B/J) : ";
                cin >> tabJoueur[j];
                tabJoueur[j] = toupper(tabJoueur[j]);
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
            cout << "\nBravo ! Vous avez devine toutes les couleurs.\n";
            cout << "Score final : " << nbPoints << " points\n";
            break;
        } else {
            // Mise à jour des points et préparation pour le tour suivant
            nbPoints -= 1000;
            // Si le joueur n'a plus de points, la partie est terminée et il a perdu
            if (nbPoints <= 0) {
                clearScreen();
                cout << "\nVous n'avez plus de points. Partie terminée !\n";
                cout << "La solution était : ";
                for (char c : tabOrdi) {
                    cout << "|" << c << "|";
                }
                cout << endl;
                break;
            }

            cout << "\n   --- Tour Suivant ---\n\n";
            cout << compteur << " tentatives correctes au dernier tour";
            tour++;
        }
    }
} // Terminé


void uncontrebot() {
    char couleurs [4] = {'R','V','B','J'};
    char tabJoueur [4] = {};
    char tabOrdi [4] = {};
    for (int i = 0; i < size(tabOrdi); i++) {
        tabOrdi[i] = couleurs[(rand()%4)];
    }
    int nbTentatives = 10;
    int nbPoints = 10000;
    int tour = 1;
    // Generation des couleurs à faire deviner aleatoirement
    for (int i = 0; i < size(tabOrdi); i++) {
        tabOrdi[i] = couleurs[(rand()%4)];
    }
    cout << "\n   --- Debut de la partie ---\n";
    // Déroulement du jeu
    for (int i = 0; i < nbTentatives; i++) {
        cout << "\nTour numero : " << tour << endl;
        cout << "Points : " << nbPoints << "\n";

        int compteur = 0; // Réinitialisation du compteur pour ce tour

        // Saisie des tentatives de devinettes
        cout << "Entrez vos tentatives de devinettes pour les 4 positions :\n";
        for (int j = 0; j < 4; j++) {
            cout << "Position " << j + 1 << "/4 : ";
            cin >> tabJoueur[j];
            tabJoueur[j] = toupper(tabJoueur[j]);

            // Vérification de la saisie
            while (tabJoueur[j] != 'R' && tabJoueur[j] != 'V' && tabJoueur[j] != 'B' && tabJoueur[j] != 'J') {
                cout << "Couleur invalide. Veuillez entrer (R/V/B/J) : ";
                cin >> tabJoueur[j];
                tabJoueur[j] = toupper(tabJoueur[j]);
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
            cout << "\nBravo ! Vous avez devine toutes les couleurs.\n";
            cout << "Score final : " << nbPoints << " points\n";
            break;
        } else {
            // Mise à jour des points et préparation pour le tour suivant
            nbPoints -= 1000;
            // Si le joueur n'a plus de points, la partie est terminée et il a perdu
            if (nbPoints <= 0) {
                clearScreen();
                cout << "\nVous n'avez plus de points. Partie terminée !\n";
                cout << "La solution était : ";
                for (char c : tabOrdi) {
                    cout << "|" << c << "|";
                }
                cout << endl;
                break;
            }

            cout << "\n   --- Tour Suivant ---\n\n";
            cout << compteur << " tentatives correctes au dernier tour";
            tour++;
        }
    }
} // Terminé


void UnContreBotFacile() {
    char couleurs [4] = {'R','V','B','J'};
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
    cout << "\n   --- Debut de la partie ---\n";
    // Déroulement du jeu
    for (int i = 0; i < nbTentatives; i++) {
        cout << "\nTour numero : " << tour << endl;
        cout << "Points : " << nbPoints << "\n";

        int compteur = 0; // Réinitialisation du compteur

        // Saisie des tentatives de devinettes
        cout << "Entrez vos tentatives de devinettes pour les 4 positions :\n";
        for (int j = 0; j < 4; j++) {
            cout << "Position " << j + 1 << "/4 : ";
            cin >> tabJoueur[j];
            tabJoueur[j] = toupper(tabJoueur[j]);

            // Vérification de la saisie
            while (tabJoueur[j] != 'R' && tabJoueur[j] != 'V' && tabJoueur[j] != 'B' && tabJoueur[j] != 'J') {
                cout << "Couleur invalide. Veuillez entrer (R/V/B/J) : ";
                cin >> tabJoueur[j];
                tabJoueur[j] = toupper(tabJoueur[j]);
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
            cout << "\nBravo ! Vous avez devine toutes les couleurs.\n";
            cout << "Score final : " << nbPoints << " points\n";
            break;
        } else {
            // Si pas de victoire mise à jour des points et préparation pour le tour suivant
            nbPoints -= 1000;
            // Si le joueur n'a plus de points, la partie est terminée et il a perdu
            if (nbPoints <= 0) {
                clearScreen();
                cout << "\nVous n'avez plus de points. Partie terminée !\n";
                cout << "La solution était : ";
                for (char c : tabOrdi) {
                    cout << "|" << c << "|";
                }
                cout << endl;
                break;
            }
            //Affichage tour suivant et partie des informations
            cout << "\n   --- Tour Suivant ---\n\n";
            cout << compteur << " tentatives correctes au dernier tour";
            tour++;
        }
    }
} // Fin


int main() {
    srand(time(nullptr));
    int choix = 0;
    cout << "\n\n     ---Menu Principal MasterMind---   \n\n 1- 1vs1\n 2- 1vsBot(Facile)\n 3- 1vsBot(100%aleatoire)\n\nSaisie : ";
    cin >> choix;
    while (choix !=1 && choix !=2 && choix !=3) {
        clearScreen();
        switch (choix) {
            case 1:uncontreun();
            case 2: UnContreBotFacile();
            case 3: uncontreun();
            default:
                cout << "\n\n     ---Menu Principal MasterMind---   \n\n 1- 1vs1\n 2- 1vsBot(Facile)\n 3- 1vsBot(100%aleatoire)\n\n";
            cout << "(Essayez avec un chiffre compris dans le menu : ) :"; }
        cin >> choix;
    }
    return 0;
}

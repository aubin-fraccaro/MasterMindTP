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
    char tabJoueur [4] = {};
    char tabOrdi [4] = {};
    int nbTentatives = 10;
    int nbPoints = 10000;
    clearScreen();
    for (int i = 0; i < size(tabOrdi); i++) {
        cout <<"Saisissez la couleur position numero "<< i+1 << "/4 a faire deviner \n(R)ouge  (V)ert  (B)leu  (J)aune en majuscule\n:   ";
        cin >> tabOrdi [i];
        tabOrdi[i] = static_cast<char>(toupper(tabOrdi[i]));
        if (tabOrdi[i] != 'R' && tabOrdi[i] != 'V' && tabOrdi[i] != 'B' && tabOrdi[i] != 'J') {
            cout << "Veuillez saisir (R)ouge ou (V)ert ou (B)leu ou (J)aune en majuscule\n";
            i--;
        }
    }
    int tour = 1;
    cout << "\n   ---Debut de la partie---";
    clearScreen();
    for (int i = 0; i < nbTentatives; i++) {
        cout << "\n\n Tour numero : "<< tour<<endl;
        cout << "Vous avez : " << nbPoints << "points\n\n";
        int compteur = 0;
        for (int j = 0; j < 4; j++) {
            cout <<"Saisissez votre tentative de devinette pour la position : "<< j+1<<"/4 : \n";
            cin >> tabJoueur [j];
            tabJoueur [j] = static_cast<char>((tabJoueur [j]));
            if (tabJoueur[j] != 'R' && tabJoueur[j] != 'V' && tabJoueur[j] != 'B' && tabJoueur[j] != 'J'){
                cout << "Veuillez saisir (R)ouge ou (V)ert ou (B)leu ou (J)aune en majuscule\n";
                j--;
            }
        }
        for (int j = 0; j < 4; j++) {
            if (tabJoueur[j] == tabOrdi[j]) {
                compteur++;
            }

        }
        cout << "Vous avez "<< compteur<<" tentatives de devinette correctes ";
        tour++;
        if(compteur != 4) {
            clearScreen();
            nbPoints -= 1000;
            if (nbPoints <= 0) {
                cout << "\nVous n'avez plus de points. Partie terminee !\n La solution etait : ";
                for (char c : tabOrdi) {
                    cout << c;
                }
                break;
            }
            clearScreen();
            cout << "\n\n   ---Tour Suivant---" <<endl;
            continue;
        }
        else {
            cout << "Vous avez : " << nbPoints << "points\n";
            break;
        }
    }
}

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
    cout << "\n   ---Debut de la partie---";
    for (int i = 0; i < nbTentatives; i++) {
        cout << "\n\nTour numero : "<< tour<<endl;
        cout << "Points : " << nbPoints<<"\n\n";
        int compteur = 0;
        for (int j = 0; j < 4; j++) {
            cout <<"Saisissez votre tentative de devinette pour la position : "<< j+1<<"/4 \n(R)ouge  (V)ert  (B)leu  (J)aune en majuscule\n:   ";
            cin >> tabJoueur [j];
            if (toupper(tabJoueur[j]) != 'R' && toupper(tabJoueur[j]) != 'V' && toupper(tabJoueur[j]) != 'B' && toupper(tabJoueur[j]) != 'J'){
                cout << "Veuillez saisir (R)ouge ou (V)ert ou (B)leu ou (J)aune en majuscule\n";
                j--;
            }
            tabJoueur [j] = static_cast<char>((tabJoueur [j]));
        }
        for (int j = 0; j < 4; j++) {
            if (tabJoueur[j] == tabOrdi[j]) {
                compteur++;
            }

        }
        cout << "Vous avez "<< compteur<<" guess corrects ";
        tour++;
        if(compteur != 4) {
            cout << "\n\n   ---Tour Suivant---" <<endl;
            nbPoints -= 1000;
            if (nbPoints <= 0) {
                cout << "\nVous n'avez plus de points. Partie terminee !\n La solution etait : ";
                for (char c : tabOrdi) {
                    cout << c;
                }
                continue;
            }
        }
        else{
            cout << "Vous avez : " << nbPoints << "points\n";
            break;
        }
    }
}

void UnContreBotFacile() {
    char couleurs [4] = {'R','V','B','J'};
    char tabJoueur [4] = {};
    char tabOrdi [4] = {};
    // Remplir tabOrdi avec des couleurs uniques
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
    cout << "\n   ---Debut de la partie---";
    for (int i = 0; i < nbTentatives; i++) {
        cout << "\n\nTour numero : "<< tour<<endl;
        cout << "Points : " << nbPoints<<"\n\n";
        int compteur = 0;
        for (int j = 0; j < 4; j++) {
            cout <<"Saisissez votre tentative de devinette pour la position : "<< j+1<<"/4 : \n(R)ouge  (V)ert  (B)leu  (J)aune\n:   ";
            cin >> tabJoueur [j];
            if (tabJoueur[j] != 'R' && tabJoueur[j] != 'V' && tabJoueur[j] != 'B' && tabJoueur[j] != 'J'){
                cout << "\nVeuillez saisir (R)ouge ou (V)ert ou (B)leu ou (J)aune en majuscule\n";
                j--;
            }
                tabJoueur [j] = static_cast<char>((tabJoueur [j]));
        }
        for (int j = 0; j < 4; j++) {
            if (tabJoueur[j] == tabOrdi[j]) {
                compteur++;
            }

        }
        cout << "Vous avez "<< compteur<<" guess corrects ";
        tour++;
        if(compteur != 4) {
            cout << "\n\n   ---Tour Suivant---" <<endl;
            nbPoints -= 1000;
            continue;
        }
        else{
            cout << "Vous avez : " << nbPoints << "points\n";
            break;
        }
    }
}


int main() {
        srand(time(nullptr));
        int choix = 0;
        cout << "\n\n     ---Menu Principal MasterMind---   \n\n 1- 1vs1\n 2- 1vsBot(Facile)\n 3- 1vsBot(100%aleatoire)\n\nSaisie : ";
        cin >> choix;
        if (choix == 1) {
            uncontreun();
            cout << endl << endl << endl;

        }
        else if (choix == 2) {
            UnContreBotFacile();
            cout << endl << endl << endl;
        }
        else if (choix == 3) {
            uncontrebot();
            cout << endl << endl << endl;
        }
        else {
            cout << "Veuillez saisir une valeur comprise dans le menu";
        }
        return 0;
    }




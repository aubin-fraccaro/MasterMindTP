#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void clearScreen() {
    for (int i = 0; i < 50; i++) {
        cout << endl;
    }
}

void uncontreun(){
    char couleurs [4] = {'R','V','B','J'};
    char tabJoueur [4] = {};
    char tabOrdi [4] = {};
    int nbTentatives = 10;
    int nbPoints = 10000;
    clearScreen();
    for (int i = 0; i < size(tabOrdi); i++) {
        cout <<"Saisissez la couleur position numero "<< i+1 << "/4 a faire deviner \n(R)ouge  (V)ert  (B)leu  (J)aune en majuscule\n:   ";
        cin >> tabOrdi [i];
        if (tabOrdi[i] != 'R' && tabOrdi[i] != 'V' && tabOrdi[i] != 'B' && tabOrdi[i] != 'J') {
            cout << "Veuillez saisir (R)ouge ou (V)ert ou (B)leu ou (J)aune en majuscule";
            break;
        }
        else continue;
    }
    int compteur = 0;
    int tour = 1;
    cout << "\n   ---Debut de la partie---";
    clearScreen();
    for (int i = 0; i < nbTentatives; i++) {
        cout << "\n\n Tour numero : "<< tour<<endl;
        cout << "Vous avez : " << nbPoints << "points\n\n";
        int compteur = 0;
        for (int j = 0; j < 4; j++) {
            cout <<"Saisissez votre tentative de devinette pour la position : "<< j+1<<" : \n";
            cin >> tabJoueur [j];
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
            cout << "\n\n   ---Tour Suivant---" <<endl;
            nbPoints -= 1000;
            continue;
        }
        else if (compteur == 4) {
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
    int compteur = 0;
    int tour = 1;
    cout << "\n   ---Debut de la partie---";
    for (int i = 0; i < nbTentatives; i++) {
        cout << "\n\nTour numero : "<< tour<<endl;
        cout << "Points : " << nbPoints<<"\n\n";
        int compteur = 0;
        for (int j = 0; j < 4; j++) {
            cout <<"Saisissez votre tentative de devinette pour la position : "<< j+1<<" \n:   ";
            cin >> tabJoueur [j];
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
        else if (compteur == 4) {
            cout << "Vous avez : " << nbPoints << "points\n";
            break;
        }
    }
}

int main() {
    srand(time(0));
    int choix = 0;
    cout << "\n\n     ---Menu Principal MasterMind---   \n\n 1- 1vs1\n 2- 1vsBot\n\nSaisie : ";
    cin >> choix;
    if (choix == 1) {
        uncontreun();
        cout << endl << endl << endl;

    }
    else if (choix == 2) {
        uncontrebot();
        cout << endl << endl << endl;
    }
    else {
        cout << "Veuillez saisir une valeur comprise dans le menu";
    }
    return 0;
}



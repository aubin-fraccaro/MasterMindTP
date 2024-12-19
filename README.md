# Documentation du jeu MasterMind en C++

## Vue d'ensemble

Ce programme implémente le jeu classique MasterMind en C++. Il propose trois modes de jeu :
1. 1 contre 1 (deux joueurs humains)
2. 1 contre Bot (facile)
3. 1 contre Bot (100% aléatoire)

## Structure du code

Le code est divisé en plusieurs fonctions principales :

1. `clearScreen()` : Efface l'écran de la console.
2. `uncontreun()` : Implémente le mode 1 contre 1.
3. `uncontrebot()` : Implémente le mode 1 contre Bot (100% aléatoire).
4. `UnContreBotFacile()` : Implémente le mode 1 contre Bot (facile).
5. `main()` : Fonction principale qui gère le menu et lance le mode de jeu choisi.

## Détails des fonctions

### clearScreen()

Cette fonction "efface" l'écran en imprimant 50 lignes vides.

### uncontreun()

Cette fonction gère le mode 1 contre 1. Voici son fonctionnement :

1. Le joueur 1 entre une combinaison de 4 couleurs (R, G, B, Y).
2. Le joueur 2 essaie de deviner la combinaison en 10 tentatives maximum.
3. À chaque tentative, le jeu indique le nombre de couleurs correctement placées.
4. Le joueur 2 gagne s'il trouve la combinaison avant d'épuiser ses tentatives.

### uncontrebot()

Cette fonction est similaire à `uncontreun()`, mais la combinaison à deviner est générée aléatoirement par l'ordinateur.

### UnContreBotFacile()

Cette fonction est une variante de `uncontrebot()` où la combinaison générée contient des couleurs uniques, rendant le jeu plus facile.

### main()

La fonction principale affiche un menu et lance le mode de jeu choisi par l'utilisateur.

## Utilisation

1. Compilez le programme avec un compilateur C++ compatible.
2. Exécutez le programme.
3. Choisissez un mode de jeu dans le menu principal.
4. Suivez les instructions à l'écran pour jouer.

## Règles du jeu

- Les couleurs sont représentées par des lettres : R (rouge), G (vert), B (bleu), Y (jaune).
- Le joueur qui devine a 10 tentatives pour trouver la bonne combinaison.
- Après chaque tentative, le jeu indique le nombre de couleurs correctement placées.
- Le joueur gagne s'il trouve la combinaison avant d'épuiser ses tentatives.
- Le score est basé sur le nombre de tentatives restantes.

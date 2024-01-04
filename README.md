# Projet de Visualisation de Tri Rapide avec Raylib

Ce projet a été développé dans le cadre d'un cours de programmation en C pour illustrer visuellement le tri rapide (quicksort) à l'aide de la bibliothèque graphique Raylib. L'application permet aux utilisateurs de saisir un tableau d'entiers, de le trier visuellement et de répéter le processus avec un nouveau tableau.

## Instructions d'utilisation

1. **Taille du tableau :** À l'exécution, l'utilisateur est invité à entrer la taille du tableau (ne doit pas dépasser 10).
2. **Saisie des éléments :** L'utilisateur doit ensuite entrer les éléments du tableau.
3. **Interface Graphique :** Une fenêtre graphique s'ouvre avec une représentation visuelle du tableau avant le tri.
4. **Boutons :**
   - *Trier :* Initie le processus de tri rapide.
   - *Répéter :* Permet à l'utilisateur de spécifier un nouveau tableau à trier.
   - *Quitter :* Ferme l'application.

## Structure du Projet

Le code source est divisé en plusieurs parties pour une meilleure compréhension et modularité :

- **main.c :** Contient la fonction `main` et la logique principale de l'application.
- **quickSort.c :** Implémente l'algorithme de tri rapide.
- **drawArray.c :** Gère la visualisation du tableau à l'aide de la bibliothèque Raylib.
- **util.c :** Contient des fonctions utilitaires telles que la copie du tableau.

## Dépendances

- [Raylib](https://www.raylib.com/) - Une bibliothèque graphique simple et facile à utiliser pour le langage C.

## Compilation et Exécution

1. Assurez-vous d'avoir la bibliothèque Raylib installée.
2. Compilez le programme avec un compilateur C compatible (gcc, clang, etc.).
3. Exécutez l'application résultante.

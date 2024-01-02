#include <stdio.h>
#include <raylib.h>

// Fonction de tri à bulles
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    // Initialiser raylib
    InitWindow(screenWidth, screenHeight, "Bubble Sort with raylib");

    // Demander à l'utilisateur de fournir la taille du tableau
    int n;
    printf("Entrez la taille du tableau : ");
    scanf("%d", &n);

    // Demander à l'utilisateur de fournir les éléments du tableau
    int arr[n];
    printf("Entrez les elements du tableau :\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Trier le tableau
    bubbleSort(arr, n);

    // Boucle principale
    while (!WindowShouldClose()) {
        BeginDrawing();

        // Effacer l'écran
        ClearBackground(RAYWHITE);

        // Afficher le tableau trié
        for (int i = 0; i < n; i++) {
            DrawRectangle(i * 80, screenHeight - arr[i], 60, arr[i], RED);
        }

        EndDrawing();
    }

    // Fermer raylib
    CloseWindow();

    return 0;
}

#include <stdio.h>
#include <raylib.h>

//pour dessiner un ensemble de rectangles
void drawArray(int arr[], int n,int posX)
{

    for (int i = 0; i < n; i++)
    {
        DrawRectangle(posX, 200 - arr[i], 50, arr[i], MAROON);
        DrawText(TextFormat("%i", arr[i]), posX + 15, 210, 10, DARKGRAY);
        posX += 60;
    }
}

// Fonction de tri rapide (quicksort)
void quickSort(int arr[], int low, int high)
{   // Verifie si l'indice bas est inferieur à l'indice haut, sinon, le tableau est dejà trie
    if (low < high)
    {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        int pi = (i + 1);
        // Applique recursivement le tri rapide aux sous-tableaux à gauche et à droite du pivot
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;
    
    InitWindow(screenWidth, screenHeight, "Quick Sort Visualization");

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
    SetTargetFPS(60);
   
    while (!WindowShouldClose()) {
        BeginDrawing();

        // Effacer l'écran
        ClearBackground(RAYWHITE);
        
        drawArray(arr, n,400);
        quickSort(arr, 0, n - 1);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

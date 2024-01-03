#include <stdio.h>
#include <raylib.h>

void drawArray(int arr[], int n, int posX, int posY, const char* message, int textSize, int textPosY)
{
    // Dessine le message au-dessous du tableau
    DrawText(message, posX, textPosY, textSize, DARKGRAY);
    // Trouve la valeur maximale dans le tableau
    int maxArrayValue = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxArrayValue)
            maxArrayValue = arr[i];
    }
    // Dessine les rectangles représentant le tableau avec la longueur en fonction des valeurs
    for (int i = 0; i < n; i++)
    {
        int rectHeight = (int)(((float)arr[i] / maxArrayValue) * 160); // Ajustez 150 en fonction de la hauteur maximale souhaitée
        DrawRectangle(posX, posY - rectHeight, 35, rectHeight, BLUE);
        DrawText(TextFormat("%i", arr[i]), posX + 10, posY + 10, textSize, DARKGRAY);
        posX += 45; // Ajustez l'espace entre les rectangles
    }
}
// Fonction de tri rapide (quicksort)
void quickSort(int arr[], int low, int high)
{
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
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
// Fonction pour copier un tableau
void copyArray(int src[], int dest[], int n)
{
    for (int i = 0; i < n; i++)
    {
        dest[i] = src[i];
    }
}
int main()
{
    const int screenWidth = 1200;
    const int screenHeight = 450;

    int n;
    do{
        printf("Entrez la taille du tableau : ");//assurer que le nombre des elements est positive
        scanf("%d", &n);
        if (n<=0)
         printf("erreur. entrer une valeur positive \n");
    }while(n<=0);
    int originalArr[n];
    int sortedArr[n];
    printf("Entrez les elements du tableau :\n");
    for (int i = 0; i < n; i++)
    {
        printf("Element %d : ", i + 1);
        scanf("%d", &originalArr[i]);
    }
    SetTargetFPS(60);
    InitWindow(screenWidth, screenHeight, "Quick Sort Visualization");

   while (!WindowShouldClose())
{
    BeginDrawing();

    ClearBackground(RAYWHITE);

    // Dessine le tableau avant le tri avec des paramètres personnalisés
    drawArray(originalArr, n, 50, 300, "Tableau avant le tri", 20, 350);

    // Copie le tableau original pour le tri
    copyArray(originalArr, sortedArr, n);

    // Trie le tableau copié
    quickSort(sortedArr, 0, n - 1);

    // Dessine le tableau après le tri avec des paramètres personnalisés
    drawArray(sortedArr, n, 650, 300, "Tableau apres le tri", 20, 350);

    EndDrawing();
}
    CloseWindow();
    return 0;
}


   

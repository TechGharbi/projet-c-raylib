
#include <stdio.h>
#include <raylib.h>

// Fonction pour dessiner le tableau
void drawArray(int arr[], int n, int posX, int posY,int spacingX)
{
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
         // La couleur du rectangle dépend de la position dans le tableau
        Color color = (Color){255 - (i * 255 / n), 0, i * 255 / n, 255};
         // La hauteur du rectangle est ajustée en fonction de la valeur actuelle dans le tableau
        int rectHeight = (int)(((float)arr[i] / maxArrayValue) * 160); // Ajustez 150 en fonction de la hauteur maximale souhaitée
       DrawRectangle(posX + i * (20 + spacingX), posY + 200 - arr[i], 35, arr[i], color);
        DrawText(TextFormat("%i", arr[i]), posX + i * (20 + spacingX) + 5, posY + 180 - arr[i], 10, DARKGRAY);
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


int main()
{
    const int screenWidth = 1200;
    const int screenHeight = 450;
    int sortingDone = 0;
    int n;
     printf("Entrer la taille du tableau (ne depasse pas 10): \n");
    do{
        scanf("%d", &n);
        if (n > 10)
         printf("Entrer une valeur ne depasse pas 10.\n");
    }while(n > 10);

     int sortButtonPosX = 50;
    int exitButtonPosX = 150;

    int originalArr[n];
    int sortedArr[n];

    printf("Entrer %d elements ne depassant pas 150\n", n);

    for (int i = 0; i < n; i++)
    {
        do
            {
        printf("Element %d : ", i + 1);
        scanf("%d", &originalArr[i]);
                if (originalArr[i] > 150)
            {
                printf("Entrer une valeur ne depasse pas 150.\n");
            }
            }while (originalArr[i] > 150);
    }
    SetTargetFPS(60);
    InitWindow(screenWidth, screenHeight, "Quick Sort Visualization");

   while (!WindowShouldClose())
{
    BeginDrawing();
    ClearBackground(RAYWHITE);

   // Check for button clicks
        if (CheckCollisionPointRec(GetMousePosition(), (Rectangle){sortButtonPosX, 400, 80, 30}) &&
            IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
           // Si le bouton "Trier" est cliqué, effectuez le tri
            for (int i = 0; i < n; i++)
            {
                sortedArr[i] =originalArr[i];
            }
            quickSort(sortedArr, 0, n - 1);
            sortingDone = 1;// Définissez le drapeau pour indiquer que le tri a été effectué
        }
        else if (CheckCollisionPointRec(GetMousePosition(), (Rectangle){exitButtonPosX, 400, 80, 30}) &&
                 IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
           // Si le bouton "Sortir" est cliqué, fermez la fenêtre
            break;
        }
    // Draw the buttons
        DrawRectangle(sortButtonPosX, 400, 80, 30, LIGHTGRAY);
        DrawText("Trier", sortButtonPosX + 20, 405, 10, DARKGRAY);

        DrawRectangle(exitButtonPosX, 400, 80, 30, LIGHTGRAY);
        DrawText("Sortir", exitButtonPosX + 20, 405, 10, DARKGRAY);

    // Draw the arrays
        DrawText("Tableau avant le tri rapide", 50, 300, 20, DARKGRAY);
        drawArray(originalArr, n, 50, 50, 30);

     if (sortingDone)
        {
            DrawText("Tableau apres le tri rapide", 600, 300, 20, DARKGRAY);
            drawArray(sortedArr, n, 600, 50, 30);
        }
    EndDrawing();
}
    CloseWindow();
    return 0;
}

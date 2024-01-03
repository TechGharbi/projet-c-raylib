#include <stdio.h>
#include <raylib.h>

// Fonction pour dessiner le tableau
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
         Color color = (Color){255, i * 255 / n, 0, 255};//pour les couleurs chaudes
        //Color color = (Color){255 - (i * 255 / n), 0, i * 255 / n, 255};  pour les couleurs froides
        
         int rectHeight = (int)(((float)arr[i] / maxArrayValue) * 160); 
    
        DrawText(TextFormat("%i", arr[i]), posX + i * (35 + 10), posY - rectHeight - 20, textSize, DARKGRAY);
        DrawRectangle(posX + i * (35 + 10), posY - rectHeight, 35, rectHeight, color);
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
    do {
     printf("Entrer la taille du tableau : \n");
        scanf("%d", &n);
         if (n <= 0)
            printf("Erreur. Entrez une valeur positive.\n");
    } while (n <= 0);
    
    int originalArr[n];
    int sortedArr[n];

    printf("Entrer %d elements :\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Element %d : ", i + 1);
        scanf("%d", &originalArr[i]);
    }
    SetTargetFPS(60);
    InitWindow(screenWidth, screenHeight, "Quick Sort Visualization");

     // Ajouter un bouton "Trier" à la fenêtre
    Rectangle sortButtonRect = { 50, 400, 100, 40 };
    bool sortButtonClicked = false;

    // Ajouter un bouton "Quitter" à la fenêtre
    Rectangle quitButtonRect = { 200, 400, 100, 40 };
    bool quitButtonClicked = false;

    bool isSorted = false; // Ajouter un indicateur pour savoir si le tableau est trié
    
   while (!WindowShouldClose())
{
     // Mise à jour de la logique des boutons
        Vector2 mousePoint = GetMousePosition();

        sortButtonClicked = CheckCollisionPointRec(mousePoint, sortButtonRect) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON);
        quitButtonClicked = CheckCollisionPointRec(mousePoint, quitButtonRect) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON);

        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Dessine le tableau avant le tri avec des paramètres personnalisés
        drawArray(originalArr, n, 50, 300, "Tableau avant le tri", 20, 350);

        // Affiche le bouton "Trier"
        DrawRectangleRec(sortButtonRect, sortButtonClicked ? LIGHTGRAY : LIGHTGRAY);
        DrawText("Trier", sortButtonRect.x + 10, sortButtonRect.y + 10, 20, DARKGRAY);

        // Affiche le bouton "Quitter"
        DrawRectangleRec(quitButtonRect, quitButtonClicked ? LIGHTGRAY : LIGHTGRAY);
        DrawText("Sortir", quitButtonRect.x + 10, quitButtonRect.y + 10, 20, DARKGRAY);

        // Trie le tableau si le bouton "Trier" est cliqué
        if (sortButtonClicked && !isSorted)
        {
            copyArray(originalArr, sortedArr, n);
            quickSort(sortedArr, 0, n - 1);
            isSorted = true; // Met à jour l'indicateur pour éviter la répétition du tri
        }

        // Dessine le tableau après le tri avec des paramètres personnalisés
        if (isSorted)
        {
            drawArray(sortedArr, n, 650, 300, "Tableau apres le tri", 20, 350);
        }

        EndDrawing();

        // Quitte l'application si le bouton "Quitter" est cliqué
        if (quitButtonClicked)
        {
            break;
        }
}
    CloseWindow();
    return 0;
}

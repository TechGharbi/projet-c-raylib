#include <stdio.h>
#include <raylib.h>

// Fonction pour dessiner le tableau
void drawArray(int arr[], int n, int posX, int posY, const char* message, int textSize, int textPosY)
{
    // Dessine le message au-dessous du tableau
    DrawText(message, posX, textPosY, textSize, BLACK);
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
         Color color = (Color){255, i * 255 / n, 0, 255}; //pour les couleurs chaudes
        //Color color = (Color){255 - (i * 255 / n), 0, i * 255 / n, 255};  pour les couleurs froides

         int rectHeight = (int)(((float)arr[i] / maxArrayValue) * 160);

        DrawText(TextFormat("%i", arr[i]), posX + i * (35 + 10), posY - rectHeight - 20, textSize, BLACK);
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
     printf("Entrer la taille du tableau (ne depasse pas 10) : \n");
     do{
        scanf("%d", &n);
         if (n <= 0)
            printf("Erreur. Entrez une valeur positive.\n");
            else
                if(n>10)
                printf("Erreur. Entrer une valeur ne depasse pas 10 \n");
    } while (n <= 0 || n>10);

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
    Rectangle quitButtonRect = { 165, 400, 100, 40 };
    bool quitButtonClicked = false;

    // Ajouter un bouton "REPETER" à la fenêtre
    Rectangle repeatButtonRect = { 280, 400, 100, 40 };
    bool repeatButtonClicked = false;

    bool isSorted = false; // Ajouter un indicateur pour savoir si le tableau est trié

    while (!WindowShouldClose())
    {
        // Mise à jour de la logique des boutons
        Vector2 mousePoint = GetMousePosition();

        sortButtonClicked = CheckCollisionPointRec(mousePoint, sortButtonRect) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON);
        quitButtonClicked = CheckCollisionPointRec(mousePoint, quitButtonRect) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON);
        repeatButtonClicked = CheckCollisionPointRec(mousePoint, repeatButtonRect) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON);

        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Dessine le tableau avant le tri avec des paramètres personnalisés
        drawArray(originalArr, n, 50, 300, "Tableau avant le tri", 20, 350);

        // Affiche le bouton "Trier"
        DrawRectangleRec(sortButtonRect, sortButtonClicked ? LIGHTGRAY : BLUE);
        DrawText("Trier", sortButtonRect.x + 10, sortButtonRect.y + 10, 20, BLACK);

        // Affiche le bouton "Quitter"
        DrawRectangleRec(quitButtonRect, quitButtonClicked ? LIGHTGRAY : RED);
        DrawText("Quitter", quitButtonRect.x + 10, quitButtonRect.y + 10, 20, BLACK);

        // Affiche le bouton "REPETER"
        DrawRectangleRec(repeatButtonRect, repeatButtonClicked ? LIGHTGRAY : GREEN);
        DrawText("REPETER", repeatButtonRect.x + 10, repeatButtonRect.y + 10, 17, BLACK);

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

        // Redonne d'autres éléments pour trier un autre tableau si le bouton "REPETER" est cliqué
        if (repeatButtonClicked)
        {
            // Réinitialiser les tableaux et l'indicateur de tri
            isSorted = false;
            do {
                printf("Entrer la nouvelle taille du tableau : \n");
                scanf("%d", &n);
                if (n <= 0)
                    printf("Erreur. Entrez une valeur positive.\n");
            } while (n <= 0);

            printf("Entrer %d nouveaux elements :\n", n);
            for (int i = 0; i < n; i++)
            {
                printf("Element %d : ", i + 1);
                scanf("%d", &originalArr[i]);
            }
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


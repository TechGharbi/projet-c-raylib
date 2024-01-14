#include <stdio.h>
#include <raylib.h>

#define MAX_ELEMENTS 10

// Structure pour stocker une paire d'élément et de couleur
typedef struct
{
    int value;
    Color color;
} Element;

Color elementColors[MAX_ELEMENTS] = {
 (Color){100, 200, 50, 200},ORANGE, (Color){200, 50, 100, 200}, YELLOW, RED, BLUE, GRAY, (Color){0, 255, 255, 255},GREEN };

void drawArray(Element arr[], int n, int posX, int posY, const char *message, int textSize, int textPosY)
{
    DrawText(message, posX, textPosY, textSize, BLACK);
     const int screenHeight = 450;
    int maxArrayValue = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].value > maxArrayValue)
            maxArrayValue = arr[i].value;
    }

    for (int i = 0; i < n; i++)
    {
    int rectHeight = (int)(((float)arr[i].value / maxArrayValue) * (screenHeight - 200));

        DrawRectangle(posX + i * (60 + 10), posY - rectHeight, 60, rectHeight, arr[i].color);

        char numberText[10];
        sprintf(numberText, "%i", arr[i].value);
        DrawText(numberText, posX + i * (60 + 10) + 20, posY - rectHeight + 5, textSize, BLACK);
    }
}

void moveRectangle(Element arr[], int index1, int index2, int posX, int posY, int* iterationsCounter)
{
    Element temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;

    // Dessine le tableau après chaque échange
    BeginDrawing();
    ClearBackground(RAYWHITE);
    drawArray(arr, MAX_ELEMENTS, posX, posY, "Tableau en cours de tri", 20, posY + 180);
    EndDrawing();

     for (int i = 0; i < 100000000; i++)
    {
        // Attente
    }
}

int partition(Element arr[], int low, int high, int posX, int posY, int* iterationsCounter)
{
    int pivot = arr[high].value;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j].value < pivot)
        {
            i++;
            moveRectangle(arr, i, j, posX, posY, iterationsCounter);
        }
    }

    moveRectangle(arr, i + 1, high, posX, posY, iterationsCounter);

    return i + 1;
}

void quickSort(Element arr[], int low, int high, int posX, int posY)
{
    int iterationsCounter = 0;
    int* pIterationsCounter = &iterationsCounter;

    if (low < high)
    {
        int pi = partition(arr, low, high, posX, posY, pIterationsCounter);

        quickSort(arr, low, pi - 1, posX, posY);
        quickSort(arr, pi + 1, high, posX, posY);
    }
}

// Fonction pour copier un tableau
void copyArray(Element src[], Element dest[], int n)
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
    do
    {
        scanf("%d", &n);
        if (n <= 0)
            printf("Erreur. Entrez une valeur positive.\n");
        else if (n > 10)
            printf("Erreur. Entrez une valeur ne depasse pas 10 \n");
    } while (n <= 0 || n > 10);

    Element originalArr[MAX_ELEMENTS];
    Element sortedArr[MAX_ELEMENTS];

    for (int i = 0; i < n; i++)
    {
        originalArr[i].color = elementColors[i];
        printf("Element %d : ", i + 1);
        scanf("%d", &originalArr[i].value);
    }

    SetTargetFPS(60);
    InitWindow(screenWidth, screenHeight, "Quick Sort Visualization");

    // Ajouter un bouton "Trier" à la fenêtre
    Rectangle sortB_Rect = {50, 400, 100, 40};
    bool sortB_Cl = false;

    // Ajouter un bouton "Quitter" à la fenêtre
    Rectangle quitB_Rect = {165, 400, 100, 40};
    bool quitB_Cl = false;

    // Ajouter un bouton "REPETER" à la fenêtre
    Rectangle repeatB_Rect = {280, 400, 100, 40};
    bool repeatB_Cl = false;

    bool isSorted = false; // Ajouter un indicateur pour savoir si le tableau est trié

    while (!WindowShouldClose())
    {
        // Mise à jour de la logique des boutons
        Vector2 mousePoint = GetMousePosition();

         sortB_Cl = CheckCollisionPointRec(mousePoint, sortB_Rect) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON);
        quitB_Cl = CheckCollisionPointRec(mousePoint, quitB_Rect) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON);
        repeatB_Cl = CheckCollisionPointRec(mousePoint, repeatB_Rect) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON);
        BeginDrawing();

        ClearBackground(RAYWHITE);

        drawArray(originalArr, n, 50, 300, "Tableau avant le tri", 20, 350);

       // Affiche le bouton "Trier"
        DrawRectangleRec(sortB_Rect, sortB_Cl ? LIGHTGRAY : BLUE);
        DrawText("Trier", sortB_Rect.x + 10, sortB_Rect.y + 10, 20, BLACK);

        // Affiche le bouton "Quitter"
        DrawRectangleRec(quitB_Rect, quitB_Cl ? LIGHTGRAY : RED);
        DrawText("Quitter", quitB_Rect.x + 10, quitB_Rect.y + 10, 20, BLACK);

        // Affiche le bouton "REPETER"
        DrawRectangleRec(repeatB_Rect, repeatB_Cl ? LIGHTGRAY : GREEN);
        DrawText("REPETER", repeatB_Rect.x + 10, repeatB_Rect.y + 10, 17, BLACK);

        // Trie le tableau si le bouton "Trier" est cliqué
        if (sortB_Cl && !isSorted)
        {
            copyArray(originalArr, sortedArr, n);
            quickSort(sortedArr, 0, n - 1, 50, 300);
            isSorted = true; // Met à jour l'indicateur pour éviter la répétition du tri
        }

        // Dessine le tableau après le tri avec des paramètres personnalisés
        if (isSorted)
        {
            drawArray(sortedArr, n, 650, 300, "Tableau apres le tri", 20, 350);
        }

        // Redonne d'autres éléments pour trier un autre tableau si le bouton "REPETER" est cliqué
        if (repeatB_Cl)
        {
            // Réinitialiser les tableaux et l'indicateur de tri
            isSorted = false;
            do
            {
                printf("Entrer la nouvelle taille du tableau : \n");
                scanf("%d", &n);
                if (n <= 0)
                    printf("Erreur. Entrez une valeur positive.\n");
            } while (n <= 0);

            printf("Entrer %d nouveaux elements :\n", n);
            for (int i = 0; i < n; i++)
            {
                originalArr[i].color = elementColors[i];
                printf("Element %d : ", i + 1);
                scanf("%d", &originalArr[i].value);
            }
        }

        EndDrawing();

        // Quitte l'application si le bouton "Quitter" est cliqué
        if (quitB_Cl)
        {
            break;
        }
    }

    CloseWindow();
    return 0;
}

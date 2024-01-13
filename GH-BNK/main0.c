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
    MAGENTA, GREEN, YELLOW, RED, BLUE, ORANGE, GRAY, (Color){0, 255, 255, 255}, BLACK, WHITE};

void drawArray(Element arr[], int n, int posX, int posY, const char *message, int textSize, int textPosY)
{
    DrawText(message, posX, textPosY, textSize, BLACK);

    int maxArrayValue = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].value > maxArrayValue)
            maxArrayValue = arr[i].value;
    }

    for (int i = 0; i < n; i++)
    {
        int rectHeight = (int)(((float)arr[i].value / maxArrayValue) * 160);

        DrawRectangle(posX + i * (35 + 10), posY - rectHeight, 35, rectHeight, arr[i].color);

        char numberText[10];
        sprintf(numberText, "%i", arr[i].value);
        DrawText(numberText, posX + i * (35 + 10) + 10, posY - rectHeight + 5, textSize, BLACK);
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
    Rectangle sortButtonRect = {50, 400, 100, 40};
    bool sortButtonClicked = false;

    // Ajouter un bouton "Quitter" à la fenêtre
    Rectangle quitButtonRect = {165, 400, 100, 40};
    bool quitButtonClicked = false;

    // Ajouter un bouton "REPETER" à la fenêtre
    Rectangle repeatButtonRect = {280, 400, 100, 40};
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

        drawArray(originalArr, n, 120, 300, "Tableau avant le tri", 20, 350);

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
            quickSort(sortedArr, 0, n - 1, 150, 300);
            isSorted = true; // Met à jour l'indicateur pour éviter la répétition du tri
        }

        // Dessine le tableau après le tri avec des paramètres personnalisés
        if (isSorted)
        {
            drawArray(sortedArr, n, 600, 300, "Tableau apres le tri", 20, 350);
        }

        // Redonne d'autres éléments pour trier un autre tableau si le bouton "REPETER" est cliqué
        if (repeatButtonClicked)
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
        if (quitButtonClicked)
        {
            break;
        }
    }

    CloseWindow();
    return 0;
}






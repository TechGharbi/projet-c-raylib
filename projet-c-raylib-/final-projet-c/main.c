#include "raylib.h"
void quickSort(int arr[], int low, int high);
void drawArray(int arr[], int n, int posX, int posY, int spacingX);

int main()
{
    const int screenWidth = 1100;
    const int screenHeight = 450;
    int n;
    int sortingDone = 0;

    printf("Entrer la taille du tableau (ne depasse pas 10): \n");
    do
    {
        scanf("%d", &n);
        if (n > 10)
            printf("Entrer une valeur ne depasse pas 10.\n");
    } while (n > 10);

    int sortButtonPosX = 50;
    int exitButtonPosX = 150;
    int againButtonPosX = 250;

    int arr1[n], arr2[n];
    printf("Entrer %d elements ne depassant pas 150\n", n);

    for (int i = 0; i < n; i++)
    {
        do
        {
            printf("Element %d: ", i + 1);
            scanf("%d", &arr1[i]);
            if (arr1[i] > 150)
            {
                printf("Entrer une valeur ne depasse pas 150.\n");
            }
        } while (arr1[i] > 150);
    }

     InitWindow(screenWidth, screenHeight, "Quick Sort Visualization");
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Check for button clicks
        if (CheckCollisionPointRec(GetMousePosition(), (Rectangle){sortButtonPosX, 400, 80, 30}) &&
            IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            // If the "Sort" button is clicked, perform the sorting
            for (int i = 0; i < n; i++)
            {
                arr2[i] = arr1[i];
            }
            quickSort(arr2, 0, n - 1);
            sortingDone = 1; // Set the flag to indicate sorting has been done
        }
        else if (CheckCollisionPointRec(GetMousePosition(), (Rectangle){exitButtonPosX, 400, 80, 30}) &&
                 IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            // If the "Exit" button is clicked, close the window
            break;
        }
        else if (CheckCollisionPointRec(GetMousePosition(), (Rectangle){againButtonPosX, 400, 80, 30}) &&
                 IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            // If the "Again" button is clicked, reset and allow sorting another array
            sortingDone = 0;
            printf("Entrer la taille du tableau (ne depasse pas 10): \n");
            do
            {
                scanf("%d", &n);
                if (n > 10)
                    printf("Entrer une valeur ne depasse pas 10.\n");
            }
            while (n > 10);
            printf("Entrer %d elements ne depassant pas 150\n", n);
            for (int i = 0; i < n; i++)
            {
                do
                {
                    printf("Element %d: ", i + 1);
                    scanf("%d", &arr1[i]);
                    if (arr1[i] > 150)
                    {
                        printf("Entrer une valeur ne depasse pas 150.\n");
                    }
                } while (arr1[i] > 150);
            }
        }

        // Draw the buttons
        DrawRectangle(sortButtonPosX, 400, 80, 35, BLUE);
        DrawText("Trier", sortButtonPosX + 20, 405, 15, BLACK);

        DrawRectangle(exitButtonPosX, 400, 80, 35, GREEN);
        DrawText("Sortir", exitButtonPosX + 20, 405, 15, BLACK);

        DrawRectangle(againButtonPosX, 400, 80, 35, RED);
        DrawText("Encore", againButtonPosX + 20, 405, 15, BLACK);

        // Draw the arrays
        DrawText("Tableau avant le tri rapide", 50, 300, 20, DARKGRAY);
        drawArray(arr1, n, 50, 50, 30);

        if (sortingDone)
        {
            DrawText("Tableau apres le tri rapide", 600, 300, 20, DARKGRAY);
            drawArray(arr2, n, 600, 50, 30);
        }

        EndDrawing();
    }
    CloseWindow();
    return 0;
}

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

void drawArray(int arr[], int n, int posX, int posY, int spacingX)
{
    for (int i = 0; i < n; i++)
    {
        Color color = (Color){255 - (i * 255 / n), 0, i * 255 / n, 255};
        DrawRectangle(posX + i * (20 + spacingX), posY + 200 - arr[i], 35, arr[i], color);
        DrawText(TextFormat("%i", arr[i]), posX + i * (20 + spacingX) + 5, posY + 180 - arr[i], 10, DARKGRAY);
    }
}


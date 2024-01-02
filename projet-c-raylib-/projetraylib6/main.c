/*#include "raylib.h"
#include <stdio.h>

#define MAX_RECTANGLES 200

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


void drawArray(int arr[], int n, int x, int y, const char* label) {
    int j = x;
    for (int i = 0; i < n; i++) {

        char text[10];

        DrawText(text, j + 10, y + 20, 20, BLACK);
        j += 60;
    }
    DrawText(label, x, y - 30, 20, BLACK);
}
int main(void) {
    int j = 100;
    int n;
    int originalTab[MAX_RECTANGLES];
    int sortedTab[MAX_RECTANGLES];

    do {
    printf("Enter the number of elements for the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &originalTab[i]);
        sortedTab[i] = originalTab[i];
    }

    bubbleSort(sortedTab, n); // Sort the array using Bubble Sort

    // Initialize Raylib window
    const int screenWidth = 1000;
    const int screenHeight = 500;

    InitWindow(screenWidth, screenHeight, "Raylib Array Visualization");

    int button1Visible = 1; // Flag to control button 1 visibility
    int rectanglesVisible = 0; // Flag to control rectangles visibility

    // Create two lists to keep track of rectangles for the original and sorted arrays
    Rectangle originalRectangles[MAX_RECTANGLES];
    Rectangle sortedRectangles[MAX_RECTANGLES];
    int originalRectanglesCount = 0;
    int sortedRectanglesCount = 0;
// Add the initial rectangles to the list for the original array
              for (int i = 0; i < n; i++) {
                    originalRectangles[originalRectanglesCount++] = (Rectangle){(float)j, 100, 100, 100};
                    j = j + 150;
                }

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        // Detect mouse button click
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            int mouseX = GetMouseX();
            int mouseY = GetMouseY();


            // Check if the mouse click is inside the first button
            if (button1Visible && CheckCollisionPointRec((Vector2){(float)mouseX, (float)mouseY}, (Rectangle){400, 400, 200, 100})) {
                // Button 1 clicked, handle the click event
                printf("Button 1 clicked!\n");
                button1Visible = 0; // Make button 1 disappear
                rectanglesVisible = 1; // Make rectangles appear



                // Add the initial rectangles to the list for the sorted array
                j = 100; // Reset j for the sorted array
                for (int i = 0; i < n; i++) {
                    sortedRectangles[sortedRectanglesCount++] = (Rectangle){(float)j, 300, 100, 100};
                    j = j + 150;
                }
            } else if (!button1Visible && CheckCollisionPointRec((Vector2){(float)mouseX, (float)mouseY}, (Rectangle){600, 400, 200, 100})) {
                // Button 2 clicked, handle the click event
                printf("Button 2 clicked!\n");
                break; // Quit the program
            }
        }

        // Clear the screen
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw buttons
        if (button1Visible) {
            DrawRectangle(300, 400, 200, 100, GREEN);
            DrawText("commence tri ", 350, 430, 20, WHITE);
        }

        DrawRectangle(600, 400, 200, 100, RED);
        DrawText("Quit", 670, 430, 20, WHITE);

        // Draw each rectangle if rectangles are visible

            for (int i = 0; i < originalRectanglesCount; ++i) {
                // Draw the current rectangle at its position without moving it for the original array
                DrawRectangleRec(originalRectangles[i], DARKPURPLE);

                // Render the text inside the current rectangle for the original array
                char text[10];
                sprintf(text, "%d", originalTab[i]);
                DrawText(text, (int)originalRectangles[i].x + 10, (int)originalRectangles[i].y + 40, 20, WHITE);
            }
            drawArray(originalTab, n, 100, 100, "Initial Array");
     if (rectanglesVisible) {
            for (int i = 0; i < sortedRectanglesCount; ++i) {
                // Draw the current rectangle at its position without moving it for the sorted array
                DrawRectangleRec(sortedRectangles[i], SKYBLUE);

                // Render the text inside the current rectangle for the sorted array
                char text[10];
                sprintf(text, "%d", sortedTab[i]);
                DrawText(text, (int)sortedRectangles[i].x + 10, (int)sortedRectangles[i].y + 40, 20, WHITE);
            }

            drawArray(sortedTab, n, 100, 300, "Sorted Array");
        }

        // End drawing
        EndDrawing();
    }

    CloseWindow();

        printf("Voulez-vous essayer un nouveau tableau ? (Y/N): ");
        char choice;
        scanf(" %c", &choice);

        if (choice != 'Y' && choice != 'y') {
            break;
        }

    } while (1);
    return 0;
}*/


/*
#include "raylib.h"
#include <stdio.h>

#define MAX_RECTANGLES 200

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

void drawArray(int arr[], int n, int x, int y, const char *label) {
    int j = x;
    for (int i = 0; i < n; i++) {
        char text[10];

        DrawText(text, j + 10, y + 20, 20, BLACK);
        j += 60;
    }
    DrawText(label, x, y - 30, 20, BLACK);
}

int main(void) {
    do {
        int j = 100;
        int n;
        int originalTab[MAX_RECTANGLES];
        int sortedTab[MAX_RECTANGLES];

        printf("Enter the number of elements for the array: ");
        scanf("%d", &n);
        printf("Enter the elements of the array\n");

        for (int i = 0; i < n; i++) {
            scanf("%d", &originalTab[i]);
            sortedTab[i] = originalTab[i];
        }

        bubbleSort(sortedTab, n); // Sort the array using Bubble Sort

        // Initialize Raylib window
        const int screenWidth = 1000;
        const int screenHeight = 500;

        InitWindow(screenWidth, screenHeight, "Raylib Array Visualization");

        int button1Visible = 1; // Flag to control button 1 visibility
        int againButtonVisible = 0; // Flag to control "again" button visibility
        int rectanglesVisible = 0; // Flag to control rectangles visibility

        // Create two lists to keep track of rectangles for the original and sorted arrays
        Rectangle originalRectangles[MAX_RECTANGLES];
        Rectangle sortedRectangles[MAX_RECTANGLES];
        int originalRectanglesCount = 0;
        int sortedRectanglesCount = 0;

        do {
            // Add the initial rectangles to the list for the original array
            for (int i = 0; i < n; i++) {
                originalRectangles[originalRectanglesCount++] = (Rectangle){(float)j, 100, 100, 100};
                j = j + 150;
            }

            SetTargetFPS(60);

            while (!WindowShouldClose()) {
                // Detect mouse button click
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    int mouseX = GetMouseX();
                    int mouseY = GetMouseY();

                    // Check if the mouse click is inside the first button
                    if (button1Visible && CheckCollisionPointRec((Vector2){(float)mouseX, (float)mouseY}, (Rectangle){400, 400, 200, 100})) {
                        // Button 1 clicked, handle the click event
                        printf("Button 1 clicked!\n");
                        button1Visible = 0; // Make button 1 disappear
                        againButtonVisible = 1; // Make "again" button appear
                        rectanglesVisible = 1; // Make rectangles appear

                        // Add the initial rectangles to the list for the sorted array
                        j = 100; // Reset j for the sorted array
                        for (int i = 0; i < n; i++) {
                            sortedRectangles[sortedRectanglesCount++] = (Rectangle){(float)j, 300, 100, 100};
                            j = j + 150;
                        }
                    } else if (againButtonVisible && CheckCollisionPointRec((Vector2){(float)mouseX, (float)mouseY}, (Rectangle){600, 400, 200, 100})) {
                        // "Again" button clicked, handle the click event
                        printf("Again button clicked!\n");
                        againButtonVisible = 0; // Make "again" button disappear
                        button1Visible = 1; // Make button 1 appear
                        rectanglesVisible = 0; // Make rectangles disappear
                        originalRectanglesCount = 0; // Reset original rectangles count
                        sortedRectanglesCount = 0; // Reset sorted rectangles count
                        break; // Break out of the inner loop to start again
                    }
                }

                // Clear the screen
                BeginDrawing();
                ClearBackground(RAYWHITE);

                // Draw buttons
                if (button1Visible) {
                    DrawRectangle(400, 400, 200, 100, GREEN);
                    DrawText("Commencer le tri", 410, 430, 20, WHITE);
                }

                if (againButtonVisible) {
                    DrawRectangle(600, 400, 200, 100, BLUE);
                    DrawText("Again", 670, 430, 20, WHITE);
                }

                DrawRectangle(100, 400, 200, 100, RED);
                DrawText("Quit", 170, 430, 20, WHITE);


                // Draw each rectangle if rectangles are visible
                for (int i = 0; i < originalRectanglesCount; ++i) {
                    // Draw the current rectangle at its position without moving it for the original array
                    DrawRectangleRec(originalRectangles[i], DARKPURPLE);

                    // Render the text inside the current rectangle for the original array
                    char text[10];
                    sprintf(text, "%d", originalTab[i]);
                    DrawText(text, (int)originalRectangles[i].x + 10, (int)originalRectangles[i].y + 40, 20, WHITE);
                }
                drawArray(originalTab, n, 100, 100, "Tableau initial");

                if (rectanglesVisible) {
                    for (int i = 0; i < sortedRectanglesCount; ++i) {
                        // Draw the current rectangle at its position without moving it for the sorted array
                        DrawRectangleRec(sortedRectangles[i], SKYBLUE);

                        // Render the text inside the current rectangle for the sorted array
                        char text[10];
                        sprintf(text, "%d", sortedTab[i]);
                        DrawText(text, (int)sortedRectangles[i].x + 10, (int)sortedRectangles[i].y + 40, 20, WHITE);
                    }

                    drawArray(sortedTab, n, 100, 300, "Tableau trié");
                }

                // End drawing
                EndDrawing();
            }

        } while (againButtonVisible);

        CloseWindow();
        printf("Voulez-vous essayer un nouveau tableau ? (Y/N): ");
        char choice;
        scanf(" %c", &choice);

        if (choice != 'Y' && choice != 'y') {
            break;
        }

    } while (1);

    return 0;
}*/
/*
#include "raylib.h"
#include <stdio.h>

#define MAX_RECTANGLES 200

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

void drawArray(int arr[], int n, int x, int y, const char *label) {
    int j = x;
    for (int i = 0; i < n; i++) {
        char text[10];

        DrawText(text, j + 10, y + 20, 20, BLACK);
        j += 60;
    }
    DrawText(label, x, y - 30, 20, BLACK);
}

int main(void) {
    do {
        int j = 100;
        int n;
        int originalTab[MAX_RECTANGLES];
        int sortedTab[MAX_RECTANGLES];

        printf("Enter the number of elements for the array: ");
        scanf("%d", &n);
        printf("Enter the elements of the array\n");

        for (int i = 0; i < n; i++) {
            scanf("%d", &originalTab[i]);
            sortedTab[i] = originalTab[i];
        }

        bubbleSort(sortedTab, n); // Sort the array using Bubble Sort

        // Initialize Raylib window
        const int screenWidth = 1000;
        const int screenHeight = 500;

        InitWindow(screenWidth, screenHeight, "Raylib Array Visualization");

        int button1Visible = 1; // Flag to control button 1 visibility
        int againButtonVisible = 0; // Flag to control "again" button visibility
        int rectanglesVisible = 0; // Flag to control rectangles visibility

        // Create two lists to keep track of rectangles for the original and sorted arrays
        Rectangle originalRectangles[MAX_RECTANGLES];
        Rectangle sortedRectangles[MAX_RECTANGLES];
        int originalRectanglesCount = 0;
        int sortedRectanglesCount = 0;

        do {
            // Add the initial rectangles to the list for the original array
            for (int i = 0; i < n; i++) {
                originalRectangles[originalRectanglesCount++] = (Rectangle){(float)j, 100, 100, 100};
                j = j + 150;
            }

            SetTargetFPS(60);

            while (!WindowShouldClose()) {
                // Detect mouse button click
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    int mouseX = GetMouseX();
                    int mouseY = GetMouseY();

                    // Check if the mouse click is inside the first button
                    if (button1Visible && CheckCollisionPointRec((Vector2){(float)mouseX, (float)mouseY}, (Rectangle){400, 400, 200, 100})) {
                        // Button 1 clicked, handle the click event
                        printf("Button 1 clicked!\n");
                        button1Visible = 0; // Make button 1 disappear
                        againButtonVisible = 1; // Make "again" button appear
                        rectanglesVisible = 1; // Make rectangles appear

                        // Add the initial rectangles to the list for the sorted array
                        j = 100; // Reset j for the sorted array
                        for (int i = 0; i < n; i++) {
                            sortedRectangles[sortedRectanglesCount++] = (Rectangle){(float)j, 300, 100, 100};
                            j = j + 150;
                        }
                    } else if (againButtonVisible && CheckCollisionPointRec((Vector2){(float)mouseX, (float)mouseY}, (Rectangle){600, 400, 200, 100})) {
                        // "Again" button clicked, handle the click event
                        printf("Again button clicked!\n");
                        againButtonVisible = 0; // Make "again" button disappear
                        button1Visible = 1; // Make button 1 appear
                        rectanglesVisible = 0; // Make rectangles disappear
                        originalRectanglesCount = 0; // Reset original rectangles count
                        sortedRectanglesCount = 0; // Reset sorted rectangles count
                        break; // Break out of the inner loop to start again
                    }
                }

                // Clear the screen
                BeginDrawing();
                ClearBackground(RAYWHITE);

                // Draw buttons
                if (button1Visible) {
                    DrawRectangle(400, 400, 200, 100, GREEN);
                    DrawText("Commencer le tri", 410, 430, 20, WHITE);
                }

                if (againButtonVisible) {
                    DrawRectangle(600, 400, 200, 100, BLUE);
                    DrawText("Again", 670, 430, 20, WHITE);
                }

                DrawRectangle(100, 400, 200, 100, RED);
                DrawText("Quit", 170, 430, 20, WHITE);

                // Draw each rectangle if rectangles are visible
                for (int i = 0; i < originalRectanglesCount; ++i) {
                    // Draw the current rectangle at its position without moving it for the original array
                    DrawRectangleRec(originalRectangles[i], DARKPURPLE);

                    // Render the text inside the current rectangle for the original array
                    char text[10];
                    sprintf(text, "%d", originalTab[i]);
                    DrawText(text, (int)originalRectangles[i].x + 10, (int)originalRectangles[i].y + 40, 20, WHITE);
                }
                drawArray(originalTab, n, 100, 100, "Tableau initial");

                if (rectanglesVisible) {
                    for (int i = 0; i < sortedRectanglesCount; ++i) {
                        // Draw the current rectangle at its position without moving it for the sorted array
                        DrawRectangleRec(sortedRectangles[i], SKYBLUE);

                        // Render the text inside the current rectangle for the sorted array
                        char text[10];
                        sprintf(text, "%d", sortedTab[i]);
                        DrawText(text, (int)sortedRectangles[i].x + 10, (int)sortedRectangles[i].y + 40, 20, WHITE);
                    }

                    drawArray(sortedTab, n, 100, 300, "Tableau trié");
                }

                // End drawing
                EndDrawing();
            }

        } while (againButtonVisible);

        CloseWindow();

                printf("Voulez-vous essayer un nouveau tableau ? (Y/N): ");
        char choice;
        scanf(" %c", &choice);

        if (choice != 'Y' && choice != 'y') {
            break;
        }

    } while (1);

    return 0;
}*/

#include "raylib.h"
void quickSort(int arr[], int low, int high);
void drawArray(int arr[], int n, int posX, int posY, int spacingX);
int main()
{
    const int screenWidth = 1100;
    const int screenHeight = 450;
    int n;
    printf("entrer la taille du tableau (ne depasse pas 10): \n");
    do {
        scanf("%d", &n);
        if (n > 10)
            printf("entrer une valeur ne depasse pas 10.\n");
    } while (n > 10);
    int arr1[n], arr2[n];
    printf("Entrer %d elements ne depassant pas 150\n", n);
    for (int i = 0; i < n; i++) {
        do {
            printf("Element %d: ", i + 1);
            scanf("%d", &arr1[i]);
            if (arr1[i] > 150) {
                printf("entrer une valeur ne depasse pas 150.\n");
            }
        } while (arr1[i] > 150);
    }
    InitWindow(screenWidth, screenHeight, "Quick Sort Visualization");
    int sortButtonPosX = 50;
    int exitButtonPosX = 150;
    int sortingDone = 0;
    SetTargetFPS(20);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        // Check for button clicks
        if (CheckCollisionPointRec(GetMousePosition(), (Rectangle){sortButtonPosX, 400, 80, 30}) &&
            IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // If the "Sort" button is clicked, perform the sorting
            for (int i = 0; i < n; i++) {
                arr2[i] = arr1[i];
            }
            quickSort(arr2, 0, n - 1);
            sortingDone = 1; // Set the flag to indicate sorting has been done
        } else if (CheckCollisionPointRec(GetMousePosition(), (Rectangle){exitButtonPosX, 400, 80, 30}) &&
                   IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // If the "Exit" button is clicked, close the window
            break;
        }
        // Draw the buttons
        DrawRectangle(sortButtonPosX, 400, 80, 30, LIGHTGRAY);
        DrawText("trier", sortButtonPosX + 20, 405, 10, DARKGRAY);

        DrawRectangle(exitButtonPosX, 400, 80, 30, LIGHTGRAY);
        DrawText("Sortir", exitButtonPosX + 20, 405, 10, DARKGRAY);

        // Draw the arrays
        DrawText("tableau avant le tri rapide", 50, 300, 20, DARKGRAY);
        drawArray(arr1, n, 50, 50, 30);

        if (sortingDone) {
            DrawText("tableau apres le tri rapide", 600, 300, 20, DARKGRAY);
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



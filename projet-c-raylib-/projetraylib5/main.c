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
    printf ("tableau initial :");
    // Create two lists to keep track of rectangles for the original and sorted arrays
    Rectangle originalRectangles[MAX_RECTANGLES];
    Rectangle sortedRectangles[MAX_RECTANGLES];
    int originalRectanglesCount = 0;
    int sortedRectanglesCount = 0;

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

                // Add the initial rectangles to the list for the original array
                for (int i = 0; i < n; i++) {
                    originalRectangles[originalRectanglesCount++] = (Rectangle){(float)j, 100, 100, 100};
                    j = j + 150;
                }

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
            DrawText("Show ", 400, 430, 20, WHITE);
        }

        DrawRectangle(600, 400, 200, 100, RED);
        DrawText("Quit", 670, 430, 20, WHITE);

        // Draw each rectangle if rectangles are visible
        if (rectanglesVisible) {
            for (int i = 0; i < originalRectanglesCount; ++i) {
                // Draw the current rectangle at its position without moving it for the original array
                DrawRectangleRec(originalRectangles[i], DARKPURPLE);

                // Render the text inside the current rectangle for the original array
                char text[10];
                sprintf(text, "%d", originalTab[i]);
                DrawText(text, (int)originalRectangles[i].x + 10, (int)originalRectangles[i].y + 40, 20, WHITE);
            }

            for (int i = 0; i < sortedRectanglesCount; ++i) {
                // Draw the current rectangle at its position without moving it for the sorted array
                DrawRectangleRec(sortedRectangles[i], SKYBLUE);

                // Render the text inside the current rectangle for the sorted array
                char text[10];
                sprintf(text, "%d", sortedTab[i]);
                DrawText(text, (int)sortedRectangles[i].x + 10, (int)sortedRectangles[i].y + 40, 20, WHITE);
            }
            drawArray(originalTab, n, 100, 100, "Initial Array");
            drawArray(sortedTab, n, 100, 300, "Sorted Array");
        }

        // End drawing
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

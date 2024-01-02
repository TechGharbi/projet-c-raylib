/*#include "raylib.h"

#define MAX_NUMBERS 5

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Enter Two Arrays");

    int leftArray[MAX_NUMBERS] = {0};
    int rightArray[MAX_NUMBERS] = {0};

    Rectangle leftBox = {10, 50, 120, 40};
    Rectangle rightBox = {screenWidth - 130, 50, 120, 40};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Display instructions
        DrawText("Click on each side to increment numbers:", 10, 10, 20, DARKGRAY);

        // Draw input boxes
        DrawRectangleRec(leftBox, LIGHTGRAY);
        DrawRectangleLines(leftBox.x, leftBox.y, leftBox.width, leftBox.height, DARKGRAY);
        DrawRectangleRec(rightBox, LIGHTGRAY);
        DrawRectangleLines(rightBox.x, rightBox.y, rightBox.width, rightBox.height, DARKGRAY);

        // Display left array
        for (int i = 0; i < MAX_NUMBERS; i++)
        {
            DrawText(TextFormat("%d", leftArray[i]), leftBox.x + 20, leftBox.y + 10 + 50 * i, 20, MAROON);
        }

        // Display right array
        for (int i = 0; i < MAX_NUMBERS; i++)
        {
            DrawText(TextFormat("%d", rightArray[i]), rightBox.x + 20, rightBox.y + 10 + 50 * i, 20, MAROON);
        }

        EndDrawing();

        // Check for user input
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            // Check if the mouse click is within the left box
            if (CheckCollisionPointRec(GetMousePosition(), leftBox))
            {
                for (int i = 0; i < MAX_NUMBERS; i++)
                {
                    leftArray[i]++;
                }
            }
            // Check if the mouse click is within the right box
            else if (CheckCollisionPointRec(GetMousePosition(), rightBox))
            {
                for (int i = 0; i < MAX_NUMBERS; i++)
                {
                    rightArray[i]++;
                }
            }
        }
    }

    CloseWindow();

    return 0;
}*/

/*
#include "raylib.h"

#define MAX_NUMBERS 5

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Enter Two Arrays");

    int arrayLeft[MAX_NUMBERS] = {10, 20, 30, 40, 50};
    int arrayRight[MAX_NUMBERS] = {10, 20, 30, 40, 50};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Display instructions
        DrawText("Click to increment numbers", 10, 10, 20, DARKGRAY);

        // Draw arrays
        DrawText("Array Left:", 10, 50, 20, MAROON);
        DrawText("Array Right:", screenWidth / 2 + 10, 50, 20, MAROON);

        // Display numbers in the left array
        for (int i = 0; i < MAX_NUMBERS; i++)
        {
            DrawText(TextFormat("%d", arrayLeft[i]), 10, 80 + i * 30, 20, MAROON);
        }

        // Display numbers in the right array
        for (int i = 0; i < MAX_NUMBERS; i++)
        {
            DrawText(TextFormat("%d", arrayRight[i]), screenWidth / 2 + 10, 80 + i * 30, 20, MAROON);
        }

        EndDrawing();

        // Check for user input
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            // Check if the mouse click is within the left array
            if (CheckCollisionPointRec(GetMousePosition(), (Rectangle){10, 80, 200, MAX_NUMBERS * 30}))
            {
                // Increment the clicked number in the left array
                int index = (GetMouseY() - 80) / 30;
                if (index >= 0 && index < MAX_NUMBERS)
                    arrayLeft[index]++;
            }
            // Check if the mouse click is within the right array
            else if (CheckCollisionPointRec(GetMousePosition(), (Rectangle){screenWidth / 2 + 10, 80, 200, MAX_NUMBERS * 30}))
            {
                // Increment the clicked number in the right array
                int index = (GetMouseY() - 80) / 30;
                if (index >= 0 && index < MAX_NUMBERS)
                    arrayRight[index]++;
            }
        }
    }

    CloseWindow();

    return 0;
}*/

/*
#include "raylib.h"
//3
void quickSort(int arr[], int low, int high);
void drawArray(int arr[], int n, int posX);

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Quick Sort Visualization");

    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr1[n], arr2[n];
    printf("Enter %d elements for the first array:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr1[i]);
    }

    // Copy the first array to the second array
    for (int i = 0; i < n; i++)
    {
        arr2[i] = arr1[i];
    }

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
         DrawText("array apres tri rapid :", 50, 50, 20, DARKGRAY);
        // Draw the first array on the left side
        drawArray(arr1, n, 90);
         DrawText("array avant tri rapid :", 500, 50, 20, DARKGRAY);
        // Draw the second array on the right side
        drawArray(arr2, n, 500);

        // Perform quick sort on the first array
        quickSort(arr1, 0, n - 1);

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

void drawArray(int arr[], int n, int posX)
{
    for (int i = 0; i < n; i++)
    {
        DrawRectangle(posX, 200 - arr[i], 50, arr[i], MAROON);
        DrawText(TextFormat("%i", arr[i]), posX + 15, 210, 10, DARKGRAY);
        posX += 60;
    }
}

*/

#include "raylib.h"

void quickSort(int arr[], int low, int high);
void drawArray(int arr[], int n, int posX);

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Quick Sort Visualization");

    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr1[n], arr2[n];
    printf("Enter %d elements for the first array:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr1[i]);
    }

    // Copy the first array to the second array
    for (int i = 0; i < n; i++)
    {
        arr2[i] = arr1[i];
    }

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("Array apres tri rapid:", 50, 50, 20, DARKGRAY);

        // Draw the first array on the left side
        drawArray(arr1, n, 50);

        DrawText("Array avant tri rapid:", 500, 50, 20, DARKGRAY);
        // Draw the second array on the right side
        drawArray(arr2, n, 500);

        // Perform quick sort on the first array
        quickSort(arr1, 0, n - 1);

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

void drawArray(int arr[], int n, int posX)
{
    for (int i = 0; i < n; i++)
    {
        // Calculate color based on the position in the sorted array
        Color color = (Color){255 - (i * 255 / n), 0, i * 255 / n, 255};

        DrawRectangle(posX, 200 - arr[i], 50, arr[i], color);
        DrawText(TextFormat("%i", arr[i]), posX + 15, 210, 10, DARKGRAY);
        posX += 60;
    }
}


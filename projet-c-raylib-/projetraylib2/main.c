#include "raylib.h"

void quickSort(int arr[], int low, int high);
void drawArray(int arr[], int n, int posX);
//3
int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Quick Sort Visualization");

    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements for the array:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Display the array before quick sort
        BeginDrawing();
        ClearBackground(RAYWHITE);

        drawArray(arr, n, 100);

        EndDrawing();
    }

    quickSort(arr, 0, n - 1); // Perform quick sort

    while (!WindowShouldClose())
    {
        // Display the array after quick sort
        BeginDrawing();
        ClearBackground(RAYWHITE);

        drawArray(arr, n, 100);

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

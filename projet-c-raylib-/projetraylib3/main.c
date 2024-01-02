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


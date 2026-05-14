//Name: Patrick Gemmell
//Course Code: ELN_9217_010
//Porject Name: Assignment2
//Date: 2026-05-12
//Explanation: Take 4 inputs and check if any are the same, if so return an error. Otherwise find the max and return it to the user.
#include <stdio.h>

int main()
{
	// Set the size of array(4), the rest of the code will adjust
    int arr[4];
    // Setting all the variable and size needed for the code
    int hasSame = 0;
    int size = sizeof(arr) / sizeof(arr[0]);
    char input[100];
    int count = 0;
    int pos = 0;
    int charsRead;

	//Ask user for input
    printf("Give me %d numbers separated by spaces: ", size);
    fgets(input, sizeof(input), stdin);

    // Parse numbers from input
    while (sscanf(input + pos, "%d%n", &arr[count], &charsRead) == 1) {
        count++;
        pos += charsRead;

        if (count > size) {
            printf("Error: Too many numbers entered.\n");
            return 1;
        }
    }

    // Check if exact amount entered
    if (count < size) {
        printf("Error: Not enough numbers entered.\n");
        return 1;
    }

    // Check for duplicates
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                hasSame = 1;
            }
        }
    }
	
	// Give user an error if numbers match
    if (hasSame) {
        printf("Two of the numbers are the same, cannot compute\n");
        return 0;
    }

    // Find max
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
	
	// Output the max number from the given input
    printf("The largest number is: %d\n", max);

    return 0;
}

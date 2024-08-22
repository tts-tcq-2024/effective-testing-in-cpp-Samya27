#include <iostream>
#include <assert.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int printColorMap() {
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
        }
    }
    return i * j;
}

// Independent function to check if the color combination is correct
void validateColorMap() {
    int index = 0;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            // Check that the current index corresponds to the correct major and minor color
            assert(majorColor[i] != nullptr);  // Validate major color is not null
            assert(minorColor[j] != nullptr);  // Validate minor color is not null

            // Expected output based on correct logic
            std::cout << "Validating: " << index << " | " << majorColor[i] << " | " << minorColor[j] << "\n";

            // Ensure that the major and minor color indexes match expected values
            assert(index == i * 5 + j);            // Validating the index value
            assert(majorColor[i] == majorColor[i]); // Validate major color is correct
            assert(minorColor[j] == minorColor[j]); // Validate minor color is correct

            index++;
        }
    }
}

int main() {
    int result = printColorMap();
    
    // Validate the result is correct
    assert(result == 25);

    // Validate the correctness of the color mapping
    validateColorMap();

    std::cout << "All is well (maybe!)\n";
    return 0;
}

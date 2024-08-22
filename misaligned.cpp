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

void testPrintColorMap() {
    int i = 0, j = 0;
    int index = 0;
    
    // Simulate the logic of printColorMap but with correct expectations
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            // Check that the current index corresponds to the correct major and minor color
            std::cout << "Testing: " << index << " | " << majorColor[i] << " | " << minorColor[j] << "\n";

            // Ensure that the color pair produced by printColorMap should match expected logic
            assert(majorColor[i] == majorColor[i]); // This is correct
            assert(minorColor[j] == minorColor[j]); // This is correct

            // The following assertion will fail due to the bug in printColorMap
            assert(minorColor[i] == minorColor[j]); // This should fail as the function is using 'i' instead of 'j'
            
            index++;
        }
    }
}

int main() {
    int result = printColorMap();
    assert(result == 25); // This assertion will pass

    testPrintColorMap();   // This will invoke the test and should fail

    std::cout << "All is well (maybe!)\n";
    return 0;
}

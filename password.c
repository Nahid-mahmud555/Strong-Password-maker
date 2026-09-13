#include <stdio.h>

int main() {
    // 1. Informative introductory messages
    printf("This is a password generator tool.\n");
    printf("Please use it if you want your password to be strong.\n\n");
    printf("Here you will enter 6 numbers (0-9) one by one.\n");
    printf("Avoid entering all digits at once.\n\n");

    // 2. The lookup table: Maps 6 positions (rows) and 10 digits (columns) to password fragments
    const char *lookup[6][11] = {
        // Position 1 (number)
        {"#O", "k87*", "yw6r#", "L7?", "Dw2re@", "c[0", "u3^", "$8k", "234fl;", "b%%3", "-/7N"},
        // Position 2 (digit)
        {"#O", "er4k*", "y0#", "L2?", "D1@", "c[6", "u9^", "$k34", "le3;", "x@3@", "f&f6"},
        // Position 3 (fantasy)
        {"#O", "k3w4*", "6y#", "L8?", "D3@", "c8[", "u0^", "$kr8ew", "l2;", "bu7%%", "6fs;"},
        // Position 4 (cyber)
        {"#9O", "k3*", "y9#", "L2?", "D@r8", "c3[", "u4q3^", "$k8s", "l;a5", "b%%4r", "kw(0"},
        // Position 5 (hack)
        {"#23O", "k8*", "y6#", "L3?", "D0@", "c[w3", "u2^", "$6k", "l4;", "b%%q34", "^th9"},
        // Position 6 (attack)
        {"#5O", "ke4*sr", "y9#", "L4?", "6D@", "c[8w", "u0^", "$3q4k", "l;w3", "be3%%", "7&8(-"}
    };

    // Ordinal labels to make the user prompt loop highly readable
    const char *labels[6] = {"1st", "2nd", "3rd", "4th", "5th", "6th"};
    int inputs[6];

    // 3. Sequential input collection loop
    for (int i = 0; i < 6; i++) {
        printf("Type your %s number = ", labels[i]);
        scanf("%d", &inputs[i]);
    }

    // 4. Safe password generation output
    printf("\n\nYour password is: ");
    for (int i = 0; i < 6; i++) {
        int val = inputs[i];
        
        // If the input is outside 0-9, seamlessly fall back to the 11th index (index 10)
        if (val < 0 || val > 9) {
            val = 10; 
        }
        
        printf("%s", lookup[i][val]);
    }
    printf("\n");

    return 0;
}

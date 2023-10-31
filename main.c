#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#include "fp_analyzer.h"


int main(int argc, char * argv[]) {

    Converter input;
    if (argc > 1 && !strcmp(argv[1], "special")) {
        FP_TYPE special_values[] = {1.0 / 0.0, (-1.0 / 0.0), NAN, -NAN};
        
        for (int i = 0; i < (sizeof(special_values) / sizeof(special_values[0])); ++i) {
            input.f = special_values[i];
            print_components(input);
            putchar('\n');
        }
    } else {
        printf("Please enter a floating-point number or q to quit.\n");
        printf("> ");
        while (scanf(INPUT_FORMAT, &input.f)) {
            print_components(input);
            print_reconstitution(input.components);
            printf("> ");
        }
    }
    return EXIT_SUCCESS;

}

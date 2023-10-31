
#include <stdio.h>
#include "fp_analyzer.h"

void print_bits(unsigned INT_TYPE value, int length) {
    for (int shift = length - 1; shift >= 0; --shift) {
        putchar(((value & (ONE << shift)) != 0) + '0');
    }
    putchar('\n');
}

void print_components(Converter input) {

    printf("%f\n", input.f);
    printf("All bits: ");
    print_bits(input.u, sizeof(input.u) * BYTE_SIZE);
    printf("Sign: ");
    print_bits(input.components.sign, SIGN_LENGTH);
    printf("Exponent: ");
    print_bits(input.components.exponent, EXPONENT_LENGTH);
    printf("Mantissa: ");
    print_bits(input.components.mantissa, MANTISSA_LENGTH);
}


void print_reconstitution(Components components) {
    
    if (components.exponent == 0) {
        print_denormalized(components);
    } else {
        print_normalized(components);
    }
}

void print_normalized(Components components) {
    
    printf("Original value:\n");
    int sign = power_of_base(-1, components.sign);
    int exponent = components.exponent - BIAS;
    FP_TYPE mantissa = ((FP_TYPE) components.mantissa) / power_of_base(2, MANTISSA_LENGTH);

    printf("(-1)^{%d} x (1 + %lf) x 2^{%d - %d}\n", components.sign, mantissa, components.exponent, BIAS);
    printf("  = %d x %lf x 2^{%d}\n", sign, 1 + mantissa, exponent);
    if(sign > 0) {
        printf("  = %lf x %d\n", (1 + mantissa), (int) power_of_base(2, exponent));
    } else {
        printf("  = %d x %lf x %d\n", sign, (1 + mantissa), (int) power_of_base(2, exponent));
    }
    printf("  = %.45lf\n", sign * (1 + mantissa) * power_of_base(2, exponent));
}

void print_denormalized(Components components) {
    FP_TYPE mantissa = ((FP_TYPE) components.mantissa) / power_of_base(2, MANTISSA_LENGTH);
    int sign = power_of_base(-1, components.sign);

    if (mantissa  == 0) {
       printf("Original value: ");
       if(sign == -1) {
           printf("%s\n", "-0.0");
       } else {
           printf("%s\n", "0.0");
       }
    } else {
       printf("Original value:\n");
       printf("(-1)^{%d} x %.45lf x 2^{1 - %d}\n", components.sign, mantissa, BIAS);
       printf("  = %d x %lf x 2^{%d}\n", sign, mantissa, 1 - BIAS);
       printf("  = %.45lf x 1/%.0lf\n", sign * mantissa, power_of_base(2, ((1 - BIAS) * - 1)));
       printf("  = %.45lf\n", sign * mantissa * power_of_base(2, 1 - BIAS));
    }
}

FP_TYPE power_of_base(int base, int exponent) {

    FP_TYPE result = 1.0;
    if (exponent < 0) {
    for (int i = 0; i > exponent; --i) {
        result /= base;
    }
    return result;
    } else {
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
    }
}

 




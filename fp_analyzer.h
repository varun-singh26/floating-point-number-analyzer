

#ifdef DOUBLE
#define FP_TYPE double
#define INT_TYPE long
#define EXPONENT_LENGTH 11u
#define ONE 1lu //???
#define INPUT_FORMAT "%lf"
#define INT_FORMAT "%lu"
#else
#define FP_TYPE float
#define INT_TYPE int
#define EXPONENT_LENGTH 8u
#define ONE 1u
#define INPUT_FORMAT "%f"
#define INT_FORMAT "%d"

#endif

#define BYTE_SIZE 8u
#define FP_TYPE_WIDTH (sizeof(FP_TYPE) * BYTE_SIZE)
#define SIGN_LENGTH 1u
#define MANTISSA_LENGTH (FP_TYPE_WIDTH - SIGN_LENGTH - EXPONENT_LENGTH)
#define BIAS ((1u << (EXPONENT_LENGTH - 1u)) - 1u)

typedef struct Components{
    

    unsigned INT_TYPE mantissa: MANTISSA_LENGTH;
    unsigned int exponent: EXPONENT_LENGTH;
    unsigned int sign: SIGN_LENGTH;
} Components;

typedef union Converter {

      FP_TYPE f;
      
      unsigned INT_TYPE u;

      Components components;
} Converter;

void print_bits( unsigned INT_TYPE value, int length);

void print_components(Converter input);

void print_normalized(Components input);

void print_denormalized(Components input);

void print_reconstitution(Components input);

FP_TYPE power_of_base(int base, int exponent);






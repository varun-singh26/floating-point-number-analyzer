<h1> Floating-point number analyzer </h1>

<h2> Purpose: </h2>
<p> The purpose of this program is to return the bitwise representation of floating-type input (either a float or double) entered by the user. </p>

<p> With the returned bitwise representation, the program then demonstrates how the different bits can be broken up and put into the following formula
to calculate the user input and ensure the bitwise representation returned is, indeed, correct. </p>


Normalized form formula (double and float):
  (-1)^S * (1 + M) * 2^(E - BIAS)


Denormalized form formula (double and float):
  (-1)^S * (M) * 2^(1 - BIAS)

  Conditional Compilation (Header File):

  Conditional Compilation is used so we can use the same source code (fp_analyzer.c and main.c) to print the bitwise representation of both
  floats (32 bits) and doubles (64 bits). The conditional is necessary because depending on if we're using floats or doubles, certain symbolic constants
  within the header file will have different values. For example, when using floats the INT_TYPE is of type integer but when using doubles the INT_TYPE is of type long. 
  Similarily, the format specifiers used in printing output differ depending on if we are trying to print the bitwise representation of a float or of a double. 

 Components type:
 
  The bit-wise representation of a floating-point number (float or double) is broken up into 3 groups: sign (S), exponent (E), and mantissa (M).
  In fp_analyzer.c the components type is used to provide easy access to any 3 of these bit fields within the floating-point user input. The Components type has three
  attributes: mantissa which is represented by the lowest 23 (if float) or 52 (if double) bits, exponent which is represented by the following
  8 (if float) or 11 (if double) bits, and sign which is represented by the highest order bit (for both floats and doubles). 

  
  Union type:
  fp_analyzer.c utilizes a union type called Converter. The value for this type is the input provided by the user. 
  A union type can use the the same space in memory to store different data types. Therefor the name "Converter" is used for this union type 
  because the value stored in its memory can be converted to a floating-point number type (float or double), an integer number type (integer or long), or
  a components type (which is defined above).


  Special Cases:
  There exist four special cases of user input: inf (1.0/0.0), -inf (-1.0/0.0), NaN, and -NaN.
  The bit-wise representation of these four special values can be found by entering the argument "special" after the executable:
  <img width="345" alt="image" src="https://github.com/varun-singh26/floating-point-number-analyzer/assets/149445092/d47b49fb-59a4-4ede-90cf-ae8e61eeacd6">

  

  
  
  
  
  
  
  
  
  
  
  
  
  
  This type takes 0000 1010
  0001 0100

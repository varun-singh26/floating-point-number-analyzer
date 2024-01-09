<h1> Floating-point number analyzer </h1>

<h2> Purpose: </h2>
<p> The purpose of this program is to return the bitwise representation of floating-type input (either a float or double) entered by the user. </p>

<p> With the returned bitwise representation, the program then demonstrates how the different bits can be broken up and put into the following formula
to calculate the user input and ensure the bitwise representation returned is, indeed, correct: </p>

<em><math> (-1)<sup>S</sup> * (1 + M) * 2<sup>(E - BIAS)</sup> </math></em>
<strong><p>In the above formula S refers to the sign of the value, M refers to the mantissa, E refers to the raw exponent, and the BIAS is either 127 (if representing float) or 
1023 (if representing double) for our purposes</strong></p>

<p> The bitwise representation of our floating-point type with either require 32 bits (if it's representing a float) or 64 bits (if it's representing a double) </p>
<p> In both cases, the single highest order bit will refer to the sign (S in the formula). Since a singular bit can either be 0 or 1, S determines if our value is positive (0) or negative (1) </p>
<p> In the float case, the next 8 bits refer to the raw exponent, E, to be used in the above formula. In the double case, it's the next 11 bits after the sign bit that refer to E. </p>
<p> In the float case, the remaining 23 bits are used to calculate the mantissa, M, in the above formula. In the double case, it's the remaining 52 bits after the raw exponent bits which are used to calculate M. </p>

<p> Here is a visual example of the bitwise representation of a float (32 bits). Note that significand here is the same thing as mantissa</p>
<img alt="bitwise representation of float" src="~/Desktop/0067-Floating-Point_Representation_Feature_Image.webp"> 

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

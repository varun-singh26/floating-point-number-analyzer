# floating-point-number-analyzer


  floating-point-number-analyzer takes a floating-point user input (float or double) and returns the 
the internal bitwise representation of it. 

  The .h header file of this program utilizes conditional compilation 
when building the executable program. Therefore if the build defintion is DOUBLE, the program will build an exectuable
for input of type double (8 bytes). If not, then the program will build an executable for input of type float (4 bytes).
The .h also contains numerous symbolic constants whose values are set depending on the build definition.



preprocessor directives of the .h header file of this program
implutilizes  This function utilizes a union type, called convert, 
which allows the floating-point input to be stored as a FLOAT_TYPE

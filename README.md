# interp-rt
 Fast (realtime) lookup table interpolation library

# Usage

interp-rt is distributed as a ANSI C source file and header. 

interp-rt requires population of a look-up-table with data, this is accomplished with the lut-generator script.

The lut-generator will take a pandas dataframe of your x-y data and generate a .c/.h file pair that contain the information for a look-up table.

The generator .c/.h file need to be added to your C build. 



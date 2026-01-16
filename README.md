A simple Number generator in c using a fixed string size
useful for generating wordlist of numbers

 It uses 2 paramaters.
   1) The minimum size of str
   2) The maximum size of str (optional)
Will generate a number string from "00" - "99".
compiling (to make the program) use "make"
example usage:
    ./generator 1 2
  will generate two strings one ranging from "0" - "9" and the seccond one from "00" to "99"
    ./generator 2
  will generate one string ranging from "00" to "99"

best used redirecting to a file
./generator > filename
then using it with an external tool such as ffuf

Potential update :
    A full on string generator using any characters of your choosing.

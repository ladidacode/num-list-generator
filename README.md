A simple Number generator in c using a fixed string size
Useful for generating wordlist of numbers

 It uses 2 paramaters.
   1)  The minimum size of the string
   2)  The maximum size of the string (optional)


Example usage:
    
    ./generator 1 2
Will generate two strings of numbers one ranging from "0" to "9" and the seccond one from "00" to "99"
    
    ./generator 2
Will generate one string of numbers ranging from "00" to "99"

Best used redirecting to a file:

    ./generator > filename
Then using it with an external tool such as ffuf

To compile (make the program):

    make


Potential update :
	
1)  Options managed with "-" for example -s for size
2)  A full on string generator using any characters of your choosing. 

easter egg (how it was used) :

	./generator 4 > otp
	

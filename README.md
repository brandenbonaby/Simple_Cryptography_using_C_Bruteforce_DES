# Simple_Cryptography_using_C_Bruteforce_DES

Brute force Program to crack DES password encrytedof passwords 5 characters or less with only uppercase& lower case inputs
Note: program could utilize the FILE function and use a dictionary file to search for the most common passwords/words but I wanted to try a literal character brute force method, so for passwords of 4 characters or less it shouldnt take long at all but most likely 5 characters will need O(n^5) time to crack, lets see how long it takes in human time. This is only for academic purposes to understand how DES hash function worked.


<h2> Usage:</h2>

After you have compiled the program, use ./Simple_Cryptography_BruteForce_DES <DES hash> to execute on the cmdline shell.  

<h2>Sample Output</h2>

**./Simple_Cryptography_BruteForce_DES 50xui9cFjD6YE

**xZts, 50xui9cFjD6YE

<h2> Limitations </h2>

This will only work for passwordds that are 5 or less characters and those characters have to be uppercase or lowercase. Meaning this is only for academic purposes to understand how the function works, it will be pretty useless as no encryption today uses DES or at least they shouldn't be.

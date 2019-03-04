/*
 * Brute force Program to crack DES password encrytedof passwords 5 characters or less with only uppercase& lower case inputs
 * Note: program could utilize the FILE function and use a dictionary file to search for the most
 * common passwords/words but I wanted to try a literal character brute force method, so for passwords of 4 characters or less
 * it shouldnt take long at all but most likely 5 characters will need O(n^5) time to crack, lets see how long
 * it takes in human time. This is only for academic purposes to understand how DES hash function worked
 * */

// including standard libraries and also DES fuunction library
#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define alphalen 53

// take only 2 commandline args, one of them being the DES hash
int main(int argc, char *argv[])
{
    if ( argc >  2 || argc == 1 ){
             printf("Usage: ./crack  \n");   //prompt user with error when 2 args not entered, return 1 error
             return 1;
         }

    if (strlen(argv[1]) != 13){
            printf("Invalid hash, please enter a new hash value\n");
            return 2;
        }

    char *hash = argv[1];   // out argv 1 into a string hash making it easier to reference

    char salt[3] = {hash[0],hash[1],'\0'};

    //making an array of characters using most common letters in english language - from http://letterfrequency.org/
    char g[alphalen] ={'\0','e','E', 't','T','a','A', 'o','O','i','I', 'n','N', 's','S', 'r', 'R','h','H', 'l','L',
    'd','D','c','C', 'u','U', 'm','M', 'f','F', 'p','P', 'g','G','w', 'W', 'y', 'Y', 'b','B', 'v','V','k','K', 'x','X', 'j','J', 'q','Q', 'z', 'Z'};

    //array of 6 that will hashed and compared to inputted hash
    char text[6];



    //for loop that will iterate over 1 -5 character words using 52 as limit for both uppe/lowercase iterations
    for (int f = 0; f < alphalen; f++){

        for (int h = 0; h < alphalen; h++){
                if(f==1 && h==0){
                        h++;
                    }
            for (int i = 0; i < alphalen; i++){
                   if(h==1 && i==0){
                        i++;
                        //sleep(5);
                    }
                for (int k = 0; k < alphalen; k++){
                    if(i==1 && k==0){
                        k++;
                    }
                    //for loop that will start at e and not EOS character
                    for (int j = 0; j < alphalen; j++){

                        text[0] = g[j];
                        text[1] = g[k];
                        text[2] = g[i];
                        text[3] = g[h];
                        text[4] = g[f];
                        text[5] = g[0];

                      //hash text string in this iteration and compare to inputted hash
                        if ( strcmp(hash,(crypt(text,salt))) == 0){
                            //once hash matches inputted hash print out the string and the hash and exit program
                            printf("%s, %s\n", text,(crypt(text,salt)));
                            return 0;}

                    }
                }
            }
        }
}
	//after going through all 1-5 character iterations return error message saying not found
	printf("unable to crack password\n");
	return 0;
}

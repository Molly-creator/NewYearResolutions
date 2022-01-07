// Libraries
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRINGS	10
#define STRING_LENGTH 50
char input[5];
char exit_string[5] = "EXIT";
char keuze;

int main () {
    // start programma
    printf("Community challenge week 1.\n");
    printf("\n                                                ★                                              \n");
    // INBOUWEN MAX CHAR
    printf("Het nieuwe jaar is aangebroken, tijd voor een goed voornemen! Dit programma gaat je helpen om je doel te bereiken.\n");

    //Variabele met onbekend aantal karakters. Met while-loop en getchar() string-karakters opvangen en toewijzen aan variabele. Enter = stop.
    char NYGoal[100] , ch, comments[100];
    int c = 0;
    printf("\nVoer je goede voornemen in: ");
    do
    {
         ch = getchar();
         NYGoal[c]=ch;
         c++;
    }while(ch != '\n');
    c=c-1; // nullbit toevoegen eind.
    NYGoal[c]='\0';

    // Printen in terminal van opgeven goede voornemen.
    printf("Je goede voornemens voor 2022 is: %s \n", NYGoal);
    printf("\n                                                ★★                                              \n");

    // Variabele voor loop en een voor het aantal stappen.
    int i = 0;
    int Steps;
    char strings[MAX_STRINGS][STRING_LENGTH];

    // Opvangen gebruikers invoer en toewijzgen aan variabele Steps
    printf("Om te slagen is het beter om je doel in kleinere stappen te verdelen!\nHoeveel stappen heb je nodig om \'%s\' te bereiken? : ", NYGoal);
    scanf("%d",&Steps);

    printf("Je gaat je doel opdelen in %d stappen.\n", Steps);


   //LATER WEGHALEN: You receive this error because in C language you are not allowed to use initializers with variable length array 

    // For-loop om dynamisch de stappen aan string array.

    for (i = 0; i < Steps; i++) {
		printf("\nStap %d, Vul in wat je voor deze stap gaat doen: ", i + 1);
		getchar(); //uitlezen van string + lege karakter eind.
		scanf("%[^\n]s", strings[i]); // In array van strings zetten. 
	}

    // Printen iedere string in de array met stringgs
     

    // printf("\nJe doel is \'%s\'\nJe stappenplan is:\n", NYGoal);
    printf("\n--------------------------------------------------------------------------------------" );
    printf("\n| DOEL:  %-75.50s |", NYGoal);
    printf("\n--------------------------------------------------------------------------------------\n" );
   
	for(i = 0; i < Steps; i++) 
	{
        printf("| Stap%2d%-2.10s |  %-70.50s |\n",i + 1," ",strings[i]);
	}
    printf("|__________|_________________________________________________________________________|");

  printf("\n                                                ★★★                                               \n");
  
  
  printf("Wil je dit overzicht wegschrijven als txt bestand? (y/n) :");
  getchar();
  scanf("%c", &keuze);
 
  if (keuze == 'y') {

    FILE *f = fopen("./goal.txt", "w"); // openen bestand als write.
    if (f == NULL)
    {
        printf("Error er ging iets mis!\n");
        exit(1);
    }
    // Printen van tabel, lijn voor lijn in txt bestand.
    fprintf(f,"\n--------------------------------------------------------------------------------------" );
    fprintf(f,"\n| DOEL:  %-75.50s |", NYGoal);
    fprintf(f,"\n--------------------------------------------------------------------------------------\n" );
   
	for(i = 0; i < Steps; i++) 
	{
        fprintf(f,"| Stap%2d%-2.10s |  %-70.50s |\n",i + 1," ",strings[i] );
	}
    fprintf(f,"|__________|_________________________________________________________________________|");
    // sluiten bestand
    fclose(f);
  } else {
      printf("\nGa verder met je doelen opstellen\n");
  }

  printf("\n                                               ★★★★                                               \n");
	
  printf("Helaas dit onderdeel is nog niet beschikbaar er wordt nog actief aan gewerkt.");
//   printf("\nOm te evalueren of je op de goede weg bent kun je de stappen tussentijdse comments toevoegen aan voornemen!.\n");


//     struct progress {
//         char *subgoal;
//         char *comments;
//     };

//     while (strcmp(exit_string, input) != 0) {

//         char *input, *keuze;
//         printf("Het programma loopt stap voor stap door de opgegeven subdoelen heen, om te stoppen voer in: \"EXIT\" Ga door (y/n)");
//         scanf("%s", input);

//         // ?? pointers
//         printf("Welkom in het keuze menu, dit zijn je subdoelen:");
//         for (i = 0; i < Steps; i++) {
//            fprintf(" %2d%-2.10s   %-70.50s \n",i + 1," ",strings[i]);
//         }

//         // structuur aanmaken voor ieder van de subdoelen
        
//         switch(Steps) {
//         int nComments;
//         // int i = 0;
//         char comments[MAX_STRINGS][STRING_LENGTH];

//         case 0:
//             struct progress subg1;
//             subg1.subgoal = strings[Steps];
//             fflush(stdin);
//             printf("Hoeveel comments wil je toevoegen aan \'%s\'? : ", strings[Steps]);
//             scanf("%d", &nComments);
//             for (i = 0; i < nComments; i++) {
//            	getchar(); //uitlezen van string + lege karakter eind.
// 		    scanf("%[^\n]s", subg1.comments[i]);
//             }   
//         break;
	
//         case 1:
//             struct progress subg2;
//             subg2.subgoal = strings[Steps];
//             fflush(stdin);
//             printf("Hoeveel comments wil je toevoegen aan \'%s\'? : ", strings[Steps]);
//             scanf("%d", &nComments);
//             for (i = 0; i < nComments; i++) {
//            	getchar(); //uitlezen van string + lege karakter eind.
// 		    scanf("%[^\n]s", subg2.comments[i]);
//             }
//         break;

//         case 2:
//             struct progress subg3;
//             subg3.subgoal = strings[Steps];
//             fflush(stdin);
//             printf("Hoeveel comments wil je toevoegen aan \'%s\'? : ", strings[Steps]);
//             scanf("%d", &nComments);
//             for (i = 0; i < nComments; i++) {
//            	getchar(); //uitlezen van string + lege karakter eind.
// 		    scanf("%[^\n]s", subg3.comments[i]);
//             }
//         break;

//         case 3:
//             struct progress subg4;
//             subg4.subgoal = strings[Steps];
//                fflush(stdin);
//             printf("Hoeveel comments wil je toevoegen aan \'%s\'? : ", strings[Steps]);
//             scanf("%d", &nComments);
//             for (i = 0; i < nComments; i++) {
//            	getchar(); //uitlezen van string + lege karakter eind.
// 		    scanf("%[^\n]s", subg4.comments[i]);
//             }
//         break;

//         case 4:
//             struct progress subg5;
//             subg5.subgoal = strings[Steps];
//             fflush(stdin);
//             printf("Hoeveel comments wil je toevoegen aan \'%s\'? : ", strings[Steps]);
//             scanf("%d", &nComments);
//             for (i = 0; i < nComments; i++) {
//            	getchar(); //uitlezen van string + lege karakter eind.
// 		    scanf("%[^\n]s", subg5.comments[i]);
//             }
//         break; 

//         case 5:
//             struct progress subg6;
//             subg6.subgoal = strings[Steps];
//             fflush(stdin);
//             printf("Hoeveel comments wil je toevoegen aan \'%s\'? : ", strings[Steps]);
//             scanf("%d", &nComments);
//             for (i = 0; i < nComments; i++) {
//            	getchar(); //uitlezen van string + lege karakter eind.
// 		    scanf("%[^\n]s", subg6.comments[i]);
//             }
//         break; 
        
//         case 6:
//             struct progress subg7;
//             subg7.subgoal = strings[Steps];
//             fflush(stdin);
//             printf("Hoeveel comments wil je toevoegen aan \'%s\'? : ", strings[Steps]);
//             scanf("%d", &nComments);
//             for (i = 0; i < nComments; i++) {
//            	getchar(); //uitlezen van string + lege karakter eind.
// 		    scanf("%[^\n]s", subg7.comments[i]);
//             }
//         break; 

//         case 7:
//             struct progress subg8;
//             subg8.subgoal = strings[Steps];
//             fflush(stdin);
//             printf("Hoeveel comments wil je toevoegen aan \'%s\'? : ", strings[Steps]);
//             scanf("%d", &nComments);
//             for (i = 0; i < nComments; i++) {
//            	getchar(); //uitlezen van string + lege karakter eind.
// 		    scanf("%[^\n]s", subg8.comments[i]);
//             }
//         break; 

//         case 8:
//             struct progress subg9;
//             subg9.subgoal = strings[Steps];
//             fflush(stdin);
//             printf("Hoeveel comments wil je toevoegen aan \'%s\'? : ", strings[Steps]);
//             scanf("%d", &nComments);
//             for (i = 0; i < nComments; i++) {
//            	getchar(); //uitlezen van string + lege karakter eind.
// 		    scanf("%[^\n]s", subg9.comments[i]);
//             }
//         break; 
  
//         case 9:
//             struct progress subg10;
//             subg10.subgoal = strings[Steps];
//             fflush(stdin);
//             printf("Hoeveel comments wil je toevoegen aan \'%s\'? : ", strings[Steps]);
//             scanf("%d", &nComments);
//             for (i = 0; i < nComments; i++) {
//            	getchar(); //uitlezen van string + lege karakter eind.
// 		    scanf("%[^\n]s", subg10.comments[i]);
//             }
//         break; 
//         }
    
//     }             

    // Eind programma
    return 0;

}                                

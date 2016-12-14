#include "stdlib.h"
#include "stdio.h"
#include "gestbib.h"
#include "gui.h"

void showHomeScreen()
{
	system("clear");
	printf("\nBonjour et bienvenue dans ce gestionnaire de dictionnaire\n");
	printf("---------------------------------------------------------\n");
  printf("1 - Créer un dictionnaire\n");
  printf("2 - Créer un dictionnaire à partir d'un text\n");
	printf("3 - Utiliser un dictionnaire\n");
	printf("4 - Détruire un dictionnaire\n");
	printf("5 - Sortir du programme\n");
  printf("---------------------------------------------------------\n\n");

	useHomeScreen();
}

void useHomeScreen(){
	HomeScreen command;
	char* title = malloc(sizeof(char) * 50);
	do{
    command = HSnone;
    scanf("%d", &command);
    fseek(stdin,0,SEEK_END);

		if(command == createDico)
		{
			printf("Veuillez rentrez le titre de votre dictionnaire :\n");

      scanf("%s", title);
      fseek(stdin,0,SEEK_END);

			createDictionary(title);
      showHomeScreen();
		}
    if(command == createDicoFromTxt)
    {
      char* text = malloc(sizeof(char) * 64);
      printf("Veuillez rentrez le titre de votre dictionnaire :\n");
      scanf("%s", title);
      fseek(stdin,0,SEEK_END);

      printf("Veuillez rentrez le titre de votre texte\n");
      scanf("%s",text);
      fseek(stdin,0,SEEK_END);

      FILE* file = fopen(text, "r");
      if(file != NULL)
      {
        createDictionaryFromTxt(file ,title);
      }
      else
      {
        printf("Le fichier %s n'existe pas\n", text);
        printf("Veuillez réessayer");
      }
      showHomeScreen();
    }
		else if(command == useDico)
		{
      printf("Veuillez rentrez le nom ou le chemin du dictionnaire :\n");
      fseek(stdin,0,SEEK_END);
      scanf("%s", title);
      if(isADictionary(title) == true) {
		      Dictionary* dico = useDictionary(title);
          showDicoScreen(dico);
      }
      else
      {
          printf("Le dictionnaire %s n'existe pas\n", title);
          showHomeScreen();
      }
		}
		else if(command == destroyDico)
		{
      printf("Veuillez rentrez le titre du dictionnaire à détruire.\n");
      scanf("%s", title);
      fseek(stdin,0,SEEK_END);
      if(isADictionary(title) == true)
      {
        Dictionary* dico = createDictionary(title);
        destroyDictionary(dico);
      }
      else
      {
        printf("Le dictionnaire %s n'existe pas donc il ne peut être détruit", title);
      }
      showHomeScreen();
 		}
    else if(command == exitProg)
    {
      system("exit");
    }
    else
    {
      printf("veuillez choisir une commande existante.\n");
    }
	}while(command > 4 && command < 1);
}

void showDicoScreen(Dictionary* dico)
{
	system("clear");
	printf("\n%s\n",dico->title);
	printf("---------------------------------------------------------\n");
	printf("1 - Ajouter un ou des mots\n");
	printf("2 - Afficher les mots du dictionnaire\n");
	printf("3 - Arrêter d'utiliser ce dictionnaire\n");
  printf("---------------------------------------------------------\n\n");

  useDicoScreen(dico);
}

void useDicoScreen(Dictionary* dico){
  DicoScreen command = DSnone;

  do{
    fseek(stdin,0,SEEK_END);
    scanf("%d", &command);

    if(command == addWords)
    {
      printf("veuillez entrer les mots que vous voulez ajouter :\n");
      insertMultipleWords(dico);

      showDicoScreen(dico);
    }
    else if(command == printDico)
    {
      printDictionary(*dico);
      showDicoScreen(dico);
    }
    else if(command == stopUseDico)
    {
      stopUseDictionnary(dico);
      showHomeScreen();
    }
    else{
      printf("Veuillez entrer une vrai option");
    }
  }while(command > 3 && command < 1);
}

void insertMultipleWords(Dictionary* dico){
  int i = 0;
  int nbrOfWords;
  printf("Combien de mots voulez-vous implémenter ?\n");
  scanf("%d", &nbrOfWords);
  fseek(stdin,0,SEEK_END);

  char** words = malloc(sizeof(char*) * nbrOfWords);
  do{
    printf("mot numéro %d : ", i + 1);
    words[i] = malloc(sizeof(char) * 64);
    fseek(stdin,0,SEEK_END);
    scanf("%s",words[i]);
    i++;
  }while(i < nbrOfWords);

  writeDictionary(dico, words, nbrOfWords);
  printf("Fin de saisie.\n");
}

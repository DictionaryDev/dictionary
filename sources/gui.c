#include "stdlib.h"
#include "gestbib.h"
#include "gui.h"

void showHomeScreen()
{
	system("clear");
	printf("\nBonjour et bienvenue dans ce gestionnaire de dictionnaire\n");
	printf("---------------------------------------------------------\n");
	printf("1	-	Créer un dictionnaire\n");
	printf("2	-	Utiliser un dictionnaire\n");
	printf("3 - Détruire un dictionnaire\n");
	printf("4 - Sortir du programme\n");
	useHomeScreen();
}

void useHomeScreen(){
	HomeScreen command = HSnone;
	char* title = malloc(sizeof(char) * 50);
	do{
    scanf("%d\n", &command);

		if(command == createDico)
		{
			printf("veuillez rentrez le titre de votre dictionnaire :\n");
      scanf("%s\n", title);
      //vider le buffer
			createDictionary(title);
		}
		else if(command == useDico)
		{
      printf("veuillez rentrez le titre de votre dictionnaire :\n");
      scanf("%s\n", title);
			Dictionary* dico = useDictionary(title);
			showDicoScreen(dico);
		}
		else if(command == destroyDico)
		{
      printf("veuillez rentrez le titre de votre dictionnaire :\n");
      scanf("%s\n", title);
      Dictionary* dico = createDictionary(title);
      destroyDictionary(dico);
      //doYouWantToSuprimScreen()*/
		}
    else if(command == exitProg)
    {
      //printf("Êtes vous sur de vouloir le supprimer?(oui/non)");
      system("exit");
    }
	}while(command > 4 && command < 1);
}

void showDicoScreen(Dictionary* dico)
{
	system("clear");
	printf("\n%s\n",dico->title);
	printf("---------------------------------------------------------\n");
	printf("1 - Ajouter un ou des mots\n");
	printf("2 - Ajouter les mots d'un texte\n");
	printf("3 - Afficher les mots du dictionnaire\n");
	printf("4 - Arrêter d'utiliser ce dictionnaire\n");
}

void useDicoScreen(Dictionary* dico)
{
  DicoScreen command = DSnone;
  do{
    scanf("%d\n", &command);

    if(command == addWords)
    {
      printf("veuillez rentrez le titre de votre dictionnaire :\n");
      //vider le buffer
    }
    else if(command == addTexte)
    {
      printf("veuillez rentrez le titre de votre dictionnaire :\n");
      showDicoScreen(dico);
    }
    else if(command == printDico)
    {
      printf("veuillez rentrez le titre de votre dictionnaire :\n");
      //printf("Êtes vous sur de vouloir le supprimer?(oui/non)");
      //doYouWantToSuprimScreen()*/
    }
    else if(command == stopUseDico)
    {

    }
  }while(command > 4 && command < 1);
}

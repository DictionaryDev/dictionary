 typedef enum HomeScreen{
  HSnone = 0,
  createDico = 1,
  createDicoFromTxt = 2,
  useDico = 3,
  destroyDico = 4,
  exitProg = 5
} HomeScreen;

typedef enum DicoScreen{
  DSnone = 0,
  addWords = 1,
  printDico = 2,
  stopUseDico = 3,
} DicoScreen;

/* show the Home screen*/
void showHomeScreen();
/* contain the command of the Home Screen*/
void useHomeScreen();

/*show the screen of the dictionnary currently used*/
void showDicoScreen(Dictionary* dico);
/*use the command in the current dictionnary*/
void useDicoScreen(Dictionary* dico);

/* A function to insert word in a clearier way */
void insertMultipleWords(Dictionary* dico);

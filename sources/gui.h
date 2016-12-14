 typedef enum HomeScreen{
  HSnone = 0,
  createDico = 1,
  useDico = 2,
  destroyDico = 3,
  exitProg = 4
} HomeScreen;

typedef enum DicoScreen{
  DSnone = 0,
  addWords = 1,
  addTexte = 2,
  printDico = 3,
  stopUseDico = 4,
} DicoScreen;

void showHomeScreen();
void showDicoScreen(Dictionary* dico);
void useHomeScreen();
void useDicoScreen(Dictionary* dico);

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

void showHomeScreen();
void useHomeScreen();

void showDicoScreen(Dictionary* dico);
void useDicoScreen(Dictionary* dico);

void insertMultipleWords(Dictionary* dico);

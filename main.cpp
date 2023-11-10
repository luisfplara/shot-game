#include <QApplication>
#include "game.h"
Game * game; // variavel global, que pode ser acessada
//por todos os arquivos do projeto
int main(int argc, char *argv[])
{
 QApplication a(argc, argv);
 // criar novo jogo
 game = new Game();
 game->show();
 return a.exec();
}

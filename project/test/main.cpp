/* barname ba run shodan az inja aghaz mishavad va tavasot objecti az class menu
 * menu farakhani mishavad va be namayesh dar miayad
*/

#include "menu.h"
#include "mainwindow.h"
#include "playlist.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    menu me;
    me.show();
    return a.exec();
}

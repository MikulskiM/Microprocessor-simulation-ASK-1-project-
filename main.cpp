/*
 * WYBRANE PRZERWANIA:
 *  00H
 *  2AH
 *  2CH
 *  0GH = reset dysku (zeruj rejestry i programy)
 *  41H = kasuj plik (kasuj plik programu zapisanego)   - remove("file.txt")
 *  56H = zmień nazwę pliku (z zapisem programu)        - rename(oldname, newname)
 *  47H = pobierz aktualny katalog / directory          - getcwd(buff, Filename)
 *  48H = alokuj blok pamięci                           - <list> push_front(string)
 *  49H = zwolnij zaalokowane bloki pamięci             - <list> clear()
 *  4AH = modyfikuj zaalokowane bloki pamięci           - for(size): list[i] = "new content"
 */

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

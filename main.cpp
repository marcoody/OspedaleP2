
#include <QMessageBox>


int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QueuePersone utenti;
    Responsabile* r = new Responsabile("ciao", "ciao", "ciao","ciao");

    utenti.push_back(r->clone());

    bool relogin = false;
    Main_dialog* mw = new Main_dialog(utenti,r, relogin);
    mw->show();
    app.exec();

    return 0;
}

#include "MODEL/header/queuepersone.h"
#include "MODEL/header/persona.h"
#include "GUI/header/login.h"
//#include "GUI/header/main_dialog.h"

#include <QApplication>
#include <QMessageBox>


int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QueuePersone listaUtenti;

    if(!listaUtenti.importXml())
    {
        listaUtenti.defaultData();
        //listaUtenti.exportXml();
        QMessageBox info;
        info.setText("Nessun utente trovato o dati errati, ricreate le impostazioni di default, consultare il manuale per ulteriori info.");
        info.setWindowTitle("Errore di apertura del file utenti");
        info.setWindowIcon(QIcon(QPixmap(":/IMG/warning")));
        info.exec();
    }

    //listaUtenti.push_back(new Medico("dio", "cane", "porco", "schifoso", Data(), gender::maschio));
/*
    QString* result = new QString();
    QXmlStreamWriter out(result);
    listaUtenti.exportXmlData(out);
    QFile output("dioporco.xml");
    output.open(QIODevice::WriteOnly);
    output.write(result->toStdString().c_str(), result->length());
    output.close();
*/
    Persona* loginUser=0;
    Login* login = new Login(listaUtenti, &loginUser);

    bool exit=false;
    while(!exit)
    {
        loginUser=0;
        login->clean();
        login->exec();
        if(loginUser==0)
            exit=true;
        else
        {
            bool relogin=false;
            //Main_dialog md(listaUtenti, loginUser, relogin);
            //md.setWindowModality(Qt::ApplicationModal);
            //md.show();
            app.exec();;
            if(!relogin)
                exit=true;
        }
    }
    return 0;
}

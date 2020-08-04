#include "../header/main_widget.h"

Main_widget::Main_widget(QueuePersone& _utenti, Persona* utenteAttuale, QWidget* parent): QWidget(parent), utenti(_utenti), chiamante(utenteAttuale){
    grid= new QGridLayout();
    setLayout(grid);

    if(chiamante->isResponsabile()){
        addButt = new QPushButton("Aggiungi un utente");
        grid->addWidget(addButt,4,0);

        editButt = new QPushButton("Modifica utente");
        grid->addWidget(editButt,5,0);

        deleteButt = new QPushButton("Elimina utente");
        grid->addWidget(deleteButt,6,0);

        connect(elenco, SIGNAL(itemSelectionChanged()), this, SLOT(refreshDelete()));
        connect(deleteButt, SIGNAL(clicked()), this, SLOT(deleteSelected()));
        connect(addButt, SIGNAL(clicked()), this, SLOT(addPersona()));
        connect(editButt, SIGNAL(clicked()), this, SLOT(editPersona()));
    }

    //lista utenti e info
    elenco = new QListWidget();
    grid->addWidget(elenco,0,0);

    infoView = new QScrollArea;
    info = new QLabel();
    infoView->setWidget(info);
    info->setText("Nessun utente selezionato.");
    info->setFixedWidth(178);
    info->setWordWrap(true);

    infoView->setFixedWidth(200);
    infoView->setFixedHeight(200);
    grid->addWidget(infoView,0,1,7,1);

    //bottoni
    sortName = new QPushButton("Riordina per cognome");
    grid->addWidget(sortName, 1,0);
    stipendioButt = new QPushButton("Calcola stipendio");
    grid->addWidget(stipendioButt,2,0);
    turnoButt = new QPushButton("Visualizza/Modifica turni");
    grid->addWidget(turnoButt, 3, 0);


    connect(elenco, SIGNAL(itemSelectionChanged()), this, SLOT(showInfoPersona()));
    connect(elenco, SIGNAL(itemSelectionChanged()), this, SLOT(refreshStipendio()));
    connect(elenco, SIGNAL(itemSelectionChanged()), this, SLOT(refreshTurno()));
    connect(stipendioButt, SIGNAL(clicked()), this, SLOT(calculateStipendio()));
    connect(sortName, SIGNAL(clicked()), this, SLOT(sortByName()));
    //connect(turnoButt, SIGNAL(clicked()), this, SLOT(editTurno()));
    //connect(elenco, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(editTurno()));

    createSearch();

    //carico gli utenti nell'elenco
    refreshElenco();

}

void Main_widget::refreshElenco(){
    elenco->clear();
    for(QueuePersone::const_iterator it=utenti.begin(); it!=utenti.end(); ++it ){
        QListWidgetItem * row = new QListWidgetItem;
        row->setText(QString::fromStdString((*it)->getCognome() + " " + (*it)->getNome()));
        elenco->addItem(row);
    }

    //se un file è selez ne mostra le info
    showInfoPersona();
    emit filtra();
}

void Main_widget::createSearch(){

    cercaLabel = new QLabel("Cerca:");
    cercaLabel->setMaximumHeight(18);
    cercaLabel->setMinimumHeight(18);
    grid->addWidget(cercaLabel,7,1);
    search = new QLineEdit();
    grid->addWidget(search,8,1);
    radioLayout = new QHBoxLayout();
    radioMedico = new QRadioButton("Medico");
    radioInfermiere = new QRadioButton("Infermiere");
    radioResponsabile = new QRadioButton("Responsabile");
    radioTutti = new QRadioButton("Tutti");
    radioTutti->setChecked(true);
    radioLayout->addSpacing(8);
    radioLayout->addWidget(radioMedico);
    radioLayout->addWidget(radioInfermiere);
    radioLayout->addWidget(radioResponsabile);
    radioLayout->addWidget(radioTutti);
    grid->addLayout(radioLayout,9,1);

    connect(search, SIGNAL(textEdited(const QString&)), this, SLOT(filtra()));
    connect(radioMedico, SIGNAL(clicked()), this, SLOT(filtra()));
    connect(radioInfermiere, SIGNAL(clicked()), this, SLOT(filtra()));
    connect(radioResponsabile, SIGNAL(clicked()), this, SLOT(filtra()));
    connect(radioTutti, SIGNAL(clicked()), this, SLOT(filtra()));
}

void Main_widget::refreshInfo(){
    info->setText(QString::fromStdString(utenti[elenco->currentRow()]->infoPersona()));
    info->adjustSize();
}

void Main_widget::showInfoPersona(){
    if(elenco->currentRow() >=0){
        refreshInfo();
    }
}

void Main_widget::refreshDelete(){
    if(chiamante->getUsername()== utenti[elenco->currentRow()]->getUsername()){
        deleteButt->setDisabled(true);
    }
    else { deleteButt->setDisabled(false); }
}

void Main_widget::refreshStipendio(){
    bool prop = (utenti[elenco->currentRow()]->getUsername() == chiamante->getUsername());
    //se selez è  responsabile, disabilito bottone
    if(utenti[elenco->currentRow()]->isResponsabile()){
        stipendioButt->setDisabled(true);
    }
    //se selez non è responabile
    //&&
    //chiamante è responsabile oppure proprietario ha accesso allo stipendio
    else if(chiamante->isResponsabile() || prop){
        stipendioButt->setDisabled(false);
    }
    //se chiamante non è nè responabile nè proprietario
    else { stipendioButt->setDisabled(true); }
}

void Main_widget::refreshTurno(){
    //no per responsabili selezionati
    if(utenti[elenco->currentRow()]->isResponsabile()){
        turnoButt->setDisabled(true);
    }
    else{ turnoButt->setDisabled(false); }
}

void Main_widget::editPersona()
{
    int posTemp = elenco->currentRow();
    Persona* p = utenti[elenco->currentRow()];
    //chiama la modifica
    AEPersona* aep = new AEPersona(utenti, p);
    int ris = aep->exec();
    if(ris == QDialog::Accepted)
    {
        utenti.exportXml();
        elenco->item(elenco->currentRow())->setText(QString::fromStdString(p->getCognome() + " " + p->getNome()));
        emit changeStatus("Modifiche apportate con successo");
        refreshInfo();
    }
    else
        emit changeStatus("Modifiche ignorate");
    elenco->setCurrentRow(posTemp);
}

//void Main_widget::editTurno()
//{
//    int posTemp = elenco->currentRow();
//    Persona* p = utenti[elenco->currentRow()];
//    //chiama la modifica
//    ETurno* et = new ETurno(p);
//    int ris = et->exec();
//    if(ris == QDialog::Accepted)
//    {
//        utenti.exportXml();
//        emit changeStatus("Modifiche apportate con successo");

//    }
//    else
//        emit changeStatus("Modifiche ignorate");
//    elenco->setCurrentRow(posTemp);
//}





void Main_widget::addPersona()
{
    int posTemp = elenco->currentRow();
    QStringList listaImpieghi;
    listaImpieghi << "Medico";
    listaImpieghi << "Infermiere";
    listaImpieghi << "Responsabile";

    QInputDialog* inputDialog;
    inputDialog = new QInputDialog();
    bool accettato = false;
    QString impiego = inputDialog->getItem(this, QString("Selezione tipo di utente"), QString("Tipo di utente che si vuole creare:"), listaImpieghi, 0, true, &accettato);
    if(accettato)
    {
        Persona* p= UserBuilder::build(impiego);

        if(p!=nullptr)
        {
            //chiama la modifica
            AEPersona* aep = new AEPersona(utenti, p);
            aep->exec();
            //ricontrollo nuovamente che i dati siano sufficenti e implicitamente controllo anche se è stato accettato
            if(p->getUsername()!="" && p->getNome()!="" && p->getCognome()!=""){
                utenti.push_back(p->clone());
                utenti.exportXml();
                elenco->addItem(new QListWidgetItem(QString::fromStdString(p->getCognome() + " " + p->getNome())));
                elenco->setCurrentRow(elenco->count()-1);
                emit changeStatus("Utente aggiunto con successo");
            }
            else
            {
                elenco->setCurrentRow(posTemp);
                emit changeStatus("Utente non inserito");
            }
        }
        else
        {
            //nel caso sia inserito un tipo non presente nella lista
            QMessageBox msgErr;
            msgErr.setWindowTitle("Errore!");
            msgErr.setText("L'impiego inserito è invalido.");
            msgErr.setWindowIcon(QIcon(QPixmap(":/error")));
            msgErr.exec();
            elenco->setCurrentRow(posTemp);
            emit changeStatus("Errore durante la creazione dell'utente");
        }

    }
    else
        emit changeStatus("Utente non inserito");
}


void Main_widget::deleteSelected()
{
    int ok = QMessageBox::question(this, "Elimina", "Sei sicuro di voler cancellare l'utente "+ elenco->currentItem()->text()+"?", "Si", "No");
    //clicca sì
    if (ok == 0)
    {
        utenti.erase(utenti.indexToIter(elenco->currentRow()));
        elenco->takeItem(elenco->currentIndex().row());
        utenti.exportXml();
        clearSelection();
        emit changeStatus("File eliminato con successo");
    }
}

void Main_widget::calculateStipendio(){
    QMessageBox msg;
    msg.setWindowIcon(QIcon(QPixmap(":/info")));
    msg.setWindowTitle("Calcolo stipendio settimanale");
    msg.setText("Lo stipendio settimanale dell'utente selezionato è: " + QString::number((utenti[elenco->currentRow()])->stipendio(),'f',2)+" Gbyte");
    msg.exec();
}

void Main_widget::filtra(){
    int c=0;
    Qt::CaseSensitivity sens = Qt::CaseSensitive;
    for(QueuePersone::iterator i=utenti.begin(); i!=utenti.end(); (++i,++c) ){
        //controlla corrispondenza nome o cognome
        bool check = (QString::fromStdString((*i)->getNome())).indexOf(search->text(), 0, sens) != -1 || (QString::fromStdString((*i)->getCognome())).indexOf(search->text(), 0, sens) != -1;

        if(radioMedico->isChecked()) {
            if(check && dynamic_cast<Medico*>(*i))
                //se e medico e c'è il match nel nome non nascondere riga
                elenco->setRowHidden(c, false);
            else
                //altrimneti nascondila
                elenco->setRowHidden(c, true);
        }

        if(radioInfermiere->isChecked()){
            if(check && dynamic_cast<Infermiere*>(*i))
                elenco->setRowHidden(c, false);
            else
                elenco->setRowHidden(c, true);
        }

        if(radioResponsabile->isChecked()){
            if(check && dynamic_cast<Responsabile*>(*i))
                elenco->setRowHidden(c, false);
            else
                elenco->setRowHidden(c, true);
        }

        if(radioTutti->isChecked()){
            if(check)
                elenco->setRowHidden(c, false);
            else
                elenco->setRowHidden(c, true);
        }
    }
}

void Main_widget::clearSelection()
{
    elenco->clearSelection();
    deleteButt->setDisabled(true);
    editButt->setDisabled(true);
    turnoButt->setDisabled(true);
    stipendioButt->setDisabled(true);
    info->setText("Nessun oggetto selezionato.");
    info->adjustSize();
}

void Main_widget::sortByName(){
    utenti.sortByName();
    emit changeStatus("Ordianto in ordine alfabetico per cognome");
    utenti.exportXml();
    refreshElenco();
    clearSelection();
}




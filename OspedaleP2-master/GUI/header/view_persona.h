#ifndef VIEW_PERSONA_H
#define VIEW_PERSONA_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QFormLayout>
#include <QMessageBox>
#include <QLineEdit>
#include <QDateEdit>
#include <QComboBox>
#include <string>
#include <QString>

#include "../../MODEL/header/persona.h"
#include "../../MODEL/header/queuepersone.h"

class view_persona : public QWidget{
    Q_OBJECT
public:
    view_persona(QueuePersone& lista, Persona* persona, bool ed = false, QWidget* parent = nullptr): QWidget(parent), mod(ed), utenti(lista), p(persona) {};
    void buildGUI();
    virtual ~view_persona();

private:
    void buildButt();
    bool mod; //booleano di modifica
protected:
    virtual bool check() const; //controlla validità dati inseriti
    virtual void edit() const; //modifica campi e converte da QString a tipi corretti
    virtual void build_field(); //costruire i campi per l'ggetto (no bottoni)

    QueuePersone& utenti;
    Persona* p;
    QFormLayout* layout;
    QPushButton* annullaButt;
    QPushButton* okButt;

    QLineEdit* username;
    QLineEdit* password;
    QLineEdit* nome;
    QLineEdit* cognome;
    QDateEdit* dataNascita;
    QComboBox* genere;

public slots:
    void checkAndEdit();
    void rejectedits();

signals:
    //per AEPersona
    void reject();
    void accept();




};

#endif // VIEW_PERSONA_H

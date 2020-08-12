#ifndef AEPERSONA_H
#define AEPERSONA_H
#include <QFormLayout>
#include <QDialog>
#include <QIcon>
#include <QLabel>

#include "../../MODEL/header/persona.h"
#include "../../GUI/header/view_persona.h"
#include "../../MODEL/header/userbuilder.h"
#include "view_userbuilder.h"

class AEPersona: public QDialog{
    Q_OBJECT
public:
    AEPersona(QueuePersone& persone, Persona* toEdit, QWidget* parent=0);
private:
    QueuePersone& utenti;
    Persona* p;
    QFormLayout* layout;
};

#endif // AEPERSONA_H

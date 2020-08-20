#ifndef ETURNO_H
#define ETURNO_H
#include <QFormLayout>
#include <QDialog>
#include <QIcon>
#include <QLabel>

#include "../../MODEL/header/turno.h"
#include "../../GUI/header/view_turno.h"
#include "../../GUI/header/view_userbuilder.h"

class ETurno : public QDialog{
    Q_OBJECT
public:
    ETurno(Turno* toEdit, QWidget* parent = 0);
private:
    Turno* t;
    QFormLayout* layout;

};

#endif // ETURNO_H

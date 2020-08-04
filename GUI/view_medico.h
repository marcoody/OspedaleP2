#ifndef VIEW_MEDICO_H
#define VIEW_MEDICO_H
#include <QWidget>
#include <QLineEdit>
#include <QComboBox>

#include "../../MODEL/header/persona.h"
#include "../../MODEL/header/medico.h"
#include "../../MODEL/header/queuepersone.h"

#include "view_persona.h"

class view_medico : public view_persona{

public:
    view_medico(QueuePersone& lista, Persona* persona, QWidget* parent = nullptr): view_persona(lista,persona, parent){}
    virtual ~view_medico();

protected:
    virtual void edit() const;
    virtual void build_field();

private:
    QLineEdit* reparto;
    QComboBox* chirurgia;


};

#endif // VIEW_MEDICO_H

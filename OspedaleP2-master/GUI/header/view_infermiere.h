#ifndef VIEW_INFERMIERE_H
#define VIEW_INFERMIERE_H

#include "../../MODEL/header/persona.h"
#include "../../MODEL/header/infermiere.h"
#include "../../MODEL/header/queuepersone.h"
#include <QWidget>

#include "view_persona.h"

class view_infermiere : public view_persona {
public:
    view_infermiere(QueuePersone& lista, Persona* persona, QWidget* parent = nullptr): view_persona(lista,persona,parent){}
    virtual ~view_infermiere();
protected:
    virtual void edit() const;
    virtual void build_field();
};

#endif // VIEW_INFERMIERE_H

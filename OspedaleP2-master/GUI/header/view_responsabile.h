#ifndef VIEW_RESPONSABILE_H
#define VIEW_RESPONSABILE_H
#include "../../MODEL/header/persona.h"
#include "../../MODEL/header/responsabile.h"
#include "../../MODEL/header/queuepersone.h"
#include <QWidget>

#include "view_persona.h"

class view_responsabile : public view_persona {
public:
    view_responsabile(QueuePersone& lista, Persona* persona,  bool ed = false, QWidget* parent = nullptr): view_persona(lista,persona,ed, parent){};
    virtual ~view_responsabile();
protected:
    virtual void edit() const;
    virtual void build_field();
};

#endif // VIEW_RESPONSABILE_H

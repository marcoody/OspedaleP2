#ifndef VIEW_TURNO_LIBERO_H
#define VIEW_TURNO_LIBERO_H
#include <QWidget>
#include <QComboBox>

#include "../../MODEL/header/turno.h"
#include "../../MODEL/header/turno_libero.h"

#include "view_turno.h"

class view_turno_libero : public virtual view_turno {
public:
    view_turno_libero(Turno* turno, QWidget* parent = nullptr): view_turno(turno, parent){}
    virtual ~view_turno_libero();
protected:
    virtual void edit() const;
    virtual void build_field();
private:
    QComboBox* permesso;
};

#endif // VIEW_TURNO_LIBERO_H

#ifndef VIEW_TURNO_INTERO_H
#define VIEW_TURNO_INTERO_H
#include <QLineEdit>
#include <QWidget>

#include "../../MODEL/header/turno.h"
#include "../../MODEL/header/turno_intero.h"

#include "view_turno_regolare.h"

class view_turno_intero : public view_turno_regolare{
public:
    view_turno_intero(Turno* turno,QWidget* parent = nullptr): view_turno(turno,parent), view_turno_regolare(turno, parent){}
    virtual ~view_turno_intero();

protected:
    virtual bool check() const;
    virtual void edit() const;
    virtual void build_field();
private:
    QLineEdit* paga_intero;

};

#endif // VIEW_TURNO_INTERO_H

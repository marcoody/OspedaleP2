#ifndef VIEW_TURNO_REGOLARE_H
#define VIEW_TURNO_REGOLARE_H
#include <QWidget>
#include <QLineEdit>
#include <string>

#include "../../MODEL/header/turno.h"
#include "../../MODEL/header/turno_regolare.h"

#include "view_turno.h"

class view_turno_regolare : public virtual view_turno{
public:
    view_turno_regolare(Turno* turno,QWidget* parent = nullptr): view_turno(turno, parent){}
    virtual ~view_turno_regolare();
protected:
    virtual void edit() const;
    virtual void build_field();
private:
    QLineEdit* reparto;
};

#endif // VIEW_TURNO_REGOLARE_H

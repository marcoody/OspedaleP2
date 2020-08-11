#ifndef VIEW_TURNO_PARZIALE_H
#define VIEW_TURNO_PARZIALE_H
#include <QLineEdit>
#include <QWidget>

#include "../../MODEL/header/turno.h"
#include "../../MODEL/header/turno_parziale.h"

#include "view_turno_regolare.h"

class view_turno_parziale :public view_turno_regolare{
public:
    view_turno_parziale(Turno* turno,QWidget* parent = nullptr): view_turno(turno,parent), view_turno_regolare(turno, parent){}
    virtual ~view_turno_parziale();

protected:
    virtual bool check() const;
    virtual void edit() const;
    virtual void build_field();
private:
    QLineEdit* paga_parziale;
};

#endif // VIEW_TURNO_PARZIALE_H

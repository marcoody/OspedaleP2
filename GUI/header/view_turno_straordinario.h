#ifndef VIEW_TURNO_STRAORDINARIO_H
#define VIEW_TURNO_STRAORDINARIO_H
#include <QWidget>
#include <QLineEdit>
#include <QComboBox>

#include "../../MODEL/header/turno.h"
#include "../../MODEL/header/turno_straordinario.h"

#include "view_turno_regolare.h"
#include "view_turno_libero.h"

class view_turno_straordinario: public view_turno_regolare, public view_turno_libero{
public:
    view_turno_straordinario(Turno* turno,QWidget* parent = nullptr): view_turno(turno,parent), view_turno_regolare(turno, parent), view_turno_libero(turno,parent){}
    virtual ~view_turno_straordinario();

protected:
    virtual bool check() const;
    virtual void edit() const;
    virtual void build_field();
private:
    QLineEdit* paga_straordinario;
    QComboBox* volontariato;
};

#endif // VIEW_TURNO_STRAORDINARIO_H

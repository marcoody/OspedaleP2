#ifndef VIEW_TURNO_H
#define VIEW_TURNO_H
#include <QWidget>
#include <QFormLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QMessageBox>
#include <QLabel>
#include "../../MODEL/header/turno.h"

class view_turno: public QWidget{
    Q_OBJECT
public:
    view_turno(Turno* turno, QWidget* parent = nullptr): QWidget(parent), t(turno){}
    void buildGUI();
    virtual ~view_turno();

private:
    void buildButt();

protected:
    virtual bool check() const;
    virtual void edit() const;
    virtual void build_field();

    Turno* t;
    QFormLayout* layout;
    QPushButton* annullaButt;
    QPushButton* okButt;
    QSpinBox* nOre;

public slots:
    void checkAndEdit();
    void rejectedits();

signals:
    //per AEPersona
    void reject();
    void accept();


};
#endif // VIEW_TURNO_H



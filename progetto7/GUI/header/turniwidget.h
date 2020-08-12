#ifndef TURNIWIDGET_H
#define TURNIWIDGET_H
#include <QPushButton>
#include <QWidget>
#include <QHBoxLayout>
#include <QInputDialog>
#include "../../MODEL/header/userbuilder.h"
#include "../../MODEL/header/persona.h"

class Main_widget;

class turniWidget: public QWidget{

friend class Main_widget;
public:
    turniWidget(QWidget* = 0);
    void refreshButtons(Persona*);
    void disableButt();
    void enableButt();

private:
    QHBoxLayout* layout;
    QPushButton* lunButt;
    QPushButton* marButt;
    QPushButton* merButt;
    QPushButton* gioButt;
    QPushButton* venButt;
    QPushButton* sabButt;
    QPushButton* domButt;

};

#endif // TURNIWIDGET_H

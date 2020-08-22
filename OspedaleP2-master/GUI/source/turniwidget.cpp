#include "../header/turniwidget.h"
#include "../../MODEL/header/metodifreq.h"

turniWidget::turniWidget(QWidget* parent): QWidget(parent){

    layout = new QHBoxLayout();
    setLayout(layout);

    lunButt = new QPushButton();
    lunButt->setFixedSize(110,100);

    marButt = new QPushButton();
    marButt->setFixedSize(110,100);

    merButt = new QPushButton();
    merButt->setFixedSize(110,100);

    gioButt = new QPushButton();
    gioButt->setFixedSize(110,100);

    venButt = new QPushButton();
    venButt->setFixedSize(110,100);

    sabButt = new QPushButton();
    sabButt->setFixedSize(110,100);

    domButt = new QPushButton();
    domButt->setFixedSize(110,100);

    layout->addWidget(lunButt);
    layout->addWidget(marButt);
    layout->addWidget(merButt);
    layout->addWidget(gioButt);
    layout->addWidget(venButt);
    layout->addWidget(sabButt);
    layout->addWidget(domButt);


}

void turniWidget::refreshButtons(Persona* p){
    QueueTurni c=p->getTurni();

    const std::string oreLunedi = std::to_string(c[0]->TotOre());
    const auto lun = oreLunedi.find(".");

    const std::string oreMartedi = std::to_string(c[1]->TotOre());
    const auto mar = oreMartedi.find(".");

    const std::string oreMercoledi = std::to_string(c[2]->TotOre());
    const auto mer = oreMercoledi.find(".");

    const std::string oreGiovedi = std::to_string(c[3]->TotOre());
    const auto gio = oreGiovedi.find(".");

    const std::string oreVenerdi = std::to_string(c[4]->TotOre());
    const auto ven = oreVenerdi.find(".");

    const std::string oreSabato = std::to_string(c[5]->TotOre());
    const auto sab = oreSabato.find(".");


    const std::string oreDomenica = std::to_string(c[6]->TotOre());
    const auto dom = oreDomenica.find(".");

    lunButt->setText(QString::fromStdString("LUNEDÌ\n"+ oreLunedi.substr(0, lun+5)+ " ore\n" + "Inizio alle: " + (c[0]->getInizio().toString("hh:mm")).toStdString() + "\n" + "Fine alle: " + (c[0]->getFine().toString("hh:mm")).toStdString()));
    marButt->setText(QString::fromStdString("MARTEDÌ\n"+ oreMartedi.substr(0, mar+5) + " ore\n" + "Inizio alle: " + (c[1]->getInizio().toString("hh:mm")).toStdString() + "\n" + "Fine alle: " + (c[1]->getFine().toString("hh:mm")).toStdString()));
    merButt->setText(QString::fromStdString("MERCOLEDÌ\n"+ oreMercoledi.substr(0, mer+5) + " ore\n" + "Inizio alle: " + (c[2]->getInizio().toString("hh:mm")).toStdString() + "\n" + "Fine alle: " + (c[2]->getFine().toString("hh:mm")).toStdString()));
    gioButt->setText(QString::fromStdString("GIOVEDÌ\n"+ oreGiovedi.substr(0, gio+5) + " ore\n" + "Inizio alle: " + (c[3]->getInizio().toString("hh:mm")).toStdString() + "\n" + "Fine alle: " + (c[3]->getFine().toString("hh:mm")).toStdString()));
    venButt->setText(QString::fromStdString("VENERDÌ\n"+ oreVenerdi.substr(0, ven+5) + " ore\n" + "Inizio alle: " + (c[4]->getInizio().toString("hh:mm")).toStdString() + "\n" + "Fine alle: " + (c[4]->getFine().toString("hh:mm")).toStdString()));
    sabButt->setText(QString::fromStdString("SABATO\n"+ oreSabato.substr(0, sab+5) + " ore\n" + "Inizio alle: " + (c[5]->getInizio().toString("hh:mm")).toStdString() + "\n" + "Fine alle: " + (c[5]->getFine().toString("hh:mm")).toStdString()));
    domButt->setText(QString::fromStdString("DOMENICA\n"+ oreDomenica.substr(0, dom+5) + " ore\n" + "Inizio alle: " + (c[6]->getInizio().toString("hh:mm")).toStdString() + "\n" + "Fine alle: " + (c[6]->getFine().toString("hh:mm")).toStdString()));


    QPalette pal0 = lunButt->palette();
    pal0.setColor(QPalette::Button, QColor(p->getTurni()[0]->getColor().getR(), p->getTurni()[0]->getColor().getG(), p->getTurni()[0]->getColor().getB() ));
    lunButt->setAutoFillBackground(true);
    lunButt->setPalette(pal0);

    QPalette pal1 = marButt->palette();
    pal1.setColor(QPalette::Button, QColor(p->getTurni()[1]->getColor().getR(), p->getTurni()[1]->getColor().getG(), p->getTurni()[1]->getColor().getB() ));
    marButt->setAutoFillBackground(true);
    marButt->setPalette(pal1);

    QPalette pal2 = merButt->palette();
    pal2.setColor(QPalette::Button, QColor(p->getTurni()[2]->getColor().getR(), p->getTurni()[2]->getColor().getG(), p->getTurni()[2]->getColor().getB() ));
    merButt->setAutoFillBackground(true);
    merButt->setPalette(pal2);

    QPalette pal3 = gioButt->palette();
    pal3.setColor(QPalette::Button, QColor(p->getTurni()[3]->getColor().getR(), p->getTurni()[3]->getColor().getG(), p->getTurni()[3]->getColor().getB() ));
    gioButt->setAutoFillBackground(true);
    gioButt->setPalette(pal3);

    QPalette pal4 = venButt->palette();
    pal4.setColor(QPalette::Button, QColor(p->getTurni()[4]->getColor().getR(), p->getTurni()[4]->getColor().getG(), p->getTurni()[4]->getColor().getB() ));
    venButt->setAutoFillBackground(true);
    venButt->setPalette(pal4);

    QPalette pal5 = sabButt->palette();
    pal5.setColor(QPalette::Button, QColor(p->getTurni()[5]->getColor().getR(), p->getTurni()[5]->getColor().getG(), p->getTurni()[5]->getColor().getB() ));
    sabButt->setAutoFillBackground(true);
    sabButt->setPalette(pal5);

    QPalette pal6 = domButt->palette();
    pal6.setColor(QPalette::Button, QColor(p->getTurni()[6]->getColor().getR(), p->getTurni()[6]->getColor().getG(), p->getTurni()[6]->getColor().getB() ));
    domButt->setAutoFillBackground(true);
    domButt->setPalette(pal6);


}

void turniWidget::disableButt(){
    lunButt->setDisabled(true);
    marButt->setDisabled(true);
    merButt->setDisabled(true);
    gioButt->setDisabled(true);
    venButt->setDisabled(true);
    sabButt->setDisabled(true);
    domButt->setDisabled(true);
}

void turniWidget::enableButt(){
    lunButt->setDisabled(false);
    marButt->setDisabled(false);
    merButt->setDisabled(false);
    gioButt->setDisabled(false);
    venButt->setDisabled(false);
    sabButt->setDisabled(false);
    domButt->setDisabled(false);
}


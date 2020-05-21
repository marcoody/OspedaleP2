#include "mywidget.h"
#include "boxpaziente.h"


#include <QMenuBar>
#include <QMenu>
#include <QPushButton>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);
    firstLayout= new QHBoxLayout();
    ButtonLayout = new QVBoxLayout(this);

    Box1 = new QGroupBox(this);
    Box2 = new QGroupBox(this);
    Box3 = new QGroupBox(this);
    Box4 = new QGroupBox(this);





    Box1->setTitle("Box1");
    Box2->setTitle("Box2");
    Box3->setTitle("Box3");
    Box4->setTitle("Box4");



    numero= new QLabel(Box1);
    num= new QLineEdit(Box1);
    data= new QLabel(Box1);;
    dataD= new QDateEdit(Box1);

    ID= new QGroupBox(this);
    layout= new QHBoxLayout(this);

    numero->setText("No");
    data->setText("Data");

    layout->addWidget(numero);
    layout->addWidget(num);
    layout->addWidget(data);
    layout->addWidget(dataD);
    ID->setLayout(layout);


    Box1->setLayout(layout);



    Box1->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    Box2->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    Box3->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    Box4->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);


    //Aggiungi il menu
    addMenu();

    //aggiungere bottoni
    addBotton();

    // Imposto lo stile

    setStyle();

    //Aggiungi i layout
    mainLayout->addLayout(firstLayout);
    firstLayout->addLayout(ButtonLayout);
    firstLayout->addWidget(Box1);
    firstLayout->addWidget(Box2);
    firstLayout->addWidget(Box3);
    firstLayout->addWidget(Box4);
    setLayout(mainLayout);

    Box2->hide();
    Box3->hide();
    Box4->hide();
}

MyWidget::~MyWidget()
{

}

void MyWidget::changeBox1()
{

    Box2->hide();
    Box3->hide();
    Box4->hide();

    Box1->show();
}

void MyWidget::changeBox2()
{
    Box1->hide();
    Box3->hide();
    Box4->hide();

    Box2->show();
}

void MyWidget::changeBox3()
{
    Box2->hide();
    Box1->hide();
    Box4->hide();

    Box3->show();
}

void MyWidget::changeBox4()
{
    Box2->hide();
    Box3->hide();
    Box1->hide();

    Box4->show();
}

void MyWidget::addBotton()
{

        QPushButton* buttON1= new QPushButton(this);
        QPushButton* buttON2= new QPushButton(this);
        QPushButton* buttON3= new QPushButton(this);
        QPushButton* buttON4= new QPushButton(this);
        buttON1->setText("Registrazione Paziente");
        buttON2->setText("Informazione Paziente");
        buttON3->setText("Gestione Personale");
        buttON4->setText("Gestione camere");
        // inserisco i bottoni
        ButtonLayout->addWidget(buttON1);
        ButtonLayout->addWidget(buttON2);
        ButtonLayout->addWidget(buttON3);
        ButtonLayout->addWidget(buttON4);


    ButtonLayout->addStretch();

    connect(buttON1, SIGNAL(clicked()),this, SLOT(changeBox1()));
    connect(buttON2, SIGNAL(clicked()),this, SLOT(changeBox2()));
    connect(buttON3, SIGNAL(clicked()),this, SLOT(changeBox3()));
    connect(buttON4, SIGNAL(clicked()),this, SLOT(changeBox4()));
}

void MyWidget::addMenu()
{
    //creo la barra del menu, poi il menu, infine le azioni
    QMenuBar* menubar= new QMenuBar(this);
    QMenu* menu = new QMenu("File",menubar);
    QMenu* menu2 = new QMenu("Tool",menubar);

    QAction* newFile= new QAction("New File",menu);
    QAction* openFile= new QAction("Open File",menu);
    QAction* exit= new QAction("Exit",menu);


    connect(exit,SIGNAL(triggered()),this, SLOT(close()));


    menu->addAction(newFile);
    menu->addAction(openFile);
    menu->addAction(exit);

    menubar->addMenu(menu);
    menubar->addMenu(menu2);

    mainLayout->addWidget(menubar);

}

void MyWidget::setStyle()
{

    // Imposto le dimensioni
    ButtonLayout->setSpacing(10);
    setMinimumSize(QSize(600,400));
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
}


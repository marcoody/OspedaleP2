#include "mywidget.h"
#include <QtWidgets>



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


    createBox1();
    /*
    createBox2();
    createBox3();
    createBox4();

*/






    Box1->setTitle("Registra Paziente");
    Box2->setTitle("Box2");
    Box3->setTitle("Box3");
    Box4->setTitle("Box4");

/*

    numero= new QLabel(Box1);
    num= new QLineEdit(Box1);
    data= new QLabel(Box1);;
    dataD= new QDateEdit(Box1);

    ID= new QGroupBox(this);
    layout= new QGridLayout(this);

    numero->setText("No");
    data->setText("Data");

    layout->addWidget(numero,0,0);
    layout->addWidget(num,0,1);
    layout->addWidget(data,1,0);
    layout->addWidget(dataD,1,1);
    ID->setLayout(layout);


    Box1->setLayout(layout);
*/






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

void MyWidget::createBox1()
{
    createIDPaziente();
    createGridGroupBox();
    createFormGroupBox();

    bigEditor = new QTextEdit;
    bigEditor->setPlainText(tr("This widget takes up all the remaining space "
                               "in the top-level layout."));

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                     | QDialogButtonBox::Cancel);

    //connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    //connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
//! [1]

//! [2]
    QVBoxLayout *LayoutBox1 = new QVBoxLayout;
//! [2] //! [3]

//! [3] //! [4]
    LayoutBox1->addWidget(IDPaziente);
    LayoutBox1->addWidget(gridGroupBox);
    LayoutBox1->addWidget(formGroupBox);
    LayoutBox1->addWidget(bigEditor);
    LayoutBox1->addWidget(buttonBox);
//! [4] //! [5]

    Box1->setLayout(LayoutBox1);
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



void MyWidget::createIDPaziente()
{
    IDPaziente = new QGroupBox(tr("ID Paziente"));
    QGridLayout *layout = new QGridLayout;

    numero= new QLabel("No",IDPaziente);
    num= new QLineEdit(IDPaziente);
    data= new QLabel("Data",IDPaziente);;
    dataD= new QDateEdit(IDPaziente);

    layout->addWidget(numero,0,0);
    layout->addWidget(num,0,1);
    layout->addWidget(data,1,0);
    layout->addWidget(dataD,1,1);

    IDPaziente->setLayout(layout);
}

void MyWidget::createGridGroupBox()
{
    gridGroupBox = new QGroupBox(tr("Informazione Paziente"));
//! [8]
    QGridLayout *layout = new QGridLayout;

//! [9]
    for (int i = 0; i < NumGridRows; ++i) {
        labels[i] = new QLabel(tr("Line %1:").arg(i + 1));
        lineEdits[i] = new QLineEdit;
        layout->addWidget(labels[i], i + 1, 0);
        layout->addWidget(lineEdits[i], i + 1, 1);
    }
    labels[0]->setText("Nome:");
    labels[1]->setText("Cognome:");
    labels[2]->setText("Data Nascita:");
    labels[3]->setText("INdirizzo:");
    labels[4]->setText("N° Telefono:");

    QRadioButton* Maschio= new QRadioButton("Maschio",gridGroupBox);
    QRadioButton* Femmina= new QRadioButton("Femmina",gridGroupBox);
    Maschio->setChecked(true);
    QLabel* genere= new QLabel("Genere:",gridGroupBox);
    layout->addWidget(genere,1,2);
    layout->addWidget(Maschio,2,2);
    layout->addWidget(Femmina,2,3);

    gridGroupBox->setLayout(layout);
}

void MyWidget::createFormGroupBox()
{
    formGroupBox = new QGroupBox(tr("Form layout"));
    QFormLayout *layout = new QFormLayout;
    layout->addRow(new QLabel(tr("Line 1:")), new QLineEdit);
    layout->addRow(new QLabel(tr("Line 2, long text:")), new QComboBox);
    layout->addRow(new QLabel(tr("Line 3:")), new QSpinBox);
    formGroupBox->setLayout(layout);
}


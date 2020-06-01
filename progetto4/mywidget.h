#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>

#include <QLabel>
#include <QDateEdit>
#include <QLineEdit>
#include <QDialog>

QT_BEGIN_NAMESPACE
class QAction;
class QDialogButtonBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QMenu;
class QMenuBar;
class QPushButton;
class QTextEdit;
QT_END_NAMESPACE


class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();
public slots:
    void changeBox1();
    void changeBox2();
    void changeBox3();
    void changeBox4();

private:
    QVBoxLayout* mainLayout;
    QHBoxLayout* firstLayout;
    QVBoxLayout* ButtonLayout;
    QGroupBox* Box1;
    QGroupBox* Box2;
    QGroupBox* Box3;
    QGroupBox* Box4;




    QGroupBox* ID;
    QGridLayout* layout;

    void createBox1();
    void createBox2();
    void createBox3();
    void createBox4();

    void addBotton();
    void addMenu();
    void setStyle();

    //prova dei box

    enum { NumGridRows = 5, NumButtons = 4 };

    QGroupBox *IDPaziente;
    QGroupBox *gridGroupBox;
    QGroupBox *formGroupBox;
    QTextEdit *smallEditor;
    QTextEdit *bigEditor;
    QLabel *labels[NumGridRows];
    QLineEdit *lineEdits[NumGridRows];
    QPushButton *buttons[NumButtons];
    QDialogButtonBox *buttonBox;

    QLabel* numero;
    QLineEdit* num;
    QLabel* data;
    QDateEdit* dataD;


    void createIDPaziente();
    void createGridGroupBox();
    void createFormGroupBox();



};
#endif // MYWIDGET_H

#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>

#include <QLabel>
#include <QDateEdit>
#include <QLineEdit>




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


    QLabel* numero;
    QLineEdit* num;
    QLabel* data;
    QDateEdit* dataD;

    QGroupBox* ID;
    QHBoxLayout* layout;


    void addBotton();
    void addMenu();
    void setStyle();

};
#endif // MYWIDGET_H

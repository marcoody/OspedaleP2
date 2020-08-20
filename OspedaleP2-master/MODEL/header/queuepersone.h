#ifndef QUEUEPERSONE_H
#define QUEUEPERSONE_H
#include <string>
#include <QString>
#include <QFile>
#include <QXmlStreamWriter>
#include "persona.h"
#include "medico.h"
#include "infermiere.h"
#include "responsabile.h"
#include "queue.h"
using std::string;


template class Queue<Persona*>;
class QueuePersone : public Queue<Persona*>{
private:
    static QString startTag;
    static QString defaultFile;
    QString getStartTagXml() const;
    QString getDefaultFile() const;
public:
    QueuePersone(): Queue() {};

    Persona* search(string username) const;
    bool search(const Persona*) const;
    static bool checkPassword(const Persona* p, string pw);
    void changePassword(Persona*, string);
    void exportXml();
    bool importXml();

    void defaultData();
    u_int nPersoneQueue() const;
    void sortByName();
};

#endif // QUEUEPERSONE_H

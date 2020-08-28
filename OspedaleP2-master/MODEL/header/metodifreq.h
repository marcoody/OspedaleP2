#ifndef METODIFREQ_H
#define METODIFREQ_H
#include <string>
#include <QXmlStreamReader>
#include <QString>

void importTagXml(QXmlStreamReader &, const std::string, std::string&);
class errore_tag {};
class err_data_nonvalida{};
class err_stringa_nonvalida{};
#endif // METODIFREQ_H

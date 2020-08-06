QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    MODEL/source/data.cpp \
    MODEL/source/persona.cpp \
    MODEL/source/medico.cpp \
    MODEL/source/infermiere.cpp \
    MODEL/source/responsabile.cpp \
    MODEL/source/turno.cpp \
    MODEL/source/metodifreq.cpp \
    MODEL/source/colore.cpp \
    MODEL/source/turno_libero.cpp \
    MODEL/source/turno_regolare.cpp \
    MODEL/source/turno_intero.cpp \
    MODEL/source/turno_parziale.cpp \
    MODEL/source/turno_straordinario.cpp \
    MODEL/source/queueturni.cpp \
    MODEL/source/queuepersone.cpp \
    MODEL/source/userbuilder.cpp \
    GUI/source/login.cpp \
    GUI/source/main_widget.cpp \
    GUI/source/aepersona.cpp \
    GUI/source/view_persona.cpp \
    GUI/source/view_userbuilder.cpp \
    GUI/source/view_medico.cpp \
    GUI/source/view_infermiere.cpp \
    GUI/source/view_responsabile.cpp \
    GUI/source/main_dialog.cpp \
    GUI/source/status_bar.cpp \


HEADERS += \
    MODEL/header/data.h \
    MODEL/header/persona.h \
    MODEL/header/queue.h \
    MODEL/header/medico.h \
    MODEL/header/infermiere.h \
    MODEL/header/queueturni.h \
    MODEL/header/responsabile.h \
    MODEL/header/turno.h \
    MODEL/header/metodifreq.h \
    MODEL/header/colore.h \
    MODEL/header/turno_libero.h \
    MODEL/header/turno_regolare.h \
    MODEL/header/turno_intero.h \
    MODEL/header/turno_parziale.h \
    MODEL/header/turno_straordinario.h \
    MODEL/header/queuepersone.h \
    MODEL/header/userbuilder.h \
    GUI/header/login.h \
    GUI/header/main_widget.h \
    GUI/header/aepersona.h \
    GUI/header/view_persona.h \
    GUI/header/view_userbuilder.h \
    GUI/header/view_medico.h \
    GUI/header/view_infermiere.h \
    GUI/header/view_responsabile.h \
    GUI/header/main_dialog.h \
    GUI/header/status_bar.h \


FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc

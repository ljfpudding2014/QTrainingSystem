QT      += core gui
QT      += sql


TARGET = QTrainingSystem
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
		Custtitledlg.cpp \
		StudentInfoDialog.cpp\
		UserLogin.cpp

HEADERS  += mainwindow.h \
		Custtitledlg.h \
		StudentInfoDialog.h\
		UserLogin.h


# FORMS    += UserLogin.ui \
#  mainwindow.ui \
#    StudentInput.ui

RESOURCES += \
    QTrainingSystem.qrc
	
UI_DIR += uic
RCC_DIR += tmp
MOC_DIR += tmp


DESTDIR +=	E:/QT4.8BuildDir/bin

TRANSLATIONS += QTrainingSystem_CN.ts \
				QTrainingSystem_EN.ts
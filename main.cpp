
#include <QtCore/QVariant>
#include <QtGui/QApplication>
#include <QMessageBox>
#include <Qtsql/QSqlDatabase>
#include <Qtsql/QSqlError>
#include <Qtsql/QSqlQuery>
#include <QMotifStyle>
#include <QFile>
#include <QIODevice>
#include <QTranslator>

//需要设置中文格式 QTextCodec
#include <QTextCodec>

#include "MainWindow.h"

int main(int argc, char *argv[])
{

   QApplication a(argc, argv);

   //解决代码中的中文问题
   //QTextCodec::codecForName("UTF-8");
   QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));

   QApplication::setStyle("macintosh");
   
   QFile styleSheet(":/qss/QTraningSystem.qss"); 
   
	if (!styleSheet.open(QIODevice::ReadOnly))  
	{  
		qWarning("Can't open the style sheet file.");  
		return 0;  
	}  
	a.setStyleSheet(styleSheet.readAll());
	
	QTranslator translator_zh;  
	translator_zh.load(QString(":/qm/QTrainingSystem_CN"));  
	a.installTranslator(&translator_zh);  
   
    MainWindow w;    
    w.show();
	
	QApplication::connect(&a, SIGNAL(lastWindowClose()), &a, SLOT(quit()));
	
    return a.exec();	
}

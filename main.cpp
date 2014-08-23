
#include <QtCore/QVariant>
#include <QtGui/QApplication>
#include <QMessageBox>
#include <Qtsql/QSqlDatabase>
#include <Qtsql/QSqlError>
#include <Qtsql/QSqlQuery>
#include <QMotifStyle>

//��Ҫ�������ĸ�ʽ QTextCodec
#include <QTextCodec>

#include "MainWindow.h"

int main(int argc, char *argv[])
{

   QApplication a(argc, argv);

   //��������е���������
   //QTextCodec::codecForName("UTF-8");
   QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));

   QApplication::setStyle("macintosh");
   
    MainWindow w;    
    w.show();
	
	QApplication::connect(&a, SIGNAL(lastWindowClose()), &a, SLOT(quit()));
	
    return a.exec();	
}

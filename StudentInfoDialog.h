
#ifndef _H_CREATESTUDENT
#define _H_CREATESTUDENT

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>
#include <QDialog>

class StudentInfoDialog : public QDialog
{
    Q_OBJECT
public:
    explicit StudentInfoDialog(QWidget *parent = 0);
    ~StudentInfoDialog();
	
	
public:
	void setupUi(QWidget * widget );	
	void retranslateUi(QDialog *Dialog);
	
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *labelStuID;
    QLabel *labelStudentIDNumber;
    QLabel *label_stu_name;
    QLineEdit *lineEdit_stu_name;
    QLabel *label_stu_phone;
    QLineEdit *lineEdit_student_phone;
    QLabel *label_stu_gender;
    QRadioButton *radioButton_stu_male;
    QRadioButton *radioButton_stu_female;
    QLabel *label_stu_age;
    QSpinBox *spinBox_stu_age;
    QWidget *widget;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_2;
    QListView *listView;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButtonConfirm;
    QToolButton *toolButtonCancel;	

};


#endif
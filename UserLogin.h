#ifndef _H_USERLOGIN
#define _H_USERLOGIN

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

class UserLoginDialog : public QDialog
{
    Q_OBJECT
public:
    explicit UserLoginDialog(QWidget *parent = 0);
    ~UserLoginDialog();
	
	
public:
	void setupUi(QWidget * widget );	
	void retranslateUi(QDialog *Dialog);
	
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelUserName;
    QLineEdit *lineEditUsername;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelPassword;
    QLineEdit *lineEditPassword;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *toolButtonConfirm;
    QToolButton *toolButtonCancel;


	
private slots:

	void ConfirmDialog();
	void CancelDialog();

	
};



#endif
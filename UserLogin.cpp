#include <QMessageBox>

#include "UserLogin.h"

UserLoginDialog::UserLoginDialog(QWidget *parent) :
    QDialog(parent)//,
    //ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
	setupUi(this);
	
	connect(toolButtonConfirm, SIGNAL(clicked()), this, SLOT(ConfirmDialog()));
	connect(toolButtonCancel, SIGNAL(clicked()), this, SLOT(CancelDialog()));
	
}

UserLoginDialog::~UserLoginDialog()
{
    //delete ui;
	
}

void UserLoginDialog::setupUi(QWidget * widget )
{
        if (widget->objectName().isEmpty())
            widget->setObjectName(QString::fromUtf8("UserLoginDialog"));
        widget->resize(230, 153);

        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/images/logoNain.png"), QSize(), QIcon::Normal, QIcon::Off);
        this->setWindowIcon(icon);
		
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelUserName = new QLabel(widget);
        labelUserName->setObjectName(QString::fromUtf8("labelUserName"));
		labelUserName->setMinimumSize(QSize(30, 0));

        horizontalLayout->addWidget(labelUserName);

        lineEditUsername = new QLineEdit(widget);
        lineEditUsername->setObjectName(QString::fromUtf8("lineEditUsername"));
        lineEditUsername->setInputMask("nnnnnnnnnnnnnnn; ");

        horizontalLayout->addWidget(lineEditUsername);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelPassword = new QLabel(widget);
        labelPassword->setObjectName(QString::fromUtf8("labelPassword"));
		labelPassword->setMinimumSize(QSize(30, 0));

        horizontalLayout_2->addWidget(labelPassword);

        lineEditPassword = new QLineEdit(widget);
        lineEditPassword->setObjectName(QString::fromUtf8("lineEditPassword"));

        horizontalLayout_2->addWidget(lineEditPassword);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        toolButtonConfirm = new QToolButton(widget);
        toolButtonConfirm->setObjectName(QString::fromUtf8("toolButtonConfirm"));
        toolButtonConfirm->setMinimumSize(QSize(80, 30));

        horizontalLayout_3->addWidget(toolButtonConfirm);

        toolButtonCancel = new QToolButton(widget);
        toolButtonCancel->setObjectName(QString::fromUtf8("toolButtonCancel"));
        toolButtonCancel->setMinimumSize(QSize(80, 30));

        horizontalLayout_3->addWidget(toolButtonCancel);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);


		//actionConfirm = new QAction(this);
		//actionCancel = new QAction(this);
		
		//toolButtonConfirm->addAction(actionConfirm);
		//toolButtonCancel->addAction(actionCancel);
		
        retranslateUi(this);

        QMetaObject::connectSlotsByName(this);
}

void UserLoginDialog::retranslateUi(QDialog *Dialog)
{

        //Dialog->setWindowTitle(QApplication::translate("UserLoginDialog", "UserLoginDialog", 0, QApplication::UnicodeUTF8));
        Dialog->setWindowTitle(tr("UserLoginDialog"));
		//labelUserName->setText(QApplication::translate("UserLoginDialog", "UserName", 0, QApplication::UnicodeUTF8));
        labelUserName->setText(tr("UserName"));
		//labelPassword->setText(QApplication::translate("UserLoginDialog", "Password", 0, QApplication::UnicodeUTF8));
        labelPassword->setText(tr("UserPassword"));
		//toolButtonConfirm->setText(QApplication::translate("UserLoginDialog", "Confirm", 0, QApplication::UnicodeUTF8));
        toolButtonConfirm->setText(tr("Confirm"));
		//toolButtonCancel->setText(QApplication::translate("UserLoginDialog", "Cancel", 0, QApplication::UnicodeUTF8));
		toolButtonCancel->setText(tr("Cancel"));

}

void UserLoginDialog::ConfirmDialog()
{
	QString strUser = lineEditUsername->text();
	if(strUser == "001")
	  done(1);
}

void UserLoginDialog::CancelDialog()
{
  accept();
}


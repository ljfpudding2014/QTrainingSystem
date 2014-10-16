
#include "StudentInfoDialog.h"

StudentInfoDialog::StudentInfoDialog(QWidget *parent) :
    QDialog(parent)//,
    //ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
	setupUi(this);
}

StudentInfoDialog::~StudentInfoDialog()
{
    //delete ui;
	
}

void StudentInfoDialog::setupUi(QWidget * widget )
{
        if (this->objectName().isEmpty())
            this->setObjectName(QString::fromUtf8("Dialog"));
        this->resize(497, 402);
		
		QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/images/logoNain.png"), QSize(), QIcon::Normal, QIcon::Off);
        this->setWindowIcon(icon);
		
        gridLayout_3 = new QGridLayout(this);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelStuID = new QLabel(this);
        labelStuID->setObjectName(QString::fromUtf8("labelStuID"));

        gridLayout->addWidget(labelStuID, 0, 0, 1, 1);

        labelStudentIDNumber = new QLabel(this);
        labelStudentIDNumber->setObjectName(QString::fromUtf8("labelStudentIDNumber"));

        gridLayout->addWidget(labelStudentIDNumber, 0, 1, 1, 2);

        label_stu_name = new QLabel(this);
        label_stu_name->setObjectName(QString::fromUtf8("label_stu_name"));

        gridLayout->addWidget(label_stu_name, 1, 0, 1, 1);

        lineEdit_stu_name = new QLineEdit(this);
        lineEdit_stu_name->setObjectName(QString::fromUtf8("lineEdit_stu_name"));

        gridLayout->addWidget(lineEdit_stu_name, 1, 1, 1, 2);

        label_stu_phone = new QLabel(this);
        label_stu_phone->setObjectName(QString::fromUtf8("label_stu_phone"));

        gridLayout->addWidget(label_stu_phone, 2, 0, 1, 1);

        lineEdit_student_phone = new QLineEdit(this);
        lineEdit_student_phone->setObjectName(QString::fromUtf8("lineEdit_student_phone"));
        lineEdit_student_phone->setInputMethodHints(Qt::ImhFormattedNumbersOnly);

        gridLayout->addWidget(lineEdit_student_phone, 2, 1, 1, 2);

        label_stu_gender = new QLabel(this);
        label_stu_gender->setObjectName(QString::fromUtf8("label_stu_gender"));

        gridLayout->addWidget(label_stu_gender, 3, 0, 1, 1);

        radioButton_stu_male = new QRadioButton(this);
        radioButton_stu_male->setObjectName(QString::fromUtf8("radioButton_stu_male"));

        gridLayout->addWidget(radioButton_stu_male, 3, 1, 1, 1);

        radioButton_stu_female = new QRadioButton(this);
        radioButton_stu_female->setObjectName(QString::fromUtf8("radioButton_stu_female"));

        gridLayout->addWidget(radioButton_stu_female, 3, 2, 1, 1);

        label_stu_age = new QLabel(this);
        label_stu_age->setObjectName(QString::fromUtf8("label_stu_age"));

        gridLayout->addWidget(label_stu_age, 4, 0, 1, 1);

        spinBox_stu_age = new QSpinBox(this);
        spinBox_stu_age->setObjectName(QString::fromUtf8("spinBox_stu_age"));

        gridLayout->addWidget(spinBox_stu_age, 4, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        widget = new QWidget(this);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_4 = new QGridLayout(widget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        listView = new QListView(widget);
        listView->setObjectName(QString::fromUtf8("listView"));

        gridLayout_2->addWidget(listView, 0, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 0, 0, 1, 1);


        gridLayout_3->addWidget(widget, 1, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(348, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 2, 0, 1, 1);

        toolButtonConfirm = new QToolButton(this);
        toolButtonConfirm->setObjectName(QString::fromUtf8("toolButtonConfirm"));

        gridLayout_3->addWidget(toolButtonConfirm, 2, 1, 1, 1);

        toolButtonCancel = new QToolButton(this);
        toolButtonCancel->setObjectName(QString::fromUtf8("toolButtonCancel"));

        gridLayout_3->addWidget(toolButtonCancel, 2, 2, 1, 1);

        toolButtonCancel->raise();
        widget->raise();

        retranslateUi(this);

        QMetaObject::connectSlotsByName(this);

}
	
void StudentInfoDialog::retranslateUi(QDialog *Dialog)
{
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        labelStuID->setText(QApplication::translate("Dialog", "StudentID", 0, QApplication::UnicodeUTF8));
        labelStudentIDNumber->setText(QApplication::translate("Dialog", "StudentIDNumbershow", 0, QApplication::UnicodeUTF8));
        label_stu_name->setText(QApplication::translate("Dialog", "Student_Name", 0, QApplication::UnicodeUTF8));
        label_stu_phone->setText(QApplication::translate("Dialog", "Student_Phone", 0, QApplication::UnicodeUTF8));
        label_stu_gender->setText(QApplication::translate("Dialog", "Student_gender", 0, QApplication::UnicodeUTF8));
        radioButton_stu_male->setText(QApplication::translate("Dialog", "male", 0, QApplication::UnicodeUTF8));
        radioButton_stu_female->setText(QApplication::translate("Dialog", "female", 0, QApplication::UnicodeUTF8));
        label_stu_age->setText(QApplication::translate("Dialog", "Student_age", 0, QApplication::UnicodeUTF8));
        toolButtonConfirm->setText(QApplication::translate("Dialog", "Confirm", 0, QApplication::UnicodeUTF8));
        toolButtonCancel->setText(QApplication::translate("Dialog", "Cancel", 0, QApplication::UnicodeUTF8));
   

}
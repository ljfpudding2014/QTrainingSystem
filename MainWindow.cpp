#include "mainwindow.h"
#include "StudentInfoDialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)//,
    //ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
	setupUi(this);
	connect(actionCreateStudent, SIGNAL(triggered()), this, SLOT(CreateNewStudent()));	
	
}

MainWindow::~MainWindow()
{
    //delete ui;
	
}

void MainWindow::setupUi(QWidget * widget )
{
        if (this->objectName().isEmpty())
            this->setObjectName(QString::fromUtf8("MainWindow"));
        this->resize(699, 415);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/images/logoNain.png"), QSize(), QIcon::Normal, QIcon::Off);
        this->setWindowIcon(icon);
        actionLogin = new QAction(this);
        actionLogin->setObjectName(QString::fromUtf8("actionLogin"));
        actionExit = new QAction(this);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionquery = new QAction(this);
        actionquery->setObjectName(QString::fromUtf8("actionquery"));
		
		actionCreateStudent = new QAction(this);
		actionquery->setObjectName(QString::fromUtf8("actionCreateStudent"));
		
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/images/home2_enable.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionquery->setIcon(icon1);
        actionTimeTable = new QAction(this);
        actionTimeTable->setObjectName(QString::fromUtf8("actionTimeTable"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/images/settings_enable.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTimeTable->setIcon(icon2);
        centralwidget = new QWidget(this);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        pageQuery = new QWidget();
        pageQuery->setObjectName(QString::fromUtf8("pageQuery"));
        gridLayout_2 = new QGridLayout(pageQuery);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        splitter = new QSplitter(pageQuery);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        widget = new QWidget(splitter);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMaximumSize(QSize(300, 16777215));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_ID = new QLabel(widget);
        label_ID->setObjectName(QString::fromUtf8("label_ID"));

        horizontalLayout->addWidget(label_ID);

        lineEdit_ID = new QLineEdit(widget);
        lineEdit_ID->setObjectName(QString::fromUtf8("lineEdit_ID"));

        horizontalLayout->addWidget(lineEdit_ID);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        listView = new QListView(widget);
        listView->setObjectName(QString::fromUtf8("listView"));

        verticalLayout->addWidget(listView);


        gridLayout_3->addLayout(verticalLayout, 0, 0, 1, 1);
		gridLayout_3->setContentsMargins(0,0,0,0); 

        splitter->addWidget(widget);
        tableView = new QTableView(splitter);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setMinimumSize(QSize(0, 0));
        tableView->setMaximumSize(QSize(16777215, 16777215));
        splitter->addWidget(tableView);

        gridLayout_2->addWidget(splitter, 0, 0, 1, 1);

        stackedWidget->addWidget(pageQuery);
        pageTimeTable = new QWidget();
        pageTimeTable->setObjectName(QString::fromUtf8("pageTimeTable"));
        stackedWidget->addWidget(pageTimeTable);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);
		gridLayout->setContentsMargins(0,0,0,0);

        this->setCentralWidget(centralwidget);
        menubar = new QMenuBar(this);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 699, 19));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menuStudentManagement = new QMenu(menubar);
        menuStudentManagement->setObjectName(QString::fromUtf8("menuStudentManagement"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        this->setMenuBar(menubar);
        statusbar = new QStatusBar(this);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        this->setStatusBar(statusbar);
        toolBar = new QToolBar(this);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        this->addToolBar(Qt::TopToolBarArea, toolBar);
        QWidget::setTabOrder(lineEdit_ID, pushButton);
        QWidget::setTabOrder(pushButton, tableView);
        QWidget::setTabOrder(tableView, listView);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menuStudentManagement->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        menu->addAction(actionLogin);
        menu->addAction(actionExit);
		
		menuStudentManagement->addAction(actionCreateStudent);
		
		
        toolBar->addAction(actionquery);
        toolBar->addAction(actionTimeTable);

        retranslateUi(this);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(this);
}

void MainWindow::retranslateUi(QMainWindow *MainWindow)
{

        //MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\346\237\245\350\257\242\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
 
		MainWindow->setWindowTitle(tr("QTrainingSystem"));
		
		//actionLogin->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));

		actionLogin->setText(tr("Login"));
				
        //actionExit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));

		actionExit->setText(tr("Exit"));
				
        //actionquery->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));

		actionquery->setText(tr("Query"));
		
		actionCreateStudent->setText(tr("Create Student"));
		
		#ifndef QT_NO_TOOLTIP
        //actionquery->setToolTip(QApplication::translate("MainWindow", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
	
		actionquery->setToolTip(tr("Query"));
		
		
		#endif // QT_NO_TOOLTIP
        actionTimeTable->setText(QApplication::translate("MainWindow", "\350\257\276\347\250\213\350\241\250", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionTimeTable->setToolTip(QApplication::translate("MainWindow", "\350\257\276\350\241\250", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_ID->setText(QApplication::translate("MainWindow", "\347\274\226\345\217\267", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "\347\224\250\346\210\267", 0, QApplication::UnicodeUTF8));
        menuStudentManagement->setTitle(QApplication::translate("MainWindow", "\345\255\246\347\224\237\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        menu_3->setTitle(QApplication::translate("MainWindow", "\347\263\273\347\273\237\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        menu_4->setTitle(QApplication::translate("MainWindow", "\346\224\266\350\264\271\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
  
}


void MainWindow::CreateNewStudent()
{
	StudentInfoDialog dlg;
	
	dlg.exec();

}
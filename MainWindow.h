#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSplitter>
#include <QtGui/QStackedWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <QMainWindow>

//namespace Ui {
//    class MainWindow;
//}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
	
	
public:
    QAction *actionLogin;
    QAction *actionExit;
    QAction *actionquery;
    QAction *actionTimeTable;
	
	QAction *actionCreateStudent;
	
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *pageQuery;
    QGridLayout *gridLayout_2;
    QSplitter *splitter;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_ID;
    QLineEdit *lineEdit_ID;
    QPushButton *pushButton;
    QListView *listView;
    QTableView *tableView;
    QWidget *pageTimeTable;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menuStudentManagement;
    QMenu *menu_3;
    QMenu *menu_4;
    QStatusBar *statusbar;
    QToolBar *toolBar;

public:
	void setupUi(QWidget * widget );	
	void retranslateUi(QMainWindow *MainWindow);
	
	
public slots:
	void CreateNewStudent();
	
//private:
    //Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

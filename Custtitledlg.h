#ifndef _H_CUSTTITLE_DLG
#define _H_CUSTTITLE_DLG

#include <QDialog>
#include <QPainter>
#include <QMouseEvent>
#include <qmath.h>

#define SHADOW_WIDTH            5
#define WINDOW_WIDTH            680
#define WINDOW_HEIGHT           372
#define WINDOW_START_X          0
#define WINDOW_START_Y          0
#define WINDOW_PAGE_COUNT       4
#define WINDOW_BUTTON_COUNT     4
#define WINDOW_PAGE_MOVE        20
#define WINDOW_ONEBUTTON_WIDTH  170

class CusttitleDlg : public QDialog
{
	Q_OBJECT
public:
	CusttitleDlg(QWidget *parent = 0);
	~CusttitleDlg();
protected:
	virtual void paintEvent(QPaintEvent *event);
	
protected:

	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	
private:
	void drawWindowShadow(QPainter &painter);
	
	
private:
	QPoint move_point; //移动的距离
	bool mouse_press; //按下鼠标左键
};

#endif

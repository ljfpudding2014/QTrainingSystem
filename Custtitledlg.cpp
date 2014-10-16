#include "Custtitledlg.h"

CusttitleDlg::CusttitleDlg(QWidget *parent)
	: QDialog(parent)
{
	setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
	setAttribute(Qt::WA_TranslucentBackground);
}

CusttitleDlg::~CusttitleDlg()
{

}

void CusttitleDlg::paintEvent(QPaintEvent *)
{

    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
    path.addRect(10, 10, this->width()-20, this->height()-20);

	QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.fillPath(path, QBrush(Qt::white));

    QColor color(0, 0, 0, 50);
    for(int i=0; i<10; i++)
    {
        QPainterPath path;
        path.setFillRule(Qt::WindingFill);
        path.addRect(10-i, 10-i, this->width()-(10-i)*2, this->height()-(10-i)*2);
        color.setAlpha(150 - qSqrt(i)*50);
        painter.setPen(color);
        painter.drawPath(path);
    }

	//QPainter painter(this);
    this->drawWindowShadow(painter);
	painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);
	painter.drawRect(QRect(SHADOW_WIDTH, SHADOW_WIDTH, this->width()-2*SHADOW_WIDTH, this->height()-2*SHADOW_WIDTH));
}

void CusttitleDlg::drawWindowShadow(QPainter &painter)
{
	//�������Ͻǡ����½ǡ����Ͻǡ����½ǡ��ϡ��¡����ұ߿�
    QList<QPixmap> pixmaps;
    pixmaps.append(QPixmap(":/shadow/shadow_left"));
    pixmaps.append(QPixmap(":/shadow/shadow_right"));
    pixmaps.append(QPixmap(":/shadow/shadow_top"));
    pixmaps.append(QPixmap(":/shadow/shadow_bottom"));
    pixmaps.append(QPixmap(":/shadow/shadow_left_top"));
    pixmaps.append(QPixmap(":/shadow/shadow_right_top"));
    pixmaps.append(QPixmap(":/shadow/shadow_left_bottom"));
    pixmaps.append(QPixmap(":/shadow/shadow_right_bottom"));

    painter.drawPixmap(0, 0, SHADOW_WIDTH, SHADOW_WIDTH, pixmaps[4]);
    painter.drawPixmap(this->width()-SHADOW_WIDTH, 0, SHADOW_WIDTH, SHADOW_WIDTH, pixmaps[5]);
    painter.drawPixmap(0,this->height()-SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH, pixmaps[6]);
    painter.drawPixmap(this->width()-SHADOW_WIDTH, this->height()-SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH, pixmaps[7]);
    painter.drawPixmap(0, SHADOW_WIDTH, SHADOW_WIDTH, this->height()-2*SHADOW_WIDTH, pixmaps[0].scaled(SHADOW_WIDTH, this->height()-2*SHADOW_WIDTH));
    painter.drawPixmap(this->width()-SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH, this->height()-2*SHADOW_WIDTH, pixmaps[1].scaled(SHADOW_WIDTH, this->height()- 2*SHADOW_WIDTH));
    painter.drawPixmap(SHADOW_WIDTH, 0, this->width()-2*SHADOW_WIDTH, SHADOW_WIDTH, pixmaps[2].scaled(this->width()-2*SHADOW_WIDTH, SHADOW_WIDTH));
    painter.drawPixmap(SHADOW_WIDTH, this->height()-SHADOW_WIDTH, this->width()-2*SHADOW_WIDTH, SHADOW_WIDTH, pixmaps[3].scaled(this->width()-2*SHADOW_WIDTH, SHADOW_WIDTH));
}

void CusttitleDlg::mousePressEvent(QMouseEvent *event)
{
	//ֻ�����������ƶ��͸ı��С
	if(event->button() == Qt::LeftButton) 
	{
		mouse_press = true;
	}

	//�����ƶ�����
	move_point = event->globalPos() - pos(); 
}

void CusttitleDlg::mouseReleaseEvent(QMouseEvent *)
{
	mouse_press = false;
}

void CusttitleDlg::mouseMoveEvent(QMouseEvent *event)
{
	//�ƶ�����
	if(mouse_press)   
	{
		QPoint move_pos = event->globalPos();
		move(move_pos - move_point);
	}
}
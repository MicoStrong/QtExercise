/*******************************************************************************
**                                                                            **
**                     Jiedi(China nanjing)Ltd.                               **
**	               ������������ �Ĳܿ����˴��������Ϊѧϰ�ο�                       **
*******************************************************************************/

/*****************************FILE INFOMATION***********************************
**
** Project       : ���ģʽ��ȫ
** Contact       : xiacaojun@qq.com
**        ����   : http://blog.csdn.net/jiedichina
**		��Ƶ�γ� : �����ƿ���	http://study.163.com/u/xiacaojun		
				   ��Ѷ����		https://jiedi.ke.qq.com/				
				   csdnѧԺ		http://edu.csdn.net/lecturer/lecturer_detail?lecturer_id=961	
**                 51ctoѧԺ	http://edu.51cto.com/lecturer/index/user_id-12016059.html	
** 				   ���Ŀ���		http://www.laoxiaketang.com #������Ԥ��2018��6��ǰ����
**                 
**   ���ģʽ �γ�Ⱥ ��726114806 ����Ⱥ���ش���ͽ���
**   ΢�Ź��ں�  : jiedi2007
**		ͷ����	 : �Ĳܿ�
**
*******************************************************************************/
//������������������ ��Ⱥ��726114806���ش���ͽ���


#include "XImage.h"
#include <QDebug>
#include <QFileDialog>
#include <QPainter>
//#include "XEditView.h"
#include <QMouseEvent>
//#include "XModel.h"
#include "IController.h"
#include "XControllerFactory.h"
//XModel m;
void XImage::Open()
{
	qDebug() << "XImage::Open()" ;
	//ѡ��ͼƬ
	QString filename = QFileDialog::getOpenFileName(this, QStringLiteral("��ͼƬ"), "",
		QStringLiteral("֧�ֵĸ�ʽ(*.png *.jpg *.bmp)"));
	if (filename.isEmpty())
	{
		qDebug() << " Open filename is empty!";
		return;
	}

	//����ͼƬ
	//if (!src.load(filename))
	if(!c->InitBack(filename.toLocal8Bit()))
	{
		qDebug() << " src.load image failed!";
		return;
	}
	qDebug() << " src.load image success!";

	//ˢ����ʾ
	update();
}

void XImage::SetPen()
{
	c->SetStatus(XPEN);
}
void XImage::SetEras()
{
	c->SetStatus(XERASER);
}

void XImage::SetRect()
{
	c->SetStatus(XRECT);
}
void XImage::Undo()
{
	c->Undo();
	//ˢ����ʾ
	update();
}
void XImage::Redo()
{
	c->Redo();
	//ˢ����ʾ
	update();
}
void XImage::SetPenSize(int size)
{
	penSize = size;
}

//������꺯��
void XImage::mousePressEvent(QMouseEvent *e)
{
	//XEditView::Get()->poss.push_back(XPos(e->x(), e->y()));
	//m.Add(XPos(e->x(), e->y()));
	c->AddModel();
	c->SetPara("size", penSize);
	c->SetPara("r", r);
	c->SetPara("g", g);
	c->SetPara("b", b);
	c->SetPara("a", a);

	c->Add(e->x(), e->y());
	//����һ��ģ��
}

//Ĭ������ƶ��¼������²Ŵ���
void XImage::mouseMoveEvent(QMouseEvent*e)
{
	c->Add(e->x(), e->y());
	//�޸�ģ������
	//m.Add(XPos(e->x(), e->y()));
	//XEditView::Get()->poss.push_back(XPos(e->x(), e->y()));
	update();
}

//���ػ��Ʒ��� update������
void XImage::paintEvent(QPaintEvent *e)
{
	c->Paint();
	////�ڵ�ǰ���ڣ�this������
	//QPainter p(this);
	////����ͼƬ
	//p.drawImage(0, 0, src);
}

XImage::XImage(QWidget *p):QWidget(p)
{
	c = IController::Create(new XControllerFactory());
	c->Init(this);

	//XEditView::Get()->InitDevice(this);
	//��ͼ�۲�ģ��
	//m.Attach(XEditView::Get());
}


XImage::~XImage()
{
}

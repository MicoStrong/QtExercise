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


#pragma once
#include <QWidget>
#include <QImage>
class IController;
class XImage:public QWidget
{

	Q_OBJECT

public:
	XImage(QWidget *p = 0);
	~XImage();

	//���ػ��Ʒ��� update������
	void paintEvent(QPaintEvent *e);

	//������꺯��
	void mousePressEvent(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent*e);
public slots:
	void Open();
	void SetPen();
	void SetEras();
	void SetRect();
	void Undo();
	void Redo();
	void SetPenSize(int size);
	void SetPenColor(int r, int g, int b, int a) 
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}
protected:
	IController *c = 0;
	int penSize = 5;
	int r=200; int g=0; int b=0; int a=255;
};


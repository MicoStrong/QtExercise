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


#include "XEditView.h"
#include <QPainter>
#include <QWidget>
#include "XModel.h"
#include "XPenGraph.h"
//XPenGraph xpen;
//��ʾĿ��
void XEditView::InitDevice(void *d)
{
	this->device = (QWidget*)d;
	if (!op) op = new QPainter(&out);
	//��һ�ε������
	op->end();
	op->begin(&out);
	map<int, IGraph*>::iterator itr = views.begin();
	for (; itr != views.end(); itr++)
	{
		itr->second->Init(op, &src);
	}
	//xpen.Init(op, &src);
}

//���뱳��ͼ
bool XEditView::InitBack(const char *url)
{
	//����ͼƬ
	if (!src.load(QString::fromLocal8Bit(url)))return false;
	if (op->isActive())
		op->end();
	out = src.copy();
	op->begin(&out);
	return true;
}
void XEditView::Update(XSubject *data)
{
	if (!data)return;
	XModel *m = static_cast<XModel*>(data);
	views[m->type]->Draw(m);

	/*map<int, IGraph*>::iterator itr = views.begin();

	for (; itr != views.end(); itr++)
	{
		itr->second->Draw(m);
	}*/
	//����ͼԪ������
	//xpen.Draw(m);
	
	//XModel
	//

	//int size = m->poss.size();
	//QPainter p(&out);
	//for (int i = 1; i < size; i++)
	//{
	//	//�����ߣ���ʼ�㵽������
	//	p.drawLine(QLine(m->poss[i - 1].x, m->poss[i - 1].y, m->poss[i].x, m->poss[i].y));
	//}
}
//���ƽ��
void XEditView::Paint()
{
	//��device���ڻ���
	QPainter p(device);
	p.drawImage(0, 0, out);
	////����ͼƬ
	//p.drawImage(0, 0, src);
	////�������������
	//int size = poss.size();
	////��1��ʼ������Ҫ������
	//for (int i = 1; i < size; i++)
	//{
	//	//�����ߣ���ʼ�㵽������
	//	p.drawLine(QLine(poss[i - 1].x, poss[i - 1].y, poss[i].x, poss[i].y));
	//}
	//
}

XEditView::XEditView()
{
	//��ʼ��ͼ��δ��ͼ��ֱ�ӻ�ͼ
	out = QImage(1280, 720, QImage::Format_RGB888);
	src = QImage(1280, 720, QImage::Format_RGB888);
}


XEditView::~XEditView()
{
}

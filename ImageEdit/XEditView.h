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
#include <QImage>
#include <vector>
#include <map>
#include "IView.h"
#include "IGraph.h"

using namespace std;
class QWidget;

class XEditView:public IView
{
public:
	//����ģʽ
	static XEditView *Get()
	{
		static XEditView v;
		return &v;
	}

	//ˢ�µ�out��
	virtual void Update(XSubject *data);

	//��ʾĿ��
	virtual void InitDevice(void *d);

	//���뱳��ͼ
	virtual bool InitBack(const char *url);

	//����out���
	virtual void Paint();

	template<class ViewClass>
	IGraph *RegView(int type)
	{
		ViewClass *view = new ViewClass();
		views.insert(make_pair(type, view));
		return view;
	}

	~XEditView();
protected:
	XEditView();

	//ͼԪ����ⲿά��
	std::map<int, IGraph*>views;

	QWidget *device;
	//ԭͼ
	QImage src;

	//���ͼ
	QImage out;

	//���Ƶ�out
	QPainter *op = 0;
};


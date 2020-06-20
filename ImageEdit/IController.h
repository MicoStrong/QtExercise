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
#include "IControllerFactory.h"
#include <vector>
enum XSTATUS
{
	XPEN,
	XERASER,
	XRECT,
	XIMAGE
};

class IController
{
public:
	static IController* Create(IControllerFactory *f);
	virtual void Init(void *device);
	//���뱳��ͼ
	virtual bool InitBack(const char *url);
	//���ģ�Ͷ��� -1ȡ��ǰ״̬
	virtual void AddModel(int s=-1);
	//����ǰģ���������
	virtual void Add(int x, int y);
	virtual void Paint();
	virtual void SetStatus(XSTATUS s) { status = s; }
	virtual void NotfyAll();
	virtual void Undo();
	virtual void Redo();
	virtual void SetPara(std::string key, int val);
	IController();
	~IController();
protected:
	IView *v = 0;
	XModel *m = 0;
	IControllerFactory *f = 0;
	//�������
	std::vector<XModel*> tasks;
	std::vector<XModel*> retasks;
	XSTATUS status = XPEN;
};


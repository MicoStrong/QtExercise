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


#include "IController.h"
#include "IView.h"
#include "XModel.h"
IController* IController::Create(IControllerFactory *f)
{
	if (!f)return 0;

	IController *c = f->CreateC();
	c->f = f;
	//c->m = f->CreateM();
	c->v = f->CreateV();
	return c;
}
void IController::Init(void *device)
{
	//��ӱ���ͼ
	AddModel(XIMAGE);
	v->InitDevice(device);
}
void IController::Paint()
{
	v->Paint();
}
//���뱳��ͼ
bool IController::InitBack(const char *url)
{
	bool re = v->InitBack(url);
	//��ӱ���ͼ
	AddModel(XIMAGE);
	return re;
}
void IController::AddModel(int s)
{
	if (s < 0) s = status;
	//����ģ�ͣ���ӹ۲���
	m = f->CreateM();
	m->Attach(v);
	m->type = s;
	tasks.push_back(m);
}
//����ǰģ���������
void IController::Add(int x, int y)
{
	if (!m)return;
	m->Add(XPos(x, y));
	NotfyAll();
}
void IController::Undo()
{
	int last = tasks.size() - 1;
	if (last < 2)return;
	retasks.push_back(tasks[last]);
	tasks.pop_back();
	NotfyAll();
}


void IController::SetPara(std::string key, int val)
{
	if (!m)return;
	m->SetPara(key,val);
}
void IController::Redo()
{
	if (retasks.empty())return;
	int rlast = retasks.size() - 1;
	tasks.push_back(retasks[rlast]);
	retasks.pop_back();
	NotfyAll();
}

void IController::NotfyAll()
{
	int size = tasks.size();
	for (int i = 0; i < size; i++)
	{
		tasks[i]->Notify();
	}
}

IController::IController()
{
}


IController::~IController()
{
}

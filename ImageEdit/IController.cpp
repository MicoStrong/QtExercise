/*******************************************************************************
**                                                                            **
**                     Jiedi(China nanjing)Ltd.                               **
**	               创建：丁宋涛 夏曹俊，此代码可用作为学习参考                       **
*******************************************************************************/

/*****************************FILE INFOMATION***********************************
**
** Project       : 设计模式大全
** Contact       : xiacaojun@qq.com
**        博客   : http://blog.csdn.net/jiedichina
**		视频课程 : 网易云课堂	http://study.163.com/u/xiacaojun		
				   腾讯课堂		https://jiedi.ke.qq.com/				
				   csdn学院		http://edu.csdn.net/lecturer/lecturer_detail?lecturer_id=961	
**                 51cto学院	http://edu.51cto.com/lecturer/index/user_id-12016059.html	
** 				   老夏课堂		http://www.laoxiaketang.com #开发中预计2018年6月前上线
**                 
**   设计模式 课程群 ：726114806 加入群下载代码和交流
**   微信公众号  : jiedi2007
**		头条号	 : 夏曹俊
**
*******************************************************************************/
//！！！！！！！！！ 加群：726114806下载代码和交流


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
	//添加背景图
	AddModel(XIMAGE);
	v->InitDevice(device);
}
void IController::Paint()
{
	v->Paint();
}
//载入背景图
bool IController::InitBack(const char *url)
{
	bool re = v->InitBack(url);
	//添加背景图
	AddModel(XIMAGE);
	return re;
}
void IController::AddModel(int s)
{
	if (s < 0) s = status;
	//创建模型，添加观察者
	m = f->CreateM();
	m->Attach(v);
	m->type = s;
	tasks.push_back(m);
}
//给当前模型添加数据
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

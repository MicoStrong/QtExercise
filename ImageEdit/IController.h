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
	//载入背景图
	virtual bool InitBack(const char *url);
	//添加模型对象 -1取当前状态
	virtual void AddModel(int s=-1);
	//给当前模型添加数据
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
	//命令队列
	std::vector<XModel*> tasks;
	std::vector<XModel*> retasks;
	XSTATUS status = XPEN;
};


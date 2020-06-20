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
	//单件模式
	static XEditView *Get()
	{
		static XEditView v;
		return &v;
	}

	//刷新到out中
	virtual void Update(XSubject *data);

	//显示目标
	virtual void InitDevice(void *d);

	//载入背景图
	virtual bool InitBack(const char *url);

	//绘制out结果
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

	//图元编号外部维护
	std::map<int, IGraph*>views;

	QWidget *device;
	//原图
	QImage src;

	//输出图
	QImage out;

	//绘制到out
	QPainter *op = 0;
};


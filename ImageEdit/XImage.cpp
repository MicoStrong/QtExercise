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
	//选择图片
	QString filename = QFileDialog::getOpenFileName(this, QStringLiteral("打开图片"), "",
		QStringLiteral("支持的格式(*.png *.jpg *.bmp)"));
	if (filename.isEmpty())
	{
		qDebug() << " Open filename is empty!";
		return;
	}

	//载入图片
	//if (!src.load(filename))
	if(!c->InitBack(filename.toLocal8Bit()))
	{
		qDebug() << " src.load image failed!";
		return;
	}
	qDebug() << " src.load image success!";

	//刷新显示
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
	//刷新显示
	update();
}
void XImage::Redo()
{
	c->Redo();
	//刷新显示
	update();
}
void XImage::SetPenSize(int size)
{
	penSize = size;
}

//重载鼠标函数
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
	//创建一个模型
}

//默认鼠标移动事件，按下才触发
void XImage::mouseMoveEvent(QMouseEvent*e)
{
	c->Add(e->x(), e->y());
	//修改模型数据
	//m.Add(XPos(e->x(), e->y()));
	//XEditView::Get()->poss.push_back(XPos(e->x(), e->y()));
	update();
}

//重载绘制方法 update后会调用
void XImage::paintEvent(QPaintEvent *e)
{
	c->Paint();
	////在当前窗口（this）绘制
	//QPainter p(this);
	////绘制图片
	//p.drawImage(0, 0, src);
}

XImage::XImage(QWidget *p):QWidget(p)
{
	c = IController::Create(new XControllerFactory());
	c->Init(this);

	//XEditView::Get()->InitDevice(this);
	//视图观察模型
	//m.Attach(XEditView::Get());
}


XImage::~XImage()
{
}

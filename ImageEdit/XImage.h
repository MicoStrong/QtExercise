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
#include <QWidget>
#include <QImage>
class IController;
class XImage:public QWidget
{

	Q_OBJECT

public:
	XImage(QWidget *p = 0);
	~XImage();

	//重载绘制方法 update后会调用
	void paintEvent(QPaintEvent *e);

	//重载鼠标函数
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


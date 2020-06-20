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


#include "XImageEdit.h"
#include <QColorDialog>
XImageEdit::XImageEdit(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//点击事件，点击打开图片
	connect(ui.openB,			//信号发出者
		SIGNAL(clicked()),	//点击信号
		ui.image,			//信号接收者
		SLOT(Open())		//槽函数
	);

	connect(ui.penButton,			//信号发出者
		SIGNAL(clicked()),	//点击信号
		ui.image,			//信号接收者
		SLOT(SetPen())		//槽函数
	);

	connect(ui.erasButton,			//信号发出者
		SIGNAL(clicked()),	//点击信号
		ui.image,			//信号接收者
		SLOT(SetEras())		//槽函数
	);

	connect(ui.rectButton,			//信号发出者
		SIGNAL(clicked()),	//点击信号
		ui.image,			//信号接收者
		SLOT(SetRect())		//槽函数
	);

	connect(ui.undoButton,			//信号发出者
		SIGNAL(clicked()),	//点击信号
		ui.image,			//信号接收者
		SLOT(Undo())		//槽函数
	);

	connect(ui.redoButton,			//信号发出者
		SIGNAL(clicked()),	//点击信号
		ui.image,			//信号接收者
		SLOT(Redo())		//槽函数
	);

	connect(ui.penSizeSlider,			//信号发出者
		SIGNAL(valueChanged(int)),	//点击信号
		ui.image,			//信号接收者
		SLOT(SetPenSize(int))		//槽函数
	);

}
void XImageEdit::SetColor()
{
	QColor col = QColorDialog::getColor(Qt::red, this);
	//background-color: rgba(255, 0, 0, 200);
	QString sty = QString("background-color: rgba(%1, %2, %3, %4);")
		.arg(col.red()).arg(col.green()).arg(col.blue()).arg(col.alpha());
	ui.colorButton->setStyleSheet(sty);
	ui.image->SetPenColor(col.red(), col.green(), col.blue(), col.alpha());
	
}
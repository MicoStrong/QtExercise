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


#include "XImageEdit.h"
#include <QColorDialog>
XImageEdit::XImageEdit(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//����¼��������ͼƬ
	connect(ui.openB,			//�źŷ�����
		SIGNAL(clicked()),	//����ź�
		ui.image,			//�źŽ�����
		SLOT(Open())		//�ۺ���
	);

	connect(ui.penButton,			//�źŷ�����
		SIGNAL(clicked()),	//����ź�
		ui.image,			//�źŽ�����
		SLOT(SetPen())		//�ۺ���
	);

	connect(ui.erasButton,			//�źŷ�����
		SIGNAL(clicked()),	//����ź�
		ui.image,			//�źŽ�����
		SLOT(SetEras())		//�ۺ���
	);

	connect(ui.rectButton,			//�źŷ�����
		SIGNAL(clicked()),	//����ź�
		ui.image,			//�źŽ�����
		SLOT(SetRect())		//�ۺ���
	);

	connect(ui.undoButton,			//�źŷ�����
		SIGNAL(clicked()),	//����ź�
		ui.image,			//�źŽ�����
		SLOT(Undo())		//�ۺ���
	);

	connect(ui.redoButton,			//�źŷ�����
		SIGNAL(clicked()),	//����ź�
		ui.image,			//�źŽ�����
		SLOT(Redo())		//�ۺ���
	);

	connect(ui.penSizeSlider,			//�źŷ�����
		SIGNAL(valueChanged(int)),	//����ź�
		ui.image,			//�źŽ�����
		SLOT(SetPenSize(int))		//�ۺ���
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
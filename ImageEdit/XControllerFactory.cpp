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


#include "XControllerFactory.h"
#include "XModel.h"
#include "IController.h"
#include "XEditView.h"
#include "XPenGraph.h"
#include "XErasGraph.h"
#include "XRectGraph.h"
#include "XImageGraph.h"
XModel *XControllerFactory::CreateM()
{
	return new XModel();
}
IView *XControllerFactory::CreateV()
{
	XEditView::Get()->RegView<XPenGraph>(XPEN);
	XEditView::Get()->RegView<XErasGraph>(XERASER);
	XEditView::Get()->RegView<XRectGraph>(XRECT);
	XEditView::Get()->RegView<XImageGraph>(XIMAGE);
	return XEditView::Get();
}
IController *XControllerFactory::CreateC()
{
	return new IController();
}

XControllerFactory::XControllerFactory()
{
}


XControllerFactory::~XControllerFactory()
{
}
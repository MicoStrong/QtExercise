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
class IController;
class XModel;
class IView;
class IControllerFactory
{
public:
	virtual XModel *CreateM()=0;
	virtual IView *CreateV()=0;
	virtual IController *CreateC() = 0;
};


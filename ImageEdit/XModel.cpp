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


#include "XModel.h"

void XModel::Add(XPos pos)
{
	this->poss.push_back(pos);
	//֪ͨ�۲���
	//this->Notify();
}

int XModel::GetPara(std::string key)
{
	//û�����
	if (paras.find(key) == paras.end())
	{
		return 0;
	}
	return paras[key];
}

void XModel::SetPara(std::string key, int val)
{
	//û�����
	if (paras.find(key) == paras.end())
	{
		paras.insert(make_pair(key, val));
	}
	else
	{
		//�����ֵ  �޸�
		paras[key] = val;
	}

	
	
}

XModel::XModel()
{
}


XModel::~XModel()
{
}

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


#include "XModel.h"

void XModel::Add(XPos pos)
{
	this->poss.push_back(pos);
	//通知观察者
	//this->Notify();
}

int XModel::GetPara(std::string key)
{
	//没有添加
	if (paras.find(key) == paras.end())
	{
		return 0;
	}
	return paras[key];
}

void XModel::SetPara(std::string key, int val)
{
	//没有添加
	if (paras.find(key) == paras.end())
	{
		paras.insert(make_pair(key, val));
	}
	else
	{
		//如果有值  修改
		paras[key] = val;
	}

	
	
}

XModel::XModel()
{
}


XModel::~XModel()
{
}

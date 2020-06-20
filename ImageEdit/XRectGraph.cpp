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


#include "XRectGraph.h"
#include "XModel.h"
#include <QPainter>
#include <QPen>
void XRectGraph::Draw(XModel *m)
{
	if (!painter || !m)return;
	QPen pen; //����
	pen.setWidth(m->GetPara("size"));
	pen.setColor(QColor(m->GetPara("r"), m->GetPara("g"), m->GetPara("b"), m->GetPara("a")));
	//�������Ӵ�
	pen.setCapStyle(Qt::RoundCap); //������ʽ
	pen.setJoinStyle(Qt::RoundJoin);//���Ӵ���ʽ

									//���ÿ����
	painter->setRenderHint(QPainter::Antialiasing, true);
	painter->setPen(pen);
	int size = m->poss.size();
	if (size < 2)return;
	//����ʼ�㵽��β������
	int x = m->poss[0].x;
	int y = m->poss[0].y;
	int w = m->poss[size - 1].x - x;
	int h = m->poss[size - 1].y - y;
	painter->drawRect(x,y,w,h);

}

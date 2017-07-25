#ifndef __UNION_FIND__
#define __UNION_FIND__

/*
���ϵ����������������
·��ѹ��ָ���ǽ�Find�����е����н��ĸ�����Ϊ���յĸ�
�ϲ�������ʵ�ַ�ʽ��
1. ����С�ϲ���_set[root]��ֵΪ�ü��ϴ�С���෴������ʼ��Ϊ-1��С���ϲ���󼯺ϣ���ÿ�κϲ�������ӡ�
2. ���߶Ⱥϲ�, _set[root]��ֵΪ������ȵ��෴������ʼ��Ϊ0��������������Ϊ0�����ҽ����ϲ����������������ȡ�
*/

#include "../util.h"
using SetType = int;
using ElementType = int;

class DisjSet {
private:
  SetType* _set;
  size_t _size;
protected:
  //����С�ϲ��汾
  //void init()
  //{
  //  _set = new int[_size];
  //  for (int i = 0; i < _size; ++i)
  //    _set[i] = -1;
  //}
  //���߶Ⱥϲ��汾
  void init()
  {
	_set = new int[_size];
	for (int i = 0; i < _size; ++i)
	  _set[i] = 0;
  }
public:
  //���߶Ⱥϲ�
  void Union(SetType& fir, SetType& sec)
  {
	if (_set[fir] < _set[sec])
	  _set[sec] = fir;
	else {
	  if (_set[fir] == _set[sec])
		_set[sec]--;
	  _set[fir] = sec;
	}
  }

  //����С�ϲ�
//  void Union(SetType& fir, SetType& sec)
//  {
//	if (_set[fir] < _set[sec]) {
//	  _set[fir] += _set[sec];
//	  _set[sec] = fir;
//	}
//	else {
//	  _set[sec] += _set[fir];
//	  _set[fir] = sec;
//	}
//  }

  SetType Find(ElementType& e) {
	if (_set[e] <= 0)
	  return e;
	else {
	  return _set[e] = Find(e);
	}
  }
};

#endif
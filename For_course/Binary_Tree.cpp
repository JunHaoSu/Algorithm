/*************************************************************************
	> File Name: Binary_Tree.cpp
	> Author: sujunhao
	> Mail: sujunhao0504@gmail.com
	> Created Time: 2017年10月04日 星期三 10时43分39秒
 ************************************************************************/

#include <iostream>
using namespace std;
template <class T>
struct BiNode
{
	T data;
	BiNode<T> *lchild,*rchild;
 } 
template<class T>
class BiTree
{
	public:
		BiTree()root=Creat(root);}
		~BiTree(){Releas(root);}
		void preOrder(){reOrder(root);}
		void InOrder(){InOrder(root);}
		void postOrder(){postOrder(root);}
		void LeverOrder();
	private:
		BiNode<T> *root;
		BiNode<T> *Creat(BiNode<T> *bt);
		void Release(BiNode<T> *bt);
		void PreOrder(BiNode<T> *bt);
		void InOrder(BiNode<T> *bt);
		void PostOrder(BiNode<T> *bt);
};
template <class T>//构造 
BiNode<T> *BiTree<T>::Creat(BiNode<T> *bt)
{
	char ch;
	cin>>ch;
	if(ch=='#')bt=NULL;
	else{
		bt=new BiNode;bt->data=ch;
		bt->lchild=Creat(bt->lchild);
		bt->rchild=Creat(bt->rchild);
	}
	return bt;
}
template <class T>//析构 
void BiTree<T>::Release(BiNode<T> *bt)
{
	if(bt!=NULL)
	{Release(bt->lchild);
	Release(bt->rchild);
	delete bt;
	}
}
template <class T>//前序 
void BiTree<T>::PreOrder(BiNode<T> *bt)
{
	if(bt==NULL)reurn;
	else{
		cout<<bt->data;
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}
template <class T>//中序 
void BiTree<T>::InOrder(BiNode<T> *bt)
{
	if(bt==NULL)reurn;
	else{
		InOrder(bt->lchild);
		cout<<bt->data;
		InOrder(bt->rchild);
	}
}
template <class T>//后序 
void BiTree<T>::PostOrder(BiNode<T> *bt)
{
	if(bt==NULL)return;
	else{
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		cout<<bt->data;
	}
}
template <class T>//层序 
void BiTree<T>::LeverOrder()
{
	front=rear=-1;
	if(root==NULL)return;
	Q[++rear]=root;
	while(front!=rear)
	{
		q=Q[++front];
		cout<<q->data;
		if(q->lchild!=NULL) Q[++rear]=q->lchild;
		if(q->rchild!=NULL) Q[++rear]=q->rchild;
	}
}
int main(int argc, char** argv) {
	cout<<"请按前序输入二叉树，空节点使用#代替"<<endl;
	Bitree<BiNode>
	return 0;
}

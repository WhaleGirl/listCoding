#include<iostream>
using namespace std;
#include<list>
struct ListNode{
	int data;
	struct ListNode* next;
	ListNode(int x):data(x),next(NULL)
	{}
};
//删除不带头的非尾节点
void delNodeTail(ListNode* pos){
	assert(pos&&pos->next);
		ListNode* next = new ListNode(0);
		next = pos->next;
		pos->data = next ->data;
		pos->next = next->next;
		free(next);
}
//从尾到头的打印链表
void printTailtoHead(ListNode* head){
	if(head==NULL)
	  return;
	printTailtoHead(head->next);
	printf("%d",head->data);
}
//在无头的单链表前面插入一个节点,思路：新建一个pos位置的节点，将原pos位置的节点的值置为x，再将新pos的位置插入即可
void insertNodeFront(ListNode* pos,int x){
	assert(pos);
	ListNode* node = new ListNode(pos->data);
	ListNode* next = pos->next;
	pos->data = x;
	node->next = next;
	pos->next = node;
}
//约瑟夫环,数到x的人就要出局，返回剩下的最后一个人
ListNode* Josephus(ListNode* hus,int x){
	assert(hus);
	while(hus->next!=hus){
		int count = x;
		while(--count){
			hus = hus->next;	
		}
		ListNode* next = hus->next;
		hus->data = next->data;
		hus->next = next->next;
		free(next);
		return hus;
	}
}

//反转链表1->2->3->4->5->6->NULL ------ NULL<-1<-2<-3<-4<-5
//思路：定义三个指针，将其分别遍历整个链表并且反转
ListNode* reverseList(ListNode** node){
	assert(ndoe);
	ListNode* n0 = NULL;
	ListNode* n1 = *head;
	ListNode* n2 = n1->next;
	while(n1){
		n1->next = n0;
		n0 = n1;
		n1 = n2;
		if(n2)
		  n2 = n2->next;
	}
	//返回头结点
	*node = n0;
}
//合并两个有序的链表

ListNode* mergeTwoList(ListNode* l1,ListNode* l2){
	ListNode* tmp = new ListNode(0);
	ListNode*　list = tmp->next;
	if(l1==NULL&& l2!=NULL)
	  return l2;
	if(l1!=NULL&& l2==NULL)
	  return l1;
	while(l1&&l2){
		if(l1->data<l2->data){
			list->next = l1;
			l1 = l1->next;
		}else{
			list->next=l2;
			l2 = l2->next;
		}
		list = list->next;
	}
	if(l1)
	  list->next = l1;
	if(l2)
	  list->next = l2;
	return tmp->next;
}
//查找单链表的中间节点，只能遍历一次------思路：使用快慢指针进行遍历，快指针走的步数是慢指针的2倍
ListNode* findMidNode(ListNode* ndoe){
	ListNode* slow = node;
	ListNode* fast = node;
	while(fast&& fast->next){
		slow=slow->next;
		fast = fast->next->next;
	}
	return slow;
}
//查找单链表中的倒数第k个节点,------思路：先让快指针走k步，再让快慢指针一起走直到快指针走到结尾
ListNode*  findTailKNode(ListNode* node,int k){
	assert(node);
	ListNode* slow = node;
	ListNode* fast = node;
	while(--k){
		if(fast)
		  fast=fast->next;
		else
		  return NULL;
	}
	while(fast){
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
//判断单链表是否带环----思路：使用快慢指针进行遍历，若快慢指针相遇则说明是带环的
bool isCycle(ListNode* node){
	ListNode* slow = node;
	ListNode* fast = node;
	while(fast&& fast->next){
		slow = slow->next;
		fast = fast->next->next;
		if(slow==fast)
		  return true;
	}
	return false;
}
//若链表带环，求环的入口点,思路：将上一个求得带环的相遇的那个节点返回，然后从第一个节点开始进行遍历，相遇的节点和head同时走
//如果相遇了就说明是环的入口。
 ListNode* getEntry(ListNode* head,ListNode* meetNode){
			assert(head);
			if(head!=meetNode){
				head = head->next;
				meetNode = meetNode->next;
				if(head==meetNode)
				  return meetNode;
			}
			return NULL;
 } 
//判断两个链表是否相交，如果相交求交点
//思路：先分别遍历两个链表，记录长度，用长链表减去短链表，再让长链表先走差值步，再让短链表一起走，若相遇说明有交点
ListNode* isCross(ListNode* list1,ListNode* list2){
	int count1 = 0, count2 = 0;
	ListNode* l1 = list1;
	ListNode* l2 = list2;
	assert(l1&&l2);
	while(l1){
		count1++;
		l1 = l1->next;
	}
	while(l2){
		count2++;
		l2 = l2->next;
	}
	int k = abs(count1-count2);
	if(count1>count2){
		while(--k)
		  list1 = list1->next;
	}
	if(count2>count1){
		while(--k)
		  lsit2 = list2->next;
	}
	while(list1&&list2){
		if(list1==list2){
			return list1;	
		}	
		list1 = list1->next;
		list2 = list2->next;
	}
	return NULL;
}




#include <iostream>
#include <vector>
 
 using namespace std;
 
 typedef struct ListNode {
 	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 } ListNode;
 
 
 ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
 {
 	ListNode* head = NULL;
 	ListNode* tail = NULL;
 	
 	if (l1 == NULL && l2 == NULL)
 	{
 		return NULL;
	 }
 	else if (l1 != NULL && l2 != NULL)
 	{
 		ListNode* temp;
 		if (l1->val < l2->val)
 		{
 			temp = l1;
 			l1 = l1->next;
		 }
		 else {
		 	temp = l2;
		 	l2 = l2->next;
		 }
		 
		head = temp;
 		tail = temp;
 		tail->next = NULL;
	 }
	 else if (l1 != NULL)
	 {
	 	return l1;
	 }
	 else
	 {
	 	return l2;
	 }
 	
 	while (l1 != NULL && l2 != NULL)
 	{
 		ListNode * temp = NULL;
 		if (l1->val < l2->val)
 		{
 			temp = l1;
 			l1 = l1->next;
		 }
		 else
		 {
		 	temp = l2;
		 	l2 = l2->next;
		 }
		 
		tail->next = temp;
 		tail = temp;
 		temp->next = NULL;
	}
	
	if (l1 != NULL)
	{
		tail->next = l1;
	}
	
	if (l2 != NULL)
	{
		tail->next = l2;
	}
	
	return head;
 }
 
 
 ListNode* removeElements(ListNode* head, int val) {
 	ListNode* resultHead = NULL;
	
	while (head != NULL && head->val == val)
	{
		head = head->next;
	}
	
	resultHead = head;
	ListNode* cur = resultHead;
	
	if (resultHead == NULL)
	{
		return resultHead;
	}
	
	while (cur->next != NULL)
	{
		if (cur->next->val == val)
		{
			cur->next = cur->next->next;
		}
		else
		{
			cur = cur->next;	
		}
	}
	
	return resultHead;	       
 }
 
ListNode* partition(ListNode* head, int x) {
	ListNode* smallHead = NULL;
	ListNode* smallTail = NULL;
	ListNode* largeHead = NULL;
	ListNode* largeTail = NULL;
	
	while (head != NULL)
	{
		ListNode* temp = head;
		head = head->next;
		temp->next = NULL;
			
		//cout << temp->val << endl;
			
		if (temp->val < x)
		{
			if (smallHead == NULL)
			{
				smallHead = temp;
			}
			
			if (smallTail != NULL)
			{
				smallTail->next = temp;
			}
			smallTail = temp;
		}
		else
		{
			if (largeHead == NULL)
			{
				largeHead = temp;
			}
			
			if (largeTail != NULL)
			{
				largeTail->next = temp;
			}
			largeTail = temp;
		}
	}
	
	//cout << largeHead->val << endl;
	
	if (smallTail == NULL)
	{
		return largeHead;
	}
	else
	{
		smallTail->next = largeHead;
		return smallHead;
	}
}
 
 int main()
 {
 	ListNode* l1 = new ListNode(4);
 	//l1->next = new ListNode(1);
 	//l1->next->next = new ListNode(8);
 	
 	ListNode* temp = l1;
 	while (temp != NULL)
 	{
 		cout << temp->val << endl; 
 		temp = temp->next;
	}
 	
 	cout << "end" << endl;
 	
 	ListNode* result = partition(l1, 1);
 	
 	while (result != NULL)
 	{
 		cout << result->val << endl;
 		result = result->next;
	 }
 }
 
 
 

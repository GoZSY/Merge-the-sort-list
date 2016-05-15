/*******************************************
循环实现
*******************************************/
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == NULL && pHead2 == NULL)
            return NULL;
        else if(pHead1 == NULL)
            return pHead2;
        else if(pHead2 == NULL)
            return pHead1;
       
        ListNode* pHead = NULL;
        if(pHead1->val <= pHead2->val)
        {
			pHead = pHead1;
            pHead1 = pHead1->next;
        }
        else
        {
            pHead = pHead2;
            pHead1 = pHead2->next;
        }
        ListNode* pHead3 = pHead;
        while(pHead1 != NULL && pHead2 != NULL)
        {
            if(pHead1->val <= pHead2->val)
        	{
				pHead->next = pHead1;
            	pHead1 = pHead1->next;
                pHead = pHead->next;
        	}
        	else
        	{
            	pHead->next = pHead2;
            	pHead2 = pHead2->next;
                pHead = pHead->next;
        	}
        }
        if(pHead2 == NULL)
            pHead->next = pHead1;
        if(pHead1 == NULL)
            pHead->next = pHead2;
        return pHead3;
        
    }
};
/*********************************************************
递归实现
**********************************************************/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == NULL && pHead2 == NULL)
            return NULL;
        else if(pHead1 == NULL)
            return pHead2;
        else if (pHead2 == NULL)
            return pHead1;
             
        ListNode *pMergedHead = NULL;
         
        if(pHead1->val < pHead2->val)
            {
            pMergedHead = pHead1;
            pMergedHead -> next = Merge(pHead1->next,pHead2);
        }
        else
            {
            pMergedHead = pHead2;
            pMergedHead -> next = Merge(pHead1,pHead2->next);
        }
        return pMergedHead;
    }
};

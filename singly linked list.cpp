#include<bits/stdc++.h>
using namespace std;

struct node{

    int val;
    node *next;

    node(int k)
    {
        val = k;
        next = NULL;
    }
};

struct singlylinkedlist{

    node *head,*tail;

    singlylinkedlist();
    void insertintohead(int);
    void insertintotail(int);
    void insertafterhead(int);
    void insertbeforetail(int);
    void findnumberofelements();
    int deletefromhead();
    void insertatpos(int,int);
    int deleteatpos(int);
    void insertafterval(int,int);
    void insertbeforeval(int,int);
    void valatpos(int);
    void findpos(int);
    void maximumval();
    void minimumval();
    void deleteallocc(int);
    int deletefromtail();
    int deleteafterhead();
    int deletebeforetail();
    int deletebeforeval(int);
    int deleteafterval(int);
    void printlist();
};

singlylinkedlist::singlylinkedlist()
{
    head = NULL;
    tail = NULL;
}

void singlylinkedlist::insertintohead(int x)
{
    node *cur = new node(x);

    if(head==NULL)
    {
        head = tail = cur;
        return;
    }

    cur->next = head;
    head = cur;
}

void singlylinkedlist::insertintotail(int x)
{
    node *cur = new node(x);

    if(tail==NULL)
    {
        head = tail = cur;
        return;
    }

    tail->next = cur;
    tail = tail->next;
}

int singlylinkedlist::deletefromhead()
{
    if(head==NULL)
    {
        cout<<"underflow"<<endl;
        return -1;
    }
    node *temp = head;
    int ret = temp->val;

    if(head->next == NULL)
    {
        head = tail = NULL;
    }

    else
    {
        head = head->next;
    }

    delete temp;
    return ret;
}

void singlylinkedlist::insertafterhead(int x)
{
    node *cur = new node(x);
    if(head->next==NULL)
        head->next = cur;
    else
    {
        cur->next = head->next;
        head->next = cur;
    }
}

void singlylinkedlist::insertbeforetail(int x)
{
    node *cur = new node(x);
    if(head->next==NULL)
    {
        cur->next = head;
        head = cur;
    }

    else
    {
        node *temp = head;
        while(temp!=tail)
        {
            if(temp->next==tail)
                break;
            temp = temp->next;
        }

        cur->next = tail;
        temp->next = cur;
    }
}

void singlylinkedlist::findnumberofelements()
{
    int count=0;
    node *temp = head;
    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }

    cout<<"number of elements : "<<count<<endl<<endl;
}

void singlylinkedlist::insertatpos(int pos,int val)
{
    node *cur = new node(val);
    node *temp = head;
    int count = 1;

    while(count<(pos-1))
    {
        temp = temp->next;
        count++;
    }

    cur->next = temp->next;
    temp->next = cur;
}

int singlylinkedlist::deleteatpos(int pos)
{
    node *temp = head;
    node *cur = temp->next;
    int count = 1,ans;

    while(count<(pos-1))
    {
        temp = temp->next;
        cur = temp->next;
        count++;
    }

    temp->next = cur->next;
    ans = cur->val;
    free(temp);
    free(cur);
    return ans;
}

void singlylinkedlist::insertafterval(int val,int refval)
{
    node *cur = new node(val);
    node *temp = head;

    while(refval != (temp->val))
    {
        temp = temp->next;
    }

    cur->next = temp->next;
    temp->next = cur;
}

void singlylinkedlist::insertbeforeval(int val,int refval)
{
    node *cur = new node(val);
    node *temp = head;
    node *ref;

    while(refval != (temp->val))
    {
        ref = temp->next;
        if(refval==(ref->val))
            break;
        else
            temp = temp->next;
    }

    cur->next = temp->next;
    temp->next = cur;
}

void singlylinkedlist::valatpos(int pos)
{
    node *temp = head;
    int count = 1;

    while(count<pos)
    {
        temp = temp->next;
        count++;
    }

    cout<<"value at "<<pos<<" : "<<temp->val<<endl;
}

void singlylinkedlist::findpos(int val)
{
    node *temp = head;
    int count = 1;

    while(val != (temp->val))
    {
        temp = temp->next;
        count++;
    }

    cout<<val<<" is at position : "<<count<<endl;
}

void singlylinkedlist::maximumval()
{
    node *temp = head;
    int maxx = -1;

    while(temp!=NULL)
    {
        maxx = max(maxx,temp->val);
        temp = temp->next;
    }

    if(maxx==-1)
        cout<<"list is empty!!!"<<endl;
    else
        cout<<"maximum value is : "<<maxx<<endl;
}

void singlylinkedlist::minimumval()
{
    node *temp = head;
    int minn = INT_MAX;

    while(temp!=NULL)
    {
        minn = min(minn,temp->val);
        temp = temp->next;
    }

    if(minn==INT_MAX)
        cout<<"empty list!!!"<<endl;
    else 
        cout<<"minimum value is : "<<minn<<endl;
}

void singlylinkedlist::deleteallocc(int refval)
{
    node *temp = head;
    node *ref;

    while(temp->val==refval)
    {
        temp = temp->next;
        head = temp;
    }

    while(temp->next!=NULL)
    {
        ref = temp->next;
        while(ref->val==refval)
        {
            ref = ref->next;
        }

        temp->next = ref;
        temp = ref;
    } 
}

int singlylinkedlist::deletefromtail()
{
    node *temp = head;
    node *ref;
    ref = temp->next;
    int ans;

    if(head==tail)
        head = tail = NULL;

    while(ref!=tail)
    {
        temp->next = ref;
        temp = ref;
        ref = ref->next;
    }

    temp->next = NULL;
    tail = temp;
    ans = ref->val;
    free(temp);
    free(ref);
    return ans;
}

int singlylinkedlist::deleteafterhead()
{
    node *temp = head;
    int ans;

    if(head==tail)
        return -1;

    temp = head->next;
    head->next = temp->next;

    ans = temp->val;
    free(temp);
    return ans;
}

int singlylinkedlist::deletebeforetail()
{
    node *temp = head,*ref=temp->next;
    int ans;

    if(head==tail)
        return -1;

    if(ref==tail)
    {
        head = tail;
        ans = temp->val;
        free(temp);
        free(ref);
        return ans;
    }

    while(ref->next!=tail)
    {
        temp->next = ref;
        temp = ref;
        ref = ref->next;
    }

    temp->next = ref->next;

    ans = ref->val;
    free(temp);
    free(ref);
    return ans;
}

int singlylinkedlist::deletebeforeval(int refval)
{
    node *temp = head,*ref = temp->next,*cur=ref->next;
    int ans;

    if(head==tail)
    {
        return -1;
    }

    if(ref->val==refval)
    {
        head = tail;
        ans = temp->val;
        free(temp);
        free(ref);
        free(cur);
        return ans;
    }

    while(cur->val!=refval)
    {
        temp->next = ref;
        temp = ref;
        ref = ref->next;
        cur = cur->next;
    }

    if(cur->val==refval)
    {
        temp->next = cur;
        ans = ref->val;
        free(temp);
        free(ref);
        free(cur);
        return ans;
    }

    else
        return -1;
}

int singlylinkedlist::deleteafterval(int refval)
{
    node *temp = head,*ref = temp->next;
    int ans;

    if(head==tail)
        return -1;
    if(temp->val==refval)
    {
        head = tail;
        ans = ref->val;
        free(ref);
        free(temp);
        return ans;
    }

    while(temp->val!=refval)
    {
        temp->next = ref;
        temp = ref;
        ref = ref->next;
    }

    if(ref->next==NULL)
    {
        temp->next = NULL;
        tail = temp;
        ans = ref->val;
        free(ref);
        free(temp);
        return ans;
    }

    else
    {
        temp->next = ref->next;
        return ref->val;
    }
}

void singlylinkedlist::printlist()
{
    cout<< "list start ---------------" <<endl;
    if(head==NULL)
        cout<< endl;
    else
    {
        node *temp = head;

        while(temp!=NULL)
        {
            cout<<temp->val<<endl;
            temp = temp->next;
        }
    }
    cout<< "list end   ---------------\n" <<endl;
}

int main()
{
    singlylinkedlist sl;

    sl.insertintotail(5);
    sl.printlist();
    sl.insertintotail(56);
    sl.printlist();
    sl.insertintohead(156);
    sl.printlist();
    sl.insertintotail(6);
    sl.printlist();
    sl.deletefromhead();
    sl.printlist();
    sl.deletefromhead();
    sl.printlist();
    sl.deletefromhead();
    sl.printlist();
    sl.insertintotail(79);
    sl.printlist();
    sl.insertafterhead(102);
    sl.printlist();
    sl.insertbeforetail(3);
    sl.printlist();
    sl.findnumberofelements();
    sl.insertatpos(4,20);
    sl.printlist();
    sl.deleteatpos(3);
    sl.printlist();
    sl.insertafterval(67,102);
    sl.printlist();
    sl.insertbeforeval(43,20);
    sl.printlist();
    sl.valatpos(3);
    sl.findpos(20);
    sl.maximumval();
    sl.minimumval();
    sl.insertintotail(3);
    sl.insertintotail(3);
    sl.insertintohead(3);
    sl.insertafterhead(3);
    sl.insertatpos(4,3);
    sl.insertatpos(5,3);
    sl.insertatpos(6,3);
    sl.insertintotail(5);
    sl.printlist();
    sl.deleteallocc(3);
    sl.printlist();
    sl.deletefromtail();
    sl.printlist();
    sl.deleteafterhead();
    sl.printlist();
    sl.deletebeforetail();
    sl.printlist();
    sl.deletebeforeval(43);
    sl.printlist();
    sl.deleteafterval(43);
    sl.printlist();

    return 0;
}

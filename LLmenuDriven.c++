#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
    int data;
    node *next;
};

class linkedlist
{
    public:
    node *head=NULL;
    node *create(int num)
    {
        node *newNode = new node;
        newNode->data=num;
        newNode->next=NULL;
        return newNode;
    }
    void insert_head(int num)
    {
        node *newNode = create(num);
        if(head == NULL)
        {
            head=newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void insert_tail(int num)
    {   
        node *newNode=create(num);
        if(head==NULL)
        {
            head = newNode;
        }
        else
        {
            node *current;
            current=head;
            while(current->next!=NULL)
            {
                current=current->next;
            }
            current->next = newNode;
        }
    }
    void insert_mid(int num,int val)
    {
        node *newNode = create(num);
        node *current=head;
        if(head==NULL)
        {
            head = newNode;
        }
        else
        {
            while(current!=NULL)
            {
                if(current->data==val)
                {
                    break;
                }
                current=current->next;
            }
            newNode->next=current->next;
            current->next=newNode;
        }
    }
    void print()
    {
        cout << "-----------------"<<endl;
        node *current=head;
        while(current!=NULL)
        {
            cout<<current->data << "->";
            current = current->next;
        }
        cout << "NULL"<<endl;
        cout << "-----------------"<<endl;
    }
    int count()
    {
        int count=0;
        node *current=head;
        while(current!=NULL)
        {
            count++;
            current=current->next;
        }
        return count;
    }
    int recurcount(node *h)
    {
        static int c;
        if(h==NULL)
        {
            return c;
        }
        c++;
        h=h->next;
        recurcount(h);
    }
    void valuenode(int index)
    {
        node *current=head;
        int count=-1;
        while(current!=NULL)
        {
            count++;
            if(count==index)
            {
                break;
            }
            current = current->next;
        }
        cout <<"NODE:"<< current->data <<"->NULL"<<endl;
    }
    node* valuefromend(node *h,int i)
    {
        static int ct=-1;
        // if(h==NULL)
        // {
        //     return head;
        // }
        // h=h->next;
        h = valuefromend(h->next,i);
        ct++;
        cout <<":"<<ct<<":"<<endl;
    }
    void deletefromhead()
    {
        node *temp=head;
        head=head->next;
        temp->next=NULL;
        delete(temp);
    }
    void deletefromtail()
    {
        node *current=head;
        while(current->next->next!=NULL)
        {
            current=current->next;
        }
        current->next=NULL;
        delete(current);
    }
    void deletefrommiddle()
    {
        node *one=head;
        node *two=head;
        node *prev=head;
        node *end;
        while(two->next!=NULL)
        {
            prev=one;
            one=one->next;
            end = one->next;
            two=two->next->next;
        }
        prev->next=end;
        one->next=NULL;
        // cout <<"test:"<< prev->data << endl;
        // cout <<"test:"<< one->data << endl;
        // cout <<"test:"<< end->data << endl;
    }
    void deletefromval(int val)
    {
        if(head->data==val)
        {
            deletefromhead();
        }
        else
        {
            node *current = head;
            node *prev;
            while(current!=NULL)
            {
                if(current->data==val)
                {
                    break;
                }
                prev=current;
                current=current->next;
            }
            // cout <<"test:"<< prev->data << endl;
            // cout <<"test:"<< current->data << endl;
            prev->next = current->next;
        }
    }
    void deleteoddones()
    {
        if(head->next == NULL)
        {
            head=NULL;
        }
        else
        {
            node *current=head;
            node *prev=head;
            
            while(current!=NULL)
            {
                if(current->next==NULL)
                {
                    break;
                }
                current = current->next->next;
                prev->next=current;
                prev=current;
            }
        }
    }
};
int main()
{
   int a;
   while(1)
   {
        cout << "Enter the choice"<<endl;
        cout << "0. STOP"<<endl;
        cout << "1. insert at head"<<endl;
        cout << "2. insert at tail"<<endl;
        cout << "3. insert at mid"<<endl;
        cout << "4. print the list"<<endl;
        cout << "5. number of nodes using recursion"<<endl;
        cout << "6. no. of nodes using counter"<<endl;
        cout << "7. Value of nth node from front"<<endl;
        cout << "8. nth node from end"<<endl;
        cout << "9. delete from head" <<endl;
        cout << "10. delete from tail" <<endl;
        cout << "11. delete from middle"<<endl;
        cout << "12. delete from using value" <<endl;
        cout << "13. delete odd ones" << endl;
        cin >> a;
        switch(a)
        {
            case 0:
            cout << "stopped"<<endl;
            exit(0);
            case 1:
            linkedlist obj;
            obj.insert_head(3);

            break;
            case 2:
            obj.insert_tail(10);
            break;
            case 3:
            obj.insert_mid(99,10);
            break;
            case 4:
            obj.print();
            break;
            case 5:
            cout <<"SIZE:"<< obj.recurcount(head)<<endl;
            case 6:
            cout <<"SIZE USING COUNTER:"<< obj.count() <<endl;
            break;
            case 7:
            cout << "Enter the node index";
            int index;
            cin >> index;
            obj.valuenode(index);
            break;
            /*
            case 8:
            cout << "Enter the index from the end"<<endl;
            int i;
            cin >> i;
            node *m=obj.valuefromend(head,i);
            cout <<"NTH NODE FROM END:"<< m->data <<"-> NULL"<< endl;
            break;
            */
            case 9:
            obj.deletefromhead();
            break;
            case 10:
            obj.deletefromtail();
            break;
            case 11:
            obj.deletefrommiddle();
            break;
            case 12:
            int val;
            cout  << "Enter the value" << endl;
            cin >> val;
            obj.deletefromval(val);
            break;
            case 13:
            obj.deleteoddones();
            break;
        }
   }
}#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *head=NULL;
class linkedlist
{
    public:
    node *create(int num)
    {
        node *newNode = new node;
        newNode->data=num;
        newNode->next=NULL;
        return newNode;
    }
    void insert_head(int num)
    {
        node *newNode = create(num);
        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void insert_tail(int num)
    {   
        node *newNode=create(num);
        if(head==NULL)
        {
            head = newNode;
        }
        else
        {
            node *current;
            current=head;
            while(current->next!=NULL)
            {
                current=current->next;
            }
            current->next = newNode;
        }
    }
    void insert_mid(int num,int val)
    {
        node *newNode = create(num);
        node *current=head;
        if(head==NULL)
        {
            head = newNode;
        }
        else
        {
            while(current!=NULL)
            {
                if(current->data==val)
                {
                    break;
                }
                current=current->next;
            }
            newNode->next=current->next;
            current->next=newNode;
        }
    }
    void print()
    {
        cout << "-----------------"<<endl;
        node *current=head;
        while(current!=NULL)
        {
            cout<<current->data << "->";
            current = current->next;
        }
        cout << "NULL"<<endl;
        cout << "-----------------"<<endl;
    }
    int count()
    {
        int count=0;
        node *current=head;
        while(current!=NULL)
        {
            count++;
            current=current->next;
        }
        return count;
    }
    int recurcount(node *h)
    {
        static int c;
        if(h==NULL)
        {
            return c;
        }
        c++;
        h=h->next;
        recurcount(h);
    }
    void valuenode(int index)
    {
        node *current=head;
        int count=-1;
        while(current!=NULL)
        {
            count++;
            if(count==index)
            {
                break;
            }
            current = current->next;
        }
        cout <<"NODE:"<< current->data <<"->NULL"<<endl;
    }
    node* valuefromend(node *h,int i)
    {
        static int ct=-1;
        // if(h==NULL)
        // {
        //     return head;
        // }
        // h=h->next;
        h = valuefromend(h->next,i);
        ct++;
        cout <<":"<<ct<<":"<<endl;
    }
    void deletefromhead()
    {
        node *temp=head;
        head=head->next;
        temp->next=NULL;
        delete(temp);
    }
    void deletefromtail()
    {
        node *current=head;
        while(current->next->next!=NULL)
        {
            current=current->next;
        }
        current->next=NULL;
        delete(current);
    }
    void deletefrommiddle()
    {
        node *one=head;
        node *two=head;
        node *prev=head;
        node *end;
        while(two->next!=NULL)
        {
            prev=one;
            one=one->next;
            end = one->next;
            two=two->next->next;
        }
        prev->next=end;
        one->next=NULL;
        // cout <<"test:"<< prev->data << endl;
        // cout <<"test:"<< one->data << endl;
        // cout <<"test:"<< end->data << endl;
    }
    void deletefromval(int val)
    {
        if(head->data==val)
        {
            deletefromhead();
        }
        else
        {
            node *current = head;
            node *prev;
            while(current!=NULL)
            {
                if(current->data==val)
                {
                    break;
                }
                prev=current;
                current=current->next;
            }
            // cout <<"test:"<< prev->data << endl;
            // cout <<"test:"<< current->data << endl;
            prev->next = current->next;
        }
    }
    void deleteoddones()
    {
        if(head->next == NULL)
        {
            head=NULL;
        }
        else
        {
            node *current=head;
            node *prev=head;
            
            while(current!=NULL)
            {
                if(current->next==NULL)
                {
                    break;
                }
                current = current->next->next;
                prev->next=current;
                prev=current;
            }
        }
    }
};
int main()
{
   int a;
   while(1)
   {
        cout << "Enter the choice"<<endl;
        cout << "0. STOP"<<endl;
        cout << "1. insert at head"<<endl;
        cout << "2. insert at tail"<<endl;
        cout << "3. insert at mid"<<endl;
        cout << "4. print the list"<<endl;
        cout << "5. number of nodes using recursion"<<endl;
        cout << "6. no. of nodes using counter"<<endl;
        cout << "7. Value of nth node from front"<<endl;
        cout << "8. nth node from end"<<endl;
        cout << "9. delete from head" <<endl;
        cout << "10. delete from tail" <<endl;
        cout << "11. delete from middle"<<endl;
        cout << "12. delete from using value" <<endl;
        cout << "13. delete odd ones" << endl;
        cin >> a;
        switch(a)
        {
            case 0:
            cout << "stopped"<<endl;
            exit(0);
            case 1:
            linkedlist obj;
            obj.insert_head(3);

            break;
            case 2:
            obj.insert_tail(10);
            break;
            case 3:
            obj.insert_mid(99,10);
            break;
            case 4:
            obj.print();
            break;
            case 5:
            cout <<"SIZE:"<< obj.recurcount(head)<<endl;
            case 6:
            cout <<"SIZE USING COUNTER:"<< obj.count() <<endl;
            break;
            case 7:
            cout << "Enter the node index";
            int index;
            cin >> index;
            obj.valuenode(index);
            break;
            /*
            case 8:
            cout << "Enter the index from the end"<<endl;
            int i;
            cin >> i;
            node *m=obj.valuefromend(head,i);
            cout <<"NTH NODE FROM END:"<< m->data <<"-> NULL"<< endl;
            break;
            */
            case 9:
            obj.deletefromhead();
            break;
            case 10:
            obj.deletefromtail();
            break;
            case 11:
            obj.deletefrommiddle();
            break;
            case 12:
            int val;
            cout  << "Enter the value" << endl;
            cin >> val;
            obj.deletefromval(val);
            break;
            case 13:
            obj.deleteoddones();
            break;
        }
   }
}
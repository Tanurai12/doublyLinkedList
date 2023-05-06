//doubly linked list
#include<iostream>
using namespace std;
class node
{
    public:
    int value;
    node *pre;
    node *next;
    node()
    {
        pre=NULL;
        next=NULL;
    }

};

class DLL
{
    public:
    node *head;

    DLL()
    {
        head=NULL;

    }
    
    void insertAtEnd(int v)
    {
        node *t= new node();
        t->value=v;
       
        if(head==NULL)
        {
            head= t;

        }
        else
        {
             node *temp= head;
             while(temp->next!=NULL)
             temp=temp->next;
             temp->next=t;
         }
     }

     void printDLL()
     {
        node *t=head;
        if(t==NULL)
        {
            cout<<"list is empty...please enter the element first !!!"<<endl;
        }
        else
        {
        while(t->next!=NULL)
         {
            cout<<t->value<<"<->";
            t=t->next;
         }
          
      }
     }

     void insertAtBegin(int v)
     {
        node *temp= new node();
        temp->value=v;

        if(head==NULL)
        {
           head=temp;
           return;
        }
        else
        {
            temp->next=head;
            head->pre=temp;
            head=temp;
            

        }
     }

     void insertAtMidddle(int n,int v)
     {

        node *temp= new node();
        temp->value=v;
        if(head==NULL)
        {
           head=temp;
        }
        if(n==1)
        {   
            temp->next=head;
            head->pre=temp;
            head=temp;
        }
        else{
            node *t = head;
            while(n>2)
        {
            n--;
            
          if(t!=NULL)
            {
                  t=t->next;
            }
            else
            {
                cout<<"position not found"<<endl;
                return ;
            }
        }
         temp->next=t->next;
         t->next->pre=temp;
         temp->pre=t;
         t->next=temp;
        }

     }
     void deleteFromparticular(int n)
     {
        node *t= head;
        if(head==NULL)
            cout<<"list is empty"<<endl;
       
        if(n==1)
        {
            head=t->next;
            head->pre=NULL;
            cout<<t->value<<"deleted"<<endl;
            delete t;

        }
       else{

                while(n>1)
                {
                    n--;
                    if(t->next == NULL)
                    {
                        cout<<"Position not found"<<endl;
                        return;
                    }
                    t = t->next;
                }

                t->pre->next = t->next;
                if(t->next != NULL)
                    t->next->pre = t->pre;
                cout<<t->value<<" deleted"<<endl;
                delete t;
            }

     }

};
int main()
{
   DLL d1;
    int choice;
    while(1)
    {
        cout<<"1. insert at begin "<<endl;
        cout<<"2. insert at end "<<endl;
        cout<<"3. insert at particular space "<<endl;
        cout<<"4. display"<<endl;
        cout<<"5. delete from particular location"<<endl;
        cout<<"6. exit "<<endl;

        cout<<"enter your choice "<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1:
            {
                int value;
                cout<<"enter a value"<<endl;
                cin>>value;
                d1.insertAtBegin(value);
                break;
            }   
            case 2:
            {
                int value;
                
                cout<<"enter a value"<<endl;
                cin>>value;
                d1.insertAtEnd(value);
                break;
            }

            case 3:
            {
                 int value,loc;
                
                cout<<"enter a value and location"<<endl;
                cin>>value>>loc;
                d1.insertAtMidddle(value,loc);
                break;
            }

            case 4:
            {
               d1.printDLL(); 
               break;
            }
            case 5:
            {
                int loc;
                cout<<"enter a location"<<endl;
                cin>>loc;
                d1.deleteFromparticular(loc);
            }

            case 6:
            {
                exit(0);
            }
        }
    }
 return 0;
}
    
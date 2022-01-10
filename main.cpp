#include<iostream>


using namespace std;
// Queue for array
void enqueue(int);
void dequeue();
int isempty();
int isfull();
void array_call();
void show();
const int total = 2;
int marks[total];
int rear = -1; //rear mean last element of queue
int front = 0;//front mean first element of queue
int counter = 0;

// Queue for Linklist
struct list
{
    int data;
    list * next;
};
list *f, *c, *p, *temp;
int linklist_counter = 0;
void linklist_insert();
void linklist_call();
void linklist_dequeu();
void linklist_show();
void linklist_front();
int linklist_isempty();

//Queue for Double Linklist
struct dlist {
    dlist * prev;
    int data;
    dlist * next;
};
dlist *first, *current, *previos, *tamp;
int dlinklist_counter = 0;
void dlinklist_insert();
void dlinklist_call();
void dlinklist_dequeu();
void dlinklist_show();
void dlinklist_front();

int main()
{
    zee:
    system("cls");
    int i;
    cout << "\t\t\t\t Welcome in Queue  \n 1- Array \n 2- Link List \n 3- Double Link List \n 4- EXIT \n";
    cin >> i;

    switch (i)
    {
        case 1:
            array_call();
            goto zee;
        case 2:
            linklist_call();
            goto zee;
        case 3:

            dlinklist_call();
            goto zee;
        case 4:
            break;
        default:
            cout << " You enter invalid number PLZ Select again \n";
            system("pause");
            goto zee;
    }
    return 0;
}

// function of Array
void array_call()
{
    start:
    system("cls");
    cout << "\t\t\t\t Welcome in Queue with Array";
    int input;
    cout << "\n 1- Enqueu \n 2- Dequeu \n 3- Front\n 4- Show all data \n 5- Exit from Queue in Array \n";
    cin >> input;
    switch (input)
    {
        case 1:
        {int z; z = isfull();
            if (z)
            {
                int y;//y is input whiich you insert in queue
                cout << "Enter you number";
                cin >> y;
                enqueue(y);
                cout << " Number entered \n";
                system("pause");
            }
            else
            {
                cout << "Your Queue is full \n";
                system("pause");
            }
            goto start;
            break;
        }

        case 2:
        { int a; a = isempty();
            if (a)
            {
                dequeue();
                cout << "Number deleted \n ";
                system("pause");
            }
            else
            {
                cout << "Your Queue is Empty \n";
                system("pause");
            }
            goto start;
            break;
        }

        case 3:
        {
            int a; a = isempty();
            if (a)
                cout << "\n Your front value is " << marks[front]<<endl;
            else
                cout << "Your Queue is Empty"<<endl;
            system("pause");
            goto start;
            break;
        }

        case 4:
        {
            int a; a = isempty();
            if (a)
                show();
            else
                cout << "Your Queue is Empty"<<endl;
            system(" pause");
            goto start;
        }

        case 5:
        {
            break;
        }
        default:
            cout << "\n You enter invalid Number \n";
            system("pause");
            goto start;
            break;
    }

}
void enqueue(int x)
{
    rear = (rear + 1) % total;
    marks[rear] = x;
    counter = counter + 1;
}
void dequeue()
{
    front = (front + 1) % total;
    counter = counter - 1;
}
int isempty()
{
    return(counter != 0);
}
int isfull()
{
    return(counter != total);
}
void show()
{
    int j = front;
    for (int i = 0; i < counter; i++)
    {

        cout << " " << marks[j];
        j++;
        j = j%total;
    }
}

void linklist()
{
    linklist_start:
    system("cls");
    cout << "\t\t\t\t Welcome in linklist Queue";
    int input;
    cout << "\n 1- Enqueu \n 2- Dequeu \n 3- show list \n 4- Front\n 5- Exit\n";
    cin >> input;
    switch (input)
    {
        case 1:
            linklist_insert();
            cout << " Number entered \n";
            system("pause");
            goto linklist_start;
        case 2:
            linklist_dequeu();
            goto linklist_start;
        case 3:
            linklist_show();
            goto linklist_start;
        case 4:
            linklist_front();
            goto linklist_start;
        case 5:
            break;
        default:
            cout << " You enter invalid number ";
            system("pause");
            goto linklist_start;
    }
}
void linklist_insert()
{
    c = new list;
    if (linklist_counter == 0)
    {
        f = c;
        p = c;
        cout << " Enter data ";
        cin >> c->data;
    }
    else
    {
        p->next = c;
        p = c;
        cout << " Enter data";
        cin >> c->data;
    }
    c->next = NULL;
    linklist_counter++;
}
void linklist_dequeu()
{
    if (linklist_counter == 0)
    {
        cout << " Queue is empty";
        system("pause");
    }
    else
    {
        f = f->next;
        linklist_counter--;
        cout << "Number deleted \n ";
        system("pause");
    }
}
void linklist_show()
{
    int emp = linklist_isempty();
    if (emp)
    {
        temp = f;
        while (temp->next != NULL)
        {
            cout << " " << temp->data;
            temp = temp->next;
        }
        cout << " " << temp->data;
    }
    else
    {
        cout << " Queue is empty";
    }
    system("pause");
}
void linklist_front()
{
    int emp = linklist_isempty();
    if (emp)
    {
        cout << " " << f->data;
    }
    else
    {
        cout << " Queue is empty";
    }
    system("pause");
}
int linklist_isempty()
{
    return(linklist_counter != 0);
}

//function of DOUBLE LINK LIST
void dlinklist_call()
{
    dlinklist_start:
    system("cls");
    cout << "\t\t\t\t Welcome in Double linklist Queue";
    int dinput;
    cout << "\n 1- Enqueu \n 2- Dequeu \n 3- show list \n 4- Front\n 5- Exit\n";
    cin >> dinput;
    switch (dinput)
    {
        case 1:
            dlinklist_insert();
            cout << " Number entered \n";
            system("pause");
            goto dlinklist_start;
        case 2:
            dlinklist_dequeu();
            cout << "Number deleted \n ";
            system("pause");
            goto dlinklist_start;
        case 3:
            dlinklist_show();
            goto dlinklist_start;
        case 4:
            dlinklist_front();
            goto dlinklist_start;
        case 5:
            break;
        default:
            cout << " You enter invalid number ";
            system("pause");
            goto dlinklist_start;
    }
}
void dlinklist_insert()
{
    current = new dlist;
    if (dlinklist_counter == 0)
    {
        previos = current;
        first = current;
        current->prev = NULL;
        cout << " Enter Data ";
        cin >> current->data;
    }
    else
    {
        previos->next = current;
        current->prev = previos;
        previos = current;
        cout << " Enter Data ";
        cin >> current->data;
    }
    current->next = NULL;
    dlinklist_counter++;
}
void dlinklist_dequeu()
{
    if (dlinklist_counter == 0)
    {
        cout << " Queue is empty";
        system("pause");
    }
    else
    {
        first = first->next;
        dlinklist_counter--;
    }
}
void dlinklist_show()
{
    if (dlinklist_counter == 0)
    {
        cout << " Queue is empty";
    }
    else
    {
        tamp = first;
        while (tamp->next != NULL)
        {
            cout << " " << tamp->data;
            tamp = tamp->next;
        }
        cout << " " << tamp->data;
    }
    system("pause");
}
void dlinklist_front()
{
    if (dlinklist_counter == 0)
    {
        cout << " Queue is empty";
    }
    else
    {
        cout << " " << first->data;
    }
    system("pause");
}
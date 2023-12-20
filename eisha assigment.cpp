#include<iostream>
#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class StackWithArray
{
    char* array;
    int top;
    int capacity;

public:
    StackWithArray(int size)
    {
        array = new char[size];
        top = -1;
        capacity = size;
    }

    ~StackWithArray()
    {
        delete[] array;
    }

    void push(char x)
    {
        if (isFull())
        {
            cout << "Stack is full";
            return;
        }
        top++;
        array[top] = x;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty";
            return '\0';
        }
        char x = array[top];
        top--;
        return x;
    }

    bool isFull()
    {
        cout << (top == capacity - 1 ? "Stack is full" : "Not full");
        return top == capacity - 1;
    }

    bool isEmpty()
    {
        cout << (top == -1 ? "Stack is empty" : "Not empty");
        return top == -1;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "\nStack is empty\n";
            return '\0';
        }
        return array[top];
    }

    bool isBalanced(char* expression)
    {
        StackWithArray stack(strlen(expression));
        int i = 0;
        while (expression[i] != '\0')
        {
            if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
            {
                stack.push(expression[i]);
            }
            else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}')
            {
                if (stack.isEmpty())
                {
                    return false;
                }
                char temp = stack.pop();
                if ((expression[i] == ')' && temp != '(') || (expression[i] == ']' && temp != '[') ||
                    (expression[i] == '}' && temp != '{'))
                {
                    return false;
                }
            }
            i++;
        }
        return stack.isEmpty();
    }

    int precedence(char x)
    {
        if (x == '+' || x == '-')
            return 1;
        else if (x == '*' || x == '/')
            return 2;
        return 0; // Add this line to handle other cases
    }

    bool isOperand(char x)
    {
        return !(x == '+' || x == '-' || x == '*' || x == '/');
    }

    char* infixToPostfix(char* infix)
    {
        StackWithArray myStack(strlen(infix));
        int i = 0, j = 0;
        int length = strlen(infix);
        char* postfix = new char[length + 1];

        while (infix[i] != '\0')
        {
            if (isOperand(infix[i]))
                postfix[j++] = infix[i++];
            else
            {
                if (precedence(infix[i]) > precedence(myStack.peek()))
                    myStack.push(infix[i++]);
                else
                    postfix[j++] = myStack.pop();
            }
        }

        while (!myStack.isEmpty())
            postfix[j++] = myStack.pop();

        postfix[j] = '\0';
        return postfix;
    }

    int size()
    {
        return top + 1;
    }
};

class StackWithLinkedList
{
public:
    Node* top;
    int size;

    StackWithLinkedList() : top(nullptr), size(0) {}

    void push(int x)
    {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
        size++;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Underflow\n";
            return 0;
        }
        Node* temp = top;
        top = top->next;
        int key = temp->data;
        delete temp;
        size--;
        return key;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return 0;
        }
        return top->data;
    }

    bool isBalanced(char* expression)
    {
        StackWithLinkedList stack;
        int i = 0;
        while (expression[i] != '\0')
        {
            if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
            {
                stack.push(expression[i]);
            }
            else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}')
            {
                if (stack.isEmpty())
                {
                    return false;
                }
                char temp = stack.pop();
                if ((expression[i] == ')' && temp != '(') || (expression[i] == ']' && temp != '[') || (expression[i] == '}' && temp != '{'))
                {
                    return false;
                }
            }
            i++;
        }
        return stack.isEmpty();
    }

    int precedence(char x)
    {
        if (x == '+' || x == '-')
            return 1;
        else if (x == '*' || x == '/')
            return 2;
        return 0; // Add this line to handle other cases
    }

    bool isOperand(char x)
    {
        return !(x == '+' || x == '-' || x == '*' || x == '/');
    }

    char* infixToPostfix(char* infix)
    {
        StackWithLinkedList myStack;
        int i = 0, j = 0;
        int length = strlen(infix);
        char* postfix = new char[length + 1];

        while (infix[i] != '\0')
        {
            if (isOperand(infix[i]))
                postfix[j++] = infix[i++];
            else
            {
                if (precedence(infix[i]) > precedence(myStack.peek()))
                    myStack.push(infix[i++]);
                else
                    postfix[j++] = myStack.pop();
            }
        }

        while (!myStack.isEmpty())
            postfix[j++] = myStack.pop();

        postfix[j] = '\0';
        return postfix;
    }

    void display()
    {
        Node* current = top;
        cout << "Stack elements: ";
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }
};

class QueueWithArray
{
private:
    int front;
    int rear;
    static const int Size = 10;
    int Arr[Size];
    int count;

public:
    QueueWithArray()
    {
        front = -1;
        rear = -1;
        count = 0;
    }

    void Enqueue(int x)
    {
        if (IsFull())
        {
            cout << "Queue is full." << endl;
        }
        else
        {
            rear = rear + 1;
            Arr[rear] = x;
            count++; // Increment count when enqueuing an element
            cout << "Enqueued: " << x << endl;
        }
    }

    void Dequeue()
    {
        if (IsEmpty())
        {
            cout << "Queue is empty." << endl;
        }
        else
        {
            int dequeuedElement = Arr[front];
            front = front + 1;
            count--; // Decrement count when dequeuing an element
            cout << "Dequeued: " << dequeuedElement << endl;
        }
    }

    int getFront()
    {
        if (IsEmpty())
        {
            cout << "Queue is empty." << endl;
            return -1;
        }
        else
        {
            return Arr[front];
        }
    }

    int getRear()
    {
        if (IsEmpty())
        {
            cout << "Queue is empty." << endl;
            return -1;
        }
        else
        {
            return Arr[rear];
        }
    }

    bool IsFull()
    {
        return rear == Size - 1;
    }

    int size()
    {
        return count;
    }

    bool IsEmpty()
    {
        return rear == -1 && front == -1;
    }
};

class QueueWithLinkedList
{
private:
    Node* front;
    Node* rear;

public:
    QueueWithLinkedList()
    {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int value)
    {
        Node* newNode = new Node(value);
        if (rear == NULL)
        {
            rear = front = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue already empty" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        delete temp;
    }

    void getFront()
    {
        if (front == NULL)
        {
            cout << "Queue empty";
            return;
        }
        else
        {
            cout << "Front is: " << front->data << endl;
        }
    }

    void getRear()
    {
        if (rear == NULL)
        {
            cout << "Queue empty";
            return;
        }
        else
        {
            cout << "Rear is: " << rear->data << endl;
        }
    }

    bool isEmpty()
    {
        return (front == NULL);
    }

    void display()
    {
        Node* temp = front;
        if (temp == NULL)
        {
            cout << "Nothing in the queue" << endl;
        }
        else
        {
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};
int main()
{
    int ch;
    char infix[] = "a+b*c-d/e";
    char exp1[] = "(a+b)*(c-d)()()";

    StackWithLinkedList stackLL;
    QueueWithArray queueArr;
    QueueWithLinkedList queueLL;

    while (true)
    {
        system("CLS");
        cout.clear();
    menu:
        cout << "-----------------------------------------------Stacks and Queues-------------------------------------------------------\n\n";
        cout << "1 to Choose Stack with Array:" << endl;
        cout << "2 to Choose Stack with Linked List" << endl;
        cout << "3 to Choose Queue with Array" << endl;
        cout << "4 to Choose Queue with Linked List" << endl;
        cout << "5 to exit" << endl;
        cin >> ch;
        system("CLS");

        switch (ch)
        {
        case 1:
        {
            cout << "Stack With Array\n";
            int size;
            cout << "Enter size of the Stack: ";
            cin >> size;
            system("CLS");
            StackWithArray stackArr(size);
            int op;

            while (true)
            {
                cout << "1 to Push a Value" << endl;
                cout << "2 to pop a Value" << endl;
                cout << "3 to peek a Value" << endl;
                cout << "4 to check if empty" << endl;
                cout << "5 to check if full" << endl;
                cout << "6 to get the size" << endl;
                cout << "7 to Check if Balanced" << endl;
                cout << "8 to Check infix to postfix" << endl;
                cout << "9 to Go back to menu" << endl;
                cout << "10 to Exit" << endl;
                cin >> op;

                switch (op)
                {
                case 1:
                    cout << "Enter a value to push: ";
                    char x;
                    cin >> x;
                    stackArr.push(x);
                    break;
                case 2:
                    cout << stackArr.pop() << "\n";
                    break;
                case 3:
                    cout << "Top element of the stack: " << stackArr.peek() << "\n";
                    break;
                case 4:
                    if (stackArr.isEmpty())
                    {
                        cout << "Stack is empty\n";
                    }
                    else
                    {
                        cout << "Stack is not empty\n";
                    }
                    break;
                case 5:
                    if (stackArr.isFull())
                    {
                        cout << "Stack is full\n";
                    }
                    else
                    {
                        cout << "Stack is not full\n";
                    }
                    break;
                case 6:
                    cout << "Size of the stack: " << stackArr.size() << "\n";
                    break;
                case 7:
                    cout << "Expression: (a+b)*(c-d)()()";
                    cout << "Is " << exp1 << " balanced? "
                         << (stackArr.isBalanced(exp1) ? "Yes \n" : "No \n");
                    break;
                case 8:
                    cout << "Expression is a+b*c-d/e";
                    cout << "Infix: " << infix << endl;
                    cout << "Postfix: " << stackArr.infixToPostfix(infix) << endl;
                    break;
                case 9:
                    system("CLS");
                    goto menu;
                    break;
                case 10:
                    return 0;
                    break;
                default:
                    cout << "Enter a valid number\n";
                    break;
                }

                system("Pause>0");
                system("CLS");
            }
            break;
        }
        case 2:
        {
            cout << "Stack With Linked List\n";
            int op;

            while (true)
            {
                cout << "1 to Push a Value" << endl;
                cout << "2 to pop a Value" << endl;
                cout << "3 to peek a Value" << endl;
                cout << "4 to check if empty" << endl;
                cout << "5 to get the size" << endl;
                cout << "6 to display stack" << endl;
                cout << "7 to Check if balanced" << endl;
                cout << "8 to Check infix to postfix" << endl;
                cout << "9 to Go back to menu" << endl;
                cout << "10 to Exit" << endl;
                cin >> op;

                switch (op)
                {
                case 1:
                    cout << "Enter a value to push: ";
                    int x;
                    cin >> x;
                    stackLL.push(x);
                    break;
                case 2:
                    cout << stackLL.pop() << "\n";
                    break;
                case 3:
                    cout << "Top element of the stack: " << stackLL.peek() << "\n";
                    break;
                case 4:
                    if (stackLL.isEmpty())
                    {
                        cout << "Stack is empty\n";
                    }
                    else
                    {
                        cout << "Stack is not empty\n";
                    }
                    break;
                case 5:
                        cout << "Size of the stack: " << stackLL.size << "\n";
                    break;

                case 6:
                    stackLL.display();
                    break;
                case 7:
                    cout << "Expression: (a+b)*(c-d)()()";
                    cout << "Is " << exp1 << " balanced? "
                         << (stackLL.isBalanced(exp1) ? "Yes \n" : "No \n");
                    break;
                case 8:
                    cout << "Expression is a+b*c-d/e";
                    cout << "Infix: " << infix << endl;
                    cout << "Postfix: " << stackLL.infixToPostfix(infix) << endl;
                    break;
                case 9:
                    system("CLS");
                    goto menu;
                    break;
                case 10:
                    return 0;
                    break;
                default:
                    cout << "Enter a valid number\n";
                    break;
                }

                system("Pause>0");
                system("CLS");
            }
            break;
        }
        // Add cases for Queue with Array, Queue with Linked List, and Exit options
        // ...

        case 5:
            return 0;
        default:
            cout << "Enter a valid number\n";
            break;
        }

        system("Pause>0");
        system("CLS");
    }

    return 0;
}

